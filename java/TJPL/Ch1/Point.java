class Point {
	public double x, y;
	public static Point origin = new Point(); //对于数字字段来说，如果不进行初始化，默认值就是0

	public void clear() {
		x = 0.0;
		y = 0.0;
	}

	public void move(double x, double y) {
		this.x = x;	//this 是当前（接受）对象的引用
		this.y = y;
	}

	public void set(Point that) {
		this.x = that.x;
		this.y = that.y;
	}
	
	public double distance(Point that) {
		double xdiff = x - that.x;
		double ydiff = y - that.y;
		return Math.sqrt(xiff * xdiff + ydiff * ydiff);
	}
}
