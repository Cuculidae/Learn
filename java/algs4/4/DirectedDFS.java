/*
 * The DirectedDFS class represents a data type for
 * determining the vertices reachable from a given source vertex s
 * (or set of source vertices) in a digraph. For versions that find the paths,
 * see DepthFirstDirectedPaths and BreadthFirstDirectedPath.
 * This implementation uses depth-first search.
 * The constructor takes time proportional V + E(in the worst case),
 * where V is the number of vertices and E is the number of edges.
 * For additional documentation, see <a href="/algs4/41graph">
 *
 * Execution:       java DirectedDFS INPUT.TXT [SOURCE_VERTEX_1 [, SOURCE_VERTEX_2 [, ...]]
 *                  % java DirectedDFS tinyDG.txt 1
 *                  1
 *
 *                  % java DirectedDFS tinyDG.txt 2
 *                  0 1 2 3 4 5
 *
 *                  % java DirectedDFS tinyDG.txt 1 2 6
 *                  0 1 2 3 4 5 6 8 9 10 11 12 
 *
 * Dependencies:    Digraph.java, In.java, StdOut.java
 * Data File:       tinyDG.txt
 * Author:          caiguochu
 * Time:            2015-03-04
 */
public class DirectedDFS
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private boolean[] marked; // marked[v] = true if v is reachable


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Computes the vertices in digraph G that are
     * reachable from the source vertex s
     * @param G the digraph
     * @param s the source vertex
     */
    public DirectedDFS(Digraph G, int s)
    {
        marked = new boolean[G.V()];
        dfs(G, s);
    }

    /**
     * Computes the vertices in digraph G that are
     * reachable from any of the source vertices s
     * @param G the digraph
     * @param s the source vertices
     */
    public DirectedDFS(Digraph G, Iterable<Integer> s)
    {
        marked = new boolean[G.V()];
        for (int v : s)
            dfs(G, v);
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
                dfs(G, w);
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Is there a directed path from the source vertex ( or any
     * of the source vertices) and vertex v ?
     * @param v the vertex
     * @return true if there is a directed path, false otherwise
     */
    public boolean marked(int v) {  return marked[v];   }
     

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the DirectedDFS data type
    public static void main(String[] args)
    {
        Digraph G = new Digraph(new In(args[0]));
        Bag<Integer> s = new Bag<Integer>();
        for (int i = 1; i < args.length; i++)
            s.add(Integer.parseInt(args[i]));
        DirectedDFS dfs = new DirectedDFS(G, s);
        for (int v = 0; v < G.V(); v++)
            if (dfs.marked(v)) StdOut.print(v + " ");
        StdOut.println();
    }
}