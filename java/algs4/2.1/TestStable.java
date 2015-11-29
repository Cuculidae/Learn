public class TestStable
{
	public static void main(String[] args)
	{
		Queue<CityTime> q = new Queue<CityTime>();
		while (StdIn.hasNextLine())
			q.enqueue(new CityTime(StdIn.readLine()));
		CityTime[] t = new CityTime[q.size()];
		for (int i = 0; i < t.length; i++)
			t[i] = q.dequeue();
		Merge.sort(t);
		for (CityTime i : t)	StdOut.println(i);
	}
	private static class CityTime implements Comparable<CityTime>
	{
		private String city;
		private String time;
		CityTime(String s)
		{
			String[] ss = s.split(" ");
			city = ss[0];
			time = ss[1];
		}
		public int compareTo(CityTime that)
		{	return this.city.compareTo(that.city);	}
		public String toString()
		{	return city+" "+time;	}
	}
}