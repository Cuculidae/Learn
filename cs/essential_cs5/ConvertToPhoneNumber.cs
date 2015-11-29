using System;
class ConvertToPhoneNumber
{
    static int Main(string[] args)
    {
        char button;

        if (args.Length == 0)
        {
            Console.WriteLine(
                    "ConvertToPhoneNumber.exe <phrase>");
            Console.WriteLine(
                    "'_' indicates no standard phone button");
            return 1;
        }
        foreach (string word in args)
        {
            foreach (char c in word)
            {
                if (TryGetPhoneButton(c, out button))
                {
                    Console.Write(button);
                }
                else
                {
                    Console.Write('_');
                }
            }
        }
        Console.WriteLine();
        return 0;
    }

    /* out is the same is ref except:
     *  # you cannot read the value of a out parameter, so it need not to initialized
     *  # you must assign to a out parameter
     */
    static bool TryGetPhoneButton(char c, out char button)
    {
        bool success = true;
        switch (char.ToLower(c))
        {
            case '1':
                button = '1';
                break;
            case '2': case 'a': case 'b': case 'c':
                button = '2';
                break;
            case '3': case 'd': case 'e': case 'f':
                button = '3';
                break;
            case '4':  case 'g': case 'h': case 'i':
                button = '4';
                break;
            case '5':  case 'j': case 'k': case 'l':
                button = '5';
                break;
            case '6':  case 'm': case 'n': case 'o':
                button = '6';
                break;
            case '7':  case 'p': case 'q': case 'r':
                button = '7';
                break;
            case '8':  case 's': case 't': case 'u':
                button = '8';
                break;
            case '9':  case 'v': case 'w': case 'x':
                button = '9';
                break;
            case '0':  case 'y': case 'z':
                button = '0';
                break;
            case '-':
                button = '-';
                break;
            default:
                // set the button to indicate an invalid value
                button = '_';
                success = false;
                break;
        }
        return success;
    }
}
