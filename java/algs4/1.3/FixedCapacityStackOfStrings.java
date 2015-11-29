public class FixedCapacityStackOfStrings
{
	private String[] a; // stack entries
	private int N = 0;
	public FixedCapacityStackOfStrings(int cap)
	{	a = new String[cap];	}
	public boolean isEmpty()
	{	return N == 0;	}
	public boolean isFull()
	{	return N == a.length;	}
	public int size()  { return N;	}
	public void push(String item)
	{	a[N++] = item;	}
	public String pop()
	{	return a[--N];	}
	public static void main(String[] args)
	{
		FixedCapacityStackOfStrings s;
		s = new FixedCapacityStackOfStrings(100);
		while (!StdIn.isEmpty())
		{
			String item = StdIn.readString();
			if (!item.equals("-"))
				s.push(item);
			else if (!s.isEmpty()) StdOut.print(s.pop() + " ");
		}
		StdOut.print("(" + s.size() + " left on stack)");
	}
}
