/*
 * The TST class represents an symbol table of key-value
 * pairs, with string keys and generic values.
 * It supports the usual put, get, contains,
 * delete, size, and is-empty methods.
 * It also provids character-based methods for finding the string
 * in the symbol table that is the longest prefix of a given prefix,
 * finding all strings in the symbol table that start with a given prefix.
 * and finding all strings in the symbol table that match a given pattern.
 * A symbol table implements the associative array abstraction:
 * when associating a value with a key that is already in the symbol table,
 * the convention is to replace the old value with the new value.
 * Unlike {@link java.util.Map}, this class uses the convention that 
 * values cannot be null; setting
 * the value associated with a key to null is equivalent to deleting the key
 * from the symbol table
 * This implementation uses a ternary search trie.
 * For additional documentation, see <"http://algs4.cs.princeton.edu/52trie">
 * Section 5.2 of Algorithms, 4th Edition by Robert Sedgewick and Kevin Wayne.
 *
 * Execution:       java TST < INPUT
 *                  % java TST < shellsST.txt
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
 *                  shells
 *
 *                  keysWithPrefix("shor"):
 *                  shore
 *
 *                  keysThatMatch(".he.l."):
 *                  shells
 *  Remarks
 *  --------
 *    - In order to support null string key "", this implementation uses a
 *    - separate value to store the value associated with "".
 *    - The delete method uses random method to keep balance.
 * Dependencies:    Queue.java, StdRandom.java, StdIn.java, StdOut.java
 * Data File:       shells.txt, shellsST.txt
 * Author:          caiguochu
 * Time:            2015-07-14
 */
