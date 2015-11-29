/*
 * C# allows any file extension name for the source files, but it usually will
 * be ".cs".
 *
 * In java, source filename must be the same as the class name. Although C#
 * usually follows this, however, it is not necessary.
 *
 * The return type of Main is either void or int, and it takes no parameters or
 * takes a parameter of type string[].
 */

// The using directive imports all types from the specified namespace into the
// entire file. Nested namespaces, identified by the period in the namespace,
// need to be imported explicitly.
using System;

class HelloWorld
{
    static void Main()
    {
        System.Console.WriteLine("Hello, My name is Inigo Montoya.");
    }
}
