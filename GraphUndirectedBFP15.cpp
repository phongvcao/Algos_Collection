//
// Created by Phong Cao on 2019-02-13.
//

#include <iostream>
#include <sstream>
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

    int V = 0;
    int E = 0;
    vector< forward_list< int > > adj;

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

    forward_list< int > getAdj( int v ) const {
        return adj[ v ];
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

class BFP {
private:

    vector< bool > marked;
    vector< int > edgeTo;
    int s = 0;

public:

    BFP( const Graph& G, int s )
        : s( s )
    {
        marked.resize( G.getV() );
        edgeTo.resize( G.getV() );
        bfs( G, s );
    }

    virtual ~BFP() {
        // not implemented
    }

    void bfs( const Graph& G, int v ) {
        marked[ v ] = true;
        queue< int > q;
        q.push( v );
        while ( ! q.empty() ) {
            int w = q.front();
            q.pop();
            for ( int x : G.getAdj( w ) ) {
                if ( ! hasPathTo( x ) ) {
                    marked[ x ] = true;
                    edgeTo[ x ] = w;
                    q.push( x );
                }
            }
        }
    }

    string toString() const {
        string rv = "\ns : " + to_string( s ) + " ; edgeTo : \n";
        for ( int v = 0; v < edgeTo.size(); ++v ) {
            rv += "\n| v : " + to_string( v ) + " : ";
            for ( int w : pathTo( v ) ) {
                rv += to_string( w ) + ", ";
            }
            rv += " | ";
        }
        return rv;
    }

    bool hasPathTo( int w ) const {
        return marked[ w ];
    }

    forward_list< int > pathTo( int v ) const {
        forward_list< int > path;
        if ( ! hasPathTo( v ) ) return path;
        for ( int w = v; w != s; w = edgeTo[ w ] ) {
            path.push_front( w );
        }
        path.push_front( s );
        return path;
    }
};

class DFP {
private:

    vector< bool > marked;
    vector< int > edgeTo;
    int s = 0;

public:

    DFP( const Graph& G, int s )
        : s( s )
    {
        marked.resize( G.getV() );
        edgeTo.resize( G.getV() );
        dfs( G, s );
    }

    virtual ~DFP() {
        // not implemented
    }

    void dfs( const Graph& G, int v ) {
        marked [ v ] = true;
        for ( int w : G.getAdj( v ) ) {
            if ( ! hasPathTo( w ) ) {
                edgeTo[ w ] = v;
                dfs( G, w );
            }
        }
    }

    string toString() const {
        string rv = "\ns : " + to_string( s ) + " ; edgeTo : \n";
        for ( int v = 0; v < edgeTo.size(); ++v ) {
            rv += "\n| v : " + to_string( v ) + " : ";
            for ( int w : pathTo( v ) ) {
                rv += to_string( w ) + ", ";
            }
            rv += " | ";
        }
        return rv;
    }

    forward_list< int > pathTo( int v ) const {
        forward_list< int > path;
        if ( ! hasPathTo( v ) ) return path;
        for ( int w = v; w != s; w = edgeTo[ w ] ) {
            path.push_front( w );
        }
        path.push_front( s );
        return path;
    }

    bool hasPathTo( int v ) const {
        return marked[ v ];
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

    DFP dfp( graph, 0 );
    cout << "DEBUG: dfp.toString(): \n" << dfp.toString() << endl;

    BFP bfp( graph, 0 );
    cout << "DEBUG: bfp.toString(): \n" << bfp.toString() << endl;

    return 0;
}
