//
// Created by Phong Cao on 2019-02-18.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iterator>
#include <functional>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::ostringstream;
using std::istringstream;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::sqrt;
using std::pow;
using std::rand;
using std::srand;
using std::time;
using std::endl;
using std::hash;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;
using std::vector;           // Unordered Array
using std::map;              // Ordered Map (Red-Black Tree)
using std::unordered_map;    // HashMap (SeparateChainingHashST)
using std::set;              // Ordered Set (Red-Black Tree)
using std::unordered_set;    // HashSet (SeparateChainingHashST)
using std::pair;
using std::list;             // Doubly-Linked List with size() ( O( 1 ) )
using std::forward_list;     // Singly-Linked List without size() function ( so O( N ) if we need to get size() )
using std::deque;            // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque
using std::queue;            // Non-Iterable & Use std::deque as underlying data structure
using std::stack;            // Non-Iterable & Use std::deque as underlying data structure
using std::next;             // Return an advanced iter without changing original iter
using std::fill;
using std::max;
using std::min;
using std::find;
using std::make_shared;
using std::shared_ptr;

class Graph {
private:

    vector< forward_list< int > > adj;
    int V = 0;
    int E = 0;

public:

    Graph( int V )
            : V( V )
    {
        adj.resize( V );
    }

    virtual ~Graph() {
        // not implemented
    }

    int getV() const {
        return V;
    }

    int getE() const {
        return E;
    }

    string toString() const {
        string rv = "\nV : " + to_string( V ) + " ; E : " + to_string( E ) + " ; adj : \n";
        for ( int v = 0; v < V; ++v ) {
            rv += "\n| v : " + to_string( v ) + " : ";
            for ( int w : getAdj( v ) ) {
                rv += to_string( w ) + ", ";
            }
            rv += " | ";
        }
        return rv;
    }

    forward_list< int > getAdj( int v ) const {
        return adj[ v ];
    }

    void addEdge( int v, int w ) {
        adj[ v ].push_front( w );
        adj[ w ].push_front( v );
        ++E;
    }

    static int degree( const Graph& G, int v ) {
        int deg = 0;
        for ( int w : G.getAdj( v ) ) {
            ++deg;
        }
        return deg;
    }

    static int maxDegree( const Graph& G ) {
        int maxDeg = 0;
        for ( int v = 0; v < G.getV(); ++v ) {
            int deg = degree( G, v );
            if ( maxDeg < deg ) {
                maxDeg = deg;
            }
        }
        return maxDeg;
    }

    static int avgDegree( const Graph& G ) {
        return 2 * G.getE() / G.getV();
    }

    static int numSelfLoops( const Graph& G ) {
        int count = 0;
        for ( int v = 0; v < G.getV(); ++v ) {
            for ( int w : G.getAdj( v ) ) {
                if ( v == w ) {
                    ++count;
                }
            }
        }
        return count / 2;
    }
};

class Biconnected {
private:

    vector< int > low;
    vector< int > pre;
    int count = 0;
    vector< bool > articulation;

public:

    Biconnected( const Graph& G )
        : low( G.getV(), -1 ),
          pre( G.getV(), -1 ),
          articulation( G.getV(), false )
    {
        for ( int v = 0; v < G.getV(); ++v ) {
            if ( pre[ v ] == -1 ) {
                dfs( G, v, v );
            }
        }
    }

    virtual ~Biconnected() {
        // not implemented
    }

    void dfs( const Graph& G, int v, int u ) {
        int children = 0;
        pre[ v ] = count++;
        low[ v ] = pre[ v ];
        for ( int w : G.getAdj( v ) ) {
            if ( pre[ w ] == -1 ) {
                ++children;
                dfs( G, w, v );

                //
                // Update low number
                //
                low[ v ] = min( low[ v ], low[ w ] );

                //
                // If v is not the root of DFS traversal ( u != v ), then
                // criteria for v to become articulation point is when
                // there is no way to reach back from w to v, since the lowest
                // value of path to w ( low[ w ] ) is larger than the max
                // preorder traversal value v can carry ( pre[ v ] ).
                //
                // In other words, v is articulation point only if removing
                // v disconnects the graph.
                //
                if ( low[ w ] >= pre[ v ] && u != v ) {
                    articulation[ v ] = true;
                }
            } else if ( w != u ) {
                //
                // Update low number - ignore reverse of edge leading to v
                //
                low[ v ] = min( low[ v ], pre[ w ] );
            }
        }

        //
        // Root of DFS is articulation point if it has more than 1 child
        //
        // Since this is a DFS, the amount of children is the amount of
        // components that don't have a back edge to one another.
        //
        // If they do, pre[ w ] == -1 above would have evaluated to false
        // because w should never be visited by the DFS path starting from
        // vertices other than w.
        //
        if ( u == v && children > 1 ) {
            articulation[ v ] = true;
        }
    }

    string toString() const {
        string rv = "\n";
        for ( int v = 0; v < pre.size(); ++v ) {
            rv += "\n| v : " + to_string( v );
            rv += " ; pre : " + to_string( pre[ v ] );
            rv += " ; low : " + to_string( low[ v ] );
            rv += " ; articulation : " + to_string( articulation[ v ] ) + " | ";
        }
        return rv;
    }

    bool isArticulation( int v ) const {
        return articulation[ v ];
    }
};

int main( int argc, char ** argv ) {

    int graphArr[ 16 ][ 2 ] = {
            { 0, 5 },
            { 4, 3 },
            { 0, 1 },
            { 9, 12 },
            { 6, 4 },
            { 5, 4 },
            { 0, 2 },
            { 11, 12 },
            { 9, 10 },
            { 0, 6 },
            { 7, 8 },
            { 9, 11 },
            { 5, 3 },
            { 6, 7 },
            { 7, 9 },
            { 8, 9 }
    };

    Graph graph( 13 );

    for ( int i = 0; i < 16; ++i ) {
        graph.addEdge( graphArr[ i ][ 0 ], graphArr[ i ][ 1 ] );
    }

    cout << "DEBUG: graph: \n" << graph.toString() << endl;

    Biconnected biconnected( graph );
    cout << "DEBUG: biconnected: \n" << biconnected.toString() << endl;

    return 0;
}
