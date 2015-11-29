/*
 * The LazyPrimMST class represents a data type for computing a
 * minimum spanning tree in an edge-weighted graph.
 * The edge weights can be positive, zero, or negative and need not
 * be distinct. If the graph is not connected, it computes a minimum
 * spanning forest, which is the union of minimum spanning trees 
 * in each connected component. The weight() method returns the
 * weight of a minimum spanning tree and the edges() method 
 * returns its edges.
 * This implementation uses a lazy version of Prim's algorithm
 * with a binary heap of edges.
 * The constructor takes time proportional to E*logE
 * and extra space (not including the graph) proportional to E,
 * where V is the number of vertices and E is the number of edges.
 * Afterwards, the weight() method takes constant time 
 * and the edges() method takes time proportional to V.
 * For additional documentation, see <href="/algs4/44sp">
 * For alternative implementations, sea PrimMST, KruskalMST,
 * and BoruvkaMST.
 *
 * Execution:       java LazyPrimMST INPUT.TXT
 *                  %  java LazyPrimMST tinyEWG.txt 
 *                  0-7 0.16000
 *                  1-7 0.19000
 *                  0-2 0.26000
 *                  2-3 0.17000
 *                  5-7 0.28000
 *                  4-5 0.35000
 *                  6-2 0.40000
 *                  1.81000
 *                
 *                  % java LazyPrimMST mediumEWG.txt
 *                  0-225   0.02383
 *                  49-225  0.03314
 *                  44-49   0.02107
 *                  44-204  0.01774
 *                  49-97   0.03121
 *                  202-204 0.04207
 *                  176-202 0.04299
 *                  176-191 0.02089
 *                  68-176  0.04396
 *                  58-68   0.04795
 *                  10.46351
 *                
 *                  % java LazyPrimMST largeEWG.txt
 *                  ...
 *                  647.66307
 *
 * Dependencies:    Edge.java, EdgeWeightedGraph.java, Queue.java, MinPQ.java, In.java, StdOut.java
 * Data File:       tinyEWG.txt, mediumEWG.txt, 1000EWC.txt, 10000EWG.txt, largeEWG.txt
 *                  tinyEWG.txt contains 8 vertices and 16 edges
 *                  mediumEWG.txt contains 250 vertices and 1,273 edges
 *                  1000EWG.txt contains 1,000 vertices and 8,433 edges
 *                  10000EWG.txt contains 10,000 vertices and 61,731 edges
 *                  largeEWG.txt contains one million vertices and 7,586,063 edges 
 *
 * Author:          caiguochu
 * Time:            2015-03-16
 */

public class LazyPrimMST
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private boolean[] marked;    // marked[v] = true if v on tree
    private Queue<Edge> mst;     // edges in the MST
    private MinPQ<Edge> pq;      // edges with one endpoint in tree
    private double weight;       // total weight of MST


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Compute a minimum spanning tree (or forest) of an edge-weighted graph.
     * @param G the edge-weighted graph
     */
    public LazyPrimMST(EdgeWeightedGraph G)
    {
        int V = G.V();
        marked = new boolean[V];
        mst = new Queue<Edge>();
        pq = new MinPQ<Edge>();
        for (int v = 0; v < V; v++)
            if (!marked[v]) prim(G, v);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // add all edges e incident to v onto pq if the other endpoint has not yet been visited
    private void visit(EdgeWeightedGraph G, int v)
    {
        marked[v] = true;
        for (Edge e : G.adj(v))
            if (!marked[e.other(v)])    pq.insert(e);
    }
    // run Prim's algorithm
    private void prim(EdgeWeightedGraph G, int s)
    {
        visit(G, s);
        while (!pq.isEmpty())
        {
            Edge e = pq.delMin();
            int v = e.either(), w = e.other(v);
            if (marked[v] && marked[w]) continue;
            mst.enqueue(e);
            weight += e.weight();
            if (!marked[v]) visit(G, v);
            if (!marked[w]) visit(G, w);
        }
    }

    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the edges in a minimum spanning tree (or forest).
     * @return the edges in a minimum spanning tree (or forest) as
     *      an Iterable of edges
     */
    public Iterable<Edge> edges() { return mst; }

    /**
     * Returns the sum of the edge weights in a minimum spanning tree (or forest).
     * @return the sum of the edge weights in a minimum spanning tree (or forest)
     */
    public double weight() {    return weight;  }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the LazyPrimMST data type
    public static void main(String[] args)
    {
        EdgeWeightedGraph G = new EdgeWeightedGraph(new In(args[0]));
        LazyPrimMST mst = new LazyPrimMST(G);
        for (Edge e : mst.edges())
            StdOut.println(e);
        StdOut.printf("%.5f\n", mst.weight());
    }
}