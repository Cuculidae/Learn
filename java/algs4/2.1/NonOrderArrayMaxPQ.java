public class NonOrderArrayMaxPQ<Key extends Comparable<Key>>
{
	private Key[] pq;
	private int N = 0;
	
	/******************************************************
	 * helper function
	 * ****************************************************/
	private boolean less(int i, int j)
	{	return pq[i].compareTo(pq[j]) < 0;	}
	private void exch(int i, int j)
	{	Key t = pq[i]; pq[i] = pq[j]; pq[j] = t;	}

	/******************************************************
	 * contracts
	 * ****************************************************/
	public NonOrderArrayMaxPQ(int maxN)
	{	pq = (Key[]) new Comparable[maxN];	}
	public int size()
	{	return N;	}
	public boolean isEmpty()
	{	return N == 0;	}
	public void insert(Key v)
	{	pq[N++] = v;	}
	public Key delMax()
	{
		if (N == 0) return null;
		int max = 0;
		for (int i = 1; i < N; i++)
			if (less(max,i))
				max = i;
		exch(max, N-1);
		return pq[--N];
	}
	public static void main(String[] args)
	{
		String[] a = In.readStrings();
		NonOrderArrayMaxPQ<String> pq = new NonOrderArrayMaxPQ<String>(a.length);
		for (int i = 0; i < a.length; i++)
			pq.insert(a[i]);
		while (!pq.isEmpty())
			StdOut.print(pq.delMax() + " ");
	}
}

