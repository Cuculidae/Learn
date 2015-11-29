/*
 * The SymbolGraph class represents an undirected graph, where the
 * vertex names are arbitrary strings.
 * By providing mappings between string vertex names and integers,
 * it serves as a wrapper around the Graph data type, which assumes 
 * the vertex names are integers between 0 and V - 1.
 * It also supports initializing a symbol graph from a file.
 * This implementation uses an ST to map from strings to integers,
 * an array to map from integers to strings, and a Graph to store
 * the underlying graph.
 * The index and contains operations take time 
 * proportional to log V, where V is the number of vertices.
 * The name operation takes constant time.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/41undirected">
 *
 * Execution:       java SymbolGraph INPUT.TXT DELIMITER
 *                  % java SymbolGraph movies.txt "/"
 *                  Tin Men (1987)
 *                     Hershey, Barbara
 *                     Geppi, Cindy
 *                     Jones, Kathy (II)
 *                     Herr, Marcia
 *                     ...
 *                     Blumenfeld, Alan
 *                     DeBoy, David
 *                  Bacon, Kevin
 *                     Woodsman, The (2004)
 *                     Wild Things (1998)
 *                     Where the Truth Lies (2005)
 *                     Tremors (1990)
 *                     ...
 *                     Apollo 13 (1995)
 *                     Animal House (1978)
 *
 * Dependencies:    ST.java, Graph.java, In.java, StdIn.java, StdOut.java
 * Data File:       movies.txt, routes.txt
 * Author:          caiguochu
 * Time:            2015-02-27
 */
public class SymbolGraph
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private ST<String, Integer> st; // String => Index
    private String[] keys;          // Index = > String
    private Graph G;                // the underlying undirected graph using integer vertices


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public SymbolGraph(String filename, String delimiter)
    {
        st = new ST<String, Integer>();

        // First pass builds the index by reading strings to associate
        // distinct strings with an index
        In in = new In(filename);
        while (!in.isEmpty())
        {
            String[] a = in.readLine().split(delimiter);
            for (int i = 0; i < a.length; i++)
                if (!st.contains(a[i]))
                    st.put(a[i], st.size());
        }
        StdOut.println("Done reading " + filename);

        // inverted index to get string keys in an array
        keys = new String[st.size()];
        for (String name : st.keys())
            keys[st.get(name)] = name;

        // Second pass builds the graph by connecting first vertex on 
        // each line to all others
        G = new Graph(st.size());
        in = new In(filename);
        while (in.hasNextLine())
        {
            String[] a = in.readLine().split(delimiter);
            int v = st.get(a[0]);
            for (int i = 1; i < a.length; i++)
            {
                int w = st.get(a[i]);
                G.addEdge(v, w);
            }
        }
        
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Does the graph contains the vertex named s
     * @param s the name of a vertex
     * @return true if s is the name of a vertex, and false otherwise
     */
    public boolean contains(String s) { return st.contains(s);  }

    /**
     * Returns the integer associated with the vertex named s
     * @param s the name of the vertex
     * @return the integer (between 0 and V-1) associated with the vertex named s
     */
    public int index(String s) { return st.get(s);    }

    /**
     * Returns the name of the vertex associated with the integer v
     * @param v the integer corresponding to a vertex
     * @return the name of the vertex associated with the integer v
     */
    public String name(int v) { return keys[v]; }

    /**
     * Returns the graph associated with the symbol graph. It's the client's responsibility
     * not to mutate the graph
     * @return the graph associated with the symbol graph
     */
    public Graph G() {  return G;   }
     

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the SymbolGraph data type
    public static void main(String[] args)
    {
        String filename = args[0];
        String delimiter = args[1];
        SymbolGraph sg = new SymbolGraph(filename, delimiter);
        Graph G = sg.G();
        while (StdIn.hasNextLine())
        {
            String source = StdIn.readLine();
            if (sg.contains(source))
            {
                int s = sg.index(source);
                for (int v : G.adj(s))
                    StdOut.println("    " + sg.name(v));
            }
            else
            {
                StdOut.println("input not contains '" + source + "'");
            }
        }   
    }
}