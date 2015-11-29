/*
 * The TopologicalQ class represents a data type for 
 * determining a topological order of a directed acyclic graph (DAG).
 * Recall, a digraph has topological order if and only if it is a DAG.
 * The hasOrder operation determines whether the digraph has 
 * a topological order, and if so, the order operation returns one.
 * This implementation uses a Queue-based algorithm which maintains
 * a vertex-index array that keeps track of the indegree of each vertex.
 * The constructor takes time proportional to V + E(in the worst case),
 * where V is the number of vertices and E is the number of edges.
 * Afterwards, the hasOrder and order operation takes constant time.
 * See DirectedCycle and EdgeWeightedDirectedCycle to compute a
 * directed cycle if the digraph is not a DAG. Topological is 
 * another implementation.
 * For additional documentation, see <href="/algs4/42digraph">
 *
 * Execution:       java TopologicalQ INPUT.TXT DELIMITER
 *                  % java TopologicalQ jobs.txt "/"
 *                  Done reading jobs.txt
 *                  Introduction to CS
 *                  Calculus
 *                  Algorithms
 *                  Advanced Programming
 *                  Linear Algebra
 *                  Databases
 *                  Scientific Computing
 *                  Theoretical CS
 *                  Artificial Intelligence
 *                  Computational Biology
 *                  Machine Learning
 *                  Robotics
 *                  Neural Networks
 *
 * Dependencies:    Queue.java, Digraph.java, SymbolDigraph.java, In.java, StdOut.java
 * Data File:       jobs.txt
 * Author:          caiguochu
 * Time:            2015-03-08
 */
public class TopologicalQ
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private Queue<Integer> order; // vertices in topological order
    private int[] indegree;       // indegree[v] = indegree of vertex v
    private int[] rank;           // rank[v] = order where vertex v appears in order
    private int count;            // for computing ranks


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Determines whether the digraph G has a topological order, and if so,
     * find such a topological order.
     * @param G the digraph
     */
    public TopologicalQ(Digraph G)
    {
        int V = G.V();
        indegree = new int[V];
        rank = new int[V];
        order = new Queue<Integer>();

        for (int v = 0; v < V; v++)
            for (int w : G.adj(v))
                indegree[w]++;

        Queue<Integer> queue = new Queue<Integer>();
        for (int v = 0; v < V; v++)
            if (indegree[v] == 0) queue.enqueue(v);
        while (!queue.isEmpty())
        {
            int v = queue.dequeue();
            order.enqueue(v);
            rank[v] = count++;
            for (int w : G.adj(v))
            {
                indegree[w]--;
                if (indegree[w] == 0)
                    queue.enqueue(w);
            }
        }
        if (count != V) order = null;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Does the digraph has a topological order (equivalently the digraph is a DAG)
     * @return true if the digraph has a topological order (equivalently the digrph
     *      is a DAG), and false otherwise
     */
    public boolean hasOrder()           {   return order != null;   }

    /**
     * Returns the rank of the vertex v in topological order
     * @param v the vertex
     * @return the rank of the vertex v in topological order
     */ 
    public int rank(int v)              {   return rank[v];         }

    /**
     * Returns a topological order if the digraph has one,
     * and null otherwise.
     * @return a topological order of the vertices (as an Iterable) if the 
     *      digraph has topological order (or equivalently the digraph is a DAG),
     *      and null otherwise.
     */
    public Iterable<Integer> order()    {   return order;           }
     

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