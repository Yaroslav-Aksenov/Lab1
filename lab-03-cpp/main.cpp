#include <iostream>
#include <clocale>
#include <memory>
#include "RiskFactor.hpp"
#include "EmergencyType.hpp"
#include "Region.hpp"

using namespace emergency;

void PrintRegionInfo(const Region& region)
{
    std::cout << "  [Ссылка] Регион: " << region.GetName() << ", код: " << region.GetCode() << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "=== Умные указатели: Композиция и Агрегация ===\n\n";

    // 1. Агрегация: создаем через make_shared 
    std::cout << "1. Агрегация (shared_ptr)\n";
    auto earthquake = std::make_shared<EmergencyType>(1, "Землетрясение", "Природное", 5);

    // 2. Композиция: Region создается через make_unique (единоличное владение)
    std::cout << "\n2. Композиция (unique_ptr)\n";
    auto kamchatka = std::make_unique<Region>("Камчатский край", "41", 316000);

    // Передаем shared_ptr в регион (счетчик ссылок earthquake станет 2)
    kamchatka->SetEmergencyType(earthquake);

    // Передаем владение фактором региону через std::move
    kamchatka->AddFactor(std::make_unique<RiskFactor>("Сейсмика", 0.8, 0.9, "Высокая активность"));

    std::cout << "Регион: " << kamchatka->GetName()
        << ", Тип ЧС: " << kamchatka->GetEmergencyType()->GetName()
        << ", Риск: " << kamchatka->GetTotalRisk() << "\n";

    PrintRegionInfo(*kamchatka); 
    std::cout << "\n";

    // 3. Проверка правила (без изменений, работает как раньше)
    std::cout << "3. Проверка правила \n";
    RiskFactor bad("Тест", 0.5, 0.5, "Тест");
    bad.SetWeight(1.5);  
    std::cout << "Итоговый вес: " << bad.GetWeight() << "\n\n";

    // 4. Время жизни: композиция (автоматическая очистка!)
    std::cout << "4. Время жизни: композиция\n";
    {
        auto temp = std::make_unique<Region>("Временный", "99", 1000);
        temp->AddFactor(std::make_unique<RiskFactor>("Временный фактор", 0.5, 0.5, "Тест"));
        std::cout << "+++Выход из блока+++\n";
    } // temp и его факторы уничтожаются
    std::cout << "Фактор уничтожен вместе с регионом (см. лог выше)\n\n";

    // 5. Время жизни: агрегация (shared_ptr продлевает жизнь)
    std::cout << "5. Время жизни: агрегация\n";
    auto flood = std::make_shared<EmergencyType>(2, "Наводнение", "Природное", 3);
    {
        auto temp2 = std::make_unique<Region>("Тест", "88", 2000);
        temp2->SetEmergencyType(flood); // Счетчик ссылок flood = 2
        std::cout << "+++Выход из блока+++\n";
    } // temp2 уничтожается, счетчик flood уменьшается до 1, но flood ЖИВ!
    std::cout << "Тип ЧС жив: " << flood->GetName() << " (счетчик ссылок: " << flood.use_count() << ")\n\n";

    // 6. Динамическая инициализация БЕЗ new и delete!
    std::cout << "6. Динамическая инициализация (без new/delete)\n";
    auto moscow = std::make_unique<Region>("Москва", "77", 12000000);
    auto fire = std::make_shared<EmergencyType>(3, "Пожар", "Техногенное", 4);
    moscow->SetEmergencyType(fire);
    std::cout << "Регион: " << moscow->GetName() << "\n";
    // moscow или fire удалятся сами в конце main().

    // 7. weak_ptr  наблюдатель
    std::cout << "7. Наблюдение через weak_ptr\n";
    auto observed = std::make_shared<EmergencyType>(4, "Ураган", "Природное", 4);
    std::weak_ptr<EmergencyType> observer = observed;

    if (auto locked = observer.lock()) {
        std::cout << "Наблюдатель видит: " << locked->GetName() << "\n";
    }
    else {
        std::cout << "Объект уничтожен\n";
    }

    observed.reset();

    if (auto locked = observer.lock()) {
        std::cout << "Наблюдатель видит: " << locked->GetName() << "\n";
    }
    else {
        std::cout << "Объект уничтожен — наблюдатель видит\n";
    }
    std::cout << "Программа завершена\n";
    return 0;
} // moscow, fire, kamchatka и earthquake будут автоматически уничтожены
