class MiracleMax
{
    static void Main()
    {
        // local variables in camel style
        string valerie;
        string max = "Have fun storming the castle!";

        // variables must be initialized or assigned before their first use
        valerie = "Think it will work?";

        System.Console.WriteLine(max);
        System.Console.WriteLine(valerie);

        // assignment return the value
        // string is immutable
        max = "It would take a miracle.";
        System.Console.WriteLine(max);
    }
}
