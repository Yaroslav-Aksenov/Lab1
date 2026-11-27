

namespace lab03_csharp
{
    public class RiskFactor
    {
        public string Name { get; private set; }
        public double Value { get; private set; }
        public double Weight { get; private set; }
        public string Description { get; private set; }

        public RiskFactor(string name, double value, double weight, string description)
        {
            Name = name;
            SetValue(value);
            SetWeight(weight);
            Description = description;
        }
        public RiskFactor()
        {
            Name = "НЕИЗВЕСТНО";
            Value = 0;
            Weight = 0;
            Description = "НЕИЗВЕСТНО";
        }

        public void SetValue(double value)
        {
            if (value < 0 || value > 1)
            {
                Console.WriteLine($"[ERR] Значение должно быть от 0 до 1, указано:{value}");
                return;            }

            Value = value;
            
        }
        public void SetWeight(double weight)
        {
            if (weight < 0 || weight > 1)
            {
                Console.WriteLine($"[ERR] Вес должно быть от 0 до 1, указано:{weight}");
                return;
            }

            Weight = weight;

        }

        public double GetContribution()
        {
            return (Value * Weight);
        } 
        
        public bool IsCritical()
        {
            return GetContribution() > 0.7;
        }

        // Переопределение ToString()
        public override string ToString()
        {
            return $"[RiskFactor] {Name}: значение= {Value}, вес= {Weight}, вклад= {GetContribution():F2}";
        }
    }
}
