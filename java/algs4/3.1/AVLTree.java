/*
 * The AVLTree class represents an AVL (Adelson-Velskii and Landis) tree containing keys of type
 * Key which implements the Comparable interface.
 *
 * Execution:       java AVLTree N
 * Dependencies:    StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-03-20
 */

public class AVLTree<Key extends Comparable<Key>>
{
    /*********************************************************************************************
     *                                       Inner Class                                         *
     *********************************************************************************************/
    private class Node
    {
        Key key;
        byte height;    // the height of the node in the AVL tree
        Node left;
        Node right;
        Node(Key key) {  this.key = key;  }
        Node(Key key, Node left, Node right)
        {   this.key = key; this.left = left; this.right = right;   }
    }


    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    // for every node in the AVL tree, the height of the left and right subtrees can differ 
    // by at most 1
    private static final byte ALLOWED_IMBALANCE = 1;
    private Node root; // the root node
    private int N;     // number of keys in the tree


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public AVLTree() {}


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // returns the height of node x in the AVL tree, empty trees have height -1
    private byte height(Node x) {   return (x == null) ? -1 : x.height;    }
    // single rotation with the node's left child
    private Node rotateWithLeftChild(Node k2)
    {
        //     k2           k1
        //    /  \         /  \
        //   k1   Z   =>  X   k2
        //  /  \              / \
        //  X   Y            Y   Z

        Node k1 = k2.left;                                           
        k2.left = k1.right;                                          
        k1.right = k2;                                               
        k2.height = (byte) (Math.max(height(k2.left), height(k2.right)) + 1); 
        k1.height = (byte) (Math.max(height(k1.left), height(k1.right)) + 1); 
        return k1;
    }
    // single rotation with the node's right child
    private Node rotateWithRightChild(Node k2)
    {
        //    k2             k1
        //   /  \           /  \
        //  X   k1    =>   K2   Z
        //     /  \       / \
        //    Y    Z     X   Y

        Node k1 = k2.right;                                          
        k2.right = k1.left;                                          
        k1.left = k2;                                                
        k2.height = (byte) (Math.max(height(k2.left), height(k2.right)) + 1); 
        k1.height = (byte) (Math.max(height(k1.left), height(k1.right)) + 1); 
        return k1;
    }
    // double rotation, first with 
    private Node doubleWithLeftChild(Node k3)
    {
        //      k3                    k3                      k2
        //     /  \                  /  \                   /    \
        //    k1   D                k2   D                 k1     k3
        //   /  \       =>         /  \       =>          /  \   /  \
        //  A    k2               k1   C                 A    B  C   D
        //      /  \             /  \
        //     B    C           A    B

        k3.left = rotateWithRightChild(k3.left);
        return rotateWithLeftChild(k3);
    }
    private Node doubleWithRightChild(Node k3)
    {
        //    k3                    k3                        k2
        //   /  \                  /  \                     /    \
        //  A   k1                A    k2                  k3     k1
        //     /  \     =>         /  \       =>          /  \   /  \
        //    k2   D                B    k1              A    B  C   D
        //   /  \                      /  \
        //  B    C                    C    D

        k3.right = rotateWithLeftChild(k3.right);
        return rotateWithRightChild(k3);
    }
    // balances the AVL tree rooted at node x   
    private Node balance(Node x)
    {
        if (x == null)  return null;
        byte lh = height(x.left), rh = height(x.right);
        if (lh - rh > ALLOWED_IMBALANCE)
        {
            if (height(x.left.left) > height(x.left.right))
                x = rotateWithLeftChild(x);
            else
                x = doubleWithLeftChild(x);
        }
        else if (rh - lh > ALLOWED_IMBALANCE)
        {
            if (height(x.right.right) > height(x.right.left))
                x = rotateWithRightChild(x);
            else
                x = doubleWithRightChild(x);
        }
        x.height = (byte) (Math.max(height(x.left), height(x.right)) + 1); 
        return x;
    }
    // returns the node containing the minimum key
    private Node min(Node x)
    {
        while (x.left != null)  x = x.left;
        return x;
    }
    // returns the node containing the maximum key
    private Node max(Node x)
    {
        while (x.right != null) x = x.right;
        return x;
    }
    // adds a new key to the tree
    private Node insert(Node x, Key key)
    {
        if (x == null)  return new Node(key);
        int cmp = key.compareTo(x.key);
        if      (cmp < 0)   x.left  = insert(x.left,  key);
        else if (cmp > 0)   x.right = insert(x.right, key);
        else                return x; // Duplicate; do nothing
        return balance(x);
    }
    // removes a key from the tree
    private Node remove(Node x, Key key)
    {
        if (x == null)  return null;
        int cmp = key.compareTo(x.key);
        if      (cmp < 0)   x.left  = remove(x.left,  key);
        else if (cmp > 0)   x.right = remove(x.right, key);
        else if (x.left != null && x.right != null)
        {
            x.key = min(x.right).key;
            x.right = remove(x.right, x.key);
        }
        else
            return (x.left != null) ? x.left : x.right;
        return balance(x);
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Is the AVL tree empty ?
     * @return true if the AVL tree is empty, false otherwise
     */
    public boolean isEmpty() {  return root == null;    }

    /**
     * Returns the number of keys in the AVL tree
     * @return the number of keys in the AVL tree
     */
    public int size() { return N;   }

    /**
     * Does the AVL tree contains the key 'key' ?
     * @param key the key to be queried
     * @return true if the AVL tree contains the key 'key', and false otherwise
     */
    public boolean contains(Key key)
    {
        Node x = root;
        int cmp;
        while (x != null)
        {
            cmp = key.compareTo(x.key);
            if      (cmp < 0)   x = x.left;
            else if (cmp > 0)   x = x.right;
            else                return true;
        }
        return false;
    }

    /**
     * Returns the minimum key in the AVL tree
     * @return the minimum key in the AVL tree
     */
    public Key min()
    {
        return min(root).key;
    }

    /**
     * Returns the maximum key in the AVL tree
     * @return the maximum key in the AVL tree
     */
    public Key max()
    {
        return max(root).key;
    }

    /**
     * Adds a new key 'key' to the AVL tree
     * @param key the new key to be added
     */
    public void insert(Key key)
    {
        root = insert(root, key);
        N++;
    }

    /**
     * Removes a key 'key' from the AVL tree
     * @param key the key to be removed
     */
    public void remove(Key key)
    {
        root = remove(root, key);
        N--;
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the AVLTree data type
    public static void main(String[] args)
    {
        AVLTree<Integer> avl = new AVLTree<Integer>();
        int N = Integer.parseInt(args[0]);
        for (int i = N-1; i >= 0; i--)
            avl.insert(i);
        for (int i = 1; !avl.isEmpty(); i++)
        {
            int min = avl.min();
            StdOut.printf("%7d%s", min, (i%10==0) ? "\n" : " ");
            avl.remove(min);
        }
    }
}