class Body {
	private long idNum;
	private String name = "<unnamed>";
	private Body orbits = null;

	public static long nextID = 0;

	Body() {
		idNum = nextID++;
	}
	
	Body(String bodyname, Body orbitsAround) {
		this();	/*explicit constructor invocation,
	       	         *must be the first statement in the constructor */
		name = bodyname;
		orbits = orbitsAround;
	}

	Body(String bodyName) {
		this(bodyName, null);
	}
	
	//copy constructor
	Body(Body other) {
		idNum = other.idNum;
		name = other.name;
		orbits = other.orbits;
	}

	//accessors
	public long getID() { return idNum; }
	public String getName() { return name; }
	public void setName(String newName) {
		name = newName;
	}
	public Body getOrbits() { return orbits; }
	public void setOrbits(Body orbitsAround) {
		orbits = orbitsAround;
	}
	
	public boolean orbitsAround(Body other) {
		return (orbits == other);
	}

	public boolean orbitsAround(long id) {
		return (orbits != null && orbits.idNum == id);
	}

	public String toString() {
		String desc = idNum + " (" + name + ")";
		if (orbits != null)
			desc += " orbits " + orbits.toString();
		return desc;
	}

	public static void main(String[] args) {
		Body sun = new Body("sun");
		Body earth = new Body("earth", sun);
		if (earth.orbitsAround(sun))
		System.out.println(earth);
	}

}
