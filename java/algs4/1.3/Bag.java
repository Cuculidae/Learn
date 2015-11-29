import java.util.Iterator;
public class Bag<Item> implements Iterable<Item>
{
	private Node first;
	private class Node
	{
		Item item;
		Node next;
	}
	public void add(Item item)
	{
		Node oldfirst = first;
		first = new Node();
		first.item = item;
		first.next = oldfirst;
	}
	public String toString()
	{
		StringBuilder s = new StringBuilder();
		for (Item item: this)
			s.append(item + " ");
		return s.toString();
	}
	public Iterator<Item> iterator()
	{	return new ListIterator();	}
	private class ListIterator implements Iterator<Item>
	{
		private Node current = first;
		public boolean hasNext()
		{	return current != null;	}
		public Item next()
		{
			Item item = current.item;
			current = current.next;
			return item;
		}
		public void remove() {	}
	}
	public static void main(String[] args)
	{
		Bag<String> b = new Bag<String>();
		while (!StdIn.isEmpty())
			b.add(StdIn.readString());
		for (String s : b)
			StdOut.println(s);
	}
}
