public class TestPoint2D
{
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		StdDraw.setXscale(0, 1.0);
		StdDraw.setYscale(0, 1.0);
		StdDraw.setPenRadius(.005);
		Point2D[] p = new Point2D[N];
		for (int i = 0; i < N; i++)
		{
			p[i] = new Point2D(Math.random(), Math.random());
			p[i].draw();
		}
		double[] dist = new double[N - 1];
		for (int i = 0; i < dist.length; i++)
		{
			double min = 1;
			double d = 1;
			for (int k = i+1; k < N; k++)
			{
				if ((d = p[i].distanceTo(p[k])) < min)
					min = d;
			}
			dist[i] = d;
		}
		double m = 1;
		for (int i = 0; i < dist.length; i++)
			if (m > dist[i])
				m = dist[i];
		StdOut.println("minimal distance: " + m);

	}
}
