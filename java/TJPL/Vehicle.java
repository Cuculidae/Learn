class Vehicle {
	private double speed;
	private double direction;
	private String owner;

	private static final boolean TURN_LEFT = true;
	private static final boolean TURN_RIGHT = true;
	private static long nextID = 0;
	private long idNum;
	
	Vehicle()  {
		idNum = nextID++;
	}

	Vehicle(String owner) {
		this();
		this.owner = owner;
	}

	//accessors
	public double getSpeed() { return speed; }
	public void setSpeed(double newSpeed) {
		speed = newSpeed;
	}
	public double getDirection() { return direction; }
	public void setDirection(double newDirection) {
		direction = newDirection;
	}
	public String getOwner() { return owner; }
	public void setOwner(String newOwner) {
		owner = newOnwer;
	}
	public long getID() { return idNum; }

	public void stop() { 
		setSpeed(0);
	}

	public void turn(double newDirction) {
		direction = newDirection;
	}
	public void turn(boolean direction) {
		if (TURN_RIGHT)
			setDirection(0);
		else if (TURN_LEFT)
			setDirection(180);
	}

	//return max idNum at the moment
	public static long getMaxID() {
		return nextID - 1;
	}

	public String toString() {
		return owner + "\'s vehicle";
	}

	public static void main(String[] args) {
		Vehicle v = new Vehicle("caiguochu");
		System.out.println(v);
	}
}

