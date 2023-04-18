//
// Created by Phong Cao on 2019-04-03.
//

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <iterator>
#include <utility>
#include <algorithm>
#include <memory>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <numeric>

//----<iostream>------------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----<cstdio>--------------//
using std::printf;
using std::fprintf;
using std::sprintf;
using std::snprintf;

//----<iomanip>-------------//
using std::setprecision;
using std::setw;

//----<ios>-----------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----<sstream>-------------//
using std::ostringstream;
using std::istringstream;

//----<fstream>-------------//
using std::ofstream;
using std::ifstream;

//----<string>--------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;

//----<cmath>---------------//
using std::sqrt;
using std::pow;
using std::log;             // log( <arg> )
using std::exp;             // e ^ <arg>
using std::abs;

//----<cstdlib>-------------//
using std::rand;
using std::srand;

//----<ctime>---------------//
using std::time;

//----<functional>----------//
using std::hash;
using std::greater;         // lhs > rhs. Used for MinPQ
using std::less;            // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;

//----<vector>--------------//
using std::vector;          // Unordered Array

//----<map>-----------------//
using std::map;             // Ordered Map (Red-Black Tree)

//----<unordered_map>-------//
using std::unordered_map;   // HashMap (SeparateChainingHashST)

//----<set>-----------------//
using std::set;             // Ordered Set (Red-Black Tree)

//----<unordered_set>-------//
using std::unordered_set;   // HashSet (SeparateChainingHashST)

//----<list>----------------//
using std::list;            // Doubly-Linked List with size() ( O( 1 ) )

//----<forward_list>--------//
using std::forward_list;    // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----<deque>---------------//
using std::deque;           // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----<queue>---------------//
using std::queue;           // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;  // MaxPQ (MaxHeap) & Non-Iterable.
//                          // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----<stack>---------------//
using std::stack;           // Non-Iterable & Use std::deque as underlying data structure

//----<iterator>------------//
using std::next;            // Return an advanced iter without changing original iter
using std::prev;            // Return an decremented iter without changin original iter
using std::distance;        // Calculate distance between 2 iterators

//----<utility>-------------//
using std::pair;

//----<algorithm>-----------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;

//----<memory>--------------//
using std::make_shared;
using std::shared_ptr;

//----<cctype>--------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;         // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;         // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----<stdexcept>-----------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----<limits>--------------//
using std::numeric_limits;

//----<numeric>-------------//
using std::iota;
using std::gcd;
using std::lcm;

//--------------------------//

class DirectedEdge {
private:

    int v = 0;
    int w = 0;
    double weight = numeric_limits< double >::infinity();

public:

    DirectedEdge() {
        // not implemented
    }

    DirectedEdge( int v, int w, double weight )
        : v( v ),
          w( w ),
          weight( weight )
    {
        // not implemented
    }

    DirectedEdge( const DirectedEdge& e )
        : v( e.v ),
          w( e.w ),
          weight( e.weight )
    {
        // not implemented
    }

    virtual ~DirectedEdge() {
        // not implemented
    }

    int getFrom() const {
        return v;
    }

    int getTo() const {
        return w;
    }

    double getWeight() const {
        return weight;
    }

    operator bool() const {
        return weight != numeric_limits< double >::infinity();
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const DirectedEdge& e ) {
        out << fixed << setprecision( 2 );
        out << " | " << e.v << " : " << e.w << " : " << e.weight << " | ";
        return out;
    }

};

class EdgeWeightedDigraph {
private:

    int V = 0;
    int E = 0;
    vector< forward_list< DirectedEdge > > adj;

public:

    EdgeWeightedDigraph( int V )
        : V( V ),
          adj( V )
    {
        // not implemented
    }

    virtual ~EdgeWeightedDigraph() {
        // not implemented
    }

    int getV() const {
        return V;
    }

    int getE() const {
        return E;
    }

    forward_list< DirectedEdge > getAdj( int v ) const {
        return adj[ v ];
    }

    forward_list< DirectedEdge > getEdges() const {
        forward_list< DirectedEdge > all;
        for ( int v = 0; v < getV(); ++v ) {
            for ( DirectedEdge e : getAdj( v ) ) {
                all.push_front( e );
            }
        }
        return all;
    }

    void addEdge( DirectedEdge e ) {
        adj[ e.getFrom() ].push_front( e );
        ++E;
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const EdgeWeightedDigraph& G ) {
        out << "\n| V : " << G.getV() << " ; E : " << G.getE() << " ; adj : \n";
        for ( int v = 0; v < G.getV(); ++v ) {
            out << "\n| v : " << v << " : ";
            for ( const DirectedEdge& e : G.getAdj( v ) ) {
                out << e << ", ";
            }
            out << " | ";
        }
        return out;
    }

};

class AdjMatrixEdgeWeightedDigraph {
private:

