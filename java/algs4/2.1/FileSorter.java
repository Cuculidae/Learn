/*
 * Prints out all of the files in the given directory in
 * sorted order.
 *
 * Execution:		java FileSorter DIRECTORY
 * Dependencies:	StdOut.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-02-19
 */

import java.io.File;
import java.util.Arrays;

public class FileSorter
{
	public static void main(String[] args)
	{
		File dir = new File(args[0]);
		File[] files = dir.listFiles();
		Arrays.sort(files);
		for (int i = 0; i < files.length; i++)
			StdOut.println(files[i].getName());
	}
}
