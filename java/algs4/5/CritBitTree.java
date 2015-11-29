/*
 *
 * Dependencies:    
 * Data File:       shells.txt, shellsST.txt
 * Author:          caiguochu
 * Time:            2015-07-19
 */
public class CritBitTree<Value>
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private int N;              // number of string keys 
    private Node<Value> root;   // root of CritBitTree

    private static class Node<Value>
    {
        int  d; // the byte 
        byte b; // the critical bit
        Object child[2];
        public boolean isLeaf()
        {   return this instanceof String;  }
    }


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public CritBitTree() {}


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // Precondition: key != null && key != ""
    private Node<Value> get(Node<Value> x, String key, int d)
    {
        if (x.isLeaf()) return x;
        int direction = (1 + (x.bit | key.charAt(d))) >> 8;
        return get(x.child[direction]);
    }

    // Precondition: key != null && key != ""
    private Node<Value> put(Node<Value> x, String key, Value val, int d)
    {}

    // returns the min node in the same level of node x
    // Precondition: x != null
    private Node<Value> min(Node<Value> x)
    {}

    // removes the subtrie rooted at the min node in the same level of x
    // used as assistant to delete only, otherwise would destroy the trie
    // Precondition: x != null
    private Node<Value> delMin(Node<Value> x)
    {}

    // returns the max node in the same level of node x
    // Precondition: x != null
    private Node<Value> max(Node<Value> x)
    {}

    // removes the subtrie rooted at the max node in the same level of x
    // used as assistant to delete only, otherwise would destroy the trie
    // Precondition: x != null
    private Node<Value> delMax(Node<Value> x)
    {}

    // Precondition: key != null && key != ""
    private Node<Value> delete(Node<Value> x, String key, int d)
    {}

    //
    private void collect(Node<Value> x, String pre, Queue<String> q)
    {}
    private void collect(Node<Value> x, String pre, String pat, Queue<String> q)
    {}

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
    // Unit test the CritBitTree data type
    public static void main(String[] args)
    {
        // build symbol table from standard input
        CritBitTree<Integer> st = new CritBitTree<Integer>();
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