    int V = 0;
    int E = 0;
    vector< vector< DirectedEdge > > adj;

public:

    AdjMatrixEdgeWeightedDigraph( int V )
        : V( V ),
          adj( V, vector< DirectedEdge >( V ) )
    {
        // not implemented
    }

    virtual ~AdjMatrixEdgeWeightedDigraph() {
        // not implemented
    }

    int getV() const {
        return V;
    }

    int getE() const {
        return E;
    }

    forward_list< DirectedEdge > getAdj( int v ) const {
        forward_list< DirectedEdge > adjList;
        for ( int w = 0; w < adj[ v ].size(); ++w ) {
            if ( adj[ v ][ w ] ) {
                adjList.push_front( adj[ v ][ w ] );
            }
        }
        return adjList;
    }

    forward_list< DirectedEdge > getEdges() const {
        forward_list< DirectedEdge > all;
        for ( int v = 0; v < getV(); ++v ) {
            for ( DirectedEdge e : getAdj( v ) ) {
                all.push_front( e );
            }
        }
        return all;
    }

    void addEdge( DirectedEdge e ) {
        adj[ e.getFrom() ][ e.getTo() ] = e;
        ++E;
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const AdjMatrixEdgeWeightedDigraph& G ) {
        out << "\n| V : " << G.getV() << " ; E : " << G.getE() << " ; adj : \n";
        for ( int v = 0; v < G.getV(); ++v ) {
            out << "\n| v : " << G.getV() << " : ";
            for ( const DirectedEdge& e : G.getAdj( v ) ) {
                out << e << ", ";
            }
            out << " | ";
        }
        return out;
    }

};

class DirectedCycle {
private:

    vector< bool > marked;
    vector< bool > onStack;
    vector< DirectedEdge > edgeTo;
    stack< DirectedEdge > cycle;

    void dfs( const EdgeWeightedDigraph& G, int v ) {
        marked[ v ] = true;
        onStack[ v ] = true;

        for ( DirectedEdge e : G.getAdj( v ) ) {
            int w = e.getTo();
            if ( hasCycle() ) {
                return;
            } else if ( ! marked[ w ] ) {
                edgeTo[ w ] = e;
                dfs( G, w );
            } else if ( onStack[ w ] ) {
                // cycle detected
                for ( int x = v; x != w; x = edgeTo[ x ].getFrom() ) {
                    if ( edgeTo[ x ] ) {
                        cycle.push( edgeTo[ x ] );
                    }
                }
                cycle.push( e );
            }
        }

        onStack[ v ] = false;
    }

public:

    DirectedCycle( const EdgeWeightedDigraph& G )
        : marked( G.getV(), false ),
          onStack( G.getV(), false ),
          edgeTo( G.getV() )
    {
        for ( int v = 0; v < G.getV(); ++v ) {
            if ( ! marked[ v ] ) {
                dfs( G, v );
            }
        }
    }

    virtual ~DirectedCycle() {
        // not implemented
    }

    bool hasCycle() const {
        return ! cycle.empty();
    }

    stack< DirectedEdge > getCycle() const {
        return cycle;
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const DirectedCycle& dCycle ) {
        out << "\ncycle:\n";
        stack< DirectedEdge > s = dCycle.getCycle();
        while ( ! s.empty() ) {
            out << s.top() << ", ";
            s.pop();
        }
        return out;
    }

};

//
// Time Complexity : O( V ^ 3 )
// Space Complexity : O( V ^ 2 )
//
class FloydWarshallAllPairsDenseSP {
private:

    bool negativeCycleFound = false;
    vector< vector< DirectedEdge > > edgeTo;
    vector< vector< double > > distTo;

public:

    FloydWarshallAllPairsDenseSP( const AdjMatrixEdgeWeightedDigraph& G )
        : edgeTo( G.getV(), vector< DirectedEdge >( G.getV() ) ),
          distTo( G.getV(), vector< double >( G.getV(), numeric_limits< double >::infinity() ) )
    {
        for ( int v = 0; v < G.getV(); ++v ) {
            for ( DirectedEdge e : G.getAdj( v ) ) {
                int w = e.getTo();
                distTo[ v ][ w ] = e.getWeight();
                edgeTo[ v ][ w ] = e;
            }

            if ( distTo[ v ][ v ] >= 0 ) {
                distTo[ v ][ v ] = 0;
                DirectedEdge nullEdge;
                edgeTo[ v ][ v ] = nullEdge;
            }
        }

        for ( int i = 0; i < G.getV(); ++i ) {
            for ( int v = 0; v < G.getV(); ++v ) {
                if ( ! edgeTo[ v ][ i ] ) continue;
                for ( int w = 0; w < G.getV(); ++w ) {
                    if ( distTo[ v ][ w ] > distTo[ v ][ i ] + distTo[ i ][ w ] ) {
                        distTo[ v ][ w ] = distTo[ v ][ i ] + distTo[ i ][ w ];
                        edgeTo[ v ][ w ] = edgeTo[ i ][ w ];
                    }
                }

                if ( distTo[ v ][ v ] < 0 ) {
                    negativeCycleFound = true;
                    return;
                }
            }
        }
    }

