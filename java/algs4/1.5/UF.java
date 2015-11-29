public class UF
{
	private int[] id;	//分量id
	private int count;	//分量数量
	public UF(int N)
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
	{	return id[p];	}
	public  void union(int p, int q)
	{
		int pID = find(p);
		int qID = find(q);
		if (pID == qID)	return;
		for (int i = 0; i < id.length; i++)
			if (id[i] == pID) id[i] = qID;
		count --;
	}
	public static void main(String[] args)
	{
		int N = StdIn.readInt();	//读取触点数量
		UF uf = new UF(N);
		while (!StdIn.isEmpty())
		{
			int p = StdIn.readInt();	
			int q = StdIn.readInt();	//读取整数对
			if (uf.connected(p, q))	continue;	//如果已经连通则忽略
			uf.union(p, q);		//归并分量
			StdOut.println(p + " " + q);
		}
		StdOut.println(uf.count() + "components");
	}
}
