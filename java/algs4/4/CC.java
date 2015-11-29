/*
 * The CC class represents a data type for 
 * determining the connected components in an undirected graph.
 * The id operation determines in which connected component
 * a given vertex lies; the connected operation
 * determines whether two vertices are in the same connected component;
 * the count operation determines the number of connected
 * components; and the size operation determines the number
 * of vertices in the connect component containing a given vertex.

 * The component identifier of a connected component is one of the
 * vertices in the connected component: two vertices have the same component
 * identifier if and only if they are in the same connected component.

 * This implementation uses depth-first search.
 * The constructor takes time proportional to V + E (in the worst case),
 * where V is the number of vertices and E is the number of edges.
 * Afterwards, the id, count, connected,
 * and size operations take constant time.
 * For additional documentation, see <href="/algs4/41graph">Section 4.1 of
 * Algorithms, 4th Edition
 *
 * Execution:       java CC INPUT.TXT
 *                  % java CC tinyG.txt
 *                  3 components
 *                  0 1 2 3 4 5 6
 *                  7 8 
 *                  9 10 11 12
 *
 * Dependencies:    Graph.java, Queue.java, In.java, StdOut.java
 * Data File:       tinyG.txt
 * Author:          caiguochu
 * Time:            2015-02-27
 */
public class CC
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private boolean[] marked; // marked[v] = has vertex v been marked ?
    private int[] id;         // id[v] = id of connected component containing v
    private int count;        // number of connected components


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Computes the connected components of the undirected graph G
     * @param G the undirected graph
     */
    public CC(Graph G)
    {
        int V = G.V();
        marked = new boolean[V];
        id = new int[V];
        for (int v = 0; v < V; v++)
        {
            if (!marked[v])
            {
                dfs(G, v);
                count++;
            }
        }
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // deapth first search
    private void dfs(Graph G, int v)
    {
        marked[v] = true;
        id[v] = count;
        for (int w : G.adj(v))
            if (!marked[w])
                dfs(G, w);
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the component id of the connected component containing vertex v
     * @param v the vertex
     * @return the component id of the connected component containing vertex v
     */
    public int id(int v) {  return id[v];   }

    /**
     * Returns the number of connected components
     * @return the number of connected components
     */
    public int count() {    return count;   }

    /** 
     * Are vertices v and w in the same connected component
     * @param v one vertex
     * @param w another vertex
     * @return true if vertices v and w are in the same component, false otherwise
     */
    public boolean areConnected(int v, int w) {  return id[v] == id[w];  }
     

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the CC data type
    public static void main(String[] args)
    {
        Graph G = new Graph(new In(args[0]));
        CC cc = new CC(G);

        // number of connected components
        int M = cc.count();
        StdOut.println(M + " components:");

        // computes lists of vertices in each component
        Queue<Integer>[] component = (Queue<Integer>[]) new Queue[M];
        for (int i = 0; i < M; i++)
            component[i] = new Queue<Integer>();
        for (int i = 0; i < G.V(); i++)
            component[cc.id(i)].enqueue(i);

        // print result
        for (int i = 0; i < M; i++)
        {
            StdOut.print("component " + i + " : ");
            for (int j : component[i])
                StdOut.print(j + " ");
            StdOut.println();
        }
    }
}