    virtual ~FloydWarshallAllPairsDenseSP() {
        // not implemented
    }

    bool hasPath( int v, int w ) const {
        return distTo[ v ][ w ] != numeric_limits< double >::infinity();
    }

    stack< DirectedEdge > getPath( int v, int w ) const {
        if ( hasNegativeCycle() ) throw runtime_error( "Negative cost cycle exists\n" );
        stack< DirectedEdge > path;
        if ( ! hasPath( v, w ) ) return path;
        for ( DirectedEdge e = edgeTo[ v ][ w ]; e; e = edgeTo[ v ][ e.getFrom() ] ) {
            path.push( e );
        }
        return path;
    }

    double getDist( int v, int w ) const {
        if ( hasNegativeCycle() ) throw runtime_error( "Negative cost cycle exists\n" );
        return distTo[ v ][ w ];
    }

    bool hasNegativeCycle() const {
        return negativeCycleFound;
    }

    stack< DirectedEdge > getNegativeCycle() const {
        stack< DirectedEdge > negativeCycle;
        if ( ! hasNegativeCycle() ) return negativeCycle;
        for ( int v = 0; v < distTo.size(); ++v ) {
            if ( distTo[ v ][ v ] < 0 ) {
                int V = edgeTo.size();
                EdgeWeightedDigraph spG( V );
                for ( int w = 0; w < V; ++w ) {
                    if ( edgeTo[ v ][ w ] ) {
                        spG.addEdge( edgeTo[ v ][ w ] );
                    }
                }

                DirectedCycle cycleFinder( spG );
                negativeCycle = cycleFinder.getCycle();
            }
        }
        return negativeCycle;
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const FloydWarshallAllPairsDenseSP& sp ) {
        out << "\nsp:\n";
        for ( int v = 0; v < sp.edgeTo.size(); ++v ) {
            out << "\n| v : " << v << " : \n";
            for ( int w = 0; w < sp.edgeTo.size(); ++w ) {
                out << "\n| w : " << w << " : ";
                stack< DirectedEdge > s = sp.getPath( v, w );
                while ( ! s.empty() ) {
                    out << s.top() << ", ";
                    s.pop();
                }
                out << " | ";
            }
            out << " | \n";
        }

        out << "\n\ndistTo:\n";
        for ( int v = 0; v < sp.distTo.size(); ++v ) {
            out << "\n| v : " << v << " : ";
            for ( int w = 0; w < sp.distTo.size(); ++w ) {
                out << "\n| w : " << w << " : ";
                if ( sp.edgeTo[ v ][ w ] ) {
                    out << " | w : " << sp.distTo[ v ][ w ] << " | , ";
                }
                out << " | ";
            }
            out << " | ";
        }

        out << "\n\nedgeTo:\n";
        for ( int v = 0; v < sp.edgeTo.size(); ++v ) {
            out << "\n| v : " << v << " : ";
            for ( int w = 0; w < sp.edgeTo.size(); ++w ) {
                out << "\n| w : " << w << " : ";
                if ( sp.edgeTo[ v ][ w ] ) {
                    out << " | w : " << sp.edgeTo[ v ][ w ] << " | , ";
                }
                out << " | ";
            }
            out << " | ";
        }

        return out;
    }

};

int main( int argc, char ** argv ) {

    double graphArr[ 15 ][ 3 ] = {
            { 4, 5, 0.35 },
            { 5, 4, 0.35 },
            { 4, 7, 0.37 },
            { 5, 7, 0.28 },
            { 7, 5, 0.28 },
            { 5, 1, 0.32 },
            { 0, 4, 0.38 },
            { 0, 2, 0.26 },
            { 7, 3, 0.39 },
            { 1, 3, 0.29 },
            { 2, 7, 0.34 },
            { 6, 2, 0.40 },
            { 3, 6, 0.52 },
            { 6, 0, 0.58 },
            { 6, 4, 0.93 }
    };

    AdjMatrixEdgeWeightedDigraph ewDigraph( 8 );

    for ( int i = 0; i < 15; ++i ) {
        DirectedEdge e( (int)graphArr[ i ][ 0 ], (int)graphArr[ i ][ 1 ], graphArr[ i ][ 2 ] );
        ewDigraph.addEdge( e );
    }

    cout << "DEBUG: ewDigraph: \n" << ewDigraph << endl;

    FloydWarshallAllPairsDenseSP sp( ewDigraph );
    cout << "DEBUG: sp: \n" << sp << endl;

    return 0;
}
