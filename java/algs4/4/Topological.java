/*
 * The Topological class represents a data type for
 * determining a topological order of a directed acyclic graph(DAG).
 * Recall, a digraph has topological order if and only if it is a DAG.
 * The hasOrder operation determines whether the digraph has
 * a topological order, and if so, the order operation returns one.
 * This implementation uses depth-first search.
 * The constructor takes time proportional to V + E(in the worst case),
 * where V is the number of vertices and E is the number of edges.
 * Afterwards, the hasOrder and order operation takes constant time.
 * See DirectedCycle and EdgeWeightedDirectedCycle to compute a
 * directed cycle if the digraph is not a DAG. TopologicalQ is
 * another implementation.
 * For additional documentation, see <href="/algs4/42digraph">
 *
 * Execution:       java Topological INPUT.TXT DELIMITER
 *                  % java Topological jobs.txt "/"
 *                  Calculus
 *                  Linear Algebra
 *                  Introduction to CS
 *                  Programming Systems
 *                  Algorithms
 *                  Theoretical CS
 *                  Artificial Intelligence
 *                  Machine Learning
 *                  Neural Networks
 *                  Robotics
 *                  Scientific Computing
 *                  Computational Biology
 *                  Databases
 *
 * Dependencies:    Digraph.java, DirectedCycle.java, DepthFirstOrder.java, In.java, StdOut.java
 * Data File:       jobs.txt
 * Author:          caiguochu
 * Time:            2015-03-05
 */

public class Topological
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    Iterable<Integer> order; // topological order


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Determines whether the digraph G has a topological order and, if so,
     * finds such a topological order.
     * @param G the digraph
     */
    public Topological(Digraph G)
    {
        DirectedCycle cycleFinder = new DirectedCycle(G);
        if (!cycleFinder.hasCycle())
        {
            DepthFirstOrder dfs = new DepthFirstOrder(G);
            order = dfs.reversePost();
        }
    }

    /**
     * Determines whether the edge-weighted digraph G has a topological
     * order and, if so, finds such an order.
     * @param G the edge-weighted digraph
     */
    public Topological(EdgeWeightedDigraph G)
    {
        EdgeWeightedDirectedCycle finder = new EdgeWeightedDirectedCycle(G);
        if (!finder.hasCycle())
        {
            DepthFirstOrder dfs = new DepthFirstOrder(G);
            order = dfs.reversePost();
        }
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Does the digraph have a topological order ?
     * @return true if the digraph has a topolocial order (or equivalently
     *      if the digraph is a DAG), and false otherwise.
     */
    public boolean hasOrder() {    return order != null;   }

    /**
     * Returns a topological order if the digraph has topological order, 
     * and null otherwise.
     * @return a topological order of the vertices (as an iterable) if the
     *      digraph has a topological order (or equivalently, if the digraph is a DAG)
     *      and null otherwise.
     */
    public Iterable<Integer> order() {  return order;   }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the Topological data type
    public static void main(String[] args)
    {
        SymbolDigraph sg = new SymbolDigraph(args[0], args[1]);
        TopologicalQ top = new TopologicalQ(sg.G());
        for (int v : top.order())
            StdOut.println(sg.name(v));
    }
}