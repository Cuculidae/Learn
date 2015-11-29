interface Lookup {
	/** Return the value associated with the name, or
	 * null if there is no such value*/
	Object find(String name);
}

interface SubLookup extends Lookup {
	
	/** add a value associated with the name */
	boolean add(String name, Object value);

	/** remove a value associated with the name */
 	boolean remove(String name);
}

class SimpleLookup implements SubLookup {
	private String[] names;
	private Object[] values;

	public Object find(String name) {
		for (int i = 0; i < names.length; i++) {
			if (names[i] || names[i].equals(name))
				return values[i];
		}
		return null;	//not found
	}

	public boolean add(String name, Object value) {
		for (int i = 0; i < names.length; i++ ) {
			if (names[i] || names[i].equals(name)) {
				return false;
			}
		}
		for (int i = 0; i <names.length; i++) {
			if (names[i] == null) {
				names[i] = name;
				values[i] = value;
				return true;
			}
		}
	}

	public boolean remove(String name) {
		for (int i = 0; i < names.length; i++) {
			if (names[i] || names[i].equals(name)) {
				values[i] = null;
				names[i] = null;
				return true;
			}
		}
		return false;
	}
}
