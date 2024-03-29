//
// Created by Phong Cao on 2019-02-19.
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

class Digraph {
private:

    int V = 0;
    int E = 0;
    vector< forward_list< int > > adj;

public:

    Digraph( int V )
            : V( V )
    {
        adj.resize( V );
    }

    virtual ~Digraph() {
        // not implemented
    }

    int getV() const {
        return V;
    }

    int getE() const {
        return E;
    }

    string toString() {
        string rv = "\n";
        for ( int v = 0; v < V; ++v ) {
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
        ++E;
    }

    Digraph reverse() {
        Digraph R( V );
        for ( int v = 0; v < V; ++v ) {
            for ( int w : getAdj( v ) ) {
                R.addEdge( w, v );
            }
        }
        return R;
    }
};

class DirectedDFS {
private:

    vector< bool > marked;

    void dfsRecursively( Digraph& G, int v ) {
        marked[ v ] = true;
        for ( int w : G.getAdj( v ) ) {
            if ( ! isMarked( w ) ) {
                dfsRecursively( G, w );
            }
        }
    }

    void dfsIteratively( Digraph& G, int s ) {
        vector< bool > marked( G.getV(), false );

        vector< forward_list< int >::iterator > adj( G.getV() );
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
                    dfsStack.push( w );
                }
            } else {
                dfsStack.pop();
            }
        }

        this->marked = marked;
    }

public:

    DirectedDFS( Digraph& G, int s, bool isRecursive = true ) {
        dfs( G, s, isRecursive );
    }

    DirectedDFS( Digraph& G,
                 const forward_list< int >& sources,
                 bool isRecursive = true ) {
        marked.resize( G.getV() );
        for ( int s : sources ) {
            if ( ! isMarked( s ) ) {
                dfs( G, s, isRecursive );
            }
        }
    }

    void dfs( Digraph& G, int v, bool isRecursive = true ) {
        if ( isRecursive ) {
            marked.resize( G.getV() );
            dfsRecursively( G, v );
        } else {
            dfsIteratively( G, v );
        }
    }

    string toString() const {
        string rv = "\n";
        for ( int v = 0; v < marked.size(); ++v ) {
            rv += "\n| v : " + to_string( v ) + " : " + to_string( marked[ v ] ) + " | ";
        }
        return rv;
    }

    bool isMarked( int v ) const {
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

    Digraph dGraph( 13 );

    for ( int i = 0; i < 16; ++i ) {
        dGraph.addEdge( graphArr[ i ][ 0 ], graphArr[ i ][ 1 ] );
    }

    cout << "DEBUG: dGraph: \n" << dGraph.toString() << endl;
    cout << "DEBUG: dGraph.reverse(): \n" << dGraph.reverse().toString() << endl;

    DirectedDFS dfsRecursive( dGraph, 0, true );
    cout << "DEBUG: dfsRecursive: \n" << dfsRecursive.toString() << endl;
    
    DirectedDFS dfsIterative( dGraph, 0, false );
    cout << "DEBUG: dfsIterative: \n" << dfsIterative.toString() << endl;

    return 0;
}
