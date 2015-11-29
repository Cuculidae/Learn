/*
 *
 *
 * Execution:       java EdgeWeightedDigraph INPUT.TXT
 *                  % java EdgeWeightedDigraph tinyEWD.txt
 *                  8 15
 *                  0: 0->2  0.26 0->4  0.38 
 *                  1: 1->3  0.29 
 *                  2: 2->7  0.34 
 *                  3: 3->6  0.52 
 *                  4: 4->7  0.37 4->5  0.35 
 *                  5: 5->1  0.32 5->7  0.28 5->4  0.35 
 *                  6: 6->4  0.93 6->0  0.58 6->2  0.40 
 *                  7: 7->3  0.39 7->5  0.28 
 *
 * Dependencies:    DirectedEdge.java, Bag.java, In.java, StdOut.java
 * Data File:       tinyEWD.txt
 * Author:          caiguochu
 * Time:            2015-03-23
 */
public class EdgeWeightedDigraph
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private final int V;
    private int E;
    private Bag<DirectedEdge>[] adj;

    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public EdgeWeightedDigraph(int V)
    {
        this.V = V;
        adj = (Bag<DirectedEdge>[]) new Bag[V];
        for (int v = 0; v < V; v++) adj[v] = new Bag<DirectedEdge>();
    }
    public EdgeWeightedDigraph(In in)
    {
        this(in.readInt());
        this.E = in.readInt();
        for (int i = 0; i < E; i++)
        {
            int v = in.readInt();
            int w = in.readInt();
            double weight = in.readDouble();
            DirectedEdge e = new DirectedEdge(v, w, weight);
            adj[v].add(e);
        }
    }

    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public int V() {    return V;   }
    public int E() {    return E;   }
    public Iterable<DirectedEdge> adj(int v) {  return adj[v];  }
    public void addEdge(int v, int w, double weight)
    {
        DirectedEdge e = new DirectedEdge(v, w, weight);
        adj[v].add(e);
    }
    public Iterable<DirectedEdge> edges()
    {
        Bag<DirectedEdge> bag = new Bag<DirectedEdge>();
        for (int v = 0; v < V; v++)
            for (DirectedEdge e : adj[v])
                bag.add(e);
        return bag;
    }
    public String toString()
    {
        StringBuilder s = new StringBuilder();
        String NEWLINE = System.getProperty("line.separator");
        s.append(V + " " + E + NEWLINE);
        for (int v = 0; v < V; v++)
        {
            s.append(v + ": ");
            for (DirectedEdge e : adj[v])
                s.append(e + " ");
            s.append(NEWLINE);
        }
        return s.toString();
    }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test EdgeWeightedDigraph data type
    public static void main(String[] args)
    {
        EdgeWeightedDigraph G = new EdgeWeightedDigraph(new In(args[0]));
        StdOut.println(G);
    }
}