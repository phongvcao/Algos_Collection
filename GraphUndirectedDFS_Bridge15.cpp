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

class Bridge {
private:

    vector< int > pre;
    vector< int > low;
    int count = 0;
    int bridgesCnt = 0;
    vector< pair< int, int > > bridges;

public:

    Bridge( const Graph& G )
        : pre( G.getV(), -1 ),
          low( G.getV(), -1 )
    {
        for ( int v = 0; v < G.getV(); ++v ) {
            if ( pre[ v ] == -1 ) {
                dfs( G, v, v );
            }
        }
    }

    virtual ~Bridge() {
        // not implemented
    }

    void dfs( const Graph& G, int v, int u ) {
        //
        // Update traversal order of v
        //
        pre[ v ] = count++;
        //
        // Initially earliest visited node reachable from v is the traversal
        // order of v itself ( pre[ v ] )
        //
        low[ v ] = pre[ v ];
        for ( int w : G.getAdj( v ) ) {
            if ( pre[ w ] == -1 ) {
                dfs( G, w, v );

                //
                // The earliest visited node reachable from v is equal the
                // earliest visited node of the earliest visited node reachable
                // from v's children.
                //
                low[ v ] = min( low[ v ], low[ w ] );

                //
                // If the earliest visited node reachable from w is equal the
                // traversal order of w itself, then that means node w cannot
                // be reached from any node other than w itself, which means
                // the initially low[ v ] = pre[ v ] value above did not change
                // after the DFS, then ( v-w ) is a bridge.
                //
                if ( low[ w ] == pre[ w ] ) {
                    bridges.push_back( { v, w } );
                    ++bridgesCnt;
                }
            } else if ( w != u ) {
                //
                // ElseIf w was already visited and w was NOT the parent node
                // of v, we update the earliest visited node reachable from v
                // ( low[ v ] )
                //
                low[ v ] = min( low[ v ], pre[ w ] );
            }
        }
    }

    string toString() const {
        string rv = "\n";
        for ( int v = 0; v < pre.size(); ++v ) {
            rv += "\n| v : " + to_string( v ) + " ; pre : " + to_string( pre[ v ] ) + " ; low : " + to_string( low[ v ] ) + " | ";
        }

        rv += "\n\nList of Bridges :\n\n";
        for ( int i = 0; i < bridges.size(); ++i ) {
            rv += "| " + to_string( bridges[ i ].first ) + " : " + to_string( bridges[ i ].second  ) + " |\n";
        }
        return rv;
    }

    int getBridgesCount() const {
        return bridgesCnt;
    }
    
    vector< pair< int, int > > getBridges() const {
        return bridges;
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

    Bridge bridge( graph );
    cout << "DEBUG: bridge: \n" << bridge.toString() << endl;
    cout << "DEBUG: bridge.getBridges(): \n" << bridge.getBridgesCount() << endl;

    return 0;
}
