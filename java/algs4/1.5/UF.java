public class UF
{
	private int[] id;	//����id
	private int count;	//��������
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
		int N = StdIn.readInt();	//��ȡ��������
		UF uf = new UF(N);
		while (!StdIn.isEmpty())
		{
			int p = StdIn.readInt();	
			int q = StdIn.readInt();	//��ȡ������
			if (uf.connected(p, q))	continue;	//����Ѿ���ͨ�����
			uf.union(p, q);		//�鲢����
			StdOut.println(p + " " + q);
		}
		StdOut.println(uf.count() + "components");
	}
}
