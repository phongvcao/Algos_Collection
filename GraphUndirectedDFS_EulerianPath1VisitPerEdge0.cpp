//
// Created by Phong Cao.
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
#include <tuple>
#include <bitset>
#include <iterator>
#include <utility>
#include <algorithm>
#include <memory>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <numeric>
#include <thread>
#include <mutex>
#include <condition_variable>

//----< iostream >--------------------------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----< cstdio >----------------------------//
using std::printf;
using std::fprintf;
using std::sprintf;
using std::snprintf;

//----< iomanip >---------------------------//
using std::setprecision;
using std::setw;

//----< ios >-------------------------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----< sstream >---------------------------//
using std::stringstream;
using std::ostringstream;
using std::istringstream;

//----< fstream >---------------------------//
using std::ofstream;
using std::ifstream;

//----< string >----------------------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;
using std::stoll;

//----< cmath >-----------------------------//
using std::sqrt;
using std::pow;
using std::log;                             // log( <arg> )
using std::exp;                             // e ^ <arg>
using std::abs;
using std::fabs;
using std::floor;                           // Round down to nearest integer double
using std::ceil;                            // Round up to nearest integer double
using std::trunc;                           // Truncate the fractional part to get the integer part
using std::round;                           // Round to nearest integer double

//----< cstdlib >---------------------------//
using std::rand;
using std::srand;
using std::atoi;
using std::atol;
using std::atoll;

//----< ctime >-----------------------------//
using std::time;

//----< functional >------------------------//
using std::hash;
using std::greater;                         // lhs > rhs. Used for MinPQ
using std::less;                            // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;
using std::bind;
using namespace std::placeholders;          // placeholders ( _1, _2, ..., _N ) for std::bind

//----< array >-----------------------------//
using std::array;                           // Fixed & Unordered Array

//----< vector >----------------------------//
using std::vector;                          // Resizable & Unordered Array

//----< map >-------------------------------//
using std::map;                             // Ordered Map (Red-Black Tree)
using std::multimap;                        // Ordered Map (Red-Black Tree) & Allow duplicated keys

//----< unordered_map >---------------------//
using std::unordered_map;                   // HashMap (SeparateChainingHashST)
using std::unordered_multimap;              // Ordered Map (Red-Black Tree) & Allow duplicated keys

//----< set >-------------------------------//
using std::set;                             // Ordered Set (Red-Black Tree)
using std::multiset;                        // Ordered Set (Red-Black Tree) & Allow duplicated keys

//----< unordered_set >---------------------//
using std::unordered_set;                   // HashSet (SeparateChainingHashST)
using std::unordered_multiset;              // HashSet (SeparateChainingHashST) & Allow duplicated keys

//----< list >------------------------------//
using std::list;                            // Doubly-Linked List with size() ( O( 1 ) )

//----< forward_list >----------------------//
using std::forward_list;                    // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----< deque >-----------------------------//
using std::deque;                           // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----< queue >-----------------------------//
using std::queue;                           // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;                  // MaxPQ (MaxHeap) & Non-Iterable.
//                                          // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----< stack >-----------------------------//
using std::stack;                           // Non-Iterable & Use std::deque as underlying data structure

//----< tuple >-----------------------------//
using std::tuple;                           // Non-Iterable & Use std::pair as underlying data structure
using std::get;                             // Access & Set element in tuple using get< index >( tuple_var )

//----< bitset >----------------------------//
using std::bitset;

//----< iterator >--------------------------//
using std::next;                            // Return an advanced iter without changing original iter
using std::prev;                            // Return an decremented iter without changing original iter
using std::distance;                        // Calculate distance between 2 iterators
using std::inserter;                        // Insert element into first arg starting from position in second arg

//----< utility >---------------------------//
using std::pair;
using std::make_pair;
using std::move;                            // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >-------------------------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;                            // Intro-Sort (QuickSort => HeapSort when recursion depth exceeds certain level), NOT IN-PLACE & NOT STABLE
using std::partial_sort;                    // HeapSort elements in range ( iterFirst, iterLast ) ( exclusively ). IN-PLACE & NOT STABLE
using std::stable_sort;                     // Merge-Sort elements. NOT IN-PLACE & STABLE
using std::sort_heap;                       // HeapSort elements. IN-PLACE & NOT STABLE
using std::remove;
using std::swap;
using std::binary_search;
using std::next_permutation;
using std::prev_permutation;
using std::set_intersection;                // Only works on std::set and not std::unordered_set
using std::set_difference;                  // Only works on std::set and not std::unordered_set
using std::set_union;
using std::lower_bound;                     // Returns iter pointing to first element >= value
using std::upper_bound;                     // Returns iter pointing to first element > value
using std::transform;                       // Apply the given function to a range and store result in another range
using std::nth_element;

//----< memory >----------------------------//
using std::make_unique;
using std::unique_ptr;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

//----< cctype >----------------------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;                         // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;                         // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----< stdexcept >-------------------------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----< limits >----------------------------//
using std::numeric_limits;

//----< numeric >---------------------------//
using std::iota;
using std::gcd;
using std::lcm;
using std::partial_sum;                     // Calculate partial_sum of range beginIter, endIter and put result to 3rd argument outIter

//----< thread >----------------------------//
using std::thread;
namespace this_thread = std::this_thread;   // Manipulate / Info of the current thread
// using this_thread::get_id;                  // Get the current thread's id
// using this_thread::yield;                   // Yield to other threads
// using this_thread::sleep_until;             // Sleep until time point
// using this_thread::sleep_for;               // Sleep for time span

