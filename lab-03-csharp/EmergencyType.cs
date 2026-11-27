

namespace lab03_csharp
{
    public class EmergencyType
    {
        // Свойства
        public string Name { get; private set; }
        public string Category { get; private set; }
        public int DangerLevel { get; private set; }
        public int Id { get; private set; }

        // Конструктор 
        public EmergencyType(string name, string category, int dangerLevel, int id)
        {
            
            Name = name;
            Category = category;
            DangerLevel = dangerLevel;
            Id = id;

        }
        // Конструктор по умолчанию
        public EmergencyType()
        {
            Id = 0;
            Name = "НЕИЗВЕСТНО";
            Category = "НЕИЗВЕСТНО";
            DangerLevel = 1;

        }

        // Метод с проверкой правила
        public void SetDangerLevel(int level)
        {
            if (level < 1 || level > 5)
            {
                Console.WriteLine($"[ERR] Уровень опасмности должен быть от 1 до 5, получено:{level}");
                return;
            }
            DangerLevel = level;
        }

        // Содержательный метод
        public bool IsHighDanger()
        {
            return DangerLevel >= 4;
        }

        // Переопределение ToString()
        public override string ToString()
        {
            return $"[EmergencyType] {Name}({Category},уровень опасности: {DangerLevel})";
        }

    }
}
