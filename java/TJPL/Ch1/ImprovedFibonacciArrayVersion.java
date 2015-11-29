class ImprovedFibonacciArrayVersion {

	static final int SIZE = 9;
	private static Fib[] fib = new Fib[SIZE];
	public static void main(String[] args) {
		int lo = 1,
		    hi = 1;
		String mark;
		
		for (int i = 0; i < fib.length; i++)
			fib[i] = new Fib();

		fib[0].value = 1;
		fib[0].mark = "";
		fib[1].value = 1;
		fib[1].mark = "";
		for (int i = 2; i < fib.length; i++) {
			hi = hi + lo;
			lo = hi - lo;
			fib[i].value = hi;
			if (hi % 2 == 0)
				fib[i].mark = " *";
			else 
				fib[i].mark = "";
		}

		
		for (int i = 0; i < fib.length; i++) 
			System.out.println((i+1) + ": " + fib[i].value + fib[i].mark);
	
	}
}

class Fib{
		public int value;
		public String mark;
	
	}