//----< mutex >-----------------------------//
using std::mutex;                           // Basic mutex
using std::timed_mutex;                     // mutex with a timeout. CAN BE LOCKED & UNLOCKED
using std::recursive_mutex;                 // mutex can be locked recursively by the same thread. CAN BE LOCKED & UNLOCKED
using std::recursive_timed_mutex;           // mutex can be locked recursively by same thread and locking with a timeout. CAN BE LOCKED & UNLOCKED
using std::lock;                            // locks specified mutexes. CAN BE LOCKED & UNLOCKED
using std::lock_guard;                      // strictly scope-based mutex ownership wrapper. LOCK ON CONSTRUCTION & UNLOCK ON DESTRUCTION 
using std::scoped_lock;                     // deadlock-avoiding RAII wrapper. LOCK ON CONSTRUCTION & UNLOCK ON DESTRUCTION
using std::unique_lock;                     // movable mutex ownership wrapper. CAN BE LOCKED & UNLOCKED

//----< condition_variable >----------------//
using std::condition_variable;

//----< chrono >----------------------------//
using std::ratio;                           // Represents exact rational (e.g. ratio< 1, 3 >)

//----< chrono >----------------------------//
using std::chrono::duration;                // Combine with std::ratio to create duration
using std::chrono::system_clock;
using std::chrono::nanoseconds;             // Duration in nanoseconds
using std::chrono::microseconds;            // Duration in microseconds
using std::chrono::milliseconds;            // Duration in milliseconds
using std::chrono::seconds;                 // Duration in seconds
using std::chrono::minutes;                 // Duration in minutes
using std::chrono::hours;                   // Duration in hours

//------------------------------------------//

//
// Eulerian Path:
// 
// 1. All vertices with non-zero degree are connected
// 2. All vertices with even degree
// 3. If 2 vertices have odd degree ( the 2 ends of the path )
//    and all other vertices have even degree
//
//
// Time Complexity : O( V + E )
// Space Complexity : O( V + E )
//
class EulerianPath {
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
    int oddDegreeVerticesCnt = 0;
    stack< int > eulerianPath;
    vector< unique_ptr< Edge > > edgesVec;

    Edge * newEdge( int v, int w ) {
        edgesVec.push_back( make_unique< Edge >( v, w ) );
        return edgesVec.back().get();
    }

public:

    EulerianPath( const vector< vector< int > >& G ) {
        vector< queue< Edge * > > adjQueue( G.size(), queue< Edge * >() );
        for ( int v = 0; v < G.size(); v++ ) {
            //
            // Condition 1 : Degree of each vertex must be even
            //
            // Count the number of odd-degree vertices in the graph
            //
            // Also get a non-isolated vertex with odd degree since it's
            // most likely the start/end of an eulerian path
            //
            if ( G[ v ].size() % 2 != 0 ) {
                ++oddDegreeVerticesCnt;
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
                    if ( selfLoops % 2 == 0 ) {
                        ++edgeCnt;
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
        // Condition 3: If there are more than 2 edges with odd degrees, the
        // graph doesn't have Eulerian path
        //
        if ( oddDegreeVerticesCnt > 2 ) return;

        //
        // Special case for graph with zero edges
        // ( has a degenerate Eulerian path )
        //
        if ( nonIsolatedVertex == -1 ) nonIsolatedVertex = 0;

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
            eulerianPath.push( v );
        }
        
        //
        // Eulerian path should contain all edges
        //
        if ( eulerianPath.size() != edgeCnt + 1 ) {
            eulerianPath = stack< int >();
        }
    }

    virtual ~EulerianPath() {
        // empty for now
    }

    stack< int > getEulerianPath() const {
        return eulerianPath;
    }

    bool hasEulerianPath() const {
        return ! eulerianPath.empty();
    }

    friend ostream& operator <<( ostream& out, const EulerianPath& ep ) {
        out << "ep:\n\n";

        stack< int > eulerianPath = ep.getEulerianPath();
        while ( ! eulerianPath.empty() ) {
            out << eulerianPath.top() << ", ";
            eulerianPath.pop();
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
    EulerianPath eulerian1( graph1 );

    if ( ! eulerian1.hasEulerianPath() ) {
        cout << "DEBUG : graph1 DOES NOT HAVE Eulerian Path!!!" << endl;
    } else {
        cout << "DEBUG : graph1 DOES HAVE Eulerian Path!!!" << endl;
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
    EulerianPath eulerian2( graph2 );

    if ( ! eulerian2.hasEulerianPath() ) {
        cout << "DEBUG : graph2 DOES NOT HAVE Eulerian Path!!!" << endl;
    } else {
        cout << "DEBUG : graph2 DOES HAVE Eulerian Path!!!" << endl;
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
    EulerianPath eulerian3( graph3 );

    if ( ! eulerian3.hasEulerianPath() ) {
        cout << "DEBUG : graph3 DOES NOT HAVE Eulerian Path!!!" << endl;
    } else {
        cout << "DEBUG : graph3 DOES HAVE Eulerian Path!!!" << endl;
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
    EulerianPath eulerian4( graph4 );

    if ( ! eulerian4.hasEulerianPath() ) {
        cout << "DEBUG : graph4 DOES NOT HAVE Eulerian Path!!!" << endl;
    } else {
        cout << "DEBUG : graph4 DOES HAVE Eulerian Path!!!" << endl;
        cout << eulerian4 << endl;
    }

    return 0;
}
