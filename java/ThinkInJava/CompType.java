// Implementing Comparable in a class.

import java.util.Arrays;
import java.util.Random;

public class CompType implements Comparable {
	int i;
	int j;
	public CompType(int n1, int n2) {
		i = n1;
		j = n2;
	}
	public String toString() {
		return "[i = " + i + ", j = " + j + "]";
	}
	public int compareTo(Object rv) {
		int rvi = ((CompType) rv).i;
		return (i < rvi ? -1 : (i == rvi ? 0 : 1));
	}
	private static Random r = new Random();
	private static int randInt() {
		return Math.abs(r.nextInt()) % 100;
	}
	public static void fill(CompType[] a) {
		for (int i = 0; i < a.length; ++i)
			a[i] = new CompType(randInt(), randInt());
	}
	public static void print(CompType[] a) {
		for (int i = 0; i < a.length; ++i)
			System.out.println(a[i]);
	}
	public static void main(String[] args) {
		CompType[] a = new CompType[10];
		fill(a);
		System.out.println("Before sort:");
		print(a);
		Arrays.sort(a);
		System.out.println("After sort:");
		print(a);
	}
}