public class TST<Value>
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private int N;              // number of string keys 
    private Node<Value> root;   // root of TST
    private Value null_str_val; // value of empty string ""

    private static class Node<Value>
    {
        char c;                         // character
        Node<Value> left, mid, right;   // left, mid, right subtrees
        Value val;                      // value associated with string
    }


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public TST() {}


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // Precondition: key != null && key != ""
    private Node<Value> get(Node<Value> x, String key, int d)
    {
        if (x == null)  return null;
        char c = key.charAt(d);
        if      (c > x.c)               return get(x.right, key, d);
        else if (c < x.c)               return get(x.left,  key, d);
        else if (d < key.length()-1)    return get(x.mid,  key, d+1);
        else                            return x;
    }

    // Precondition: key != null && key != ""
    private Node<Value> put(Node<Value> x, String key, Value val, int d)
    {
        char c = key.charAt(d);
        if (x == null) { x = new Node<Value>(); x.c = c; }
        if      (c > x.c)               x.right = put(x.right, key, val, d);
        else if (c < x.c)               x.left  = put(x.left,  key, val, d);
        else if (d < key.length()-1)    x.mid   = put(x.mid,   key, val, d+1);
        else if (x.val != null)         x.val   = val;
        else                            { x.val = val; ++N; }
        return x;
    }

    // returns the min node in the same level of node x
    // Precondition: x != null
    private Node<Value> min(Node<Value> x)
    {
        while (x.left != null) x = x.left;
        return x;
    }

    // removes the subtrie rooted at the min node in the same level of x
    // used as assistant to delete only, otherwise would destroy the trie
    // Precondition: x != null
    private Node<Value> delMin(Node<Value> x)
    {
        if (x.left == null) return x.right;
        x.left = delMin(x.left);
        return x;
    }

    // returns the max node in the same level of node x
    // Precondition: x != null
    private Node<Value> max(Node<Value> x)
    {
        while (x.right != null) x = x.right;
        return x;
    }

    // removes the subtrie rooted at the max node in the same level of x
    // used as assistant to delete only, otherwise would destroy the trie
    // Precondition: x != null
    private Node<Value> delMax(Node<Value> x)
    {
        if (x.right == null) return x.left;
        x.right = delMax(x.right);
        return x;
    }

    // Precondition: key != null && key != ""
    private Node<Value> delete(Node<Value> x, String key, int d)
    {
        if (x == null)  return null;
        char c = key.charAt(d);
        if      (c > x.c)               x.right = delete(x.right, key, d);
        else if (c < x.c)               x.left  = delete(x.left,  key, d);
        else if (d < key.length()-1)    x.mid   = delete(x.mid,   key, d+1);
        else if (x.val != null)         { x.val = null; --N; }
        if (x.mid == null && x.val == null)
        {
            if (x.left  == null) return x.right;
            if (x.right == null) return x.left;
            Node<Value> t;
            if (StdRandom.bernoulli())  // to keep balance
                { t = min(x.right); x.right = delMin(x.right); }
            else
                { t = max(x.left);  x.left  = delMax(x.left);  }
            t.right = x.right;
            t.left  = x.left;
            return t;
        }
        return x;
    }

    //
    private void collect(Node<Value> x, String pre, Queue<String> q)
    {
        if (x == null) return;
        collect(x.left,  pre, q);
        if (x.val != null) q.enqueue(pre+x.c);
        collect(x.mid, pre+x.c, q);
        collect(x.right, pre, q);
    }
    private void collect(Node<Value> x, String pre, String pat, Queue<String> q)
    {
        if (x == null) return;
        int d = pre.length();
        char c = pat.charAt(d);
        if (c == '.' || c > x.c)    collect(x.right, pre, pat, q);
        if (c == '.' || c == x.c) {
            if (d == pat.length()-1)    q.enqueue(pre+x.c);
            else                        collect(x.mid, pre+x.c, pat, q);
        }
        if (c == '.' || c < x.c)    collect(x.left, pre, pat, q);
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
    {   return N == 0;    }

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
        if (key.equals("")) return null_str_val;
        Node<Value> x = get(root, key, 0);
        return x == null ? null : x.val;
    }

    /**
     * Inserts the key-value pair into the symbol table, overwriting the old value
     * with the new value if the key is already in the symbol table.
     * @param key the key
     * @param val the value
     */
    public void put(String key, Value val)
    {
        if (key.equals("")) {
            if (null_str_val == null) ++N;
            null_str_val = val;
            return;
        }
        root = put(root, key, val, 0);
    }

    /**
     * Removes the key from the set if the key is present.
     * @param key the key
     */
    public void delete(String key)
    {
        if (key.equals("")) {
            if (null_str_val != null) --N;
            null_str_val = null;
            return;
        }
        root = delete(root, key, 0);
    }

    /**
     * Returns the string in the symbol table that is the longest prefix of query,
     * or null, if no such string.
     * @param query the query string
     * @return the string in the symbol table that is the longest prefix of query,
     *      or null if no such string
     */
    public String longestPrefixOf(String query)
    {
        Node<Value> x = root;
        int d = 0, e = 0;
        int len = query.length();
        while (d < len)
        {
            if (x == null) break;
            char c = query.charAt(d);
            if      (c > x.c)       x = x.right;
            else if (c < x.c)       x = x.left;
            else                    { ++d; if (x.val != null) e = d; x = x.mid; }
        }
        String s = query.substring(0, e);
        return (s.equals("") && null_str_val == null) ? null : s;
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
        Node x;
        if (prefix.equals("")) {
            if (null_str_val != null) q.enqueue("");
            x = root;
        } else x = get(root, prefix, 0).mid;
        collect(x, prefix, q);
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
        if ((pattern.equals("") || pattern.equals(".")) && null_str_val != null)
            q.enqueue("");
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
    // Unit test the TST data type
    public static void main(String[] args)
    {
        // build symbol table from standard input
        TST<Integer> st = new TST<Integer>();
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

        StdOut.println("keysWithPrefix(\"shor\"):");
        for (String s : st.keysWithPrefix("shor"))
            StdOut.println(s);
        StdOut.println();

        StdOut.println("keysThatMatch(\".he.l.\"):");
        for (String s : st.keysThatMatch(".he.l."))
            StdOut.println(s);
    }
}