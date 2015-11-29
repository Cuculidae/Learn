// Implementing a Comparator for a class.

import java.util.Comparator;
import java.util.Arrays;

class CompTypeComparator implements Comparator {
	public int compare(Object o1, Object o2) {
		int j1 = ((CompType) o1).j;
		int j2 = ((CompType) o2).j;
		return (j1 < j2 ? -1 : (j1 == j2 ? 0 : 1));
	}
}

public class ComparatorTest {
	public static void main(String[] args) {
		CompType[] a = new CompType[10];
		CompType.fill(a);
		System.out.println("before sort:");
		CompType.print(a);
		Arrays.sort(a, new CompTypeComparator());
		System.out.println("after sort:");
		CompType.print(a);
	}
}
