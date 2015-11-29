public class Dedup
{
	public static String[] dedup(String[] a)
	{
		Queue<String> q = new Queue<String>();
		Quick.sort(a);
		final int N = a.length;
		int cnt;
		for (int i = 0; i < N; i += cnt)
		{
			cnt = 0;
			q.enqueue(a[i]);
			for (int j = i; j < N && a[i].compareTo(a[j]) == 0; cnt++, j++);
		}
		String[] b = new String[q.size()];
		int i = 0;
		while (!q.isEmpty())
			b[i++] = q.dequeue();
		return b;
	}
	public static void main(String[] args)
	{
		String[] a = In.readStrings();
		String[] b = dedup(a);
		for (String s: b)
			StdOut.print(s + " ");
	}
}
