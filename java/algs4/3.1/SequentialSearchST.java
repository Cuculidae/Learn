/*
 * The SequentialSearchST class represents an (unordered)
 * symbol table of generic key-value pairs.
 * It supports the usual put, get, contains,
 * delete, size, and is-empty methods.
 * It also proides a keys method for iterating over all of the keys.
 * A symbol table implements the associative array abstraction:
 * when associating a value with a key that is already in the symbol table,
 * the convention is to replace the old value with the new value.
 * The class also uses the convention that values cannot be null. Setting the
 * value associated with a key to null is equivalent to deleting the key
 * from the symbol table.
 * This implementation uses a singly-linked list and sequential search.
 * It relies on the equals() method to test whether two keys
 * are equal. It does not call either the compareTo() or 
 * hashCode() method.
 * The put and delete operations take linear time; the
 * get and contains operations takes linear time  in the worst case.
 * The size, and is-empty operations take constant time.
 * Construction takes constant time.
 * For additional documetation, see "http://algs4.cs.princeton.edu/31elementary"
 * Algorithms, 4th Edition by Robert Sedgewick and Kevin Wayne.
 *
 * Execution:       java SequentialSearchST < INPUT
 *				    % more tinyST.txt
 *				    S E A R C H E X A M P L E
 *				  
 *				    % java SequentialSearchST < tinyST.txt 
 *				    L 11
 *				    P 10
 *				    M 9
 *				    X 7
 *				    H 5
 *				    C 4
 *				    R 3
 *				    A 8
 *				    E 12
 *				    S 0
 * Dependencies:    Queue.java, StdIn.java, StdOut.java
 * Data File:       tinyST.txt
 * Author:          caiguochu
 * Time:            2015-05-28
 */
public class SequentialSearchST<Key, Value>
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private int N;		// number of key-value pairs
    private Node first;	// the linked-list of key-value pairs


    /*********************************************************************************************
     *                                    Helper Inner Class                                     *
     *********************************************************************************************/
    // a helper linked-list data-type
    private class Node
    {
    	Key key;
    	Value val;
    	Node next;

    	public Node(Key key, Value val, Node next)
    	{
    		this.key = key;
    		this.val = val;
    		this.next = next;
    	}
    }


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Initalizes an empty symbol table.
     */
    public SequentialSearchST() {}


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // delete key in linked list beginning at Node x
    // warning: function call stack too large if table is large
    private Node delete(Node x, Key key)
    {
    	if (x == null) return null;
    	if (key.equals(x.key))
    	{
    		N--;
    		return x.next;
    	}
    	x.next = delete(x.next, key);
    	return x;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the number of key-value pairs.
     * @return the number of key-value pairs.
     */
    public int size()
    	{	return N;	}

    /**
     * Is this symbol table empty?
     * @return true if this symbol table is empty, false otherwise
     */
    public boolean isEmpty()
    	{	return N == 0;	}

    /**
     * Does this symbol table contains the given key?
     * @param key the key
     * @return true if this symbol table contains the given key and
     *		false otherwise
     */
    public boolean contains(Key key)
    	{	return get(key) != null;	}

    /**
     * Returns the value associated with the given key.
     * @param key the key
     * @return the value associated with the given key,
     *		and null if the key is not in the symbol table
     */
    public Value get(Key key)
    {
    	for (Node x = first; x != null; x = x.next)
    	{
    		if (key.equals(x.key))
    		{
    			return x.val;
    		}
    	}
    	return null;
    }

    /**
     * Insets teh key-value pair into the symbol table, overwriting the old value
     * with the new value if the key is already in the symbol table.
     * If the value is null, this effictively deletes the key from the symbol table.
     * @param key the key
     * @param val the value
     */
    public void put(Key key, Value val)
    {
    	if (val == null)
    	{
    		delete(key);
    		return;
    	}

    	for (Node x = first; x != null; x = x.next)
    	{
    		// key already exists, overwrites 
    		if (key.equals(x.key))
    		{
    			x.val = val;
    			return;
    		}
    	}
    	// key is not in the symbol table, insert
    	first = new Node(key, val, first);
    	N++;
    }

    /**
     * Removes teh key and associated value from the symbol table
     * (if the key is in the symbol table).
     * @param key the key
     */
    public void delete(Key key)
    {
    	first = delete(first, key);
    }

    /**
     * Returns all keys in the symbol table as an iterable.
     * To iterate over all of the keys in the symbol table named st,
     * use the foreach notation: for (Key key : st.keys()).
     * @return all keys in the symbol table as an iterable
     */
    public Iterable<Key> keys()
    {
    	Queue<Key> queue = new Queue<Key>();
    	for (Node x = first; x != null; x = x.next)
    	{
    		queue.enqueue(x.key);
    	}
    	return queue;
    }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit test the SequentialSearchST data type.
    public static void main(String[] args)
    {
        SequentialSearchST<String, Integer> st;
        st = new SequentialSearchST<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); ++i)
        {
        	String key = StdIn.readString();
        	st.put(key, i);
        }

        for (String s : st.keys())
        	StdOut.println(s + " " + st.get(s));
    }
}