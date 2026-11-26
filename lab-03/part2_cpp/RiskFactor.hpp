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
        RiskFactor(std::string_view name, double value, double weight, std::string_view description);
        RiskFactor();
        ~RiskFactor();

        [[nodiscard]] std::string_view GetName() const;
        [[nodiscard]] double GetValue() const;
        [[nodiscard]] double GetWeight() const;
        [[nodiscard]] std::string_view GetDescription() const;

        void SetValue(double value);
        void SetWeight(double weight);

        [[nodiscard]] double GetContribution() const;
        [[nodiscard]] bool IsCritical() const;
    };
} // namespace emergency
