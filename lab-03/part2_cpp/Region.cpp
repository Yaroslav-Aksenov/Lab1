#include "Region.hpp"
#include <iostream>

namespace emergency
{
    Region::Region(std::string_view name, std::string_view code, int population)
        : m_name{ name }
        , m_code{ code }
        , m_population{ population }
    {
        std::cout << "[Region] Создан: " << m_name << "\n";
    }

    Region::Region()
        : m_name{ "Неизвестный" }
        , m_code{ "00" }
        , m_population{ 0 }
    {
        std::cout << "[Region] Создан пустой регион\n";
    }

    Region::~Region()
    {
        std::cout << "[Region] Уничтожен: " << m_name << " (факторов: " << m_factors.size() << ")\n";
        
    }

    std::string_view Region::GetName() const { return m_name; }
    std::string_view Region::GetCode() const { return m_code; }
    int Region::GetPopulation() const { return m_population; }
    size_t Region::GetFactorCount() const { return m_factors.size(); }

    std::shared_ptr<EmergencyType> Region::GetEmergencyType() const {
        return m_emergencyType;
    }

    void Region::SetEmergencyType(std::shared_ptr<EmergencyType> type)
    {
        m_emergencyType = type;
    }

    void Region::AddFactor(std::unique_ptr<RiskFactor> factor)
    {
        if (m_factors.size() >= 10)
        {
            std::cout << "[Ошибка] Нельзя добавить больше 10 факторов\n";
            return;
        }
        // std::move передает право владения уникальным указателем внутрь вектора
        m_factors.push_back(std::move(factor));
        std::cout << "[Region] Добавлен фактор\n";
    }

    double Region::GetTotalRisk() const
    {
        double total = 0.0;
        for (const auto& factor : m_factors) 
        {
            total += factor->GetContribution();
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
