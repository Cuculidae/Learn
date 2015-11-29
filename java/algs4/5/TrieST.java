/*
 * The TrieST class represents an symbol table of key-value
 * pairs, with string keys and generic values.
 * It supports the usual put, get, contains,
 * delete, size, and is-empty methods.
 * It also provides character-based methods for finding the string
 * in the symbol table that is the longest prefix of a given prefix,
 * finding all strings in the symbol table that start with a given prefix,
 * and finding all strings in the symbol table that match a given pattern.
 * A symbol table implements the associative array abstraction:
 * when associating a value with a key that is already in the symbol table,
 * the convention is to replace the old value with the new value.
 * Unlike {@link java.util.Map}, this class uses the convention that
 * values cannot be null&mdash;setting the
 * value associated with a key to null is equivalent to deleting the key
 * from the symbol table.
 * <p>
 * This implementation uses a 256-way trie.
 * The put, contains, delete, and
 * longest prefix operations take time proportional to the length
 * of the key (in the worst case). Construction takes constant time.
 * The size, and is-empty operations take constant time.
 * Construction takes constant time.
 * <p>
 * For additional documentation, see <"http://algs4.cs.princeton.edu/52trie">
 * Section 5.2 of Algorithms, 4th Edition by Robert Sedgewick and Kevin Wayne.
 *
 * Execution:       java TrieST < INPUT
 *                  % java TrieST < shellsST.txt
 *                  keys(""):
 *                  by 4
 *                  sea 6
 *                  sells 1
 *                  she 0
 *                  shells 3
 *                  shore 7
 *                  the 5                     
 *
 *                  longestPrefixOf("shellsort"):
 *                  shell                    
 *
 *                  longestPrefixOf("quicksort"):
 *                  null                     
 *
 *                  keysWithPrefix("shor"):
 *                  shore                    
 *
 *                  keysThatMatch(".he.l."):
 *                  shells
 * Dependencies:    Queue.java, StdIn.java, StdOut.java
 * Data File:       shells.txt, shellsST.java
 * Author:          caiguochu
 * Time:            2015-07-14
 */
public class TrieST<Value>
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int R = 256;
    private int N;
    private Node root;

    private static class Node
    {
        private Node[] next = new Node[R];
        private Object val;
    }


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public TrieST() {}


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    private Node get(Node x, String key, int d)
    {
        if (x == null) return null;
        if (d == key.length()) return x;
        return get(x.next[key.charAt(d)], key, d+1);
    }
    private Node put(Node x, String key, Value val, int d)
    {
        if (x == null) x = new Node();
        if (d == key.length()) {
            x.val = val;
            ++N;
            return x;
        }
        char c = key.charAt(d);
        x.next[c] = put(x.next[c], key, val, d+1);
        return x;
    }
    private Node delete(Node x, String key, int d)
    {
        if (x == null)  return null;
        if (d == key.length()) {
            if (x.val != null) --N;
            x.val = null;
        } else {
            char c = key.charAt(d);
            x.next[c] = delete(x.next[c], key, d+1);
        }
        
        if (x.val != null)  return x;
        for (char c = 0; c < R; ++c)
            if (x.next[c] != null)  return x;
        return null;
    }
    private void collect(Node x, String pre, Queue<String> q)
    {
        if (x == null) return;
        if (x.val != null) q.enqueue(pre);
        for (char c = 0; c < R; ++c)
            collect(x.next[c], pre+c, q);
    }
    private void collect(Node x, String pre, String pat, Queue<String> q)
    {
        int d = pre.length();
        if (x == null)  return;
        if (d == pat.length() && x.val != null) q.enqueue(pre);
        if (d == pat.length()) return;

        char next = pat.charAt(d);
        for (char c = 0; c < R; ++c)
            if (next == '.' || next == c)
                collect(x.next[c], pre+c, pat, q);
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the number of key-value pairs in this symbol table.
     * @return the number of key-value pairs in this symbol table
     */
    public int size()
    {   return  N;  }

    /**
     * Is the symbol table empty ?
     * @return true if this symbol table is empty and
     *      false otherwise.
     */
    public boolean isEmpty()
    {   return root == null;    }

    /**
     * Does this symbol table contain the given key ?
     * @param key the key
     * @return true if this symbol table contains key and
     *      false otherwise.
     */
    public boolean contains(String key)
    {   return get(key) != null;    }

    /**
     * Returns the value associated with the given key.
     * @param key the key
     * @return the value associated with the given key
     */
    public Value get(String key)
    {
        Node x = get(root, key, 0);
        return x == null ? null : (Value) x.val;
    }

    /**
     * Inserts the key-value pair into the symbol table, overwriting the old value
     * with the new value if the key is already in the symbol table.
     * @param key the key
     * @param val the value
     */
    public void put(String key, Value val)
    {   root = put(root, key, val, 0);  }

    /**
     * Removes the key from the set if the key is present.
     * @param key the key
     */
    public void delete(String key)
    {   root = delete(root, key, 0);    }

    /**
     * Returns the string in the symbol table that is the longest prefix of query,
     * or null, if no such string.
     * @param query the query string
     * @return the string in the symbol table that is the longest prefix of query,
     *      or null if no such string
     */
    public String longestPrefixOf(String query)
    {
        if (root == null) return null;
        Node x = root;
        int len = query.length();
        int d = 0, e = -1;
        while (d <= len) {
            char c = query.charAt(d++);
            if (x.next[c] == null) break;
            x = x.next[c];
            if (x.val != null) e = d;
        }
        if (e == -1) return null;
        return query.substring(0, e);
    }

    /**
     * Returns all of the keys in the set that start with prefix.
     * @param prefix the prefix
     * @return all of the keys in the set that start with prefix,
     *      as an iterable
     */
    public Iterable<String> keysWithPrefix(String prefix)
    {
        Queue<String> q = new Queue<String>();
        collect(get(root, prefix, 0), prefix, q);
        return q;
    }

    /**
     * Returns all of the keys in the symbol table that match pattern,
     * where . symbol is rreated as a wildcard character.
     * @param pattern the pattern
     * @return all of the keys in the symbol table that match pattern,
     *      as an iterable, where . is treated as a wildcard character.
     */
    public Iterable<String> keysThatMatch(String pattern)
    {
        Queue<String> q = new Queue<String>();
        collect(root, "", pattern, q);
        return q;
    }

    /**
     * Returns all keys in the symbol table as an Iterable.
     * To iterate over all of the keys in the symbol table named st,
     * use the foreach notation: for (Key key : st.keys()).
     * @return all keys in the symbol table as an Iterable
     */
    public Iterable<String> keys()
    {   return keysWithPrefix("");  }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        // build symbol table from standard input
        TrieST<Integer> st = new TrieST<Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }

        // print results
        if (st.size() < 100) {
            StdOut.println("keys(\"\"):");
            for (String key : st.keys()) {
                StdOut.println(key + " " + st.get(key));
            }
            StdOut.println();
        }

        StdOut.println("longestPrefixOf(\"shellsort\"):");
        StdOut.println(st.longestPrefixOf("shellsort"));
        StdOut.println();

        StdOut.println("longestPrefixOf(\"quicksort\"):");
        StdOut.println(st.longestPrefixOf("quicksort"));
        StdOut.println();

        StdOut.println("keysWithPrefix(\"shor\"):");
        for (String s : st.keysWithPrefix("shor"))
            StdOut.println(s);
        StdOut.println();

        StdOut.println("keysThatMatch(\".he.l.\"):");
        for (String s : st.keysThatMatch(".he.l."))
            StdOut.println(s);
    }
}