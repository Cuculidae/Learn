/*
 *
 *
 * Execution:       
 * Dependencies:    
 * Data File:       tinyEWDAG.txt
 * Author:          caiguochu
 * Time:            2015-03-26
 */
public class AcyclicSP
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private double[] distTo;
    private DirectedEdge[] edgeTo;


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public AcyclicSP(EdgeWeightedDigraph G, int s)
    {
        int V = G.V();
        distTo = new double[V];
        edgeTo = new DirectedEdge[V];
        for (int v = 0; v < V; v++) distTo[v] = Double.POSITIVE_INFINITY;
        distTo[s] = 0.0;
        Topological tp = new Topological(G);
        if (!tp.hasOrder())
        {
            StdOut.println("EdgeWeightedDigraph is not acyclic!");
            return;
        }
        for (int v : tp.order())
            relax(G, v);
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
    // Unit-test the AcyclicSP data type
    public static void main(String[] args)
    {
        EdgeWeightedDigraph G = new EdgeWeightedDigraph(new In(args[0]));
        int s = Integer.parseInt(args[1]);
        AcyclicSP sp = new AcyclicSP(G, s);
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