/*
 * The DepthFirstSearch class represents a data type for 
 * determining the vertices connected to a given source vertex s
 * in an undirected graph. For versions that find the paths, see
 * DepthFirstPaths and BreadthFirstPaths.
 * This implementation uses depth-first search.
 * The constructor takes time proportional to V + E
 * (in the worst case),
 * where V is the number of vertices and E is the number of edges.
 * It uses extra space (not including the graph) proportional to V.
 * For additional documentation, see <href="/algs4/41graph">
 *
 * Execution:		java DepthFirstSearch INPUT.TXT VERTEX
 * 					% java DepthFirstSearch tinyG.txt 0
 *					0 1 2 3 4 5 6 
 *					NOT connected
 *
 * Dependencies:	Graph.java, In.java, StdOut.java
 * Data File:		tinyG.txt
 * Author:			caiguochu
 * Time:			2015-02-23
 */
public class DepthFirstSearch
{
	/*********************************************************************************************
	 *                                         Fields                                            *
	 *********************************************************************************************/
	private boolean[] marked; // marked[v] = is there an s-v path?
	private int count;        // number of vertices connected to s 
	

	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
    /**
     * Computes the vertices in graph G that are
     * connected to the source vertex s.
     * @param G the graph
     * @param s the source vertex
     */
	public DepthFirstSearch(Graph G, int s)
	{
		marked = new boolean[G.V()];
		dfs(G, s);
	}


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	// depth first search from v
	private void dfs(Graph G, int v)
	{
		count++;
		marked[v] = true;
		for (int w : G.adj(v))
			if (!marked[w])
				dfs(G, w);
	}


	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
    /**
     * Returns the number of vertices connected to the source vertex s.
     * @return the number of vertices connected to the source vertex s
     */
	public int count() {	return count;	}

    /**
     * Is there a path between the source vertex s and vertex v?
     * @param v the vertex
     * @return true if there is a path, false otherwise
     */
	public boolean marked(int v)
	{
		return marked[v];
	}
	 

	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	// Unit-test the DepthFirstSearch data type
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        Graph G = new Graph(in);
        int s = Integer.parseInt(args[1]);
        DepthFirstSearch search = new DepthFirstSearch(G, s);
        for (int v = 0; v < G.V(); v++)
        {
            if (search.marked(v))
                StdOut.print(v + " ");
        }
        StdOut.println();
        if (search.count() != G.V()) StdOut.println("NOT connected");
        else                         StdOut.println("connected");
    }
}