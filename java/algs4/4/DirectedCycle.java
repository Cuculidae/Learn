/*
 * The DirectedCycle class represents a data type for
 * determining whether a digraph has a directed cycle.
 * The hasCycle operation determines whether the digraph has
 * a directed cycle and, if so, the cycle operation returns one.
 * This implementation uses depth-first search.
 * The constructor takes time proportional to V + E(in the worst case),
 * where V is the number of vertices and E is the number of edges.
 * Afterwards, the hasCycle and cycle operation takes constant time;
 * See Topological to compute a topological order if the digraph is acyclic.
 * For additional documentation, see <href="/algs4/42digraph">
 *
 * Execution:       java DirectedCycle INPUT.TXT
 *                  % java DirectedCycle tinyDG.txt 
 *                  Cycle: 3 5 4 3 
 *                  %  java DirectedCycle tinyDAG.txt 
 *                  No cycle
 *
 * Dependencies:    Stack.java, Digraph.java, In.java, StdOut.java
 * Data File:       tinyDG.txt, tinyDAG.txt
 * Author:          caiguochu
 * Time:            2015-03-04
 */
public class DirectedCycle
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
     private boolean[] marked;     // marked[v] = has vertex v been marked ?
     private boolean[] onStack;    // onStack[v] = is vertex on the stack ? 
     private int[] edgeTo;         // edgeTo[v] = previous vertex on path to v
     private Stack<Integer> cycle; // cycle of vertices


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Determines whether the digraph G has a directed cycle, and if so,
     * finds such a cycle.
     * @param G the digraph
     */
    public DirectedCycle(Digraph G)
    {
        int V = G.V();
        marked = new boolean[V];
        onStack = new boolean[V];
        edgeTo = new int[V];
        for (int v = 0; v < V; v++)
            if (!marked[v]) dfs(G, v);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // check that algorithm computes either the topological order or finds a directed cycle
    private void dfs(Digraph G, int v)
    {
        marked[v] = true;
        onStack[v] = true;
        for (int w : G.adj(v))
        {
            if (this.hasCycle())    return;
            else if (!marked[w])
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
     * Does the digraph have a directed cycle ?
     * @return true if the digraph has a directed cycle, false otherwise
     */
    public boolean hasCycle() { return cycle != null;   }

    /**
     * Returns a directed cycle if the digraph has a directed cycle, and null otherwise
     * @return a directed cycle (as an iterable) if the digraph has a directed cycle
     * and null otherwise.
     */
    public Iterable<Integer> cycle()
    {   return cycle;    }
     

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the DirectedCycle data type
    public static void main(String[] args)
    {
        Digraph G = new Digraph(new In(args[0]));
        DirectedCycle c = new DirectedCycle(G);

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