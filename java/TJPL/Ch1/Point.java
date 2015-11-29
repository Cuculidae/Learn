class Point {
	public double x, y;
	public static Point origin = new Point(); //���������ֶ���˵����������г�ʼ����Ĭ��ֵ����0

	public void clear() {
		x = 0.0;
		y = 0.0;
	}

	public void move(double x, double y) {
		this.x = x;	//this �ǵ�ǰ�����ܣ����������
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
