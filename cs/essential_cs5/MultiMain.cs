/*
 * If a program includes two classes with Main() methods, it is possible to
 * specify on the command line which class to use for the Main() declaration.
 * csc.exe includes an /m option to specify the fully qualified class name of
 * Main().
 */

// Compilation: csc MultiMain.cs /m:OneClass
//              csc MultiMain.cs /m:AnotherClass
using System;
class OneClass
{
    static void Main()
    {
        Console.WriteLine("Main() in OneClass");
    }
}

class AnotherClass
{
    static void Main()
    {
        Console.WriteLine("Main() in AnotherClass");
    }
}
