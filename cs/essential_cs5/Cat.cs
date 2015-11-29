class Cat
{
    static void Main()
    {
        int i;
        char c;
        // System.Console.Read read a char at a time,
        // returns -1 at the end
        while ((i = System.Console.Read()) != -1)
        {
            c = (char) i;
            System.Console.Write(c);
        }
    }
}
