import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.ConcurrentModificationException;
public class Steque<Item> implements Iterable<Item>
{
	private Node first;
	private Node last;
	private int N;
	private Counter pushCounter = new Counter("pushCounter");
	private Counter popCounter = new Counter("popCounter");
	private Counter enqueueCounter = new Counter("enqueueCounter");
	private class Node
	{
		Item item;
		Node next;
	}
	public boolean isEmpty()
	{	return first == null;	}
	public int size()
	{	return N;	}
	public void push(Item item)
	{
		pushCounter.increment();
		Node oldfirst = first;
		first = new Node();
		first.item = item;
		first.next = oldfirst;
		if (oldfirst == null)	last = first;
		N++;
	}
	public Item pop()
	{
		popCounter.increment();
		if (isEmpty())	throw new NoSuchElementException();
		Item item = first.item;
		first = first.next;
		if (isEmpty())	last = null;
		N--;
		return item;
	}
	public void enqueue(Item item)
	{
		enqueueCounter.increment();
		Node oldlast = last;
		last = new Node();
		last.item = item;
		last.next = null;
		if (isEmpty())	first = last;
		else		oldlast.next = last;
		N++;
	}
	public String toString()
	{
		StringBuilder s = new StringBuilder();
		for (Item item : this)
			s.append(s + " ");
		return s.toString();
	}
	public Iterator<Item> iterator()
	{	return new StequeIterator();	}
	private class StequeIterator implements Iterator<Item>
	{
		private Node current = first;
		private final int push = pushCounter.tally();
		private final int pop = popCounter.tally();
		private final int enqueue = enqueueCounter.tally();
		public boolean hasNext()
		{	return current != null;	}
		public void remove()
		{	throw new UnsupportedOperationException();	}
		public Item next()
		{
			if (push != pushCounter.tally() || 
			    pop != popCounter.tally()	||
			    enqueue != enqueueCounter.tally())
				throw new ConcurrentModificationException();
			if (!hasNext())	throw new NoSuchElementException();
			Item item = current.item;
			current = current.next;
			return item;
		}
	}
	public static void main(String[] args)
	{
		Steque<String> steq = new Steque<String>();
		for (int i = 0; !StdIn.isEmpty(); i++)
		{
			String s = StdIn.readString();
			if (i % 2 == 0)
				steq.push(s);
			else 	steq.enqueue(s);
		}
		for (String s : steq)
			StdOut.print(s + " ");
	}
}
