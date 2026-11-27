using System.Collections.Generic;

namespace lab03_csharp
{
    public class Region
    {
        public string Name { get; private set; }
        public string Code { get; private set; }
        public int Population { get; private set; }

        private List<RiskFactor> _factors;

        public EmergencyType EmergencyType { get; private set; }

        public Region(string name, string code, int population)
        {
            Name = name;
            Code = code;
            Population = population;
            _factors = new List<RiskFactor>();  
        }

        public Region()
        {
            Name = "НЕИЗВЕСТНО";
            Code = "0";
            Population = 0;
            _factors = new List<RiskFactor>();
        }

        public void AddFactor(RiskFactor factor)
        {
            if (_factors.Count >= 10)
            {
                Console.WriteLine("[ERR] Нельзя добавить больше 10 факторов риска");
                return;
            }
            _factors.Add(factor);
        }

        public double GetTotalRisk()
        {
            double total = 0;
            foreach (var factor in _factors)
            {
                total += factor.GetContribution();
            }
            return total;
        }

        public string GetRiskLevel()
        {
            double risk = GetTotalRisk();
            if (risk < 1.0) return "Низкий";
            if (risk < 3.0) return "Средний";
            return "Высокий";
        }

        public void SetEmergencyType(EmergencyType type)
        {
            EmergencyType = type;
        }

        public override string ToString()
        {
            return $"[Region] {Name} (код: {Code}), население: {Population}, риск: {GetRiskLevel()}";
        }

        ~Region()
        {
            Console.WriteLine($"[GC] Регион {Name} уничтожен сборщиком мусора!");
        }
    }
}