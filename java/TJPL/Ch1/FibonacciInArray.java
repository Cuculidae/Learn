class FibonacciInArray {
	static final int MAX_INDEX = 9;
	/**
	 * compute a few Fibonacci numbers
	 * and store in an array and print
	 */
	public static void main(String[] args) {
		int lo = 1;
		int hi = 1;
		int[] fibonacci = new int[MAX_INDEX];

		fibonacci[0] = lo;
		fibonacci[1] = hi;
		for (int i = 2; i < MAX_INDEX; i++) {
			hi = lo + hi;
			lo = hi - lo;
			fibonacci[i] = hi;
		}
		
		for (int i = 0; i < fibonacci.length; i++)
			System.out.println(fibonacci[i]);
	}
}

