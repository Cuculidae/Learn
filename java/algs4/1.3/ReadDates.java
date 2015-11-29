public class ReadDates
{
	public static Date[] readDates()
	{
		Queue<Date> q = new Queue<Date>();
		while (!StdIn.isEmpty())
		{
			String s = StdIn.readString();
			q.enqueue(new Date(s));
		}
		Date[] date = new Date[q.size()];
		for (int i = 0; i < date.length; i++)
			date[i] = q.dequeue();
		return date;
	}
	public static void main(String[] args)
	{
		Date[] date = readDates();
		for (Date d : date)
			StdOut.println(d);
	}
}
