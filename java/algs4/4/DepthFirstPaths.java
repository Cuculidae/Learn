/*
 * The DepthFirstPaths class represents a data type for finding
 * paths from a source vertex s to every other vertex
 * in an undirected graph.
 * <p>
 * This implementation uses depth-first search.
 * The constructor takes time proportional to V + E,
 * where V is the number of vertices and E is the number of edges.
 * It uses extra space (not including the graph) proportional to V.
 * <p>
 * For additional documentation, see <a href="/algs4/41graph">
 *
 * Execution:       java DepthFirstPaths INPUT.TXT VERTEX
 *                  % java DepthFirstPaths tinyCG.txt 0
 *                  0 to 0:  0
 *                  0 to 1:  0-2-1
 *                  0 to 2:  0-2
 *                  0 to 3:  0-2-3
 *                  0 to 4:  0-2-3-4
 *                  0 to 5:  0-2-3-5
 *
 * Dependencies:    Stack.java, Graph.java，In.java, StdOut.java
 * Data File:       tinyCG.txt
 * Author:          caiguochu
 * Time:            2015-02-23
 */

public class DepthFirstPaths
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private int[] edgeTo;     // edgeTo[v] = last edge on s-v path
    private boolean[] marked; // marked[v] = is there an s-v path ?
    private final int s;      // source vertex



    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Computes a path between s and every other vertex in graph G.
     * @param G the graph
     * @param s the source vertex
     */
    public DepthFirstPaths(Graph G, int s)
    {
        this.s = s;
        edgeTo = new int[G.V()];
        marked = new boolean[G.V()];
        dfs(G, s);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // depth first search from v
    private void dfs(Graph G, int v)
    {
        marked[v] = true;
        for (int w : G.adj(v))
            if (!marked[w])
            {
                edgeTo[w] = v;
                dfs(G, w);
            }
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Is there a path between the source vertex s and vertex v?
     * @param v the vertex
     * @return true if there is a path, false otherwise
     */
    public boolean hasPathTo(int v){    return marked[v];  }

    /**
     * Returns a path between the source vertex s and vertex v, or
     * null if no such path.
     * @param v the vertex
     * @return the sequence of vertices on a path between the source vertex
     *   s and vertex v, as an Iterable
     */
    public Iterable<Integer> pathTo(int v)
    {
        if (!hasPathTo(v)) return null;
        Stack<Integer> path = new Stack<Integer>();
        for (int x = v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }
     

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-tests the DepthFirstPaths data type.
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        Graph G = new Graph(in);
        int s = Integer.parseInt(args[1]);
        DepthFirstPaths dfs = new DepthFirstPaths(G, s);
        for (int v = 0; v < G.V(); v++)
        {
            if (dfs.hasPathTo(v))
            {
                StdOut.printf("%d to %d:  ", s, v);
                for (int x : dfs.pathTo(v))
                {
                    if (x == s) StdOut.print(x);
                    else        StdOut.print("-" + x);
                }
                StdOut.println();
            }
            else
            {
                StdOut.printf("%d to %d:  not connected\n", s, v);
            }
        }
    }
}