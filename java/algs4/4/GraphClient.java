/*
 * Typical graph-processing code.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/41undirected">
 *
 * Execution:		java GraphClient INPUT.TXT
 *                  % java GraphClient tinyG.txt
 *                  13 13
 *                  0: 6 2 1 5 
 *                  1: 0 
 *                  2: 0 
 *                  3: 5 4 
 *                  4: 5 6 3 
 *                  5: 3 4 0 
 *                  6: 0 4 
 *                  7: 8 
 *                  8: 7 
 *                  9: 11 10 12 
 *                  10: 9 
 *                  11: 9 12 
 *                  12: 11 9 
 *
 *                  vertex of maximum degree = 4
 *                  average degree           = 2
 *                  number of self loops     = 0
 *
 * Dependencies:	Graph.java, In.java, StdOut.java
 * Data File:		tinyG.txt, mediumG.txt, largeG.txt
 * Author:			caiguochu
 * Time:			2015-02-23
 */
public class GraphClient
{
	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private GraphClient() {}; // This class should not bean instantiated


	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
	// degree of v 
    public static int degree(Graph G, int v) { 
        int degree = 0;
        for (int w : G.adj(v)) degree++;
        return degree;
    }

    // maximum degree 
    public static int maxDegree(Graph G) {
        int max = 0;
        for (int v = 0; v < G.V(); v++)
            if (degree(G, v) > max)
                max = degree(G, v);
        return max;
    }

    // average degree
    public static int avgDegree(Graph G) {
        // each edge incident on two vertices
        return 2 * G.E() / G.V();
    }

    // number of self-loops
    public static int numberOfSelfLoops(Graph G) {
        int count = 0;
        for (int v = 0; v < G.V(); v++)
            for (int w : G.adj(v))
                if (v == w) count++;
        return count/2;   // self loop appears in adjacency list twice
    } 
	 

	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
    public static void main(String[] args) {
        In in = new In(args[0]);
        Graph G = new Graph(in);
        StdOut.println(G);
        StdOut.println("vertex of maximum degree = " + maxDegree(G));
        StdOut.println("average degree           = " + avgDegree(G));
        StdOut.println("number of self loops     = " + numberOfSelfLoops(G));

    }
}