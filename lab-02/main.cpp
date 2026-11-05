#include <iostream>
#include <clocale>
#include "RiskFactor.hpp"
#include "EmergencyType.hpp"
#include "Region.hpp"

using namespace emergency;

// Работы по ссылке 
void PrintRegionInfo(const Region& region)
{
    std::cout << "  [Ссылка] Регион: " << region.GetName() << ", код: " << region.GetCode() << "\n";
        
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << " Композиция и агрегация\n\n";

    // 1. Агрегация: EmergencyType создаётся отдельно
    std::cout << "1. Агрегация\n";
    EmergencyType earthquake(1, "Землетрясение", "Природное", 5);

    // 2. Композиция: Region содержит факторы
    std::cout << "\n2. Композиция\n";
    Region kamchatka("Камчатский край", "41", 316000);
    kamchatka.SetEmergencyType(&earthquake); // Работа по указателю

    RiskFactor seismic("Сейсмика", 0.8, 0.9, "Высокая активность");
    kamchatka.AddFactor(seismic);

    std::cout << "Регион: " << kamchatka.GetName()
        << ", Тип ЧС: " << kamchatka.GetEmergencyType()->GetName()
        << ", Риск: " << kamchatka.GetTotalRisk() << "\n";

    // Работа по ссылке
    PrintRegionInfo(kamchatka);
    std::cout << "\n";

    // 3 Проверка правила
    std::cout << "3. Проверка правила \n";
    RiskFactor bad("Тест", 0.5, 0.5, "Тест");
    bad.SetWeight(1.5);  // Ошибка: вес > 1
    std::cout << "Итоговый вес: " << bad.GetWeight() << "\n\n";

    // 4 Время жизни: композиция
    std::cout << "4. Время жизни: композиция\n";
    {
        Region temp("Временный", "99", 1000);
        RiskFactor f("Временный фактор", 0.5, 0.5, "Тест");
        temp.AddFactor(f);
        std::cout << "Выходи из блока\n";
    }
    std::cout << "Фактор уничтожен вместе с регионом\n\n";

    // 5 Время жизни: агрегация
    std::cout << "5. Время жизни: агрегация\n";
    EmergencyType flood(2, "Наводнение", "Природное", 3);
    {
        Region temp2("Тест", "88", 2000);
        temp2.SetEmergencyType(&flood);
        std::cout << "Выход из блока\n";
    }
    std::cout << "Тип ЧС жив: " << flood.GetName() << "\n\n";

    // 6 Динамическая инициализация 
    std::cout << "6. Динамическая инициализация\n";
    Region* moscow = new Region("Москва", "77", 12000000);
    EmergencyType* fire = new EmergencyType(3, "Пожар", "Техногенное", 4);
    moscow->SetEmergencyType(fire);
    std::cout << "Регион: " << moscow->GetName() << "\n";
    delete moscow;
    delete fire;
    std::cout << "\n";

    // 7 Динамический массив объектов 
    std::cout << "7. Динамический массив объектов\n";
    int count = 5;
    Region* regionsArray = new Region[count]; 

    for (int i = 0; i < count; i++)
    {
        std::cout << "Элемент массива " << i << " инициализирован\n";
    }

    delete[] regionsArray; 
    std::cout << "Массив удалён через delete[]\n\n";

    std::cout << "Программа завершена\n";
    return 0;
}