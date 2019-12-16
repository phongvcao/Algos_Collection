//
// Created by Phong Cao on 2019-04-10.
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
#include <array>
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

//----<array>---------------//
using std::array;           // Fixed & Unordered Array

//----<vector>--------------//
using std::vector;          // Resizable & Unordered Array

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

class Graph {
private:

    int V = 0;
    int E = 0;
    vector< forward_list< int > > adj;

public:

    Graph( int V )
        : V( V ),
          adj( V )
    {
        // not implemented
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

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const Graph& G ) {
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

namespace std {
    template <>
    struct hash< forward_list< int > > {
        size_t operator ()( forward_list< int > fList ) const {
            int hash = 17;
            fList.sort();
            for ( int v : fList ) {
                hash = 31 * hash + std::hash< int >{}( v );
            }
            return hash;
        }
    };
}

class PatonFindAllFundamentalCycles {
private:

    vector< bool > marked;
    vector< int > edgeTo;
    stack< int > bfsStack;
    unordered_map< int, unordered_set< int > > invMarkedMap;
    unordered_set< forward_list< int > > allCycles;

    void bfs( const Graph& G, int v ) {
        marked[ v ] = true;
        bfsStack.push( v );
        edgeTo[ v ] = v;

        invMarkedMap.clear();
        invMarkedMap.insert( { v, unordered_set< int >() } );

        while ( ! bfsStack.empty() ) {
            int w = bfsStack.top();
            bfsStack.pop();
            const unordered_set< int > * wInvMarked = &invMarkedMap[ w ];

            for ( int x : G.getAdj( w ) ) {
                if ( ! marked[ x ] ) {
                    marked[ x ] = true;
                    edgeTo[ x ] = w;
                    invMarkedMap.insert( { x, unordered_set< int >( { w } ) } );
                    bfsStack.push( x );
                } else if ( x == w ) {
                    allCycles.insert( forward_list< int >( { x } ) );
                    invMarkedMap[ x ].insert( w );
                } else if ( wInvMarked->find( x ) == wInvMarked->end() ) {
                    unordered_set< int > * xInvMarked = &invMarkedMap[ x ];
                    forward_list< int > cycle;
                    int y;
                    for ( y = w; xInvMarked->find( y ) == xInvMarked->end(); y = edgeTo[ y ] ) {
                        cycle.push_front( y );
                    }
                    cycle.push_front( y );
                    cycle.push_front( x );
                    allCycles.insert( cycle );
                    xInvMarked->insert( w );
                }
            }
        }
    }

public:

    PatonFindAllFundamentalCycles( const Graph& G )
        : marked( G.getV(), false ),
          edgeTo( G.getV() )
    {
        for ( int v = 0; v < G.getV(); ++v ) {
            if ( ! marked[ v ] ) {
                bfs( G, v );
            }
        }
    }

    virtual ~PatonFindAllFundamentalCycles() {
        // not implemented
    }

    bool hasCycle() const {
        return ! allCycles.empty();
    }

    unordered_set< forward_list< int > > getAllCycles() const {
        return allCycles;
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const PatonFindAllFundamentalCycles& pCycles ) {
        out << "\ncycle : count : " << pCycles.allCycles.size() << endl;
        for ( const forward_list< int >& cycle : pCycles.allCycles ) {
            for ( int v : cycle ) {
                out << v << ", ";
            }
            out << endl;
        }
        return out;
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
            { 9, 9 },
            { 7, 9 },
            { 8, 9 }
    };

    Graph graph( 13 );

    for ( int i = 0; i < 16; ++i ) {
        graph.addEdge( graphArr[ i ][ 0 ], graphArr[ i ][ 1 ] );
    }

    cout << "DEBUG: graph: \n" << graph.toString() << endl;

    PatonFindAllFundamentalCycles pCycleFinder( graph );
    cout << "DEBUG: pCycleFinder: \n" << pCycleFinder << endl;

    return 0;
}
