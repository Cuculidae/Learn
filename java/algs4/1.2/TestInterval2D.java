public class TestInterval2D
{
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		double min = Double.parseDouble(args[1]);
		double max = Double.parseDouble(args[2]);
		StdDraw.setXscale(min, max);
		StdDraw.setYscale(min, max);
		StdDraw.setPenRadius(.005);
		StdDraw.setPenColor(StdDraw.RED);
		Interval2D[] intv = new Interval2D[N];
		for (int i = 0; i < N; i++)
		{
			intv[i] = func(min, max);
			intv[i].draw();
		}
		int intersects = 0;
		int contains = 0;
		for (int i = 0; i < intv.length; i++)
			for (int k = i+1; k < intv.length; k++)
			{
				if (intv[i].intersects(intv[k]))
					intersects++;
			}
		StdOut.println("intersects: " + intersects + " contains: " + contains);
	}
	private static Interval2D func(double min, double max)
	{
		double xlo = StdRandom.uniform(min, max);
		double xhi = StdRandom.uniform(min, max);
		double m;
		if (xhi < xlo)
		{
			m = xlo;
			xlo = xhi;
			xhi = m;
		}
		double ylo = StdRandom.uniform(min, max);
		double yhi = StdRandom.uniform(min, max);
		if (yhi < ylo)
		{
			m = ylo;
			ylo = yhi;
			yhi = m;
		}
		return new Interval2D(new Interval1D(xlo, xhi), new Interval1D(ylo, yhi));
	}
		
}


		
		



		
