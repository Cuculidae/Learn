public class Rational
{
	private final int numerator;
	private final int denominator;
	private int gcd(int p, int q)
	{
		if (q == 0) return p;
		int r = p % q;
		return gcd(q, r);
	}
	public Rational(int numerator, int denominator)
	{
		this.numerator = numerator / gcd (numerator, denominator);
		this.denominator = denominator / gcd(numerator, denominator);
	}
	public Rational plus(Rational b)
	{
		int n = numerator * b.denominator + denominator * b.numerator;
		int m = numerator * denominator;
		return new Rational(n, m);
	}
	public Rational minus(Rational b)
	{
		int n = numerator * b.denominator - denominator * b.numerator;
		int m = numerator * denominator;
		return new Rational(n, m);
	}
	public Rational times(Rational b)
	{
		int n = numerator * b.numerator;
		int m = denominator * b.denominator;
		return new Rational(n, m);
	}
	public Rational divides(Rational b)
	{
		int n = numerator * b.denominator;
		int m = denominator * b.numerator;
		return new Rational(n, m);
	}
	public boolean equals(Rational that)
	{
		return numerator == that.numerator && denominator == that.denominator;
	}
	public String toString()
	{
		return numerator + "/" + denominator;
	}
	public static void main(String[] args)
	{
		Rational a = new Rational(2,4);
		Rational b = new Rational(2,3);
		Rational c = a.divides(b);
		StdOut.println(a);
		StdOut.println(b);
		StdOut.println(c);
	}
}

