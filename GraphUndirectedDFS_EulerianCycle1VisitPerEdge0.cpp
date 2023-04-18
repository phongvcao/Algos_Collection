//
// Created by Phong Cao on 2019-02-17.
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
using std::unique_ptr;
using std::make_unique;

//
// Eulerian Cycle:
//
// 1. All vertices with non-zero degree are connected
// 2. All vertices have even degree
//
//
// Time Complexity : O( V + E )
// Space Complexity : O( V + E )
//
class EulerianCycle {
private:

    class Edge {
    public:
        int v = -1;
        int w = -1;
        bool isUsed = false;

        Edge( int v, int w )
            : v( v ),
              w( w )
        {
            // empty for now
        }

        Edge( const Edge& other )
            : v( other.v ),
              w( other.w )
        {
            // empty for now
        }

        virtual ~Edge() {
            // empty for now
        }

        int getEither() const {
            return v;
        }

        int getOther( int x ) const {
            return ( x == v ) ? w : v;
        }
    };

    int edgeCnt = 0;
    int nonIsolatedVertex = -1;
    vector< unique_ptr< Edge > > edgesVec;
    stack< int > eulerianCycle;

    Edge * newEdge( int v, int w ) {
        edgesVec.push_back( make_unique< Edge >( v, w ) );
        return edgesVec.back().get();
    }

public:

    EulerianCycle( const vector< vector< int > >& G ) {
        vector< queue< Edge * > > adjQueue( G.size(), queue< Edge * >() );
        for ( int v = 0; v < G.size(); ++v ) {
            //
            // Condition 1 : Degree of each vertex must be even
            //
            if ( G[ v ].size() % 2 != 0 ) {
                return;
            }
            
            //
            // We will start the search from an edge with degree > 0 if any
            //
            if ( G[ v ].size() > 0 && nonIsolatedVertex == -1 ) {
                nonIsolatedVertex = v;
            }

            //
            // Condition 2 : The graph must have at least 1 edge
            //
            int selfLoops = 0;
            for ( int w : G[ v ] ) {
                //
                // Build the list of graph edges
                //
                if ( v == w ) {
                    ++edgeCnt;
                    if ( selfLoops % 2 == 0 ) {
                        Edge * e = newEdge( v, w );
                        adjQueue[ v ].push( e );
                        adjQueue[ w ].push( e );
                    }
                    ++selfLoops;
                } else if ( v < w ) {
                    ++edgeCnt;
                    Edge * e = newEdge( v, w );
                    adjQueue[ v ].push( e );
                    adjQueue[ w ].push( e );
                }
            }
        }

        //
        // If the graph has no edge, it won't have Eulerian Cycle
        // ( it may still have degenerate Eulerian path though )
        //
        if ( edgeCnt == 0 ) return;

        //
        // DFS using a stack< int > instead of Recursion because we're
        // mark-ing the edges and not the vertices - thus we used adjQueue
        // to traverse edges instead of adjList to traverse vertices.
        //
        stack< int > verticesStack;
        verticesStack.push( nonIsolatedVertex );

        while ( ! verticesStack.empty() ) {
            int v = verticesStack.top();
            verticesStack.pop();

            while ( ! adjQueue[ v ].empty() ) {
                Edge * edge = adjQueue[ v ].front();
                adjQueue[ v ].pop();
                if ( edge->isUsed ) continue;
                edge->isUsed = true;
                verticesStack.push( v );
                v = edge->getOther( v );
            }
            eulerianCycle.push( v );
        }

        if ( eulerianCycle.size() != edgeCnt + 1 ) {
            eulerianCycle = stack< int >();
        }
    }

    virtual ~EulerianCycle() {
        // empty for now
    }

    stack< int > getEulerianCycle() const {
        return eulerianCycle;
    }

    bool hasEulerianCycle() const {
        return ! eulerianCycle.empty();
    }

    friend ostream& operator <<( ostream& out, const EulerianCycle& ec ) {
        out << "ec:\n\n";

        stack< int > eulerianCycle = ec.getEulerianCycle();
        while ( ! eulerianCycle.empty() ) {
            out << eulerianCycle.top() << ", ";
            eulerianCycle.pop();
        }
        out << endl;

        return out;
    }

};

