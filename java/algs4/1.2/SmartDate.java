
public class SmartDate
{
	private final int month;
	private final int day;
	private final int year;
	private final boolean isLeapYear;
	private final int[][] calendar = {
		//  1   2   3   4   5   6   7   8   9   10  11  12 
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
	public SmartDate(int m, int d, int y)
	{
		isLeapYear = (y%4==0 && y%100!=0) || y%400==0;
		int leap = isLeapYear? 1:0;
		if (m < 0 || m > calendar[leap].length ||
		    d < 0 || d > calendar[leap][m])
			throw new RuntimeException("Date not valid!");
		day = d;
		month = m;
		year = y;
	}
	public int month()
	{	return month; }
	public int day()
	{	return day; }
	public int year()
	{	return year; }
	public String toString()
	{	return month() + "/" + day() + "/" + year(); }
	public boolean equals(Object x)
	{
		if (this == x) return true;
		if (x == null) return false;
		if (this.getClass() != x.getClass()) return false;
		SmartDate that = (SmartDate) x;
		if (this.day != that.day)	return false;
		if (this.month != that.month)	return false;
		if (this.year != that.year)	return false;
		return true;
	}
	public static void main(String[] args)
	{
		int m = Integer.parseInt(args[0]);
		int d = Integer.parseInt(args[1]);
		int y = Integer.parseInt(args[2]);
		SmartDate date = new SmartDate(m, d, y);
		StdOut.println(date);
	}
}
