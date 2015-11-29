import java.util.Iterator;
import java.util.NoSuchElementException;
public class RingQueue<Item> implements Iterable<Item>
{
	private Node last;
	private int N;
	private class Node
	{
		Item item;
		Node next;
	}
	public boolean isEmpty() { return  last == null;	}
	public int size() { 	return N;	}
	public void enqueue(Item item)
	{
		Node oldlast = last;
		last = new Node();
		last.item = item;
		if (oldlast == null)
			last.next = last;
		else
	       	{	
			last.next = oldlast.next; 
			oldlast.next = last;
		}
		N++;
	}
	public Item dequeue()
	{
		if (isEmpty())
			return null;
		Item item = last.next.item;
		if (last.next == last)	last = null;
		else			last.next = last.next.next;
		N--;
		return item;
	}
	public Iterator<Item> iterator()
	{	return new RingIterator();	}
	private class RingIterator implements Iterator<Item>
	{
		private Node current = last;
		public boolean hasNext()
		{	return current != null;	}
		public Item next()
		{
			if (!hasNext()) throw new NoSuchElementException();
			current = current.next;
			Item item = current.item;
			if (current == last)
				current = null;
			return item;
		}
		public void remove() {	throw new UnsupportedOperationException();	}
	}
	public String toString()
	{
		StringBuilder s = new StringBuilder();
		for (Item item : this)
			s.append(item + " ");
		return s.toString();
	}
	public static void main(String[] args)
	{
		String s;
		RingQueue<String> q = new RingQueue<String>();
		while (!StdIn.isEmpty())
		{
			s = StdIn.readString();
			q.enqueue(s);
		}
		for (String str : q)
			StdOut.println(str);
		StdOut.println(q);
	}
}