int main( int argc, char ** argv ) {

    vector< vector< int > > graph1Arr {
            { 0, 1 },
            { 0, 2 },
            { 0, 3 },
            { 1, 3 },
            { 1, 4 },
            { 2, 5 },
            { 2, 9 },
            { 3, 6 },
            { 4, 7 },
            { 4, 8 },
            { 5, 8 },
            { 5, 9 },
            { 6, 7 },
            { 6, 9 },
            { 7, 8 },
    };
    vector< vector< int > > graph1( 10, vector< int >() );
    for ( int i = 0; i < graph1Arr.size(); i++ ) {
        graph1[ graph1Arr[ i ][ 0 ] ].push_back( graph1Arr[ i ][ 1 ] );
        graph1[ graph1Arr[ i ][ 1 ] ].push_back( graph1Arr[ i ][ 0 ] );
    }
    EulerianCycle eulerian1( graph1 );

    if ( ! eulerian1.hasEulerianCycle() ) {
        cout << "DEBUG : graph1 DOES NOT HAVE Eulerian Cycle!!!" << endl;
    } else {
        cout << "DEBUG : graph1 DOES HAVE Eulerian Cycle!!!" << endl;
        cout << eulerian1 << endl;
    }

    vector< vector< int > > graph2Arr {
            { 0, 1 },
            { 1, 2 },
            { 2, 0 },
            { 0, 3 },
            { 3, 4 },
            { 0, 4 },
    };
    vector< vector< int > > graph2( 5, vector< int >() );
    for ( int i = 0; i < graph2Arr.size(); i++ ) {
        graph2[ graph2Arr[ i ][ 0 ] ].push_back( graph2Arr[ i ][ 1 ] );
        graph2[ graph2Arr[ i ][ 1 ] ].push_back( graph2Arr[ i ][ 0 ] );
    }
    EulerianCycle eulerian2( graph2 );

    if ( ! eulerian2.hasEulerianCycle() ) {
        cout << "DEBUG : graph2 DOES NOT HAVE Eulerian Cycle!!!" << endl;
    } else {
        cout << "DEBUG : graph2 DOES HAVE Eulerian Cycle!!!" << endl;
        cout << eulerian2 << endl;
    }

    vector< vector< int > > graph3Arr {
            { 0, 1 },
            { 1, 2 },
            { 2, 3 },
            { 3, 4 },
            { 4, 5 },
            { 5, 6 },
            { 6, 7 },
            { 7, 8 },
            { 8, 9 },
    };
    vector< vector< int > > graph3( 10, vector< int >() );
    for ( int i = 0; i < graph3Arr.size(); i++ ) {
        graph3[ graph3Arr[ i ][ 0 ] ].push_back( graph3Arr[ i ][ 1 ] );
        graph3[ graph3Arr[ i ][ 1 ] ].push_back( graph3Arr[ i ][ 0 ] );
    }
    EulerianCycle eulerian3( graph3 );

    if ( ! eulerian3.hasEulerianCycle() ) {
        cout << "DEBUG : graph3 DOES NOT HAVE Eulerian Cycle!!!" << endl;
    } else {
        cout << "DEBUG : graph3 DOES HAVE Eulerian Cycle!!!" << endl;
        cout << eulerian3 << endl;
    }

    vector< vector< int > > graph4Arr {
            { 0, 1 },
            { 1, 2 },
            { 2, 3 },
            { 3, 4 },
            { 4, 5 },
            { 5, 6 },
            { 6, 7 },
            { 7, 8 },
            { 8, 9 },
            { 9, 0 },
    };
    vector< vector< int > > graph4( 10, vector< int >() );
    for ( int i = 0; i < graph4Arr.size(); i++ ) {
        graph4[ graph4Arr[ i ][ 0 ] ].push_back( graph4Arr[ i ][ 1 ] );
        graph4[ graph4Arr[ i ][ 1 ] ].push_back( graph4Arr[ i ][ 0 ] );
    }
    EulerianCycle eulerian4( graph4 );

    if ( ! eulerian4.hasEulerianCycle() ) {
        cout << "DEBUG : graph4 DOES NOT HAVE Eulerian Cycle!!!" << endl;
    } else {
        cout << "DEBUG : graph4 DOES HAVE Eulerian Cycle!!!" << endl;
        cout << eulerian4 << endl;
    }

    return 0;
}
