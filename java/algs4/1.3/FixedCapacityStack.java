public class FixedCapacityStack<Item>
{
	private Item[] a;
	private int N = 0;
	private void resize(int max)
	{
		Item temp = (Item[]) new Object[max];
		for (int i = 0; i < N; i++)
			temp[i] = a[i];
		a = temp;
	}
	public FixedCapacityStack(int cap)
	{	a = (Item[]) new Object[cap];	}
	public boolean isEmpty() { return N == 0;	}
	public int size() {	return N;	}
	public void push(Item item)
	{
		if (N == a.length) resize(2*a.length);
		a[N++] = item;
	}
	public Item pop()
	{
		String item = a[--N];
		a[N] = null;
		if (N > 0 && N == a.length/4) resize(a.length/2);
		return item;
	}
	public static void main(String[] args)
	{
		FixedCapacityStack<String> s;
		s = new FixedCapacityStack<String>(100);
		while (!StdIn.isEmpty())
		{
			String item = StdIn.readString();
			if (!item.equals("-"))
				s.push(item);
			else if (!s.isEmpty()) StdOut.print(s.pop() + " ");
		}
		StdOut.println("(" + s.size() + " left on stack)");
	}
}
