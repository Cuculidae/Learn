public class SearchCompare
{
	private static double time(String alg, String L, String in)
	{
		Stopwatch timer = new Stopwatch();
		switch (alg)
		{
			case "ST"			: FrequencyCounter.main(new String[] { L, in });   break;
			case "SequentialSearchST"	: SequentialSearchST.main(new String[] { L, in }); break;
			case "BinarySearchST"		: BinarySearchST.main(new String[] { L, in });     break;
			case "BST"			: BST.main(new String[] { L, in });		   break;
			case "RedBlackBST"		: RedBlackBST.main(new String[] { L, in});	   break;
			case "SeparateChainingHashST"	: SeparateChainingHashST.main(new String[]{L, in});break;
			case "LinearProbingHashST"	: LinearProbingHashST.main(new String[]{ L, in }); break;
			default				: StdOut.println("unknow algrithm: " + alg);
							  throw new RuntimeException();
		}
		return timer.elapsedTime();
	}
	public static void main(String[] args)
	{
		String L = args[2];
		String in = args[3];
		double t1 = time(args[0], L, in);
		double t2 = time(args[1], L, in);
		StdOut.printf("%20s\t%-10s\n", "Algrithms", "Time");
		StdOut.printf("%20s\t%5.2fs\n", args[0], t1);
		StdOut.printf("%20s\t%5.2fs\n", args[1], t2);
		StdOut.printf("%20s\t%5.2f\n", "ratio", t1/t2);
	}
}
