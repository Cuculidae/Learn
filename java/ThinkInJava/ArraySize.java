// Initialization & re-assignment of arrays.

class Weeble {}	// A small mythical creature

public class ArraySize {
	public static void main(String[] args) {
		// Arrays of objects
		Weeble[] a;	// null reference
		Weeble[] b = new Weeble[5]; // null references
		Weeble[] c = new Weeble[4];
		for (int i = 0; i < c.length; ++i)
			c[i] = new Weeble();
		// Aggregate initialization
		// used as initializer
		Weeble[] d = {
			new Weeble(), new Weeble(), new Weeble()
		};
		// Dynamic aggregate initialization
		// can be used anywhere
		a = new Weeble[] {
			new Weeble(), new Weeble()
		};
		System.out.println("a.length=" + a.length);
		System.out.println("b.length=" + b.length);
	}
}
