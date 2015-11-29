/*
 *
 *
 * Execution:       java DijkstraSP INPUT.TXT SOURCE_VERTEX
 *                  % java DijkstraSP tinyEWD.txt 0
 *                  0 to 0 (0.00)  
 *                  0 to 1 (1.05)  0->4  0.38   4->5  0.35   5->1  0.32   
 *                  0 to 2 (0.26)  0->2  0.26   
 *                  0 to 3 (0.99)  0->2  0.26   2->7  0.34   7->3  0.39   
 *                  0 to 4 (0.38)  0->4  0.38   
 *                  0 to 5 (0.73)  0->4  0.38   4->5  0.35   
 *                  0 to 6 (1.51)  0->2  0.26   2->7  0.34   7->3  0.39   3->6  0.52   
 *                  0 to 7 (0.60)  0->2  0.26   2->7  0.34   
 *                
 *                  % java DijkstraSP mediumEWD.txt 0
 *                  0 to 0 (0.00)  
 *                  0 to 1 (0.71)  0->44  0.06   44->93  0.07   ...  107->1  0.07   
 *                  0 to 2 (0.65)  0->44  0.06   44->231  0.10  ...  42->2  0.11   
 *                  0 to 3 (0.46)  0->97  0.08   97->248  0.09  ...  45->3  0.12   
 *                  0 to 4 (0.42)  0->44  0.06   44->93  0.07   ...  77->4  0.11   
 *                  ...
 * Dependencies:    Stack.java, IndexMinPQ.java, DirectedEdge.java, EdgeWeightedDigraph.java,
 *                  In.java, StdOut.java
 * Data File:       tinyEWD.txt, mediumEWD.txt, largeEWD.txt
 * Author:          caiguochu
 * Time:            2015-03-26
 */
public class DijkstraSP
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private DirectedEdge[] edgeTo;
    private double[] distTo;
    private IndexMinPQ<Double> pq;


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public DijkstraSP(EdgeWeightedDigraph G, int s)
    {
        int V = G.V();
        distTo = new double[V];
        pq = new IndexMinPQ<Double>(V);
        edgeTo = new DirectedEdge[V];
        for (int v = 0; v < V; v++)
            distTo[v] = Double.POSITIVE_INFINITY;
        distTo[s] = 0.0;
        pq.insert(s, 0.0);
        while (!pq.isEmpty())
            relax(G, pq.delMin());
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    private void relax(EdgeWeightedDigraph G, int v)
    {
        for (DirectedEdge e : G.adj(v))
        {
            int w = e.to();
            if (distTo[w] > distTo[v] + e.weight())
            {
                distTo[w] = distTo[v] + e.weight();
                edgeTo[w] = e;
                if (pq.contains(w))     pq.change(w, distTo[w]);
                else                    pq.insert(w, distTo[w]);
            }
        }
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public boolean hasPathTo(int v) {   return distTo[v] != Double.POSITIVE_INFINITY;   }
    public Iterable<DirectedEdge> pathTo(int v)
    {
        if (!hasPathTo(v))  return null;
        Stack<DirectedEdge> path = new Stack<DirectedEdge>();
        for (DirectedEdge e = edgeTo[v]; e != null; e = edgeTo[e.from()])
            path.push(e);
        return path;
    }
    public double distTo(int v) {   return distTo[v];   }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the DijkstraSP data type 
    public static void main(String[] args)
    {
        EdgeWeightedDigraph G = new EdgeWeightedDigraph(new In(args[0]));
        int s = Integer.parseInt(args[1]);
        DijkstraSP sp = new DijkstraSP(G, s);
        for (int v = 0; v < G.V(); v++)
        {
            if (sp.hasPathTo(v))
            {
                StdOut.printf("%d to %d (%.2f)  ", s, v, sp.distTo(v));
                for (DirectedEdge e : sp.pathTo(v))
                    StdOut.print(e + " ");
                StdOut.println();
            }
            else
                StdOut.printf("%d to %d         no path%n", s, v);
        }
    }
}