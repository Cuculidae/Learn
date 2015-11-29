/*
 * In C#, you can use the @ symbol in front of a literal string to signify that 
 * a backslash should not be interpreted as the beginning of an escape sequence.
 * Whitespace is also taken in the resulted verbatim string literal.
 * The only escape sequence the verbatim string does support is "", which
 * signifies double quotes and does not terminate the string.
 *
 * Unlike C++, C# does not automatically concatenate literal strings.
 */

class Triangle
{
    static void Main()
    {
        System.Console.Write(@"begin
                /\
               /  \
              /    \
             /      \
            /________\
end");
    }
}
