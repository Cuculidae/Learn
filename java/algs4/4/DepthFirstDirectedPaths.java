/*
 * The DepthFirstDirectedPaths class represents a data type for finding
 * directed paths from a source vertex s to every
 * other vertex in the digraph.
 * This implementation uses depth-first search.
 * This implementation uses depth-first search.
 * The constructor takes time proportional to V + E,
 * where V is the number of vertices and E is the number of edges.
 * It uses extra space (not including the graph) proportional to V.
 * For additional documentation, see <href="/algs4/41graph">
 *
 * Execution:       java DepthFirstDirectedPaths INPUT.TXT SOURCE_VERTEX
 *                  % java DepthFirstDirectedPaths tinyDG.txt 3
 *                  3 to 0:  3-5-4-2-0
 *                  3 to 1:  3-5-4-2-0-1
 *                  3 to 2:  3-5-4-2
 *                  3 to 3:  3
 *                  3 to 4:  3-5-4
 *                  3 to 5:  3-5
 *                  3 to 6:  not connected
 *                  3 to 7:  not connected
 *                  3 to 8:  not connected
 *                  3 to 9:  not connected
 *                  3 to 10:  not connected
 *                  3 to 11:  not connected
 *                  3 to 12:  not connected
 *
 * Dependencies:    Digraph.java, Stack.java, In.java, StdOut.java
 * Data File:       tinyDG.txt, mediumDG.txt
 * Author:          caiguochu
 * Time:            2015-03-07
 */
public class DepthFirstDirectedPaths
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private boolean[] marked; // marked[v] = true if v is reachable from s
    private int[] edgeTo;     // edgeTo[v] = last edge on path from s to v
    private int s;            // source vertex


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Computes a directed path from s to every other vertex in digraph G
     * @param G the digraph
     * @param s the source vertex
     */
    public DepthFirstDirectedPaths(Digraph G, int s)
    {
        this.s = s;
        int V = G.V();
        marked = new boolean[V];
        edgeTo = new int[V];
        dfs(G, s);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // depth first search from v
    private void dfs(Digraph G, int v)
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
     * Is there a directed path from the source vertex s to vertex v ?
     * @param v the vertex
     * @return true if there is a directed path from the source
     *      vertex s to vertex v, false otherwise
     */
    public boolean hasPathTo(int v) {   return marked[v];   }

    /**
     * Returns a directed path from the source vertex s to vertex v, or
     * null if no such path.
     * @param v the vertex
     * @return the sequence of vertices on a directed path from the source vertex
     *      s to vertex v, as an Iterable
     */
    public Iterable<Integer> pathTo(int v)
    {
        if (!marked[v]) return null;
        Stack<Integer> path = new Stack<Integer>();
        for (int x = v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit test the DepthFirstDirectedPaths data type
    public static void main(String[] args)
    {
        Digraph G = new Digraph(new In(args[0]));
        int s = Integer.parseInt(args[1]);
        DepthFirstDirectedPaths dfs = new DepthFirstDirectedPaths(G, s);
        for (int v = 0; v < G.V(); v++)
        {    

            StdOut.printf("%d to %d:    ", s, v);
            if (dfs.hasPathTo(v))
            {
                for (int x : dfs.pathTo(v))
                {
                    if (x == s) StdOut.print(x);
                    else        StdOut.print("-" + x);
                }
                StdOut.println();
            }
            else
                StdOut.println("not connected");
        }
    }
}