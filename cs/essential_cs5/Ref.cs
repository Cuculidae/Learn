// pass by reference

class Ref
{
    static void Main()
    {
        string first = "Hello";
        string second = "World";

        System.Console.WriteLine(
                @"first = ""{0}"", second = ""{1}""",
                first, second);

        // the variable passed by reference must be initialized
        // the caller must specify ref
        Swap(ref first, ref second);

        System.Console.WriteLine(
                @"first = ""{0}"", second = ""{1}""",
                first, second);
    }

    // pass by reference
    static void Swap(ref string x, ref string y)
    {
        string temp = x;
        x = y;
        y = temp;
    }
}
