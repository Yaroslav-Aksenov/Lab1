#include "RiskFactor.hpp"
#include <iostream>

namespace emergency
{
    RiskFactor::RiskFactor(std::string_view name, double value, double weight, std::string_view description)
        : m_name{ name }
        , m_value{ value }
        , m_weight{ weight }
        , m_description{ description }
    {
        std::cout << "[RiskFactor] Создан: " << m_name << "\n";
    }

    RiskFactor::RiskFactor()
        : m_name{ "Пустой" }
        , m_value{ 0.0 }
        , m_weight{ 0.0 }
        , m_description{ "" }
    {

    }

    RiskFactor::~RiskFactor()
    {
        if (m_name != "Пустой") {
            std::cout << "[RiskFactor] Уничтожен: " << m_name << "\n";
        }
    }

    std::string_view RiskFactor::GetName() const { return m_name; }
    double RiskFactor::GetValue() const { return m_value; }
    double RiskFactor::GetWeight() const { return m_weight; }
    std::string_view RiskFactor::GetDescription() const { return m_description; }

    void RiskFactor::SetValue(double value)
    {
        if (value < 0.0 || value > 1.0)
        {
            std::cout << "[Ошибка] Значение фактора должно быть от 0 до 1\n";
            return;
        }
        m_value = value;
    }

    void RiskFactor::SetWeight(double weight)
    {
        // вес от 0 до 1
        if (weight < 0.0 || weight > 1.0)
        {
            std::cout << "[Ошибка] Вес фактора должен быть от 0 до 1, получено: " << weight << "\n";
            return;
        }
        m_weight = weight;
    }

    double RiskFactor::GetContribution() const
    {
        return m_value * m_weight;
    }

    bool RiskFactor::IsCritical() const
    {
        return GetContribution() > 0.7;
    }
} // namespace emergency
