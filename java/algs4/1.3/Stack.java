import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.ConcurrentModificationException;
public class Stack<Item> implements Iterable<Item>
{
	private Node first;	//栈顶
	private int N;		//元素数量
	private Counter pushCount = new Counter("push counter");	//记录push次数
	private Counter popCount = new Counter("pop counter");	//记录pop次数
	private class Node
	{	//定义了结点的嵌套类
		Item item;
		Node next;
	}
	public boolean isEmpty() { return first == null; } //or: N==0
	public int size() { 	return N;	}
	public void push(Item item)
	{
		pushCount.increment();
		Node oldfirst = first;
		first = new Node();
		first.item = item;
		first.next = oldfirst;
		N++;
	}
	public Item pop()
	{	
		popCount.increment();
		if (isEmpty()) throw new NoSuchElementException();
		Item item = first.item;
		first = first.next;
		N--;	//空栈时继续弹出会产生负值 
		return item;
	}
	public Item peak()
	{	//返回栈中最近添加的元素（而不弹出它）
		if (!isEmpty())
			return first.item;
		throw new NoSuchElementException();
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
		private Node current = first;
		private final int pushcount = pushCount.tally();
		private final int popcount = popCount.tally();
		public boolean hasNext()
		{	//如果在迭代中调用pop或push，抛出异常
			if (pushCount.tally() != pushcount || popCount.tally() != popcount)
				throw new java.util.ConcurrentModificationException();
			return current != null;
		}
		public Item next()
		{	//如果在迭代中调用pop或push，抛出异常	
			if (pushCount.tally() != pushcount || popCount.tally() != popcount)
				throw new ConcurrentModificationException();
			if (!hasNext()) throw new NoSuchElementException();
			Item item = current.item;
			current = current.next;
			return item;
		}
		public void remove() {	}
	}
	public static void main(String[] args)
	{
		Stack<String> s = new Stack<String>();
		while (!StdIn.isEmpty())
		{
			String item = StdIn.readString();
			s.push(item);
		}
		boolean pop = Boolean.parseBoolean(args[0]);
		for (String str : s)
		{
			if (pop) s.pop();
			StdOut.println(str);
		}
	}
}
