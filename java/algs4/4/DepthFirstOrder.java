/*
 *
 *
 * Execution:       java DepthFirstOrder INPUT.TXT
 * Dependencies:    Digraph.java, EdgeWeightedDigraph.java, DirectedEdge.java, Queue.java, 
 *                  Stack.java, In.java, StdOut.java
 * Data File:       tinyDG.txt, tinyDAG.txt
 * Author:          caiguochu
 * Time:            2015-03-05
 */

public class DepthFirstOrder
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private boolean[] marked;
    private Queue<Integer> pre;
    private Queue<Integer> post;
    private Stack<Integer> reversePost;


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public DepthFirstOrder(Digraph G)
    {
       pre = new Queue<Integer>();
       post = new Queue<Integer>();
       reversePost = new Stack<Integer>();
       int V = G.V();
       marked = new boolean[V];
       for (int v = 0; v < V; v++)
           if (!marked[v]) dfs(G, v);
    }
    public DepthFirstOrder(EdgeWeightedDigraph G)
    {
       pre = new Queue<Integer>();
       post = new Queue<Integer>();
       reversePost = new Stack<Integer>();
       int V = G.V();
       marked = new boolean[V];
       for (int v = 0; v < V; v++)
           if (!marked[v]) dfs(G, v);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    private void dfs(Digraph G, int v)
    {
        marked[v] = true;
        pre.enqueue(v);
        for (int w : G.adj(v))
            if (!marked[w]) dfs(G, w);
        post.enqueue(v);
        reversePost.push(v);
    }
    private void dfs(EdgeWeightedDigraph G, int v)
    {
        marked[v] = true;
        pre.enqueue(v);
        for (DirectedEdge e : G.adj(v))
        {
            int w = e.to();
            if (!marked[w]) dfs(G, w);
        }
        post.enqueue(v);
        reversePost.push(v);
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public Iterable<Integer> pre() { return pre; }
    public Iterable<Integer> post() {   return post;    }
    public Iterable<Integer> reversePost() {    return reversePost; }
     

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    public static void main(String[] args)
    {
        Digraph G = new Digraph(new In(args[0]));
        DepthFirstOrder o = new DepthFirstOrder(G);
        StdOut.print("PreOrder: ");
        for (int v : o.pre())
            StdOut.print(v + " ");
        StdOut.println();
        StdOut.print("PostOrder: ");
        for (int v : o.post())
            StdOut.print(v + " ");
        StdOut.println();
        StdOut.print("ReversePostOrder: ");
        for (int v : o.reversePost())
            StdOut.print(v + " ");
        StdOut.println();
    }
}