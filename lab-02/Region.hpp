#pragma once
#include <string>
#include <string_view>
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

        emergency::RiskFactor m_factors[10];  
        int m_factorCount{ 0 };

        EmergencyType* m_emergencyType{ nullptr };

    public:
        bool RemoveFactor(std::string_view factorName);
        Region(std::string_view name, std::string_view code, int population);
        Region();
        ~Region();

        [[nodiscard]] std::string_view GetName() const;
        [[nodiscard]] std::string_view GetCode() const;
        [[nodiscard]] int GetPopulation() const;
        [[nodiscard]] int GetFactorCount() const;
        [[nodiscard]] EmergencyType* GetEmergencyType() const;

        void SetEmergencyType(EmergencyType* type);
        void AddFactor(const emergency::RiskFactor& factor);  
        [[nodiscard]] double GetTotalRisk() const;
        [[nodiscard]] std::string GetRiskLevel() const;
    };
} // namespace emergency