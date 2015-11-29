class LinkedList {
	private Object objRef;
	private LinkedList next;
	
	LinkedList(LinkedList next) {
		this.next  = next;
	}

	public String toString() {
	}

	public static void main(String[] args) {
		Vehicle v1 = new Vehicle();
		Vehicle v2 = new Vehicle();

		LinkedList n1 = new LinkedList();
		n1.f = v1;
		LinkedList n2 = new LinkedList();
		n1.next = n2;
		n2.f = v2;
		System.out.println(n1);
	}
}
