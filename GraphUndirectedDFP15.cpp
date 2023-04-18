//
// Created by Phong Cao on 2019-02-12.
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

    string toString() {
        string rv = "\nV : " + to_string( V ) + " ; E : " + to_string( E ) + " ; adj : \n";
        for ( int v = 0; v < getV(); ++v ) {
            rv += "\n| v : " + to_string( v ) + " : ";
            for ( int w : getAdj( v ) ) {
                rv += to_string( w ) + ", ";
            }
            rv += " | ";
        }
        return rv;
    }

    forward_list< int > & getAdj( int v ) {
        return adj[ v ];
    }

    void addEdge( int v, int w ) {
        adj[ v ].push_front( w );
        adj[ w ].push_front( v );
        ++E;
    }

    static int degree( Graph& G, int v ) {
        int deg = 0;
        for ( int w : G.getAdj( v ) ) {
            ++deg;
        }
        return deg;
    }

    static int maxDegree( Graph& G ) {
        int maxDeg = 0;
        for ( int v = 0; v < G.getV(); ++v ) {
            int deg = degree( G, v );
            if ( maxDeg < deg ) {
                maxDeg = deg;
            }
        }
        return maxDeg;
    }

    static int avgDegree( Graph& G ) {
        return 2 * G.getE() / G.getV();
    }

    static int numSelfLoops( Graph& G ) {
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

class DFP {
private:

    vector< bool > marked;
    vector< int > edgeTo;
    int s = 0;

    void dfsRecursively( Graph& G, int v ) {
        marked[ v ] = true;
        for ( int w : G.getAdj( v ) ) {
            if ( ! hasPathTo( w ) ) {
                edgeTo[ w ] = v;
                dfs( G, w );
            }
        }
    }

    void dfsIteratively( Graph& G, int s ) {
        vector< bool > marked( G.getV(), false );
        vector< int > edgeTo( G.getV(), -1 );
        vector< forward_list< int >::iterator >  adj( G.getV() );
        for ( int v = 0; v < G.getV(); v++ ) {
            adj[ v ] = G.getAdj( v ).begin();
        }

        stack< int > dfsStack;
        marked[ s ] = true;
        dfsStack.push( s );

        while ( ! dfsStack.empty() ) {
            int v = dfsStack.top();
            if ( adj[ v ] != G.getAdj( v ).end() ) {
                int w = *( adj[ v ] );
                ++adj[ v ];
                if ( ! marked[ w ] ) {
                    marked[ w ] = true;
                    edgeTo[ w ] = v;
                    dfsStack.push( w );
                }
            } else {
                dfsStack.pop();
            }
        }

        this->marked = marked;
        this->edgeTo = edgeTo;
    }

public:

    DFP( Graph& G, int s, bool isRecursive = true )
        : s( s )
    {
        dfs( G, s, isRecursive );
    }

    virtual ~DFP() {
        // not implemented
    }

    void dfs( Graph& G, int v, bool isRecursive = true ) {
        if ( isRecursive ) {
            marked.resize( G.getV() );
            edgeTo.resize( G.getV() );
            dfsRecursively( G, v );
        } else {
            dfsIteratively( G, v );
        }
    }

    forward_list< int > pathTo( int v ) const {
        forward_list< int > path;
        for ( int w = v; w != s; w = edgeTo[ w ] ) {
            path.push_front( w );
        }
        path.push_front( s );
        return path;
    }

    bool hasPathTo( int v ) const {
        return marked[ v ];
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

    DFP dfpRecursive( graph, 0, true );
    cout << "DEBUG: dfpRecursive.toString(): \n" << dfpRecursive.toString() << endl;
    
    DFP dfpIterative( graph, 0, false );
    cout << "DEBUG: dfpIterative.toString(): \n" << dfpIterative.toString() << endl;

    return 0;
}
