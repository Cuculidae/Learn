// Using System.arraycopy()

import java.util.Arrays;

public class CopyingArrays {
	public static void main(String[] args) {
		int[] i = new int[25];
		int[] j = new int[25];
		Arrays.fill(i, 47);
		Arrays.fill(j, 99);
		System.arraycopy(i, 0, j, 0, i.length);
		System.out.print("i[]: ");
		for (int k = 0; k < i.length; ++k)
			System.out.print(i[k] + " ");
		System.out.println();
		System.out.println("j[]: ");
		for (int k = 0; k < j.length; ++k)
			System.out.print(j[k] + " ");
		System.out.println();
	}
}
