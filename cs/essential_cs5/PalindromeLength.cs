class PalindromeLength
{
    /* To determine the length of a string you use a string member called
     * Length. This particular member is called a read-only property.
     */
    static void Main()
    {
        string palindrome;

        System.Console.Write("Enter a palindrome: ");
        palindrome = System.Console.ReadLine();

        System.Console.WriteLine(
                "The palindrome, \"{0}\" is {1} characters.",
                palindrome, palindrome.Length);
    }
}
