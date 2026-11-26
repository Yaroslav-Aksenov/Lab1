public class IssueLog : IDisposable
{
    private string _title;

    public IssueLog(string title)
    {
        _title = title;
        Console.WriteLine($"[+] Журнал открыт: {_title}");  
    }

    public void Write(string line) => Console.WriteLine($"  {line}");

    public void Dispose() => Console.WriteLine($"[-] Журнал закрыт: {_title}");  
}
