class Shape {
	void draw() {}
	void erase() {}
}

class Circle extends Shape {
	void draw() {
	  System.out.println("Circle.draw()");
	}
	void erase() {
	  System.out.println("Circle.erase()");
	}
}

class Square extends Shape {
	void draw() {
	  System.out.println("Square.draw()");
	}
	void erase() {
	  System.out.println("Square.erase()");
	}
}

class Triangle extends Shape {
	void draw() {
	  System.out.println("Triangle.draw()");
	}
	void erase() {
	  System.out.println("Triangle.erase()");
	}
}

public class Shapes {
	public static Shape randShape() {
	  switch ((int) (Math.random() * 3)) {
	    default :
	    case 0: return new Circle();
	    case 1: return new Square();
	    case 2: return new Triangle();
	  }
	}
	public static void main(String[] args) {
	  Shape[] s = new Shape[9];
	  for (int i = 0; i < s.length; ++i)
	    s[i] = randShape();
	  for (int i = 0; i < s.length; ++i)
	    s[i].draw();
	}
}
