public class OrderArrayMaxPQ<Key extends Comparable<Key>>
{
	private Key[] pq;
	private int N = 0;

	/******************************************************************
	 * helper function
	 * ****************************************************************/
	private boolean less(int i, int j)
	{	return pq[i].compareTo(pq[j]) < 0;	}
	private void exch(int i, int j)
	{	Key t = pq[i]; pq[i] = pq[j]; pq[j] = t;	}

	/*****************************************************************
	 * contracts
	 * ***************************************************************/
	public OrderArrayMaxPQ(int maxN)
	{	pq = (Key[]) new Comparable[maxN];	}
	public boolean isEmpty()
	{	return N == 0;	}
	public int size()
	{	return N;	}
	public void insert(Key v)
	{
		pq[N] = v;
		int j = N;
		while (j > 0 && less(j, j-1))
			exch(j, --j);
		N++;
	}
	public Key delMax()
	{	return pq[--N];	}
	public static void main(String[] args)
	{
		String[] a = In.readStrings();
		OrderArrayMaxPQ<String> pq = new OrderArrayMaxPQ<String>(a.length);
		for (int i = 0; i < a.length; i++)
			pq.insert(a[i]);
		while (!pq.isEmpty())
			StdOut.print(pq.delMax() + " ");
	}
}
