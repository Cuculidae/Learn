public class VisualCounter
{
	private final int MAX_TIMES;
	private final int MAX_ABS;
	private int count = 0;
	private int times = 0;
	public VisualCounter(int N, int max)
	{	
		MAX_TIMES = N;
	       	MAX_ABS = max; 
		StdDraw.setXscale(0, N);
		StdDraw.setYscale(-max, max);
		StdDraw.setPenColor(StdDraw.RED);
		StdDraw.setPenRadius(0.005);
	}
	public void increment()
	{
		if (times <= MAX_TIMES && count < MAX_ABS)
		{
			count++;
			times++;
		}
		(new Point2D(times, count)).draw();
	}
	public void decrement()
	{
		if (times <= MAX_TIMES && count > -MAX_ABS)
		{
			count --;
			times++;
		}
		(new Point2D(times, count)).draw();
	}
	public int tally()
	{	return count;	}
	public String toString()
	{	return count + " counts";	}
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		int max = Integer.parseInt(args[1]);
		VisualCounter c = new VisualCounter(N, max);
		for (int i = 0; i < N/2; i++)
			c.increment();
		for (int i = 0; i < N/2; i++)
			c.decrement();
		StdOut.print(c);
	}
}
			
