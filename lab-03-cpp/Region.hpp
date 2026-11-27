#pragma once
#include <string>
#include <string_view>
#include <vector>
#include <memory> 
#include "RiskFactor.hpp"
#include "EmergencyType.hpp"

namespace emergency
{
    class Region
    {
    private:
        std::string m_name{};
        std::string m_code{};
        int m_population{ 0 };

        // КОМПОЗИЦИЯ Region единолично владеет факторами через unique_ptr
        std::vector<std::unique_ptr<RiskFactor>> m_factors;

        // АГРЕГАЦИЯ Region делит владение типом ЧС через shared_ptr
        std::shared_ptr<EmergencyType> m_emergencyType;

    public:
        Region(std::string_view name, std::string_view code, int population);
        Region();
        ~Region();

        [[nodiscard]] std::string_view GetName() const;
        [[nodiscard]] std::string_view GetCode() const;
        [[nodiscard]] int GetPopulation() const;
        [[nodiscard]] size_t GetFactorCount() const; // size_t вместо int для вектора

        // Возвращаем shared_ptr (или nullptr, если не задан)
        [[nodiscard]] std::shared_ptr<EmergencyType> GetEmergencyType() const;

        // Принимает shared_ptr по значению (увеличивает счетчик ссылок)
        void SetEmergencyType(std::shared_ptr<EmergencyType> type);

        // Принимает unique_ptr через std::move (передаем право владения)
        void AddFactor(std::unique_ptr<RiskFactor> factor);

        [[nodiscard]] double GetTotalRisk() const;
        [[nodiscard]] std::string GetRiskLevel() const;
    };
} // namespace emergency
