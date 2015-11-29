/*
 * The EdgeWeightedDirectedCycle class represents a data type for
 * determining whether a edge-weighted digraph has a directed cycle.
 * The hasCycle operation determines whether the edge-weighted digraph has
 * a directed cycle and, if so, the cycle operation returns one.
 * This implementation uses depth-first search.
 * The constructor takes time proportional to V + E(in the worst case),
 * where V is the number of vertices and E is the number of edges.
 * Afterwards, the hasCycle and cycle operation takes constant time;
 * See Topological to compute a topological order if the edge-weighted digraph is acyclic.
 * For additional documentation, see <href="/algs4/42digraph">
 *
 * Execution:       java EdgeWeightedDirectedCycle INPUT.TXT 
 * Dependencies:    Stack.java, DirectedEdge.java, EdgeWeightedDigraph.java, In.java, StdOut.java
 * Data File:       tinyEWD.txt, tinyEWDAG.txt
 * Author:          caiguochu
 * Time:            2015-03-26
 */
public class EdgeWeightedDirectedCycle
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private boolean[] marked;
    private boolean[] onStack;
    private int[] edgeTo;
    private Stack<Integer> cycle;


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Determines whether the edge-weighted digraph G has a directed cycle, and if so,
     * finds such a cycle.
     * @param G the edge-weighted digraph
     */
    public EdgeWeightedDirectedCycle(EdgeWeightedDigraph G)
    {
        marked = new boolean[G.V()];
        onStack = new boolean[G.V()];
        edgeTo = new int[G.V()];
        for (int v = 0; v < G.V(); v++)
            if (!marked[v]) dfs(G, v);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    private void dfs(EdgeWeightedDigraph G, int v)
    {
        marked[v] = true;
        onStack[v] = true;
        for (DirectedEdge e : G.adj(v))
        {
            int w = e.to();
            if (cycle != null)  return;
            if (!marked[w])
            {
                edgeTo[w] = v;
                dfs(G, w);
            }
            else if (onStack[w])
            {
                cycle = new Stack<Integer>();
                for (int x = v; x != w; x = edgeTo[x])
                    cycle.push(x);
                cycle.push(w);
                cycle.push(v);
            }
        }
        onStack[v] = false;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Does the edge-weighted digraph have a directed cycle ?
     * @return true if the edge-weighted digraph has a directed cycle, false otherwise
     */
    public boolean hasCycle() { return cycle != null;   }

    /**
     * Returns a directed cycle if the edge-weighted digraph has a directed cycle, and null otherwise
     * @return a directed cycle (as an iterable) if the edge-weighted digraph has a directed cycle
     * and null otherwise.
     */
    public Iterable<Integer> cycle()
    {   return cycle;    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the EdgeWeightedDirectedCycle data type
    public static void main(String[] args)
    {
        EdgeWeightedDigraph G = new EdgeWeightedDigraph(new In(args[0]));
        EdgeWeightedDirectedCycle c = new EdgeWeightedDirectedCycle(G);

        if (c.hasCycle())
        {
            StdOut.print("Cycle: ");
            for (int v : c.cycle())
                StdOut.print(v + " ");
            StdOut.println();
        }
        else
            StdOut.println("No Cycle");        
    }
}