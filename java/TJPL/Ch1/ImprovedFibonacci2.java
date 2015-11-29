class ImprovedFibonacci2 {
	static final int MAX_INDEX = 9;
	/**
	 * Print out a few Fibonacci numbers
	 * marking evens with a '*'
	 */
	public static void main(String[] args) {
		int lo = 1;
		int hi = 1;
		String mark = "*";

		System.out.println(MAX_INDEX + ": " + lo);
		for (int i = 2; i <= MAX_INDEX; i++) {
			if (hi % 2 == 0)
				mark = " *";
			else
				mark = "";
			System.out.println((MAX_INDEX + 1 - i) + ": " + hi + mark);
			hi = hi + lo;
			lo = hi - lo;
		}
	}
}
