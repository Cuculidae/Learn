// Inheriting an inner class.

class WithInner {
	WithInner() { System.out.println("WithInner constructor"); }
	class Inner { 
		Inner() {
			System.out.println("WithInner.Inner constructor"); 
		}
	}
}

public class InheritInner extends WithInner.Inner {
	InheritInner(WithInner wi) {
		wi.super();
	}
	public static void main(String[] args) {
		WithInner wi = new WithInner();
		InheritInner ii = new InheritInner(wi);
	}
}
