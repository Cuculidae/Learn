/*
 * The Graph class represents an undirected graph of vertices
 * named 0 through V - 1.
 * It supports the following two primary operations: add an edge to the graph,
 * iterate over all of the vertices adjacent to a vertex. It also provides
 * methods for returning the number of vertices V and the number
 * of edges E. Parallel edges and self-loops are permitted.
 * This implementation uses an adjacency-lists representation, which 
 * is a vertex-indexed array of Bag objects.
 * All operations take constant time (in the worst case) except
 * iterating over the vertices adjacent to a given vertex, which takes
 * time proportional to the number of such vertices.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/41undirected">
 *
 * Execution:		java Graph INPUT.TXT
 *                  % java Graph tinyG.txt
 *                  13 vertices, 13 edges 
 *                  0: 6 2 1 5 
 *                  1: 0 
 *                  2: 0 
 *                  3: 5 4 
 *                  4: 5 6 3 
 *                  5: 3 4 0 
 *                  6: 0 4 
 *                  7: 8 
 *                  8: 7 
 *                  9: 11 10 12 
 *                  10: 9 
 *                  11: 9 12 
 *                  12: 11 9
 *
 * Dependencies:	Bag.java, In.java, StdOut.java
 * Data File:		tinyG.txt, mediumG.txt, largeG.txt
 * Author:			caiguochu
 * Time:			2015-02-19
 */
public class Graph
{
	/*********************************************************************************************
	 *                                         Fields                                            *
	 *********************************************************************************************/
	private final int V;
	private int E;
	private Bag<Integer>[] adj;


	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
    /**
     * Initializes an empty graph with V vertices and 0 edges.
     * @param V the number of vertices
     * @throws java.lang.IllegalArgumentException if V < 0
     */
	public Graph(int V)
	{
		if (V < 0) throw new IllegalArgumentException("Number of vertices must be nonnegative");
		this.E = 0;
		this.V = V;
		adj = (Bag<Integer>[]) new Bag[V];
		for (int v = 0; v < V; v++)
			adj[v] = new Bag<Integer>();
	}

    /**  
     * Initializes a graph from an input stream.
     * The format is the number of vertices V,
     * followed by the number of edges E,
     * followed by E pairs of vertices, with each entry separated by whitespace.
     * @param in the input stream
     * @throws java.lang.IndexOutOfBoundsException if the endpoints of any edge are not in prescribed range
     * @throws java.lang.IllegalArgumentException if the number of vertices or edges is negative
     */
    public Graph(In in) {
        this(in.readInt());
        int E = in.readInt();
        if (E < 0) throw new IllegalArgumentException("Number of edges must be nonnegative");
        for (int i = 0; i < E; i++) {
            int v = in.readInt();
            int w = in.readInt();
            addEdge(v, w);
        }
    }

    /**
     * Initializes a new graph that is a deep copy of G.
     * @param G the graph to copy
     */
    public Graph(Graph G) {
        this(G.V());
        this.E = G.E();
        for (int v = 0; v < G.V(); v++) {
            // reverse so that adjacency list is in same order as original
            Stack<Integer> reverse = new Stack<Integer>();
            for (int w : G.adj[v]) {
                reverse.push(w);
            }
            for (int w : reverse) {
                adj[v].add(w);
            }
        }
    }


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	private boolean isValidVertex(int v) {	return 0 <= v && v < V;	}


	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
    /**
     * Returns the number of vertices in the graph.
     * @return the number of vertices in the graph
     */
	public int V() {	return V;	}

    /**
     * Returns the number of edges in the graph.
     * @return the number of edges in the graph
     */
	public int E() {	return E;	}

    /**
     * Returns the vertices adjacent to vertex v.
     * @return the vertices adjacent to vertex v as an Iterable
     * @param v the vertex
     * @throws java.lang.IndexOutOfBoundsException unless 0 <= v < V
     */
	public Iterable<Integer> adj(int v)
	{
		if (!isValidVertex(v)) throw new IndexOutOfBoundsException("not valid vertex " + v);
		return adj[v];
	}

    /**
     * Adds the undirected edge v-w to the graph.
     * @param v one vertex in the edge
     * @param w the other vertex in the edge
     * @throws java.lang.IndexOutOfBoundsException unless both 0 <= v < V and 0 <= w < V
     */
	public void addEdge(int v, int w)
	{
		if (!isValidVertex(v))
			throw new IndexOutOfBoundsException("not valid vertex " + v);
		if (!isValidVertex(w))
			throw new IndexOutOfBoundsException("not valid vertex " + w);
		E++;
		adj[v].add(w);
		adj[w].add(v);
	}

    /**
     * Returns the degree of vertex v.
     * @return the degree of vertex v
     * @param v the vertex
     * @throws java.lang.IndexOutOfBoundsException unless 0 <= v < V
     */
    public int degree(int v) {
        if (!isValidVertex(v)) throw new IndexOutOfBoundsException("not valid vertex " + v);
        return adj[v].size();
    }


    /**
     * Returns a string representation of the graph.
     * This method takes time proportional to E + V.
     * @return the number of vertices V, followed by the number of edges E,
     * followed by the V adjacency lists
     */
    public String toString() {
        StringBuilder s = new StringBuilder();
        String NEWLINE = System.getProperty("line.separator");
        s.append(V + " vertices, " + E + " edges " + NEWLINE);
        for (int v = 0; v < V; v++) {
            s.append(v + ": ");
            for (int w : adj[v]) {
                s.append(w + " ");
            }
            s.append(NEWLINE);
        }
        return s.toString();
    }
	 

	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	// Unit-test the Graph data type
    public static void main(String[] args) {
        In in = new In(args[0]);
        Graph G = new Graph(in);
        StdOut.println(G);
    }
}