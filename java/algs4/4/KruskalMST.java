/*
 * The KruskalMST class represents a data type for computing a
 * minimum spanning tree in an edge-weighted graph.
 * The edge weights can be positive, zero, or negative and need not
 * be distinct. If the graph is not connected, it computes a minimum
 * spanning forest, which is the union of minimum spanning tress
 * in each connected component. The weight() method returns the
 * weight of a minimum spanning tree and the edges() method
 * returns its edges.
 * This implementation uses Kruskal's algorithm and the union-find
 * data type.
 * The constructor takes time proportional to E*logV and extra space
 * (not including the graph) proportional to V, where V is the number
 * of vertices and E is the number of edges.
 * Afterwards, the weight() and edges() methods take constant time.
 * For additional documentation, see <href="/algs4/44sp">
 *
 * Execution:       java KruskalMST INPUT.TXT
 *                  %  java KruskalMST tinyEWG.txt 
 *                  0-7 0.16000
 *                  2-3 0.17000
 *                  1-7 0.19000
 *                  0-2 0.26000
 *                  5-7 0.28000
 *                  4-5 0.35000
 *                  6-2 0.40000
 *                  1.81000
 *                
 *                  % java KruskalMST mediumEWG.txt
 *                  168-231 0.00268
 *                  151-208 0.00391
 *                  7-157   0.00516
 *                  122-205 0.00647
 *                  8-152   0.00702
 *                  156-219 0.00745
 *                  28-198  0.00775
 *                  38-126  0.00845
 *                  10-123  0.00886
 *                  ...
 *                  10.46351
 * Dependencies:    
 * Data File:       tinyEWG.txt, mediumEWG.txt, largeEWG.txt
 * Author:          caiguochu
 * Time:            2015-03-18
 */
public class KruskalMST
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private Queue<Edge> mst;    // edges in MST
    private double weight;      // total weight of MST


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Computes a minimum spanning tree (or forest) of an edge-weighted graph.
     * @param G the edge-weighted graph
     */
    public KruskalMST(EdgeWeightedGraph G)
    {
        mst = new Queue<Edge>();
        MinPQ<Edge> pq = new MinPQ<Edge>(G.V());
        for (Edge e : G.edges()) pq.insert(e);
        UF uf = new UF(G.V());
        while (!pq.isEmpty() && mst.size() < G.V() - 1)
        {
            Edge e = pq.delMin();
            int v = e.either(), w = e.other(v);
            if (!uf.connected(v, w))
            {
                uf.union(v, w);
                mst.enqueue(e);
                weight += e.weight();
            }
        }
    }

    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the sum of the edge weights in a minimum spanning tree (or forest).
     * @return the sum of the edge weights in a minimum spanning tree (or forest)
     */
    public double weight() {    return weight;  }

    /**
     * Returns the edges in a minimum spanning tree (or forest).
     * @return the edges in a minimum spanning tree (or forest) as
     *      an iterable of edges
     */
    public Iterable<Edge> edges() { return mst; }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the KruskalMST data type
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        EdgeWeightedGraph G = new EdgeWeightedGraph(in);
        KruskalMST mst = new KruskalMST(G);
        for (Edge e : mst.edges())
            StdOut.println(e);
        StdOut.printf("%.5f\n", mst.weight());       
    }
}