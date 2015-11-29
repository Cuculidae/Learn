/*
 * The DirectedEdge class represents a weighted edge in an
 * EdgeWeightedDigraph. Each edge consists of two integers
 * (naming the two vertices) and a real-value weight. The data type
 * provides methods fro accessing the two endpoints of the directed edge and
 * the weight.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/44sp">
 *
 * Execution:       java DirectedEdge
 *                  % java DirectedEdge
 *                    12->23 3.14
 * Dependencies:    StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-03-23
 */
public class DirectedEdge implements Comparable<DirectedEdge>
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private final int v;        // edge source
    private final int w;        // edge target
    private final double weight;// edge weight


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Initializes a directed edge from vertex v to vertex w with
     * the given weight.
     * @param v the tail vertex
     * @param w the head vertex
     * @param weight the weight of the directed edge
     */
    public DirectedEdge(int v, int w, double weight)
    {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /** 
     * Returns the tail vertex of the directed edge
     * @return the tail vertex of the directed edge
     */
    public int from() { return v;   }

    /**
     * Returns the head vertex of the directed edge
     * @return the head vertex of the directed edge
     */
    public int to() {   return w;   }

    /**
     * Returns the weight of the directed edge
     * @return the weight of the directed edge
     */
    public double weight() {    return weight;  }

    /**
     * Returns a string representation of the directed edge
     * @return a string representation of the directed edge
     */
    public String toString() {  return String.format("%d->%d %5.2f", v, w, weight);  }

    /**
     * Compare two directed edge by weight
     * @param that the other directed edge
     * @return a negative, zero or positive integer depending on whether
     *      the this edge is less than, equal or greater than that edge
     */
    public int compareTo(DirectedEdge that)
    {
        if      (weight < that.weight)  return -1;
        else if (weight > that.weight)  return +1;
        else                            return 0;
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the DirectedEdge data type
    public static void main(String[] args)
    {
        DirectedEdge e = new DirectedEdge(12, 23, 3.14);
        StdOut.println(e);
    }
}