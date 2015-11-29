import java.util.Iterator;
import java.util.NoSuchElementException;
public class ResizingArrayStack<Item> implements Iterable<Item>
{
	private Item[] a = (Item[]) new Object[1]; //stack entries
	private int N = 0;			   //number of entries
	public boolean isEmpty() {	return N == 0;	}
	public int size() {	return N;	}
	private void resize(int max)
	{
		Item[] temp = (Item[]) new Object[max];
		for (int i = 0; i < N; i++)
			temp[i] = a[i];
		a = temp;
	}
	public void push(Item item)
	{
		if (N == a.length) resize(2*a.length);
		a[N++] = item;
	}
	public Item pop()
	{
		if (isEmpty()) throw new NoSuchElementException();
		Item item = a[--N];
		a[N] = null;	//避免对象游离
		if (N > 0 && N == a.length/4) resize(a.length/2);
		return item;
	}
	public String toString()
	{
		StringBuilder s = new StringBuilder();
		for (Item item : this)
			s.append(s + " ");
		return s.toString();
	}
	public Iterator<Item> iterator()
	{	return new ReverseArrayIterator();	}
	private class ReverseArrayIterator implements Iterator<Item>
	{	//支持后进先出的迭代
		private int i = N;
		public boolean hasNext() { 	return i > 0;	}
		public Item next() {	return a[--i];	}
		public void remove() {	throw new UnsupportedOperationException();	}
	}
	public static void main(String[] args)
	{
		ResizingArrayStack<String> s = new ResizingArrayStack<String>();
		while (!StdIn.isEmpty())
		{
			String item = StdIn.readString();
			if (!item.equals("-"))
				s.push(item);
			else if (!s.isEmpty()) StdOut.print(s.pop() + " ");
		}
		StdOut.println("(" + s.size() + " items left on stack)");
	}
}

