/*
 * The SymbolDigraph class represents an directed digraph, where the
 * vertex names are arbitrary strings.
 * By providing mappings between string vertex names and integers,
 * it serves as a wrapper around the Digraph data type, which assumes 
 * the vertex names are integers between 0 and V - 1.
 * It also supports initializing a symbol digraph from a file.
 * This implementation uses an ST to map from strings to integers,
 * an array to map from integers to strings, and a Digraph to store
 * the underlying digraph.
 * The index and contains operations take time 
 * proportional to log V, where V is the number of vertices.
 * The name operation takes constant time.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/42directed">
 *
 * Execution:       None
 * Dependencies:    ST.java, Digraph.java, In.java, StdIn.java, StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-02-27
 */
public class SymbolDigraph
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private ST<String, Integer> st; // String => Index
    private String[] keys;          // Index = > String
    private Digraph G;              // the underlying directed graph using integer vertices


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public SymbolDigraph(String filename, String delimiter)
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

        // Second pass builds the digraph by connecting first vertex on 
        // each line to all others
        G = new Digraph(st.size());
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
     * Does the digraph contains the vertex named s
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
     * Returns the digraph associated with the symbol digraph. It's the client's responsibility
     * not to mutate the digraph
     * @return the digraph associated with the symbol digraph
     */
    public Digraph G() {  return G;   }
     

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the SymbolDigraph data type
    public static void main(String[] args)
    {
        String filename = args[0];
        String delimiter = args[1];
        SymbolDigraph sg = new SymbolDigraph(filename, delimiter);
        Digraph G = sg.G();
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