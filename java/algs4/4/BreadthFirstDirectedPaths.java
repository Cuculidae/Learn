/*
 * The BreadthFirstDirectedPaths class represents a data type for finding
 * shortest paths (number of edges) from a source vertex s 
 * (or set of source vertices) to every other vertex in the digraph.
 * This implementation uses breadth-first search.
 * The constructor takes time proportional to V + E,
 * where V is the number of vertices and E is the number of edges.
 * It uses extra space (not including the digraph) proportional to V.
 * For additional documentation, see <href="/algs4/41graph">
 *
 * Execution:       java BreadthFirstDirected INPUT.TXT SOURCE_VERTEX
 *                  % java BreadthFirstDirectedPaths tinyDG.txt 3
 *                  3 to 0 (2):  3->2->0
 *                  3 to 1 (3):  3->2->0->1
 *                  3 to 2 (1):  3->2
 *                  3 to 3 (0):  3
 *                  3 to 4 (2):  3->5->4
 *                  3 to 5 (1):  3->5
 *                  3 to 6 (-):  not connected
 *                  3 to 7 (-):  not connected
 *                  3 to 8 (-):  not connected
 *                  3 to 9 (-):  not connected
 *                  3 to 10 (-):  not connected
 *                  3 to 11 (-):  not connected
 *                  3 to 12 (-):  not connected
 *
 * Dependencies:    Digraph.java, Queue.java, Stack.java, In.java, StdOut.java
 * Data File:       tinyDG.txt, mediumDG.txt
 * Author:          caiguochu
 * Time:            2015-03-07
 */
public class BreadthFirstDirectedPaths
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private final int INFINITY = Integer.MAX_VALUE;
    private boolean[] marked; // marked[v] = is there an s->v path ?
    private int[] edgeTo;     // edgeTo[v] = last edge on shortest s->v path
    private int[] distTo;     // distTo[v] = length of shortest s->v path


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Computes the shortest path from s to every other vertex in digraph G
     * @param G the digraph
     */
    public BreadthFirstDirectedPaths(Digraph G, int s)
    {
        int V = G.V();
        marked = new boolean[V];
        edgeTo = new int[V];
        distTo = new int[V];
        for (int v = 0; v < V; v++) distTo[v] = INFINITY;
        bfs(G, s);
    }

    /**
     * Computes the shortest path from any one of the source vertices in sources
     * to every other vertex in digraph G
     * @param G the digraph
     * @param sources the source vertices
     */
    public BreadthFirstDirectedPaths(Digraph G, Iterable<Integer> sources)
    {
        int V = G.V();
        marked = new boolean[V];
        edgeTo = new int[V];
        distTo = new int[V];
        for (int v = 0; v < V; v++) distTo[v] = INFINITY;
        bfs(G, sources);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // breadth first search from single source
    private void bfs(Digraph G, int s)
    {
        Queue<Integer> q = new Queue<Integer>();
        distTo[s] = 0;
        q.enqueue(s);
        while (!q.isEmpty())
        {
            int v = q.dequeue();
            marked[v] = true;
            for (int w : G.adj(v))
                if (!marked[w])
                {
                    edgeTo[w] = v;
                    distTo[w] = distTo[v] + 1;
                    q.enqueue(w);
                }
        }
    }

    // breadth first search from multiple sources
    private void bfs(Digraph G, Iterable<Integer> sources)
    {
        Queue<Integer> queue = new Queue<Integer>();
        for (int s : sources)
        {
            queue.enqueue(s);
            distTo[s] = 0;
        }
        while (!queue.isEmpty())
        {
            int v = queue.dequeue();
            marked[v] = true;
            for (int w : G.adj(v))
                if (!marked[w])
                {
                    edgeTo[w] = v;
                    distTo[w] = distTo[v] + 1;
                    queue.enqueue(w);
                }
        }
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Is there a directed path from the source s (or sources) to vertex v ?
     * @param v the vertex
     * @return true if there is a directed path, false otherwise
     */
    public boolean hasPathTo(int v) {   return marked[v];   }

    /**
     * Returns the number of edges in a shortest path from the source s
     * (or sources) to vertex v ?
     * @param v the vertex
     * @return the number of edges in a shortest path
     */
    public int distTo(int v) {  return distTo[v];   }

    /**
     * Returns a shortest path from s (or sources) to v or null if no such path
     * @param v the vertex
     * @return the sequence of vertices on a shortest path, as an Iterable
     */
    public Iterable<Integer> pathTo(int v)
    {
        if (!marked[v]) return null;
        Stack<Integer> path = new Stack<Integer>();
        int x;
        for (x = v; distTo[x] != 0; x = edgeTo[x])
            path.push(x);
        path.push(x);
        return path;
    }
     

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the BreadthFistDirected data type
    public static void main(String[] args)
    {
        Digraph G = new Digraph(new In(args[0]));
        int s = Integer.parseInt(args[1]);
        BreadthFirstDirectedPaths bfs = new BreadthFirstDirectedPaths(G, s);
        for (int v = 0; v < G.V(); v++)
        {    
            if (bfs.hasPathTo(v))
            {
                StdOut.printf("%d to %d (%d):    ", s, v, bfs.distTo(v));
                for (int x : bfs.pathTo(v))
                {
                    if (x == s) StdOut.print(x);
                    else        StdOut.print("->" + x);
                }
                StdOut.println();
            }
            else
                StdOut.printf("%d to %d (-):  not connected\n", s, v);
        }
    }
}