/* 
 * Sort N random real numbers, T times using the two
 * algorithms specified on the command line.
 *
 * Execution:		java SortCompare [alg1, alg2...]  N  T
 * Dependencies:	Selection.java, Insertion.java, Shell.java, Merge.java, Quick.java, Heap.java
 *					MergeX.java, Quick3way.java, MergeBU.java, QuickX.java, StdOut.java, QuickKR.java
 *					QuickDualPivot.java, Shell2.java, Quick3wayFast.java,
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-01-22
 */

public class SortCompare
{
	/*
	 * The sort algorithms support in this program
	 * more algorithms can be added to 'algorithms'
	 * to enhance this program
	 */
	private static String[] algorithms = {
		"", // so the code of alogrithm starts from 1
		"Selection",
		"Insertion",
		"InsertionX",		//2015-02-19
		"InsertionXB",		//2015-02-19
		"Shell",
		"Shell2",			// 2015-09-05
		"Merge",
		"MergeX",			//2015-01-23
		"MergeBU",			//2015-01-26
		"Quick",
		"Quick3way",		//2015-01-25
		"Quick3wayFast",	//2015-09-06
		"QuickX",			//2015-02-04
		"QuickKR",			//2015-02-04
		"QuickDualPivot",	//2015-02-05
		"Heap",
	};

	/*
	 * Show how to use this program
	 */
	private static void showUsage()
	{
		StdOut.println(" *** *******************************************************************\n" +
			" *** This is program SortCompare, I compare the speed of different sort algorithms.\n" +
			" *** Usage: java SortCompare [algorithm_1[, algorithm_2...]] SIZE N\n" +
			" ***\tsort N array of size SIZE, using algorithm_1, algorithm_2...\n" +
			" ***\there, algorithm_1... are positive integers representing different algorithms:");
		for (int i = 1; i < algorithms.length; i++)
			StdOut.println("\t" + i + " : " + algorithms[i]);
	}

	/*
	 * Return the time using 'algorithm' to sort 'a',
	 * whitch must implements the Comparable interface
	 */
	private static double time(int algorithm, Comparable[] a)
	{
		StopWatch timer = new StopWatch();
		switch (algorithm)
		{
			case  1: Selection.sort(a);		break;
			case  2: Insertion.sort(a);		break;
			case  3: InsertionX.sort(a);	break;
			case  4: InsertionXB.sort(a);	break;
			case  5: Shell.sort(a);			break;
			case  6: Shell2.sort(a);		break;
			case  7: Merge.sort(a);			break;
			case  8: MergeX.sort(a);		break;
			case  9: MergeBU.sort(a);		break;
			case 10: Quick.sort(a);			break;
			case 11: Quick3way.sort(a);		break;
			case 12: Quick3wayFast.sort(a);	break;
			case 13: QuickX.sort(a);		break;
			case 14: QuickKR.sort(a);		break;
			case 15: QuickDualPivot.sort(a);break;
			case 16: Heap.sort(a);			break;
		}
		return timer.elapsedTime();
	}

	/*
	 * Generates a Double random array of size SIZE, compute the time
	 * sorting this array, repeat N times, accumulate the time 
	 * return the total time costs
	 */
	private static double timeOfRandomIput(int algorithm, int SIZE, int N)
	{
		double total = 0.0;
		Double[] a = new Double [SIZE];
		for (int n = 0; n < N; n++)
		{
			for (int i = 0; i < SIZE; i++)
				a[i] = StdRandom.uniform();
			total += time(algorithm, a);
		}
		return total;
	}

	/*
	 * Draw a readable table 
	 */
	public static void main(String[] args)
	{
		int nalg = args.length - 2;
		if (nalg < 1)	// check if the usage is correct
		{
			showUsage();
			return;
		}else{
			for (int i = 0, j; i < nalg; i++)
				if ((j=Integer.parseInt(args[i])) < 1 || j >= algorithms.length)
				{
					showUsage();
					return;
				}
		}
		int size = Integer.parseInt(args[nalg]);// size of test array
		int N = Integer.parseInt(args[nalg+1]); // number of test array
		double[] times = new double[nalg]; 		// stores the time of every algorithm
		StdOut.println("********************|***************|********************|");
		StdOut.printf("%20s|%15s|%20s|\n","Algorithms", "AverageTime", "Ratio(t[i]/t[0])");
		StdOut.println("********************|***************|********************|");
		for (int i = 0, alg; i < nalg; i++)
		{
			alg = Integer.parseInt(args[i]);
			times[i] = timeOfRandomIput(alg, size, N);
			StdOut.printf("%20s|%15.3f|%20.3f|\n", algorithms[alg], times[i]/N, i==0?1:times[i]/times[0]);
			StdOut.println("********************|***************|********************|");
		}
	}
}