// the protected keyword

class Art {
	protected void printArt() {
		System.out.println("Art");
	}
}

class Drawing extends Art {
	protected void printDrawing() {
		printArt();
		System.out.println("Drawing");
	}
}

public class Cartoon extends Drawing {
	public void printCartoon() {
		printArt();
		printDrawing();
		System.out.println("Cartoon");
	}
	public static void main(String[] args) {
		Cartoon c = new Cartoon();
		c.printCartoon();
	}
}
