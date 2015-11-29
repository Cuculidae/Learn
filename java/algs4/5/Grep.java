/*
 *
 *
 * Execution:       
 * Dependencies:    
 * Data File:       
 * Author:          caiguochu
 * Time:            2015-08-01
 */
public class Grep
{
    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        String regexp = "(.*" + args[0] + ".*)";
        NFA nfa = new NFA(regexp);
        while (StdIn.hasNextLine())
        {
            String txt = StdIn.readLine();
            if (nfa.recognizes(txt))
                StdOut.println(txt);
        }
    }
}