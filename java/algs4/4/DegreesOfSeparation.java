/*
 * The DegreesOfSeparation class provides a client for finding
 * the degree of separation between one distinguished individual and
 * every other individual in a social network.
 * As an example, if the social network consists of actors in which
 * two actors are connected by a link if they appeared in the same movie,
 * and Kevin Bacon is the distinguished individual, then the client
 * computes the Kevin Bacon number of every actor in the network.
 * The running time is proportional to the number of individuals and
 * connections in the network. If the connections are given implicitly,
 * as in the movie network example (where every two actors are connected
 * if they appear in the same movie), the efficiency of the algorithm
 * is improved by allowing both movie and actor vertices and connecting
 * each movie to all of the actors that appear in that movie.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/41undirected">
 *
 * Execution:       java DegreesOfSeparation INPUT.TXT DELIMITER SOURCE
 *                  % java DegreesOfSeparation movies.txt "/" "Bacon, Kevin"
 *                  Kidman, Nicole
 *                     Bacon, Kevin
 *                     Woodsman, The (2004)
 *                     Grier, David Alan
 *                     Bewitched (2005)
 *                     Kidman, Nicole
 *                  Grant, Cary
 *                     Bacon, Kevin
 *                     Planes, Trains & Automobiles (1987)
 *                     Martin, Steve (I)
 *                     Dead Men Don't Wear Plaid (1982)
 *                     Grant, Cary
 *
 *                  % java DegreesOfSeparation movies.txt "/" "Animal House (1978)"
 *                  Titanic (1997)
 *                     Animal House (1978)
 *                     Allen, Karen (I)
 *                     Raiders of the Lost Ark (1981)
 *                     Taylor, Rocky (I)
 *                     Titanic (1997)
 *                  To Catch a Thief (1955)
 *                     Animal House (1978)
 *                     Vernon, John (I)
 *                     Topaz (1969)
 *                     Hitchcock, Alfred (I)
 *                     To Catch a Thief (1955)
 *
 * Dependencies:    Graph.java, SymbolGraph.java, StdIn.java, StdOut.java
 * Data File:       movies.txt, routes.txt
 * Author:          caiguochu
 * Time:            2015-03-03
 */

public class DegreesOfSeparation
{
    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
     private DegreesOfSeparation() {} // This class should not been instantiated


    /*********************************************************************************************
     *                                      Main Program                                         *
     *********************************************************************************************/
    /**
     *  Reads in a social network from a file, and then repeatedly reads in
     *  individuals from standard input and prints out their degrees of
     *  separation.
     *  Takes three command-line arguments: the name of a file,
     *  a delimiter, and the name of the distinguished individual.
     *  Each line in the file contains the name of a vertex, followed by a
     *  list of the names of the vertices adjacent to that vertex,
     *  separated by the delimiter.
     */
    public static void main(String[] args)
    {
        String filename = args[0];
        String delimiter = args[1];
        String source = args[2];

        SymbolGraph sg = new SymbolGraph(filename, delimiter);
        Graph G = sg.graph();
        if (!sg.contains(source))
        {
            StdOut.println(source + " not in database.");
            return;
        }

        int s = sg.index(source);
        BreadthFirstPaths bfs = new BreadthFirstPaths(G, s);

        while (!StdIn.isEmpty())
        {
            String sink = StdIn.readLine();
            if (sg.contains(sink))
            {
                int v = sg.index(sink);
                if (bfs.hasPathTo(v))
                {
                    for (int w : bfs.pathTo(v))
                        StdOut.println("    " + sg.name(w));
                }
                else
                {
                    StdOut.println("    not connected");
                }
            }
            else
            {
                StdOut.println("    not in database");
            }
        }
    }
}