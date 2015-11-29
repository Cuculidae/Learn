public class QuickUnion
{
	private int[] id;	//分量id
	private int count;	//分量数量
	public QuickUnion(int N)
	{
		count = N;
		id = new int[N];
		for (int i = 0; i < N; i++)
			id[i] = i;
	}
	public int count()
	{	return count;	}
	public boolean connected(int p, int q)
	{	return find(p) == find(q);	}
	public int find(int p)
	{	 
		while (p != id[p]) p = id[p];
		return p;
	}
	public  void union(int p, int q)
	{
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot) return;
		id[pRoot] = qRoot;
		count --;
	}
	public static void main(String[] args)
	{
		int N = StdIn.readInt();	//读取触点数量
		QuickUnion qu = new QuickUnion(N);
		while (!StdIn.isEmpty())
		{
			int p = StdIn.readInt();	
			int q = StdIn.readInt();	//读取整数对
			if (qu.connected(p, q))	continue;	//如果已经连通则忽略
			qu.union(p, q);		//归并分量
			StdOut.println(p + " " + q);
		}
		StdOut.println(qu.count() + "components");
	}
}
