/*
 * The Edge class represents a weighted edge in an
 * EdgeWeightedGraph. Each edge consists of two integers
 * (naming the two vertices) and a real-value weight. The data type
 * provides methods fro accessing the two endpoints of the edge and
 * the weight. The natural order for this data type is by
 * ascending order of weight.
 * For additional documentation, see <a href="http://algs4.cs.princeton.edu/43mst">Section 4.3</a> of
 *
 * Execution:       java Edge
 *                  % java Edge
 *                  12-23 3.14000
 *
 * Dependencies:    In.java, StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-03-10
 */
public class Edge implements Comparable<Edge>
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private final int v;            // one vertex
    private final int w;            // the other vertex
    private final double weight;    // edge weight


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Initializes an edge between vertices v and w of
     * the given weight.
     * @param v one vertex
     * @param w the other vertex
     * @param weigth the weight of the edge
     * @throws IndexOutOfBoundsException if either v or w
     *      is negative integer
     * @throws IllegalArgumentException if weight is NaN
     */
    public Edge(int v, int w, double weight)
    {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the weight of the edge.
     * @return the weight of the edge
     */
    public double weight() {    return weight;  }

    /**
     * Returns either endpoint of the edge.
     * @return either endpoint of the edge
     */
    public int either() {   return v;   }

    /**
     * Returns the endpoint of the edge that is different from the given vertex
     * (unless the edge represents a self-loop in which case it returns the same vertex).
     * @param vertex one endpoint of the edge
     * @return the endpoint of the edge that is different from the given vertex
     * (unless the edge represents a self-loop in which case it returns the same vertex).
     * @throws java.lang.IllegalArgumentException if the vertex is not one of the endpoints
     *   of the edge
     */
    public int other(int vertex)
    {
        if (vertex == v) return w;
        if (vertex == w) return v;
        throw new IllegalArgumentException("Inconsistent edge");
    }

    /**
     * Compares two edges by weight
     * @param that the other edge
     * @return a negative integer, zero, or positive integer depending on whether
     *      this edge is less than, equal to, or greater than that edge
     */
    public int compareTo(Edge that)
    {
        if      (this.weight < that.weight) return -1;
        else if (this.weight > that.weight) return +1;
        else                                return 0;
    }

    /**
     * Returns a string representation of the edge.
     * @return a string representation of the edge
     */
    public String toString()
    {   return String.format("%d-%d %.5f", v, w, weight);   }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the Edge data type
    public static void main(String[] args)
    {
        Edge e = new Edge(12, 23, 3.14);
        StdOut.println(e); 
    }
}