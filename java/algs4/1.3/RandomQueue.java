import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.ConcurrentModificationException;
public class RandomQueue<Item> implements Iterable<Item>
{
	private Item[] items = (Item[]) new Object[1];
	private int N;
	private Counter enCounter = new Counter("enCounter");
	private Counter deCounter = new Counter("deCounter");
	private Item[] resize(int size)
	{
		if (size < N) throw new RuntimeException("at resize(): argument size should be larger than N");
		Item[] temp = (Item[]) new Object[size];
		for (int i = 0; i < N; i++)
			temp[i] = items[i];
		return temp;
	}
	public boolean isEmpty()
	{	return N == 0;	}
	public int size()
	{	return N;	}
	public void enqueue(Item item)
	{
		enCounter.increment();
		if (N == items.length)
			items = resize(2 * items.length);
		items[N++] = item;
	}
	public Item dequeue()
	{
		deCounter.increment();
		if (isEmpty())	throw new NoSuchElementException();
		int i = StdRandom.uniform(0, N);
		Item temp = items[i];
		items[i] = items[--N];
		items[N] = null; 	//防止对象游离
		if (N == items.length/4)
			items = resize(items.length/2);
		return temp;
	}
	public Item sample()
	{
		if (isEmpty()) throw new NoSuchElementException();	
		return items[StdRandom.uniform(0, N)];	
	}
	public Iterator<Item> iterator()
	{	return new RandomQueueIterator();	}
	private class RandomQueueIterator implements Iterator<Item>
	{
		private int n = N;
		private final int enc = enCounter.tally();
		private final int dec = deCounter.tally();
		public boolean hasNext()
		{	return n > 0;	}
		public void remove()
		{	throw new UnsupportedOperationException();	}
		public Item next()
		{	//迭代时不能调用enqueue， dequeue
			if (enc != enCounter.tally() || dec != deCounter.tally())
				throw new ConcurrentModificationException();
			if (!hasNext())	throw new NoSuchElementException();
			return items[--n];
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
		RandomQueue<Card> c = new RandomQueue<Card>();
		for (int i = 0; i < 13; i++)
			for (int j = 0; j < 4; j++)
			{
				Card card = new Card((byte) (i + 1), Card.Suit.values()[j]);
				c.enqueue(card);
			}
		for (int i = 0; i < 4; i++)
		{
			StdOut.println("number: " + (i+1));
			for (int j = 0; j < 13; j++)
				StdOut.println(c.dequeue());
		}	
	}
}

