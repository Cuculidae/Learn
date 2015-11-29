//: generics/ExplicitTypeSpecification.java

import java.util.*;

class Person {}
class Pet {}

public class ExplicitTypeSpecification {
	static void f(Map<Person, List<Pet>> petPeople) {}
	public static void main(String[] args) {
		f(New.<Person, List<Pet>>map());
	}
}
