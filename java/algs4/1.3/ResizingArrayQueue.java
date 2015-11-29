import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.ConcurrentModificationException;
public class ResizingArrayQueue<Item> implements Iterable<Item>
{
	private Item[] items = (Item[]) new Object[1];
	private int head;
	private int tail;
	private Item[] resize(int size)
	{
		if (size() > size) throw new RuntimeException("at resize(): argumet size should be larger than Queue size");
		Item[] temp = (Item[]) new Object[size];
		for (int i = head, j = 0; i < tail; i++, j++)
			temp[j] = items[i];
		tail = tail - head;
		head = 0;
		return temp;
	}
	public boolean isEmpty()
	{	return tail <= head;	}
	public int size()
	{	return tail - head;	}
	public void enqueue(Item item)
	{
		if (tail == items.length)
			if (size() > items.length/2)
				items = resize(2 * items.length);
			else	items = resize(items.length);
		items[tail++] = item;
	}
	public Item dequeue()
	{
		Item item;
		if (!isEmpty())
		{
			item = items[head];
			items[head++]= null;	//∑¿÷π∂‘œÛ”Œ¿Î
		} else {	throw new NoSuchElementException();	}
		if (size() == items.length/4)
			items = resize(items.length/2);
		return item;
	}
	public Iterator<Item> iterator()
	{	return new ResizingArrayQueueIterator();	}
	private class ResizingArrayQueueIterator implements Iterator<Item>
	{
		private final int h = head;
		private final int t = tail;
		private int i = h;
		public boolean hasNext()
		{	return t > i;	}
		public void remove()
		{	throw new UnsupportedOperationException();	}
		public Item next()
		{
			if (h != head || t != tail)
				throw new ConcurrentModificationException();
			if (!hasNext())	throw new NoSuchElementException();
			return items[i++];
		}
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
		ResizingArrayQueue<String> q = new ResizingArrayQueue<String>();
		while (!StdIn.isEmpty())
		{
			String s = StdIn.readString();
			q.enqueue(s);
		}
		for (String s : q)
			StdOut.print(s + " ");
	}
}

