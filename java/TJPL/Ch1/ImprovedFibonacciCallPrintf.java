class ImprovedFibonacciCallPrintf {
	static final int SIZE = 9;

	public static void main(String[] args) {
		int lo = 1,
		    hi = 1;
		String mark;

		System.out.printf("1: 1%n");
		for (int i = 2; i <= SIZE; i++) {
			if (hi % 2 == 0)
				mark = "*";
			else
				mark = "";

			System.out.printf("%d: %d %s%n", i, hi, mark);
			hi = hi + lo;
			lo = hi - lo;
		}
	}
}
			
