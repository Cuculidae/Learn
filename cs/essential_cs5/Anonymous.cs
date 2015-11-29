/*
 * C# 3.0 includes a contextual keyword, var, for declaring an implicitly typed
 * local variable. As long as the code initializes a variable at declaration
 * time with an unambiguous type, C# 3.0 allows for the variable data type to be
 * implied.
 * var was added to the language to support anonymous types.
 */

class Anonymous
{
    static void Main()
    {
        var patent1 = 
            new {   Title = "Bifocals",
                    YearOfPublication = "1784"};
        var patent2 = 
            new {   Title = "Phonograph",
                    YearOfPublication = "1877"};

        System.Console.WriteLine("{0} ({1})",
                patent1.Title, patent1.YearOfPublication);
        System.Console.WriteLine("{0} ({1})",
                patent2.Title, patent2.YearOfPublication);

    }
}
