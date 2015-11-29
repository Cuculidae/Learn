/*
 *
 *
 * Execution:       
 * Dependencies:    
 * Data File:       
 * Author:          caiguochu
 * Time:            2015-05-29
 */

import java.util.NoSuchElementException;

public class RedBlackBST<Key extends Comparable<Key>, Value>
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final boolean RED = true;
    private static final boolean BLACK = false;
    private Node root;


    /*********************************************************************************************
     *                                    Helper Inner Class                                     *
     *********************************************************************************************/
    private class Node
    {
        private Key key;            // sorted by key
        private Value val;          // associated data
        private Node left, right;   // left and right subtrees
        private int N;              // number of nodes in subtree
        private boolean color;      // color of the link to this node

        public Node(Key key, Value val, int N, boolean color)
        {
            this.key = key;
            this.val = val;
            this.N = N;
            this.color = color;
        }
    }



    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public RedBlackBST() { }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // helper function to test node color
    private boolean isRed(Node h)
    {
        if (h == null)  return false;   // null links are BLACK
        return h.color == RED;
    }

    // returns the size of subtree
    private int size(Node h)
    {
        if (h == null)  return 0;
        return h.N;
    }

    //
    private int height(Node h)
    {
        if (h == null)  return -1;
        return 1 + Math.max(height(h.left), height(h.right));
    }

    //
    private Node put(Node h, Key key, Value val)
    {
        // attach new node with red link at the bottom
        if (h == null)  return new Node(key, val, 1, RED);
        int cmp = key.compareTo(h.key);
        if      (cmp > 0)   h.right = put(h.right, key, val);
        else if (cmp < 0)   h.left  = put(h.left,  key, val);
        else                h.val = val;

        return fixUp(h);
    }

    //
    private Node min(Node h)
    {
        if (h == null)  return null;
        while (h.left != null)
            h = h.left;
        return h;
    }

    //
    private Node max(Node h)
    {
        if (h == null)  return null;
        while (h.right != null)
            h = h.right;
        return h;
    }

    //
    private Node floor(Node h, Key key)
    {
        if (h == null)  return null;
        int cmp = key.compareTo(h.key);
        if (cmp == 0)  return h;
        if (cmp < 0)   return floor(h.left, key);
        Node t = floor(h.right, key);
        if (t == null)  return h;
        return t;
    }

    //
    private Node ceiling(Node h, Key key)
    {
        if (h == null)  return null;
        int cmp = key.compareTo(h.key);
        if (cmp == 0)   return h;
        if (cmp > 0)    return ceiling(h, key);
        Node t = ceiling(h.left, key);
        if (t == null)  return h;
        return t;
    }

    //
    private Node select(Node h, int k)
    {
        if (h == null) return null;
        int t = size(h.left);
        if      (t > k) return select(h.left, k);
        else if (t < k) return select(h.right, k-t-1);
        else            return h;
    }

    //
    private int rank(Node h, Key key)
    {
        if (h == null)  return 0;
        int cmp = key.compareTo(h.key);
        if      (cmp < 0)   return rank(h.left, key);
        else if (cmp > 0)   return size(h.left) + rank(h.right, key) + 1;
        else                return size(h.left);
    }

    //
    private void keys(Node h, Queue<Key> q, Key lo, Key hi)
    {
        if (h == null)  return;
        int cmplo = lo.compareTo(h.key);
        int cmphi = hi.compareTo(h.key);
        if (cmplo < 0)  keys(h.left, q, lo, hi);
        if (cmplo <= 0 && cmphi >= 0) q.enqueue(h.key);
        if (cmphi > 0)  keys(h.right, q, lo, hi);
    }

    // orient a (temporarily) right-leaning red link to lean left.
    private Node rotateLeft(Node h)
    {
        Node x = h.right;
        x.color = h.color;
        h.right = x.left;
        h.color = RED;
        x.left = h;
        x.N = h.N;
        h.N = size(h.left) + size(h.right) + 1;
        return x;
    }

    // orieant a left-leaning red link to (temporarily) lean right.
    private Node rotateRight(Node h)
    {
        Node x = h.left;
        x.color = h.color;
        h.left = x.right;
        x.right = h;
        h.color = RED;
        x.N = h.N;
        h.N = size(h.left) + size(h.right) + 1;
        return x;
    }

    // flip the colors of a node and its two children
    private void flipColors(Node h) {
        // h must have opposite color of its two children
        // assert (h != null) && (h.left != null) && (h.right != null);
        // assert (!isRed(h) &&  isRed(h.left) &&  isRed(h.right))
        //    || (isRed(h)  && !isRed(h.left) && !isRed(h.right));
        h.color = !h.color;
        h.left.color = !h.left.color;
        h.right.color = !h.right.color;
    }

    // fix right-leaning reds and eliminate 4-nodes on the way up.
    private Node fixUp(Node h)
    {
        // fix right-leaning reds on the way up
        if (isRed(h.right) && !isRed(h.left))   h = rotateLeft(h);

        // fix two reds in a row on the way up
        if (isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);

        // split 4-node, pass red link up to parent
        if (isRed(h.left) && isRed(h.right))    flipColors(h);

        h.N = size(h.left) + size(h.right) + 1;
        return h;
    }

    //
    private Node moveRedRight(Node h)
    {
        flipColors(h);
        if (isRed(h.left.left))
        {
            h = rotateRight(h);
            flipColors(h);
        }
        return h;
    }

    // 
    private Node delMax(Node h)
    {
        if (isRed(h.left))
            h = rotateRight(h);
        if (h.right == null)
            return null;
        if (!isRed(h.right) && !isRed(h.right.left))
            h = moveRedRight(h);
        h.right = delMax(h.right);
        return fixUp(h);
    }

    //
    private Node moveRedLeft(Node h)
    {
        flipColors(h);
        if (isRed(h.right.left))
        {
            h.right = rotateRight(h.right);
            h = rotateLeft(h);
            flipColors(h);
        }
        return h;
    }

    //
    private Node delMin(Node h)
    {
        if (h.left == null) return null;
        if (!isRed(h.left) && !isRed(h.left.left))
            h = moveRedLeft(h);
        h.left = delMin(h.left);
        return fixUp(h);
    }

    //
    private Node delete(Node h, Key key)
    {
        if (key.compareTo(h.key) < 0) {
            if (!isRed(h.left) && !isRed(h.left.left))
                h = moveRedLeft(h);
            h.left = delete(h.left, key);
        } else {
            if (isRed(h.left))  h = rotateRight(h);
            if (key.compareTo(h.key) == 0 && (h.right == null))
                return null;
            if (!isRed(h.right) && !isRed(h.right.left))
                h = moveRedRight(h);
            if (key.compareTo(h.key) == 0) {
                Node t = min(h.right);
                h.key = t.key;
                h.val = t.val;
                h.right = delMin(h.right);
            }
            else    h.right = delete(h.right, key);
        }
        return fixUp(h);
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Is the red-black tree empty?
     * @return true if the red-black tree is empty, false otherwise
     */
    public boolean isEmpty()
        {   return root == null;    }

    /**
     * Does the red-black tree contain the given key?
     * @return true if the red-black tree contains the given key, false otherwise
     */
    public boolean contains(Key key)
    {
        return get(key) != null;    
    }

    /**
     * Returns the size of the red-black tree.
     * @return the size of the red-black tree
     */
    public int size()
        {   return size(root);  }

    /**
     *
     */
    private int size(Key lo, Key hi)
    {
        if (lo.compareTo(hi) > 0)   return 0;
        if (get(hi) != null)    return rank(hi) - rank(lo) + 1;
        else                    return rank(hi) - rank(lo);
    }

    /**
     *
     */
    public int height()
        {   return height(root);    }

    /**
     *
     */
    public Value get(Key key)
    {
        Node x = root;
        while (x != null)
        {
            int cmp = key.compareTo(x.key);
            if      (cmp > 0)   x = x.right;
            else if (cmp < 0)   x = x.left;
            else                return x.val;
        }
        return null;
    }

    /**
     *
     */
    public void put(Key key, Value val)
    {
        root = put(root, key, val);
        root.color = BLACK;     // root's color is always BLACK
    }

    /**
     */
    public Key floor(Key key)
    {
        Node t = floor(root, key);
        if (t == null)  return null;
        return t.key;
    }

    /**
     *
     */
    public Key ceiling(Key key)
    {
        Node t = ceiling(root, key);
        if (t == null)  return null;
        return t.key;
    }

    /**
     *
     */
    public Key select(int k)
    {
        Node t = select(root, k);
        if (t == null)  return null;
        return t.key;
    }

    /**
     *
     */
    public int rank(Key key)
        {    return rank(root, key);    }

    /**
     * Returns the minimum value in the RBTree.
     * @return the minimum value in the RBTree
     * @throws java.util.NoSuchElementException if RBTree is empty
     */
    public Key min()
    {
        if (isEmpty())
            throw new NoSuchElementException("BST underflow");
        return min(root).key;
    }

    /**
     * Returns the maximum value in the RBTree.
     * @return the maximum value in the RBTree
     * @throws java.util.NoSuchElementException if RBTree is empty
     */
    public Key max()
    {
        if (isEmpty())
            throw new NoSuchElementException("BST underflow");
        return max(root).key;
    }

    /**
     *
     */
    public Iterable<Key> keys(Key lo, Key hi)
    {
        Queue<Key> q = new Queue<Key>();
        keys(root, q, lo, hi);
        return q;
    }

    /**
     *
     */
    public Iterable<Key> keys()
    {
        return keys(min(), max());
    }

    /**
     */
    public void delMin()
    {
        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;
        root = delMin(root);
        if (root != null)   root.color = BLACK;
    }

    /**
     *
     */
    public void delMax()
    {
        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;
        root = delMax(root);
        if (root != null)   root.color = BLACK;
    }

    /**
     */
    public void delete(Key key)
    {
        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;
        root = delete(root, key);
        if (root != null)   root.color = BLACK;
    }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        RedBlackBST<Integer, Integer> st;
        st = new RedBlackBST<Integer, Integer>();
        int N = Integer.parseInt(args[0]);
        for (int i = 0; i < N; ++i)
            st.put(i, i);
        StdOut.println("height = " + st.height());
        for (int i = N/2; i < N; ++i)
            st.delMax();
        StdOut.println("height = " + st.height());
    }
}