public class ReadIntsUseQueue
{
	public static int[] readInts(String name)
	{
		In in = new In(name);
		Queue<Integer> q = new Queue<Integer>();
		while (!in.isEmpty())
			q.enqueue(in.readInt());

		int N = q.size();
		int[] a = new int[N];
		for (int i = 0; i < N; i++)
			a[i] = q.dequeue();
		return a;
	}
	public static void main(String[] args)
	{
		int[] i = readInts(args[0]);
		for (int k = 0; k < i.length; k++)
			StdOut.println(i[k]);
	}
}

