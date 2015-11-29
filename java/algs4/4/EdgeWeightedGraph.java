/*
 * The EdgeWeightedGraph class represents an edge-weighted
 * graph of vertices named 0 through V-1, where each
 * undirected edge is of type Edge and has a real-valued weight;
 * It supports the following two primary operations: add an edge to the graph,
 * iterate over all of the edges incident to a vertex. It also provides
 * methods for returning the number of vertices V and the number of edges E.
 * Parallel edges and self-loops are permitted.
 * This implementation uses an adjacency-lists representation, which
 * is a vertex-indexed array of Bag objects.
 * All operations take constant time (in the worst case) except
 * iterating over the edges incident to a given vertex, which takes
 * time proportional to the number of such edges.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/43mst">
 *
 * Execution:       java EdgeWeightedGraph INPUT.TXT
 *                  8 16
 *                  0: 6-0 0.58000  0-2 0.26000  0-4 0.38000  0-7 0.16000  
 *                  1: 1-3 0.29000  1-2 0.36000  1-7 0.19000  1-5 0.32000  
 *                  2: 6-2 0.40000  2-7 0.34000  1-2 0.36000  0-2 0.26000  2-3 0.17000  
 *                  3: 3-6 0.52000  1-3 0.29000  2-3 0.17000  
 *                  4: 6-4 0.93000  0-4 0.38000  4-7 0.37000  4-5 0.35000  
 *                  5: 1-5 0.32000  5-7 0.28000  4-5 0.35000  
 *                  6: 6-4 0.93000  6-0 0.58000  3-6 0.52000  6-2 0.40000  
 *                  7: 2-7 0.34000  1-7 0.19000  0-7 0.16000  5-7 0.28000  4-7 0.37000  
 *
 * Dependencies:    Edge.java, Bag.java, In.java, StdOut.java
 * Data File:       tinyEWG.txt
 * Author:          caiguochu
 * Time:            2015-03-11
 */

public class EdgeWeightedGraph
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
     private final int V;       // number of vertices
     private int E;             // number of edges
     private Bag<Edge>[] adj;   // adjacency list


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Initializea an empty edge-weighted graph with V vertices and 0 edges
     * @param V the number of vertices
     * @throws java.lang.IllegalArgumentException if V < 0
     */
    public EdgeWeightedGraph(int V)
    {
        if (V < 0) throw new IllegalArgumentException("Number of vertices must be nonnegative");
        this.V = V;
        this.E = 0;
        adj = (Bag<Edge>[]) new Bag[V];
        for (int v = 0; v < V; v++)
            adj[v] = new Bag<Edge>();
    }

    /**
     * Initializes a random edge-weighted graph with V vertices and E edges
     * @param V the number of vertices
     * @param E the number of edges
     * @throws java.lang.IllegalArgumentException if V < 0
     * @throws java.lang.IllegalArgumentException if E < 0
     */
    public EdgeWeightedGraph(int V, int E)
    {
        this(V);
        if (E < 0) throw new IllegalArgumentException("Number of edges must be nonnegative");
        for (int i = 0; i < E; i++)
        {
            int v = (int) Math.random() * V;
            int w = (int) Math.random() * V;
            double weight = Math.round(100 * Math.random()) / 100.0;
            addEdge(new Edge(v, w, weight));
        }
    }

    /**
     * Initializes an edge-weighted graph from an input stream.
     * The format is the number of vertices V,
     * followed by the number of edges E,
     * followed by E pairs of vertices and edge weights,
     * with each entry separated by whitespace
     * @param in the input stream
     * @throws java.lang.IndexOutOfBoundsException if the endpoints of any edge are not in prescribed range
     * @throws java.lang.IllegalArgumentException if the number of vertices or edges is negative
     */
    public EdgeWeightedGraph(In in)
    {
        this(in.readInt());
        this.E = in.readInt();
        if (E < 0) throw new IllegalArgumentException("Number of edges must be nonnegative");
        for (int i = 0; i < E; i++)
        {
            int v = in.readInt();
            int w = in.readInt();
            double weight = in.readDouble();
            validateVertex(v);
            validateVertex(w);
            Edge e = new Edge(v, w, weight);
            adj[v].add(e);
            adj[w].add(e);
        }
    }

    /**
     * Initializes a new edge-weighted graph that is a deep copy of G
     * @param G the edge-weighted graph to copy
     */
    public EdgeWeightedGraph(EdgeWeightedGraph G)
    {
        this(G.V);
        this.E = G.E;
        for (int v = 0; v < V; v++)
        {
            Stack<Edge> reverse = new Stack<Edge>();
            for (Edge e : G.adj[v])
                reverse.push(e);
            for (Edge e : reverse)
                adj[v].add(e);
        }
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // throw an IndexOutOfBoundsException unless 0 <= v < V
    private void validateVertex(int v)
    {
        if (v < 0 || v >= V)
            throw new IndexOutOfBoundsException("vertex " + v + " is not between 0 and " + (V-1));
    }

    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the number of vertices in the edge-weighted graph.
     * @return the number of vertices in the edge-weighted graph
     */
    public int V() {    return V;   }

    /**
     * Returns the number of edges in the edge-weighted graph.
     * @return the number of edges in the edge-weighted grpah
     */
    public int E() {    return E;   }

    /**
     * Returns the edges incident to vertex v
     * @return the edges incident to vertex v as an Iterable
     * @param v the vertex
     * @throws java.lang.IndexOutOfBoundsException unless 0 <= v < V
     */
    public Iterable<Edge> adj(int v) 
    {  validateVertex(v); return adj[v];  }

    /**
     * Returns the degree of vertex v.
     * @return the degree of vertex v               
     * @param v the vertex
     * @throws java.lang.IndexOutOfBoundsException unless 0 <= v < V
     */
    public int degree(int v)
    {   validateVertex(v); return adj[v].size();    }

    /**
     * Adds the undirected edge e to the edge-weighted graph.
     * @param e the edge
     * @throws java.lang.IndexOutOfBoundsException unless both endpoints are between 0 and V-1
     */
    public void addEdge(Edge e)
    {
        int v = e.either();
        int w = e.other(v);
        validateVertex(v);
        validateVertex(w);
        adj[v].add(e);
        adj[w].add(e);
        E++;
    }

    /**
     * Returns all edges in the edge-weighted graph.
     * To iterate over the edges in the edge-weighted graph, use foreach notation.
     * for (Edge e : G.edges())
     * Self-loops are omitted
     * @return all edges in the edge-weighted graph as an Iterable
     */
    public Iterable<Edge> edges()
    {
        Bag<Edge> bag = new Bag<Edge>();
        for (int v = 0; v < V; v++)
            for (Edge e : adj[v])
                if (e.other(v) > v)
                    bag.add(e);
        return bag;
    }

    /**
     * Returns a string representation of the edge-weighted graph
     * This method takes time proportional to E + V
     * @return the number of vertices V, followed by the number of edges E,
     *      followed by the V ajacency lists of edges as a string
     */
    public String toString()
    {
        String NEWLINE = System.getProperty("line.separator");
        StringBuilder s = new StringBuilder();
        s.append(V + " " + E + NEWLINE);
        for (int v = 0; v < V; v++)
        {
            s.append(v + ": ");
            for (Edge e : adj[v])
                s.append(e + "  ");
            s.append(NEWLINE);
        }
        return s.toString();
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the EdgeWeightedGraph data type
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        EdgeWeightedGraph G = new EdgeWeightedGraph(in);
        StdOut.println(G);
    }
}