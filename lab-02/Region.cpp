#include "Region.hpp"
#include <iostream>

namespace emergency
{
    Region::Region(std::string_view name, std::string_view code, int population)
        : m_name{ name }
        , m_code{ code }
        , m_population{ population }
        , m_factorCount{ 0 }
        , m_emergencyType{ nullptr }
    {
        std::cout << "[Region] Создан: " << m_name << "\n";
    }

    Region::Region()
        : m_name{ "Неизвестный" }
        , m_code{ "00" }
        , m_population{ 0 }
        , m_factorCount{ 0 }
        , m_emergencyType{ nullptr }
    {
        std::cout << "[Region] Создан пустой регион\n";
    }

    Region::~Region()
    {
        std::cout << "[Region] Уничтожен: " << m_name << " (факторов: " << m_factorCount << ")\n";
    }

    std::string_view Region::GetName() const { return m_name; }
    std::string_view Region::GetCode() const { return m_code; }
    int Region::GetPopulation() const { return m_population; }
    int Region::GetFactorCount() const { return m_factorCount; }
    EmergencyType* Region::GetEmergencyType() const { return m_emergencyType; }

    void Region::SetEmergencyType(EmergencyType* type)
    {
        m_emergencyType = type;
    }

    void Region::AddFactor(const RiskFactor& factor)
    {
        if (m_factorCount >= 10)
        {
            std::cout << "[Ошибка] Нельзя добавить больше 10 факторов\n";
            return;
        }
        m_factors[m_factorCount] = factor;
        m_factorCount++;
        std::cout << "[Region] Добавлен фактор: " << factor.GetName() << "\n";
    }

    bool Region::RemoveFactor(std::string_view factorName)
    {
        for (int i = 0; i < m_factorCount; i++)
        {
            if (m_factors[i].GetName() == factorName)
            {
                for (int j = i; j < m_factorCount - 1; j++)
                {
                    m_factors[j] = m_factors[j + 1];
                }
                m_factorCount--;
                std::cout << "[Region] Удалён фактор: " << factorName << "\n";
                return true;
            }
        }
        std::cout << "[Ошибка] Фактор не найден: " << factorName << "\n";
        return false;
    }

    double Region::GetTotalRisk() const
    {
        double total = 0.0;
        for (int i = 0; i < m_factorCount; i++)
        {
            total += m_factors[i].GetContribution();
        }
        return total;
    }

    std::string Region::GetRiskLevel() const
    {
        double risk = GetTotalRisk();
        if (risk < 1.0) return "низкий";
        if (risk < 2.0) return "средний";
        return "высокий";
    }
} // namespace emergency