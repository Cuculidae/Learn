/*
 * The GabowSCC class represents a data type for
 * determining the strong components in a digraph.
 * The id operation determines in which strong component
 * a given vertex lies; the areStrongConnected operation
 * determines whether two vertices are in the same strong component;
 * and the count operation determines the number of strong components.
 * This implementation uses the Gabow's algorithm.
 * The constructor takes time proportional to V + E(in the worst case),
 * where V is the number of vertices and E is the number of edges.
 * Afterwards, the id, count, and areStronglyConnected operations take constant time.
 * For alternate implementations of the same API, see KosarajuSharirSCC and TarjanSCC.
 * For additional documentation, see <href="/algs4/42digraph">
 *
 * Execution:       java GabowSCC INPUT.TXT
 *                  % java GabowSCC tinyDG.txt
 *                  5 components
 *                  1 
 *                  0 2 3 4 5 
 *                  9 10 11 12 
 *                  6 8 
 *                  7
 *
 *                  % java GabowSCC mediumDG.txt 
 *                  10 components
 *                  21 
 *                  2 5 6 8 9 11 12 13 15 16 18 19 22 23 25 26 28 29 30 31 32 33 34 35 37 38 39 40 42 43 44 46 47 48 49 
 *                  14 
 *                  3 4 17 20 24 27 36 
 *                  41 
 *                  7 
 *                  45 
 *                  1 
 *                  0 
 *                  10 
 *
 *                  % java -Xss50m GabowSCC largeDG.txt 
 *                  25 components
 *                  7 11 32 36 61 84 95 116 121 128 230   ...
 *                  28 73 80 104 115 143 149 164 184 185  ...
 *                  38 40 200 201 207 218 286 387 418 422 ...
 *                  12 14 56 78 87 103 216 269 271 272    ...
 *                  42 48 112 135 160 217 243 246 273 346 ...
 *                  46 76 96 97 224 237 297 303 308 309   ...
 *                  9 15 21 22 27 90 167 214 220 225 227  ...
 *                  74 99 133 146 161 166 202 205 245 262 ...
 *                  43 83 94 120 125 183 195 206 244 254  ...
 *                  1 13 54 91 92 93 106 140 156 194 208  ...
 *                  10 39 67 69 131 144 145 154 168 258   ...
 *                  6 52 66 113 118 122 139 147 212 213   ...
 *                  8 127 150 182 203 204 249 367 400 432 ...
 *                  63 65 101 107 108 136 169 170 171 173 ...
 *                  55 71 102 155 159 198 228 252 325 419 ...
 *                  4 25 34 58 70 152 172 196 199 210 226 ...
 *                  2 44 50 88 109 138 141 178 197 211    ...
 *                  57 89 129 162 174 179 188 209 238 276 ...
 *                  33 41 49 119 126 132 148 181 215 221  ...
 *                  3 18 23 26 35 64 105 124 157 186 251  ...
 *                  5 16 17 20 31 47 81 98 158 180 187    ...
 *                  24 29 51 59 75 82 100 114 117 134 151 ...
 *                  30 45 53 60 72 85 111 130 137 142 163 ...
 *                  19 37 62 77 79 110 153 352 353 361    ...
 *                  0 68 86 123 165 176 193 239 289 336   ... 
 *
 * Dependencies:    Digraph.java, Stack.java, Queue.java, In.java, StdOut.java
 * Data File:       tinyDG.txt, mediumDG.txt, largeDG.txt
 * Author:          caiguochu
 * Time:            2015-03-09
 */
public class GabowSCC
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private boolean[] marked;      // marked[v] = has v been visited ?
    private int[] id;              // id[v] = id of strong component containing v
    private int[] preorder;        // preorder[v] = preorder of v
    private int pre;               // preorder number counter
    private int count;             // number of strong connected components
    private Stack<Integer> stack1; //
    private Stack<Integer> stack2; //


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Computes the strong components of the digraph G
     * @param G the digraph
     */
    public GabowSCC(Digraph G)
    {
        int V = G.V();
        marked = new boolean[V];
        id = new int[V];
        preorder = new int[V];
        stack1 = new Stack<Integer>();
        stack2 = new Stack<Integer>();
        for (int v = 0; v < V; v++)
            if (!marked[v]) dfs(G, v);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    private void dfs(Digraph G, int v)
    {
        marked[v] = true;
        id[v] = -1;
        preorder[v] = pre++;
        stack1.push(v);
        stack2.push(v);
        for (int w : G.adj(v))
        {
            if (!marked[w]) dfs(G, w);
            else if (id[w] == -1)
                while (preorder[stack2.peek()] > preorder[w])
                    stack2.pop();
        }
        // found strong component containing v
        if (stack2.peek() == v)
        {
            stack2.pop();
            int w;
            do {
                w = stack1.pop();
                id[w] = count;
            } while (w != v);
            count++;
        }
    }

    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the number of strong components
     * @return the number of strong components
     */
    public int count() {    return count;   }
    
    /**
     * Returns the component id of the strong component containing vertex v
     * @param v the vertex
     * @return the component id of the strong component containing vertex v
     */
    public int id(int v) {  return id[v];   }
    
    /**
     * Are vertices v and w in the same strong component 
     * @param v one vertex
     * @param w the other vertex
     * @return true if vertices v and w are in the same
     *      strong component, and false otherwise.
     */
    public boolean areStrongConnected(int v, int w) {    return id[v] == id[w];  }
         

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the GabowSCC data type
    public static void main(String[] args)
    {
        Digraph G = new Digraph(new In(args[0]));
        GabowSCC scc = new GabowSCC(G);

        // number of connected components
        int M = scc.count();
        StdOut.println(M + " components");

        // compute list of vertices in each strong component
        Queue<Integer>[] components = (Queue<Integer>[]) new Queue[M];
        for (int i = 0; i < M; i++)
            components[i] = new Queue<Integer>();
        for (int v = 0; v < G.V(); v++)
            components[scc.id(v)].enqueue(v);

        // print results
        for (int i = 0; i < M; i++)
        {   
            while (!components[i].isEmpty())
                        StdOut.print(components[i].dequeue() + " ");
                    StdOut.println();
        }        
    }
}