#pragma once
#include <string>
#include <string_view>

namespace emergency
{
    class EmergencyType
    {
    private:
        int m_id{ 0 };
        std::string m_name{};
        std::string m_category{};
        int m_dangerLevel{ 1 };

    public:
        // Конструктор с параметрами
        EmergencyType(int id, std::string_view name, std::string_view category, int dangerLevel);

        // Конструктор по умолчанию
        EmergencyType();

        // Деструктор
        ~EmergencyType();


        // Геттеры
        [[nodiscard]] int GetId() const;
        [[nodiscard]] std::string_view GetName() const;
        [[nodiscard]] std::string_view GetCategory() const;
        [[nodiscard]] int GetDangerLevel() const;

        // Сеттер с проверкой правила
        void SetDangerLevel(int level);  // Правило: уровень от 1 до 5

        // Содержательный метод
        [[nodiscard]] bool IsHighDanger() const;  // true, если уровень >= 4
    };
} // namespace emergency