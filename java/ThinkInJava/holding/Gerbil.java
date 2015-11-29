// Holding your objects
// exercise 1: Gerbil.java

import java.util.ArrayList;

public class Gerbil {
	private int gerbilNumber;
	Gerbil(int i) { gerbilNumber = 1; }
	public void hop() {
		System.out.println("gerbil " + gerbilNumber + " hopping");
	}
	public static void main(String[] args) {
		ArrayList<Gerbil> gerbils = new ArrayList<Gerbil>();
		gerbils.add(new Gerbil(1));
		gerbils.add(new Gerbil(2));
		gerbils.add(new Gerbil(3));
		for (int i=0; i < gerbils.size(); ++i)
			gerbils.get(i).hop();
	}
}
