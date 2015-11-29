/*
 * The Bipartite class represents a data type for
 * determining whether an undirected graph is bipartite or whether
 * it has and odd-length cycle.
 * The isBipartite operation determines whether the graph is
 * bipartite. If so, the color operation determines a
 * bipartition; if not, the oddCycle operation determines a
 * cycle with an odd number of edges.
 * This implementation uses depth-first search.
 * The constructor takes proportional to V + E (in the worst case),
 * where V is the number of vertices and E is the number of edges.
 * Afterwards, the isBipartite, color and oddCycle operations
 * take constant time.
 * For additional documentation, see <href="/algs4/41graph">
 *
 * Execution:		java Bipartite V E F
 * Dependencies:	Stack.java, Graph.java, StdRandom.java, StdOut.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-03-26
 */
public class Bipartite
{
	/*********************************************************************************************
	 *                                         Fields                                            *
	 *********************************************************************************************/
	private boolean[] color;		// color[v] gives vertices on one side of bipartition
	private boolean[] marked;		// marked[v] = true if v has been visited
	private Stack<Integer> cycle;	// odd-length cycle
	private int[] edgeTo;			// edgeTo[v] = last edge on path to v


	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	/**
	 * Determines whether an undirected graph is bipartite and finds either a 
	 * bipartition or an odd-length cycle.
	 * @param G the graph
	 */
	public Bipartite(Graph G)
	{
		marked = new boolean[G.V()];
		color = new boolean[G.V()];
		edgeTo = new int[G.V()];
		for (int v = 0; v < G.V(); v++)
			if (!marked[v])	dfs(G, v);
	}


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	private void dfs(Graph G, int v)
	{
		marked[v] = true;
		for (int w : G.adj(v))
		{
			if (cycle != null)	return;
			if (!marked[w])
			{
				marked[w] = true;
				edgeTo[w] = v;
				color[w] = !color[v];
				dfs(G, w);
			}
			else if(color[v] == color[w])
			{
				cycle = new Stack<Integer>();
				cycle.push(w);
				for (int x = v; x != w; x = edgeTo[x])
					cycle.push(x);
				cycle.push(w);
			}
		}
	}


	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
	/**
	 * Is the graph bipartite ?
	 * @return true if the graph is bipartite, false otherwise
	 */
	public boolean isBipartite() {	return cycle == null;	}

	/**
	 * Returns the side of the bipartition that vertex v is on
	 * @param v the vertex
	 * @return the side of the bipartition that vertex v is on; two vertices
	 *		are in the same side of the bipartition if and only if they have
	 *		the same color.
	 * @throws UnsupportedOperationException if this methed is called when the graph
	 *		is not bipartite
	 */
    public boolean color(int v)
    {
        if (cycle != null)
            throw new UnsupportedOperationException("Graph is not bipartite");
        return color[v];
    }

    /**
     * Returns an odd-length cycle if the graph is not bipartite, and
     * null otherwise.
     * @return and odd-length cycle (as an iterable) if the graph is not bipartite
     * 		(and hence has an odd-length cycle), and null otherwise
     */
	public Iterable<Integer> oddCycle() {	return cycle;	}
	 

	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	// Unit-test the Bipartite data type
	public static void main(String[] args)
	{
        // create random bipartite graph with V vertices and E edges; then add F random edges
        int V = Integer.parseInt(args[0]);
        int E = Integer.parseInt(args[1]);
        int F = Integer.parseInt(args[2]);

        Graph G = new Graph(V);
        int[] vertices = new int[V];
        for (int i = 0; i < V; i++) vertices[i] = i;
        StdRandom.shuffle(vertices);
        for (int i = 0; i < E; i++) {
            int v = StdRandom.uniform(V/2);
            int w = StdRandom.uniform(V/2);
            G.addEdge(vertices[v], vertices[V/2 + w]);
        }

        // add F extra edges
        for (int i = 0; i < F; i++) {
            int v = (int) (Math.random() * V);
            int w = (int) (Math.random() * V);
            G.addEdge(v, w);
        }

        StdOut.println(G);


        Bipartite b = new Bipartite(G);
        if (b.isBipartite()) {
            StdOut.println("Graph is bipartite");
            for (int v = 0; v < G.V(); v++) {
                StdOut.println(v + ": " + b.color(v));
            }
        }
        else {
            StdOut.print("Graph has an odd-length cycle: ");
            for (int x : b.oddCycle()) {
                StdOut.print(x + " ");
            }
            StdOut.println();
        }		
	}
}