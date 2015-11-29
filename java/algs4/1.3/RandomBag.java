import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.ConcurrentModificationException;
public class RandomBag<Item> implements Iterable<Item>
{
	private Item[] items = (Item[]) new Object[1];
	private int N;
	private Item[] resize(int size)
	{
		if (size < N) throw new RuntimeException("at  resize(): argument size should be larger than N");
		Item[] temp = (Item[]) new Object[size];
		for (int i = 0; i < N; i++)
			temp[i] = items[i];
		return temp;
	}
	public boolean isEmpty()
	{	return N != 0;	}
	public int size()
	{	return N;	}
	public void add(Item item)
	{
		if (N == items.length)
			items = resize(2 * items.length);
		items[N++] = item;
	}
	public String toString()
	{
		StringBuilder s = new StringBuilder();
		for (Item item : this)
			s.append(item + " ");
		return s.toString();
	}
	public Iterator<Item> iterator()
	{	return new RandomBagIterator();	}
	private class RandomBagIterator implements Iterator<Item>
	{
		private final int num = N;
		private int n = num;
		private int[] index = new int[num];
		public RandomBagIterator()
		{
			for (int i = 0; i < num; i++)
				index[i] = i;
			StdRandom.shuffle(index);
		}
		public boolean hasNext()
		{	return n != 0;	}
		public void remove()
		{	throw new UnsupportedOperationException();	}
		public Item next()
		{
			if (num != N) throw new ConcurrentModificationException();
			if (!hasNext()) throw new NoSuchElementException();
			return items[index[--n]];
		}
	}
	public static void main(String[] args)
	{
		RandomBag<String> rb = new RandomBag<String>();
		while (!StdIn.isEmpty())
		{
			String s = StdIn.readString();
			rb.add(s);
		}
		for (String s : rb)
			StdOut.print(s + " ");
	}
}
