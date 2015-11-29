using System;
using System.IO;

class PathEx
{
    static void Main()
    {
        string fullName;

        // call Combine() with four parameters
        fullName = Combine(
                Directory.GetCurrentDirectory(),
                "bin", "config", "index.html");
        Console.WriteLine(fullName);

        // call Combine() with three  arguments
        fullName = Combine(
                Environment.SystemDirectory,
                "Temp", "index.html");
        Console.WriteLine(fullName);

        // call Combine() with an array
        fullName = Combine(
                new string[] {
                "C:\\", "Data",
                "HomeDir", "index.html"});
        Console.WriteLine(fullName);
    }

    /* Parameter array must be the last parameter in a function prototype.
     */
    static string Combine(params string[] paths)
    {
        string result = string.Empty;
        foreach (string path in paths)
        {
            result = System.IO.Path.Combine(result, path);
        }
        return result;
    }
}
                
