
using lab03_csharp;
using System.Text;

Console.OutputEncoding = System.Text.Encoding.UTF8;

// Блок 1: Базовый сценарий (Композиция + Агрегация + Правило)
Console.WriteLine("\n=== Блок 1: Базовый сценарий (Композиция + Агрегация + Правило ===)\n");
var flood = new EmergencyType("Наводнение", "Природное", 3, 1);

var region = new Region("Krasnodarski krai", "23", 5842238);
var factor1 = new RiskFactor("Наводнение",0.7,0.7,"Частота ливней");
var factor2 = new RiskFactor("Наводнение", 0.9, 0.9, "Близость к крупным рекам");


region.AddFactor(factor1);
region.AddFactor(factor2);

region.SetEmergencyType(flood);
Console.WriteLine(region.GetTotalRisk());

flood.SetDangerLevel(10);

// Блок 2: Ссылки и копии (class vs struct)
Console.WriteLine("\n=== Блок 2: Ссылки и копии ===\n");
var region1 = new Region("Altaiski krai", "22", 2100000);
var region2 = region1;
region2.SetEmergencyType(flood);
Console.WriteLine($"ReferenceEquals(region1, region2): {ReferenceEquals(region1, region2)}");
Console.WriteLine(region1.EmergencyType);

var money1 = new Money { Rubles = 150, Kopecks = 50 };
var money2 = money1;  

money2.Rubles = 300;  

Console.WriteLine($"money1.Rubles: {money1.Rubles}");
Console.WriteLine($"money2.Rubles: {money2.Rubles}");

// Блок 3: Освобождение ресурса через using    
using (var log = new IssueLog("Абонемент"))
{
    log.Write("Выдана книга 1");
    log.Write("Выдана книга 2");
}

// Блок 4: Сборщик мусора
Console.WriteLine("Создаём временный регион");
var watcher = CreateTemporaryRegion();
Console.WriteLine($"WeakReference создан. Объект жив: {watcher.TryGetTarget(out _)}");

Console.WriteLine("Запускается сборщик мусора ");
GC.Collect();
GC.WaitForPendingFinalizers();
GC.Collect(); 

Console.WriteLine($"После GC. Объект жив: {watcher.TryGetTarget(out _)}");
Console.WriteLine("Если выше есть сообщение '[GC] Регион ... уничтожен' — сборщик сработал.");
// Вспомогательный метод

[System.Runtime.CompilerServices.MethodImpl(System.Runtime.CompilerServices.MethodImplOptions.NoInlining)]
static WeakReference<Region> CreateTemporaryRegion()
{
    var temp = new Region("Временный регион", "00", 0);
    return new WeakReference<Region>(temp);
}

//  финализаторы отработают
Console.WriteLine("\nЖдём завершения финализаторов");
System.Threading.Thread.Sleep(1000); 

Console.WriteLine("\nФорсированная очистка...");
GC.Collect();
GC.WaitForPendingFinalizers();
GC.Collect();
Console.WriteLine("Очистка завершена.");

Console.WriteLine("\nНажмите любую клавишу для выхода...");
Console.ReadKey();  

