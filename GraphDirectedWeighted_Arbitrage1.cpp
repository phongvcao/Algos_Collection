//
// Created by Phong Cao on 2019-04-01.
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

    stack< DirectedEdge > getCycle() const {
        return cycle;
    }

    bool hasCycle() const {
        return ! cycle.empty();
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

class BellmanFordNegativeSP {
private:

    vector< double > distTo;
    vector< DirectedEdge > edgeTo;
    queue< int > relaxQueue;
    vector< bool > onQueue;
    stack< DirectedEdge > negativeCycle;
    int cost = 0;

    void relax( const EdgeWeightedDigraph& G, int v ) {
        for ( DirectedEdge e : G.getAdj( v ) ) {
            int w = e.getTo();
            if ( distTo[ w ] > distTo[ v ] + e.getWeight() ) {
                distTo[ w ] = distTo[ v ] + e.getWeight();
                edgeTo[ w ] = e;

                if ( ! onQueue[ w ] ) {
                    relaxQueue.push( w );
                    onQueue[ w ] = true;
                }
            }

            if ( cost++ % G.getV() ) {
                findNegativeCycle();
                if ( hasNegativeCycle() ) return;
            }
        }
    }

    void findNegativeCycle() {
        int V = edgeTo.size();
        EdgeWeightedDigraph ewDigraph( V );
        for ( int v = 0; v < edgeTo.size(); ++v ) {
            if ( edgeTo[ v ] ) {
                ewDigraph.addEdge( edgeTo[ v ] );
            }
        }

        DirectedCycle cycleFinder( ewDigraph );
        negativeCycle = cycleFinder.getCycle();
    }

    string getNegativeCycleErrorOutput() const {
        string rv = "Negative cost cycle exists : \n";
        stack< DirectedEdge > s = getNegativeCycle();
        while ( ! s.empty() ) {
            rv += s.top().toString() + ", ";
            s.pop();
        }
        return rv;
    }

public:

    BellmanFordNegativeSP( const EdgeWeightedDigraph& G, int s )
            : distTo( G.getV(), numeric_limits< double >::infinity() ),
              edgeTo( G.getV() ),
              onQueue( G.getV(), false )
    {
        distTo[ s ] = 0;
        relaxQueue.push( s );
        onQueue[ s ] = true;

        while ( ! relaxQueue.empty() && ! hasNegativeCycle() ) {
            int v = relaxQueue.front();
            relaxQueue.pop();
            onQueue[ v ] = false;
            relax( G, v );
        }
    }

    virtual ~BellmanFordNegativeSP() {
        // not implemented
    }

    bool hasPathTo( int v ) const {
        return distTo[ v ] != numeric_limits< double >::infinity();
    }

    double getDistTo( int v ) const {
        if ( hasNegativeCycle() ) throw runtime_error( getNegativeCycleErrorOutput() );
        return distTo[ v ];
    }

    stack< DirectedEdge > getPathTo( int v ) const {
        if ( hasNegativeCycle() ) throw runtime_error( getNegativeCycleErrorOutput() );
        stack< DirectedEdge > path;
        if ( ! hasPathTo( v ) ) return path;
        for ( DirectedEdge e = edgeTo[ v ]; e; e = edgeTo[ e.getFrom() ] ) {
            path.push( e );
        }
        return path;
    }

    bool hasNegativeCycle() const {
        return ! negativeCycle.empty();
    }

    stack< DirectedEdge > getNegativeCycle() const {
        return negativeCycle;
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const BellmanFordNegativeSP& sp ) {
        out << "\nsp:\n";
        try {
            for ( int v = 0; v < sp.edgeTo.size(); ++v ) {
                out << "\n| v : " << v << " : ";
                stack< DirectedEdge > s = sp.getPathTo( v );
                while ( ! s.empty() ) {
                    out << s.top() << ", ";
                    s.pop();
                }
                out << " | ";
            }
        } catch ( const runtime_error& err ) {
            out << err.what() << endl;
        }
        return out;
    }

};

class Arbitrage {
public:

    Arbitrage( const vector< pair< string, vector< double > > >& graphVec ) {
        int V = graphVec.size();
        EdgeWeightedDigraph G( V );
        vector< string > name( V );
        for ( int v = 0; v < V; ++v ) {
            name[ v ] = graphVec[ v ].first;
            for ( int w = 0; w < graphVec[ v ].second.size(); ++w ) {
                double rate = graphVec[ v ].second[ w ];
                DirectedEdge e( v, w, -1 * log( rate ) );
                G.addEdge( e );
            }
        }

        cout << G << endl;

        BellmanFordNegativeSP sp( G, 0 );
        if ( sp.hasNegativeCycle() ) {
            double stake = 1000;
            stack< DirectedEdge > negativeCycle = sp.getNegativeCycle();
            while ( ! negativeCycle.empty() ) {
                DirectedEdge e = negativeCycle.top();
                printf( "%10.5f %s ", stake, name[ e.getFrom() ].c_str() );
                stake *= exp( -1 * negativeCycle.top().getWeight() );
                printf( " = %10.5f %s\n", stake, name[ e.getFrom() ].c_str() );
                negativeCycle.pop();
            }
        } else {
            cout << "No arbitrage opportunity" << endl;
        }
    }

    virtual ~Arbitrage() {
        // not implemented
    }

};

int main( int argc, char ** argv ) {

    vector< pair< string, vector< double > > > graphVec {
            { "USD", { 1     , 0.741 , 0.657 , 1.061 , 1.005 }, },
            { "EUR", { 1.349 , 1     , 0.888 , 1.433 , 1.366 }, },
            { "GBP", { 1.521 , 1.126 , 1     , 1.614 , 1.538 }, },
            { "CHF", { 0.942 , 0.698 , 0.619 , 1     , 0.953 }, },
            { "CAD", { 0.995 , 0.732 , 0.650 , 1.049 , 1     }, },
    };

    Arbitrage arbitrage( graphVec );

    return 0;
}
