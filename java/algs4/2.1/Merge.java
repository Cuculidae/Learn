/*
 * This ia program implementing merge sort
 * in a recuisive approach
 * based on Sedgewick' <<Algorithms>> 4ed
 * Author:	caiguochu
 * Time:	2015-01-26
 */

public class Merge
{
	private static Comparable[] aux;
	public static boolean less(Comparable v, Comparable w)
	{	return v.compareTo(w) < 0;	}	
	public static boolean isSorted(Comparable[] a)
	{
		final int N = a.length;
		for (int i = 1; i < N; i++)
			if (less(a[i], a[i-1])) return false;
		return true;
	}
	public static void sort(Comparable[] a)
	{
		aux = new Comparable[a.length];
		sort(a, 0, a.length -1);
	}
	private static void sort(Comparable[] a, int lo, int hi)
	{
		if (hi <= lo) return;
		int mid = lo + (hi - lo)/2;
		sort(a, lo, mid);
		sort(a, mid+1, hi);
		merge(a, lo, mid, hi);
	}
	public static void merge(Comparable[] a, int lo, int mid, int hi)
	{
		int i = lo, j = mid + 1;
		for (int k = lo; k <= hi; k++)
			aux[k] = a[k];
		for (int k = lo; k <= hi; k++)
			if		(i > mid)				while(k <= hi) a[k++] = aux[j++];
			else if (j > hi)				while(k <= hi) a[k++] = aux[i++];
			else if (less(aux[j], aux[i]))	a[k] = aux[j++];
			else 							a[k] = aux[i++];
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
