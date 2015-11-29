/*
 * The BST class represents an unbalanced binary search tree key-value pairs,
 * in which the key must implement the Comparable interface.
 * It supports the usual get, put, delete, size, contains ans is-empty operations.
 * It also provides some order-relavent operations: min, max, delete-min,
 *  delete-max, rank, select, floor, ceiling.
 * The class also uses the convention that values cannot be null. Setting the
 * value associated with a key to null is equivalent to deleting the key
 * from the symbol table.
 *
 * Execution:       java BST < INPUT
 *                  % more tinyST.txt
 *                  S E A R C H E X A M P L E
 *                  
 *                  % java BST < tinyST.txt
 *                  A 8
 *                  C 4
 *                  E 12
 *                  H 5
 *                  L 11
 *                  M 9
 *                  P 10
 *                  R 3
 *                  S 0
 *                  X 7
 * Dependencies:    Queue.java, StdIn.java, StdOut.java
 * Data File:       tinyST.txt
 * Author:          caiguochu
 * Time:            2015-05-29
 */

import java.util.NoSuchElementException;

public class BST<Key extends Comparable<Key>, Value>
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private Node root;  // root of BST


    /*********************************************************************************************
     *                                    Helper Inner Class                                     *
     *********************************************************************************************/
    private class Node
    {
        private Key key;            // sorted by key
        private Value val;          // associated data
        private Node left, right;   // left and right subtrees
        private int N;              // number of nodes in subtree

        public Node(Key key, Value val, int N)
        {
            this.key = key;
            this.val = val;
            this.N = N;
        }
    }


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public BST() {}


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // returns the size of a substree x
    private int size(Node x)
    {
        if (x == null)  return 0;
        return x.N;
    }

    // returns the height of the subtree
    private int height(Node x)
    {
        if (x == null)  return -1;
        return  1 + Math.max(height(x.left), height(x.right));
    }

    // insert key-value pair into subtree x, if key already exists, update with new value.
    // returns the link to the updated subtree
    private Node put(Node x, Key key, Value val)
    {
        if (x == null)  return new Node(key, val, 1);
        int cmp = key.compareTo(x.key);
        if      (cmp > 0)   x.right = put(x.right, key, val);
        else if (cmp < 0)   x.left  = put(x.left,  key, val);
        else                x.val = val;
        x.N = size(x.left) + size(x.right) + 1;
        return x;
    }

    // returns the subtree x after its min node has been deleted
    private Node delMin(Node x)
    {
        if (x.left == null) return x.right;
        x.left = delMin(x.left);
        x.N = size(x.left) +  size(x.right) + 1;
        return x;
    }

    // returns the subtree x after its max node has been deleted
    private Node delMax(Node x)
    {
        if (x.right == null) return x.right;
        x.right = delMax(x.right);
        x.N = size(x.left) + size(x.right) + 1;
        return x;
    }

    // returns the subtree x after certain key-value pair has been deleted
    private Node delete(Node x, Key key)
    {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if      (cmp > 0)   x.right = delete(x.right, key);
        else if (cmp < 0)   x.left  = delete(x.left,  key);
        else {
            if (x.right == null)    return x.left;
            if (x.left  == null)    return x.right;
            Node t = x;
            x = min(t.right);
            x.left = t.left;
            x.right = delMin(t.right);
        }
        x.N = size(x.left) + size(x.right) + 1;
        return x;
    }

    // returns the min node of the subtree
    private Node min(Node x)
    {
        while (x.left != null)
            x = x.left;
        return x;
    }

    // returns the max node of the subtree
    private Node max(Node x)
    {
        while (x.right != null)
            x = x.right;
        return x;
    }

    // returns the 
    private Node floor(Node x, Key key)
    {
        if (x == null)  return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0)   return x;
        if (cmp < 0)    return floor(x.left, key);
        Node t = floor(x.right, key);
        if (t == null)  return x;
        return t;
    }

    // 
    private Node ceiling(Node x, Key key)
    {
        if (x == null)  return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0)   return x;
        if (cmp > 0)    return ceiling(x.right, key);
        Node t = ceiling(x.left, key);
        if (t == null)  return x;
        return t;
    }

    // returns the node contains key ranked k
    private Node select(Node x, int k)
    {
        if (x == null)  return null;
        int t = size(x.left);
        if      (k < t) return select(x.left, k);
        else if (k > t) return select(x.right, k-t-1);
        else            return x;
    }

    // number of keys in the subtree less than key
    private int rank(Node x, Key key)
    {
        if (x == null)  return 0;
        int cmp = key.compareTo(x.key);
        if      (cmp > 0)   return size(x.left) + rank(x.right, key) + 1;
        else if (cmp < 0)   return rank(x.left, key);
        else                return size(x.left);
    }

    // collect the keys in the given range of the subtree
    private void keys(Node x, Queue<Key> q, Key lo, Key hi)
    {
        if (x == null) return;
        int cmplo = lo.compareTo(x.key);
        int cmphi = hi.compareTo(x.key);
        if (cmplo < 0)  keys(x.left, q, lo, hi);
        if (cmplo <=0 && cmphi >= 0) q.enqueue(x.key);
        if (cmphi > 0)  keys(x.right, q, lo, hi);
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Is the symbol table empty?
     * @return true if the symbol table is empty, false otherwise
     */
    public boolean isEmpty()
        {   return root == null; }

    /**
     * Returns the number of key-value pairs in BST
     * @return the number of key-value pairs in BST
     */
    public int size()
        {   return size(root);  }

    /**
     * Returns the number of key-value pairs in the given range
     * specified by key lo and key hi.
     * @return the number of key-value pairs in the given range
     */
    public int size(Key lo, Key hi)
    {
        if (lo.compareTo(hi) > 0)   return 0;
        if (contains(hi))   return rank(hi) - rank(lo) + 1;
        else                return rank(hi) - rank(lo);
    }

    /**
     * Returns the height of the BST.
     * @return the height of the BST
     */
    public int height()
        {   return height(root);    }

    /**
     * Does there exist a key-value pair with given key?
     * @return true if there exists a key-value pair with given key,
     *      and false otherwise
     */
    public boolean contains(Key key)
        {   return get(key) != null;    }

    /**
     * Returns the value associated with the given key, or null if no such key
     * @return the value associated with the given key, or null if no such key
     */
    public Value get(Key key)
    {
        Node x = root;
        while (x != null)
        {
            int cmp = key.compareTo(x.key);
            if      (cmp > 0)   x = x.right;    // search right subtree
            else if (cmp < 0)   x = x.left;     // search left subtree
            else                return x.val;   // found
        }
        // not found
        return null;
    }

    /**
     * Insert key-value pair into BST, if key already exists, update with new value.
     * @param key the key
     * @param val teh value
     */
    public void put(Key key, Value val)
    {    
        if (val == null)    {   delete(key); return;  }
        root = put(root, key, val);
    }

    /**
     * Delete the minimum key and its associated value
     * @throws java.util.NoSuchElementException if symbol table is empty
     */
    public void delMin()
    {
        if (isEmpty())
            throw new NoSuchElementException("BST underflow");
        root = delMin(root);
    }

    /**
     * Delete the maximum key and its associated value.
     * @throws java.util.NoSuchElementException if symbol table is empty
     */
    public void delMax()
    {
        if (isEmpty())
            throw new NoSuchElementException("BST underflow");
        root = delMax(root);
    }

    /**
     * Delete the given key and its associated value.
     */
    public void delete(Key key)
        {    root = delete(root, key);    }

    /**
     * Returns the minimum value in the symbol table.
     * @return the minimum value in the symbol table
     * @throws java.util.NoSuchElementException if symbol table is empty
     */
    public Key min()
    {
        if (isEmpty())
            throw new NoSuchElementException("BST underflow");
        return min(root).key;
    }

    /**
     * Returns the maximum value in the symbol table.
     * @return the maximum value in the symbol table
     * @throws java.util.NoSuchElementException if symbol table is empty
     */
    public Key max()
    {
        if (isEmpty())
            throw new NoSuchElementException("BST underflow");
        return max(root).key;
    }

    /**
     * Returns the key not greater than the given key, null if no such key.
     * @return the key not greater than the given key, null if no such key
     */
    public Key floor(Key key)
    {
        Node x = floor(root, key);
        if (x == null)  return null;
        else            return x.key;
    }

    /**
     * Returns the key not less than the given key, or null if no such key.
     * @return the key not less than the given key, or null if no such key
     */
    public Key ceiling(Key key)
    {
        Node x = ceiling(root, key);
        if (x == null)  return null;
        else            return x.key;
    }

    /**
     * Returns key of rank k.
     * @param k the rank of the key
     * @return key of rank k
     */
    public Key select(int k)
    {
        Node x = select(root, k);
        if (x == null)  return null;
        else            return x.key;
    }

    /**
     * Returns the rank of key.
     * @param key the key
     * @return the rank of key
     */
    public int rank(Key key)
        {    return rank(root, key);    }

    /**
     * Returns all the keys in the symbol table as an iterable.
     * @return all the keys in the symbol table as an iterable
     */
    public Iterable<Key> keys()
        {   return keys(min(), max());  }

    /**
     * Returns the keys as an iterable in the given range specified
     * by key lo and key hi.
     * @return the keys as an iterable in the given range
     */
    public Iterable<Key> keys(Key lo, Key hi)
    {
        Queue<Key> q = new Queue<Key>();
        keys(root, q, lo, hi);
        return q;
    }

    /**
     * Returns all the keys in the symbol table as an iterable in level order.
     * @return all the keys in the symbol table as an iterable in level order
     */
    public Iterable<Key> levelOrder()
    {
        Queue<Key> keys = new Queue<Key>();
        Queue<Node> q = new Queue<Node>();
        q.enqueue(root);
        while (!q.isEmpty())
        {
            Node x = q.dequeue();
            if (x == null)  continue;
            keys.enqueue(x.key);
            q.enqueue(x.left);
            q.enqueue(x.right);
        }
        return keys;
    }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit test the BST data type
    public static void main(String[] args)
    { 
        BST<String, Integer> st = new BST<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++) {
            String key = StdIn.readString();
            st.put(key, i);
        }

        for (String s : st.levelOrder())
            StdOut.println(s + " " + st.get(s));

        StdOut.println();

        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
    }
}