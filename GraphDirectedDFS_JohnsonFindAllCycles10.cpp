//
// Created by Phong Cao on 2019-04-08.
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

class Digraph {
private:

    int V = 0;
    int E = 0;
    vector< forward_list< int > > adj;

public:

    Digraph( int V )
        : V( V ),
          adj( V )
    {
        // not implemented
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

    forward_list< int > getAdj( int v ) const {
        return adj[ v ];
    }

    void addEdge( int v, int w ) {
        adj[ v ].push_front( w );
        ++E;
    }

    Digraph reverse() const {
        Digraph R( getV() );
        for ( int v = 0; v < getV(); ++v ) {
            for ( int w : getAdj( v ) ) {
                R.addEdge( w, v );
            }
        }
        return R;
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const Digraph& G ) {
        out << "\n| V : " << G.getV() << " ; E : " << G.getE() << " ; adj : \n";
        for ( int v = 0; v < G.getV(); ++v ) {
            out << "\n| v : " << v << " : ";
            for ( int w : G.getAdj( v ) ) {
                out << w << ", ";
            }
            out << " | ";
        }
        return out;
    }

};

class TarjanSCC {
private:

    vector< bool > marked;
    vector< int > id;
    vector< int > low;
    stack< int > dfsStack;
    map< int, vector< int > > multiVertexComps;
    int pre = 0;
    int count = 0;

    void dfs( const Digraph& G, int v ) {
        marked[ v ] = true;
        low[ v ] = pre++;
        int min = low[ v ];
        dfsStack.push( v );

        for ( int w : G.getAdj( v ) ) {
            if ( ! marked[ w ] ) {
                dfs( G, w );
            }

            if ( min > low[ w ] ) {
                min = low[ w ];
            }
        }

        if ( min < low[ v ] ) {
            low[ v ] = min;
            return;
        }

        int w;
        int minVertex = G.getV();
        vector< int > comp;
        do {
            w = dfsStack.top();
            dfsStack.pop();

            if ( minVertex > w ) {
                minVertex = w;
            }
            comp.push_back( w );

            id[ w ] = count;
            low[ w ] = G.getV();
        } while ( w != v );

        if ( comp.size() > 1 ) {
            multiVertexComps.insert( { w, comp } );
        }

        ++count;
    }

public:

    TarjanSCC( const Digraph& G )
        : marked( G.getV(), false ),
          id( G.getV() ),
          low( G.getV() )
    {
        for ( int v = 0; v < G.getV(); ++v ) {
            if ( ! marked[ v ] ) {
                dfs( G, v );
            }
        }
    }

    virtual ~TarjanSCC() {
        // not implemented
    }

    map< int, vector< int > > getMultiVertexComponents() const {
        return multiVertexComps;
    }

    int getId( int v ) const {
        return id[ v ];
    }

    bool stronglyConnected( int v, int w ) const {
        return getId( v ) == getId( w );
    }

    int getCount() const {
        return count;
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const TarjanSCC& scc ) {
        out << "\n\nscc:\n";
        out << "\n\nid:\n";
        for ( int v = 0; v < scc.id.size(); ++v ) {
            out << v << " : " << scc.id[ v ] << endl;
        }

        out << "\n\nlow:\n";
        for ( int v = 0; v < scc.low.size(); ++v ) {
            out << v << " : " << scc.low[ v ] << endl;
        }

        out << "\n\nmultiVertexComps:\n";
        for ( map< int, vector< int > >::const_iterator iter = scc.multiVertexComps.begin();
              iter != scc.multiVertexComps.end(); ++iter ) {
            for ( int v : iter->second ) {
                out << v << ", ";
            }
            out << endl;
        }
        return out;
    }

};

namespace std {
    template <>
    struct hash< forward_list< int > > {
        size_t operator ()( forward_list< int > fList ) const {
            int hash = 17;
            fList.sort();
            for ( int val : fList ) {
                hash = 31 * hash + std::hash< int >{}( val );
            }
            return hash;
        }
    };
}

class JohnsonFindAllCycles {
private:

    vector< bool > marked;
    vector< forward_list< int > > allCycles;
    vector< int > edgeTo;
    unordered_map< int, unordered_set< int > > invMarkedMap;
    bool cycleFound = false;

