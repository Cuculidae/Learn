import java.util.Iterator;
import java.util.NoSuchElementException;
public class Deque<Item> implements Iterable<Item>
{
	private DoubleNode head;
	private DoubleNode tail;
	private int N;
	private class DoubleNode
	{
		Item item;
		DoubleNode next;
		DoubleNode prev;
	}
	public boolean isEmpty() {	return head == null;	}
	public int size() {	return N;	}
	public void pushLeft(Item item)
	{
		DoubleNode oldhead = head;
		head = new DoubleNode();
		head.item = item;
		head.next = oldhead;
		if (oldhead == null)	tail = head;
		else			oldhead.prev = head;
		N++;
	}
	public void pushRight(Item item)
	{
		DoubleNode oldtail = tail;
		tail = new DoubleNode();
		tail.item = item;
		tail.prev = oldtail;
		if (oldtail == null)	head = tail;
		else			oldtail.next = tail;
		N++;
	}
	public Item popLeft()
	{
		if (isEmpty())	return null;
		Item item = head.item;
		if (head.next == null)	head = tail = null;
		else{	head = head.next; head.prev =  null;	}
		N--;
		return item;
	}
	public Item popRight()
	{
		if (isEmpty())	return null;
		Item item = tail.item;
		if (tail.prev == null)	head = tail = null;
		else{	tail = tail.prev; tail.next = null;	}
		N--;
		return item;
	}
	public String toString()
	{
		StringBuilder s = new StringBuilder();
		for (Item item : this)
			s.append(item + " ");
		return s.toString();
	}
	public Iterator<Item> iterator()
	{	return new DequeIterator();	}
	private class DequeIterator implements Iterator<Item>
	{
		private DoubleNode current = head;
		public boolean hasNext()
		{	return current != null;	}
		public void remove()
		{	throw new UnsupportedOperationException();	}
		public Item next()
		{
			if (!hasNext())	throw new NoSuchElementException();
			Item item = current.item;
			current = current.next;
			return item;
		}
	}
	public static void main(String[] args)
	{
		Deque<String> dq = new Deque<String>();
		StdOut.println("pushRight");
		String s = StdIn.readString();
		dq.pushRight(s);
		StdOut.println("pushLeft");
		s = StdIn.readString();
		dq.pushLeft(s);
		StdOut.println("foreach");
		for (String i : dq)
			StdOut.println(i);
		StdOut.println("popRight");
		StdOut.println(dq.popRight());
		StdOut.println("popLeft");
		StdOut.println(dq.popLeft());
		StdOut.println("size");
		StdOut.println(dq.size());
	}
}
