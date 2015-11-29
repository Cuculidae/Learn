public class LinearProbingHashST<Key, Value>
{
	private int N;	//符号表中键值对的总数
	private int M;	//线性探测表的大小
	private Key[] keys;//键
	private Value[] vals;//值
	public LinearProbingHashST()
	{	this(16);	}
	public LinearProbingHashST(int cap)
	{
		M = cap;
		keys = (Key[]) new Object[M];
		vals = (Value[]) new Object[M];
	}
	private int hash(Key key)
	{	return (key.hashCode() & 0x7fffffff) % M;	}
	private void resize(int cap)
	{
		LinearProbingHashST<Key, Value> t;
		t = new LinearProbingHashST<Key, Value>(cap);
		for (int i = 0; i < M; i++)
			if (keys[i] != null)
				t.put(keys[i], vals[i]);
		keys = t.keys;
		vals = t.vals;
		M    = t.M;
	}
	public int size()
	{	return N;	}
	public boolean isEmpty()
	{	return N == 0;	}
	public boolean contains(Key key)
	{	return get(key) != null;	}
	public Value get(Key key)
	{
		for (int i = hash(key); keys[i] != null; i = (i+1) % M)
			if (keys[i].equals(key))
				return vals[i];
		return null;	//返回null，代表键不存在
	}
	public void put(Key key, Value val)
	{
		if (val == null){ delete(key); return;	}
		if (N >= M*3/4) resize(2*M);
		int i;
		for (i = hash(key); keys[i] != null; i = (i+1) % M)
			if (keys[i].equals(key)) { vals[i] = val; return; }
		keys[i] = key;
		vals[i] = val;
		N++;
	}
	public void delete(Key key)
	{
		int i;
		for (i = hash(key); keys[i] != null; i = (i+1) % M)
			if (keys[i].equals(key)) break;
		if (keys[i] == null) return;	//not found, just return
		keys[i] = null;
		vals[i] = null;
		N--;
		int blank = i;	//空出的位置
		i = (i+1) % M;
		while (keys[i] != null)
		{
			put(keys[i], vals[i]);
			if (keys[blank] != null)
			{
				keys[i] = null;
				vals[i] = null;
				blank = i;	//更新空出的位置
				N--;
			}
			i = (i+1) % M;
		}
		if (N > 0 && N <= M/8) resize(M/2);
	}
	public void print()
	{
		StdOut.printf("%8s","hashid: ");
		for (int i = 0; i < M; i++)
			StdOut.printf("%8d", i);
		StdOut.println();
		StdOut.printf("%8s", "key: ");
		for (int i = 0; i < M; i++)
			StdOut.printf("%8s", keys[i] == null? " " : keys[i] + "");
	}
	public Iterable<Key> keys()
	{
		Queue<Key> q = new Queue<Key>();
		for (int i = 0; i < M; i++)
			if (keys[i] != null)
				q.enqueue(keys[i]);
		return q;
	}
	public static void main(String[] args)
	{
		int minlen = Integer.parseInt(args[0]);
		LinearProbingHashST<String, Integer> st = new LinearProbingHashST<String, Integer>(1024);
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
