public class SeparateChainingHashST<Key, Value>
{
	private int N;	//��ֵ������
	private int M;	//ɢ�б��С
	private SequentialSearchST<Key, Value>[] st; //���������������
	
	private int hash(Key key)
	{	return (key.hashCode() & 0x7fffffff) % M;	}

	public SeparateChainingHashST()
	{	this(997);	}
	public SeparateChainingHashST(int M)
	{	//����M������
		this.M = M;
		st = (SequentialSearchST<Key, Value>[]) new SequentialSearchST[M];
		for (int i = 0; i < M; i++) st[i] = new SequentialSearchST();
	}
	public int size()
	{	return N;	}
	public boolean isEmpty()
	{	return N == 0;	}
	public boolean contains(Key key)
	{	return st[hash(key)].contains(key);	}
	public Value get(Key key)
	{	return st[hash(key)].get(key);	}
	public void put(Key key, Value val)
	{
		if (val == null) delete(key);
		st[hash(key)].put(key, val);
	}
	public void delete(Key key)
	{	st[hash(key)].delete(key);	}
	public Iterable<Key> keys()
	{
		Queue<Key> q = new Queue<Key>();
		for (int i = 0; i < M; i++)
			for (Key k : st[i].keys())
				q.enqueue(k);
		return q;
	}
	public static void main(String[] args)
	{
		int minlen = Integer.parseInt(args[0]);
		SeparateChainingHashST<String, Integer> st = new SeparateChainingHashST<String, Integer>();
		In in = new In(args[1]);
		while (!in.isEmpty())
		{
			String word = in.readString();
			if (word.length() < minlen) continue;
			if (!st.contains(word)) st.put(word, 1);
			else			st.put(word, st.get(word) + 1);
		}
		String max = " ";
		st.put(max, 0);
		for (String word : st.keys())
			if (st.get(word) > st.get(max))
				max = word;
		StdOut.println(max + " " + st.get(max));
	}
}	
