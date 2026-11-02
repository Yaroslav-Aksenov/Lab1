#pragma once
#include <string>
#include <string_view>

namespace emergency
{
    class RiskFactor
    {
    private:
        std::string m_name{};
        double m_value{ 0.0 };
        double m_weight{ 0.0 };
        std::string m_description{};

    public:
        // Конструктор с параметрами
        RiskFactor(std::string_view name, double value, double weight, std::string_view description);

        // Конструктор по умолчанию
        RiskFactor();

        // Деструктор
        ~RiskFactor();


        // Геттеры
        [[nodiscard]] std::string_view GetName() const;
        [[nodiscard]] double GetValue() const;
        [[nodiscard]] double GetWeight() const;
        [[nodiscard]] std::string_view GetDescription() const;

        // Сеттеры с проверкой правил
        void SetValue(double value);
        void SetWeight(double weight);  // Правило: вес от 0 до 1

        // Содержательные методы
        [[nodiscard]] double GetContribution() const;  // value * weight
        [[nodiscard]] bool IsCritical() const;         // true, если вклад > 0.7
    };
} // namespace emergency