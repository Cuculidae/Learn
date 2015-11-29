class ImprovedFibonacciStringVersion {
	static final int SIZE = 9;

	public static void main(String[] args) {
		int lo = 1,
		    hi = 1;
		String mark;
		String[] strarr = new String[SIZE];

		strarr[0] = "1: 1";
		for (int i = 1; i < SIZE; i++) {
			if (hi % 2 == 0)
				mark = " *";
			else 
				mark = "";
			strarr[i] =  (i + 1) + ": " + hi + mark;
			hi = hi + lo;
			lo = hi - lo;
		}
		for (int i = 0; i < SIZE; i++)
			System.out.println(strarr[i]);
	}
}
