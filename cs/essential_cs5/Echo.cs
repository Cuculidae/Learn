/*
 * Class, method, and field names in Pascal style, 
 * local variables in camel styel.
 */
class Echo
{
    // array args doesn't contain the program name
    static void Main(string[] args)
    {
        // The commandline to call this program
        System.Console.WriteLine(System.Environment.CommandLine);
        foreach (string s in args)
            System.Console.WriteLine(s);
    }
}
