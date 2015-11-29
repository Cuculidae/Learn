import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.ConcurrentModificationException;
public class GeneralizedQueue<Item> implements Iterable<Item>
{
	private Node first;
	private Node last;
	private int N;		//队列中元素数量
	private Counter inCounter = new Counter("inCounter");
	private Counter deCounter = new Counter("deCounter");
	private class Node
	{	//定义了结点的嵌套类
		Item item;
		Node next;
	}
	public boolean isEmpty() {	return first == null;	}
	public int size() {	return N;	}
	public void insert(Item x)
	{
		inCounter.increment();
		Node oldlast = last;
		last = new Node();
		last.item = x;
		last.next = null;
		if (isEmpty())	first = last;
		else		oldlast.next = last;
		N++;
	}
	/**
	 * 删除并返回最早插入的第K个元素
	 * k~[0,N)
	 */
	public Item delete(final int k)
	{
		deCounter.increment();	
		if (k < 0 || k >= N) throw new NoSuchElementException();
		Item item;
		if (k == 0) item = first.item;
		else {
			Node node = first;
			for (int i = 1; i < k; i++)//第k-1个元素
				node = node.next;	
			item = node.next.item;
			node.next = node.next.next;
		}
		if (isEmpty())	last = null;
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
	{	return new ListIterator();	}
	private class ListIterator implements Iterator<Item>
	{
		Node current = first;
		private final int in = inCounter.tally();
		private final int de = deCounter.tally();
		public boolean hasNext()
		{	return current != null;	}
		public Item next()
		{
			if (de != deCounter.tally() || in != inCounter.tally())
				throw new ConcurrentModificationException();
			Item item = current.item;
			current = current.next;
			return item;
		}
		public void remove()
	       	{ throw new UnsupportedOperationException();	}
	}
	public static void main(String[] args)
	{
		GeneralizedQueue<String> q = new GeneralizedQueue<String>();
		while (!StdIn.isEmpty())
		{
			String s = StdIn.readString();
			q.insert(s);
		}
		StdOut.println(q);
	 	StdOut.println(q.delete(0));
		StdOut.println(q.delete(1));
	}
}
