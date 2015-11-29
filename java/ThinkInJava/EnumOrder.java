public class EnumOrder {
	public static void main(String[] args) {
		// static method values() produces an array of values of the enum constants
		// in the order that they were declared
		for (Spiciness s : Spiciness.values())
			// ordinal() returns the declaration order of a particular enum constant
			System.out.println(s + ", ordinal " + s.ordinal());
	}
}
