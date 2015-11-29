/*
 * The PrimMST class represents a data type for computing a
 * minimum spanning tree in an edge-weighted graph.
 * The edge weights can positive, zeor of negative and need not
 * be distinct. If the graph is not connected, it computes a minimum
 * spanning forest, which is the union of minimum spanning trees
 * in each connected component. The weight() method returns the
 * weight of a minimum spanning tree and the edges() method
 * returns its edges.
 * This implementation uses Prim's algorithm with an indexed binary heap.
 * The constructor takes time proportional to E*logV and extra space
 * (not including the graph) proportional to V, where V is the number of
 * vertices and E is the number of edges.
 * Afterwards, the weight() and edges() methods take constant time.
 * For additional documentation, see <href="/algs4/44sp">
 *
 * Execution:       java PrimMST INPUT.TXT
 *                  %  java PrimMST tinyEWG.txt 
 *                  0-7 0.16000
 *                  1-7 0.19000
 *                  0-2 0.26000
 *                  2-3 0.17000
 *                  5-7 0.28000
 *                  4-5 0.35000
 *                  6-2 0.40000
 *                  1.81000
 *                
 *                  % java PrimMST mediumEWG.txt
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
 *                  % java PrimMST largeEWG.txt
 *                  ...
 *                  647.66307
 *
 * Dependencies:    Edge.java, EdgeWeightedGraph.java, IndexMinPQ.java, Queue.java, In.java, StdOut.java
 * Data File:       tinyEWG.txt, mediumEWG.txt, largeEWG.txt
 * Author:          caiguochu
 * Time:            2015-03-17
 */
public class PrimMST
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private boolean[] marked;       // marked[v] = true if v on tree
    private Queue<Edge> mst;        // edges in the MST
    private IndexMinPQ<Edge> pq;    // eligible crossing edges
    private double weight;          // total weight of MST

    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Computes a minimum spanning tree (or forest) of an edge-weighted graph.
     * @param G the edge-weighted graph
     */
    public PrimMST(EdgeWeightedGraph G)
    {
        int V = G.V();
        marked = new boolean[V];
        mst = new Queue<Edge>();
        pq = new IndexMinPQ<Edge>(V);
        for (int v = 0; v < V; v++)
            if (!marked[v])  prim(G, v);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // visit vertex x
    private void visit(EdgeWeightedGraph G, int v)
    {
        marked[v] = true;
        for (Edge e : G.adj(v))
        {
            int w = e.other(v);
            if (marked[w])  continue;
            if (pq.contains(w))
                if (e.compareTo(pq.keyOf(w)) < 0)    pq.change(w, e);
            else
                pq.insert(w, e);
        }
    }
    // run Prim's algorithm in graph G, starting from vertex s
    private void prim(EdgeWeightedGraph G, int s)
    {
        visit(G, s);
        while (!pq.isEmpty())
        {
            Edge e = pq.minKey();
            weight += e.weight();
            mst.enqueue(e);
            visit(G, pq.delMin());
        }
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the edges in a minimum spanning tree (or forest).
     * @return the edges in a minimum spanning tree (or forest) as
     *      an iterable of edges
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
    // Unit-test the PrimMST data type
    public static void main(String[] args)
    {
        EdgeWeightedGraph G = new EdgeWeightedGraph(new In(args[0]));
        PrimMST mst = new PrimMST(G);
        for (Edge e : mst.edges())
            StdOut.println(e);
        StdOut.printf("%.5f\n", mst.weight());
    }
}