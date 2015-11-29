/*
 * The AdjMatrixDigraph class represents a directed graph of vertices named 0 through V-1.
 * It supports the following two primary operations: add an edge to the digraph;
 * iterates through the vertices adjacent from a given vertex.
 * Parallel edges are not supported, but self loops are permitted.
 * This implementation uses an ajacency-matrix representation, which
 * is a 2-dimensional boolean array $adj$ in which adj[v][w] indicates
 * vertex v directs to vertex w.
 * All operations take constant time except iterating over the vertices adjacent
 * from a given vertex, which takes time proportional to the number of such vertices.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/42directed">
 *
 * Execution:       java AdjMatrixDigraph INPUT.TXT
 *                  % java AdjMatrixDigraph tinyDG.txt
 *                  13 vertices, 22 edges:
 *                  0: 1 5 
 *                  1: 
 *                  2: 0 3 
 *                  3: 2 5 
 *                  4: 2 3 
 *                  5: 4 
 *                  6: 0 4 8 9 
 *                  7: 6 9 
 *                  8: 6 
 *                  9: 10 11 
 *                  10: 12 
 *                  11: 4 12 
 *                  12: 9 
 *
 * Dependencies:    In.java, StdOut.java
 * Data File:       tinyDG.txt, mediumDG.txt, largeDG.txt
 * Author:          caiguochu
 * Time:            2015-03-09
 */

import java.util.NoSuchElementException;
import java.util.Iterator;

public class AdjMatrixDigraph
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private final int V;        // number of vertices
    private int E;              // number of edges  
    private boolean[][] adj;    // adjacency-matrix


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Initializes an empty digraph with V vertices
     * @param V the number of vertices
     * @throws java.lang.IllegalArgumentException if V < 0
     */
    public AdjMatrixDigraph(int V)
    {
        if (V < 0) throw new IllegalArgumentException("Number of in a Digraph must be Nonnegative");
        this.V = V;
        this.E = 0;
        this.adj = new boolean[V][V];
    }

    /**
     * Initializes a digraph from an input stream
     * The format is the number of vertices V
     * followed by the number of edges E
     * followed by E pairs of vertices, with each entry separated by whitespace
     * @param in the input stream 
     * @throws java.lang.IndexOutOfBoundsException if the endpoints of any edges are not in prescribed range
     * @throws java.lang.IllegalArgumentException if the number of vertices or edges is negative
     */
    public AdjMatrixDigraph(In in)
    {
        this(in.readInt());
        this.E = in.readInt();
        if (E < 0) throw new IllegalArgumentException("Number of edges in a Digraph must be nonnegative");
        for (int e = 0; e < E; e++)
        {
            int v = in.readInt();
            int w = in.readInt();
            adj[v][w] = true;
        }
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // throw an IndexOutOfBoundsException unless v in [0, V)
    private void validateVertex(int v)
    {
        if (v < 0 || v >= V)
            throw new IndexOutOfBoundsException("vertex " + v + " not in [0, " + V + ")");
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the number of vertices in the digraph
     * @return the number of vertices in the digraph
     */
    public int V() {    return V;   }

    /**
     * Returns the number of edges in the digraph
     * @return the number of edges in the digraph
     */
    public int E() {    return E;   }

    /**
     * Adds the directed edge v -> w to the digraph
     * @param v the tail vertex
     * @param w the head vertex
     * @throws java.lang.IndexOutOfBoundsException unless both v and w in [0, V)
     */
    public void addEdge(int v, int w)
    {
        if (adj[v][w]) return;
        E++;
        adj[v][w] = true;
    }

    /**
     * Returns the vertices adjacent from vertex v in the digraph
     * @return the vertices adjacent from vertex v in the digarph
     * @param v the vertex
     * @throws java.lang.IndexOutBoundsException unless v in [0, V)
     */
    public Iterable<Integer> adj(int v) 
    {
        validateVertex(v);
        return new AdjIterator(v);  
    }

    /**
     * Returns a string representation of the graph
     * This method takes time proportional to E + V
     * @return the number of vertice, followed by the number of edges,
     *     followed by the adjacency lists.
     */
    public String toString()
    {
        StringBuilder s = new StringBuilder();
        String NEWLINE = System.getProperty("line.separator");
        s.append(V + " vertices, " + E + " edges:" + NEWLINE);
        for (int v = 0; v < V; v++)
        {
            s.append(v + ": ");
            for (int w = 0; w < V; w++)
                if (adj[v][w])
                    s.append(w + " ");
            s.append(NEWLINE);

        }
        return s.toString();
    }


    /*********************************************************************************************
     *                                       Iterator                                            *
     *********************************************************************************************/
    // support iteration over graph vertices
    private class AdjIterator implements Iterator<Integer>, Iterable<Integer>
    {
        int v, w;
        AdjIterator(int v) {    this.v = v; }
        public Iterator<Integer> iterator() {   return this; }
        public boolean hasNext()
        {
            while (w < V)
            {
                if (adj[v][w]) return true;
                w++;
            }
            return false;
        }
        public Integer next()
        {
            if (hasNext()) return w++;
            throw new NoSuchElementException();
        }
        public void remove() {  throw new UnsupportedOperationException();  }
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the Digraph data type
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        AdjMatrixDigraph G = new AdjMatrixDigraph(in);
        StdOut.println(G);
    }
}