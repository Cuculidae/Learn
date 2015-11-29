public class Detergent extends Cleanser {
	// change method:
	public void scrub() {
		append(" Detergent scrub");
		super.scrub();
	}

	// add methods to the interface:
	public void foam() { append(" foam"); }
	public static void main(String[] args) {
		Detergent x = new Detergent();
		x.dilute();
		x.apply();
		x.scrub();
		x.foam();
		x.print();
		System.out.println("Testing base class;");
		Cleanser.main(args);
	}
}
