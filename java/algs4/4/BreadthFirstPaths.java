/*
 * The BreadthFirstPaths class represents a data type for finding
 * shortest paths (number of edges) from a source vertex s(or a set
 * of source vertices) to every other vertex in an undirected graph.
 * This implementation uses breadth-first search.
 * The constructor takes time proportional to V + E,
 * where V is the number of vertices and E is the number of edges.
 * It uses extra space (not including the graph) proportional to V.
 * For additional documentation, see <href="/algs4/41graph">
 *
 * Execution:       java BreadthFirstPaths INPUT.TXT SOURCE_VERTEX
 *                  %  java Graph tinyCG.txt
 *                  6 8
 *                  0: 2 1 5 
 *                  1: 0 2 
 *                  2: 0 1 3 4 
 *                  3: 5 4 2 
 *                  4: 3 2 
 *                  5: 3 0
 *
 *                  %  java BreadthFirstPaths largeG.txt 0
 *                  0 to 0 (0):  0
 *                  0 to 1 (418):  0-932942-474885-82707-879889-971961-...
 *                  0 to 2 (323):  0-460790-53370-594358-780059-287921-...
 *                  0 to 3 (168):  0-713461-75230-953125-568284-350405-...
 *                  0 to 4 (144):  0-460790-53370-310931-440226-380102-...
 *                  0 to 5 (566):  0-932942-474885-82707-879889-971961-...
 *                  0 to 6 (349):  0-932942-474885-82707-879889-971961-... 
 *
 * Dependencies:    Graph.java, Queue.java, Stack.java, In.java, StdOut.java
 * Data File:       tinyCG.txt, mediumG.txt, largeG.txt
 * Author:          caiguochu
 * Time:            2015-02-24
 */
public class BreadthFirstPaths
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int INFINITY = Integer.MAX_VALUE;
    private boolean[] marked; // marked[v] = is there an s-v path ?
    private int[] edgeTo;     // edgeTo[v] = last edge on s-v path
    private int[] distTo;     // distTo[v] = number of edges on shortest s-v path


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Computes the shortest path between the source vertex s
     * every other vertex in the graph G
     * @param G the graph
     * @param s the source vertex
     */
    public BreadthFirstPaths(Graph G, int s)
    {
        int V = G.V();
        marked = new boolean[V];
        edgeTo = new int[V];
        distTo = new int[V];
        for (int v = 0; v < V; v++) distTo[v] = INFINITY;
        bfs(G, s);
    }

    /**
     * Computes the shortest path between any one of the source vertices in sources
     * and every other vertex in graph G
     * @param G the graph
     * @param sources the source vertices
     */
    public BreadthFirstPaths(Graph G, Iterable<Integer> sources)
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
    // breadth first search from a single source s
    private void bfs(Graph G, int s)
    {
        Queue<Integer> q = new Queue<Integer>();
        marked[s] = true;
        distTo[s] = 0;
        q.enqueue(s);
        while (!q.isEmpty())
        {
            int v = q.dequeue();
            for (int w : G.adj(v))
                if (!marked[w])
                {
                    marked[w] = true;
                    edgeTo[w] = v;
                    q.enqueue(w);
                }
        }
    }

    // breadth first search from multiple sources
    private void bfs(Graph G, Iterable<Integer> sources)
    {
        Queue<Integer> q = new Queue<Integer>();
        for (int s : sources)
        {
            marked[s] = true;
            q.enqueue(s);
            distTo[s] = 0;
        }
        while (!q.isEmpty())
        {
            int v = q.dequeue();
            for (int w : G.adj(v))
                if (!marked[w])
                {
                    edgeTo[w] = v;
                    distTo[w] = distTo[v] + 1;
                    q.enqueue(w);
                }
        }
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Is there a path between the source vertex s (or sources) and the vertex v
     * @param v the vertex
     * @return true if there is a path, and false otherwise
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
     * Returns a shortest path between the source vertex s (or sources) and v,
     * and null if no such path
     * @param v the vertex
     * @return the sequence of vertices on a shortest path, as an Iterable
     */
    public Iterable<Integer> pathTo(int v)
    {
        if (!hasPathTo(v)) return null;
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
    // Unit-test the BreadthFirstPaths data type
    public static void main(String[] args)
    {
        In in = new In(args[0]);
        Graph G = new Graph(in);
        int s = Integer.parseInt(args[1]);
        BreadthFirstPaths bfs = new BreadthFirstPaths(G, s);
        for (int v = 0; v < G.V(); v++)
        {
            if (bfs.hasPathTo(v))
            {
                StdOut.printf("%d to %d:  ", s, v);
                for (int x : bfs.pathTo(v))
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