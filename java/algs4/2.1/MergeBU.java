/*
 * This is a program implementing merge sort in
 * a bottom up approach(none recursive)
 * based on Sedgewick's <<Algorithms>> 4ed
 * Author:	caiguochu
 * Time:	2015-01-25
 */

public class MergeBU
{
	private static Comparable[] aux;
	private static boolean less(Comparable a, Comparable b)
	{	return (a.compareTo(b) < 0);	}
	private static boolean isSorted(Comparable[] a)
	{
		for (int i = 1; i < a.length; i++)
			if (less(a[i], a[i-1]))
				return false;
		return true;
	}
	private static void merge(Comparable[] a, int lo, int mid, int hi)
	{
     	for (int k = lo; k <= hi; k++)
            aux[k] = a[k]; 
    
        // merge back to a[]
        int i = lo, j = mid+1;
        for (int k = lo; k <= hi; k++) 
            if      (i > mid)              while(k <= hi)	a[k++] = aux[j++];
            else if (j > hi)               while(k <= hi)	a[k++] = aux[i++];
            else if (less(aux[j], aux[i])) a[k] = aux[j++];
            else                           a[k] = aux[i++];
	}
	public static void sort(Comparable[] a)
	{
		int N = a.length;
		aux = new Comparable[N];

		for (int sz = 1; sz < N; sz *= 2)				// alternative implementation:
		{												// for (int sz = 1; sz < N; sz *= 2)
			int lo = 0; 								//		for (int lo = 0; lo < N - sz; lo += 2*sz)
			while (lo < N - 2*sz)						//			merge(a, lo, lo+sz-1, Math.min(a+2*sz-1, N-1));
				merge(a, lo, lo+sz-1, (lo+=2*sz)-1);	//
			if (lo < N - sz)							//
				merge(a, lo, lo+sz-1, N-1);				//
		}												//
	}
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		Double[] d = new Double[N];
		for (int i = 0; i < N; i++)
			d[i] = StdRandom.uniform();
		sort(d);
		for (int i = 0; i < N; i++)
			StdOut.printf("%.3f%s", d[i], (i%10==9)?"\n":"\t");
		StdOut.println("\n"+isSorted(d)+"\n");
	}
}