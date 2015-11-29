/*
 *
 *
 * Execution:       
 * Dependencies:    
 * Data File:       
 * Author:          caiguochu
 * Time:            2015-
 */
public class SubstrCMP
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static String[] algs = {
        "BruteForce",
        "KMP",
        "BoyerMoore",
        "BM",
        "RabinKarp",
        "Bitap",
    };


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    private static double time(int alg, String pat, String txt)
    {
        StopWatch timer = new StopWatch();
        switch (alg) {
            case 0: BruteForce.search(pat, txt);
                    break;
            case 1: KMP kmp = new KMP(pat);
                    kmp.search(txt);
                    break;
            case 2: BoyerMoore bm = new BoyerMoore(pat);
                    bm.search(txt);
                    break;
            case 3: BM bm2 = new BM(pat);
                    bm2.search(txt);
                    break;
            case 4: RabinKarp rk = new RabinKarp(pat);
                    rk.search(txt);
                    break;
            case 5: Bitap bit = new Bitap(pat);
                    bit.search(txt);
                    break;
            default:
                    break;
        }
        return timer.elapsedTime();
    }

    private static void test(String pat, String txt)
    {
        for (int i = 0; i < algs.length; ++i)
        {
            double t = time(i, pat, txt);
            StdOut.printf(" |%15s|%15.5f|\n", algs[i], t);
        }
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/


    /*********************************************************************************************
     *                                       Iterator                                            *
     *********************************************************************************************/
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        String pat = StdIn.readString();
        String txt = StdIn.readString();
        test(pat, txt);
    }
}