    void dfs( const Digraph& G, int v, int s ) {
        marked[ v ] = true;

        for ( int w : G.getAdj( v ) ) {
            if ( ! marked[ w ] ) {
                edgeTo[ w ] = v;
                dfs( G, w, s );
            } else if ( w == s ) {
                // cycle detected
                forward_list< int > cycle;
                cycle.push_front( w );
                for ( int x = v; x != w; x = edgeTo[ x ] ) {
                    cycle.push_front( x );
                }
                cycle.push_front( w );
                allCycles.push_back( cycle );
                cycleFound = true;
            }
        }

        if ( cycleFound ) {
            unmark( v );
        } else {
            for ( int w : G.getAdj( v ) ) {
                if ( invMarkedMap.find( w ) == invMarkedMap.end() ) {
                    invMarkedMap.insert( { w, unordered_set< int >() } );
                }
                invMarkedMap[ w ].insert( v );
            }
        }
    }

    void unmark( int v ) {
        marked[ v ] = false;
        if ( invMarkedMap.find( v ) == invMarkedMap.end() ) return;
        for ( int w : invMarkedMap[ v ] ) {
            if ( marked[ w ] ) {
                unmark( w );
            }
        }
        invMarkedMap.erase( v );
    }

public:

    JohnsonFindAllCycles( const Digraph& G )
        : marked( G.getV(), false ),
          edgeTo( G.getV() )
    {
        int s = 0;
        while ( s < G.getV() ) {
            Digraph subGraph( G.getV() );
            for ( int v = s; v < G.getV(); ++v ) {
                for ( int w : G.getAdj( v ) ) {
                    if ( w < s ) continue;
                    subGraph.addEdge( v, w );
                }
            }

            TarjanSCC scc( subGraph );
            map< int, vector< int > > multiVertexComps = scc.getMultiVertexComponents();
            if ( multiVertexComps.empty() ) break;
            map< int, vector< int > >::iterator iter = multiVertexComps.begin();

            Digraph sccGraph( subGraph.getV() );
            for ( int v : iter->second ) {
                for ( int w : subGraph.getAdj( v ) ) {
                    if ( scc.stronglyConnected( v, w ) ) {
                        sccGraph.addEdge( v, w );
                    }
                }
            }

            cycleFound = false;
            dfs( sccGraph, iter->first, iter->first );
            s = iter->first + 1;
        }
    }

    virtual ~JohnsonFindAllCycles() {
        // not implemented
    }

    vector< forward_list< int > > getAllCycles() const {
        return allCycles;
    }

    bool hasCycle() const {
        return ! allCycles.empty();
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const JohnsonFindAllCycles& jCycle ) {
        out << "\n\ncycle : count : " << jCycle.allCycles.size() << "\n";
        for ( const forward_list< int >& cycle : jCycle.allCycles ) {
            for ( int v : cycle ) {
                out << v << ", ";
            }
            out << endl;
        }
        return out;
    }

};

int main( int argc, char ** argv ) {

    int graphArr[ 15 ][ 2 ] = {
            { 1, 2 },
            { 1, 8 },
            { 1, 5 },
            { 2, 9 },
            { 2, 7 },
            { 2, 3 },
            { 3, 1 },
            { 3, 2 },
            { 3, 6 },
            { 3, 4 },
            { 6, 4 },
            { 4, 5 },
            { 5, 2 },
            { 8, 9 },
            { 9, 8 },
    };

    Digraph dGraph( 10 );

    for ( int i = 0; i < 15; ++i ) {
        dGraph.addEdge( graphArr[ i ][ 0 ], graphArr[ i ][ 1 ] );
    }

    cout << "DEBUG: dGraph: \n" << dGraph.toString() << endl;
    cout << "DEBUG: dGraph.reverse(): \n" << dGraph.reverse().toString() << endl;

    TarjanSCC scc( dGraph );
    cout << "DEBUG: scc: \n" << scc << endl;

    JohnsonFindAllCycles jCycleFinder( dGraph );
    cout << "DEBUG: jCycleFinder: \n" << jCycleFinder.toString() << endl;

    return 0;
}
