public class StaticInit
{
	static Cup cup1 = new Cup(1);
	static Cup cup2;
	static Cup cup3;
	static {
		cup1 = new Cup(4);
		cup2 = new Cup(2);
		cup3 = new Cup(3);
	}
	public static void main(String[] args)
	{}
}
