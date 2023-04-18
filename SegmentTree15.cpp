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
#include <iterator>
#include <utility>
#include <algorithm>
#include <memory>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <numeric>

//----< iostream >----------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----< cstdio >------------//
using std::printf;
using std::fprintf;
using std::sprintf;
using std::snprintf;

//----< iomanip >-----------//
using std::setprecision;
using std::setw;

//----< ios >---------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----< sstream >-----------//
using std::ostringstream;
using std::istringstream;

//----< fstream >-----------//
using std::ofstream;
using std::ifstream;

//----< string >------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;

//----< cmath >-------------//
using std::sqrt;
using std::pow;
using std::log;             // log( <arg> )
using std::exp;             // e ^ <arg>
using std::abs;
using std::floor;           // Round down to nearest integer double
using std::ceil;            // Round up to nearest integer double
using std::trunc;           // Truncate the fractional part to get the integer part
using std::round;           // Round to nearest integer double

//----< cstdlib >-----------//
using std::rand;
using std::srand;

//----< ctime >-------------//
using std::time;

//----< functional >--------//
using std::hash;
using std::greater;         // lhs > rhs. Used for MinPQ
using std::less;            // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;

//----< array >-------------//
using std::array;           // Fixed & Unordered Array

//----< vector >------------//
using std::vector;          // Resizable & Unordered Array

//----< map >---------------//
using std::map;             // Ordered Map (Red-Black Tree)

//----< unordered_map >-----//
using std::unordered_map;   // HashMap (SeparateChainingHashST)

//----< set >---------------//
using std::set;             // Ordered Set (Red-Black Tree)

//----< unordered_set >-----//
using std::unordered_set;   // HashSet (SeparateChainingHashST)

//----< list >--------------//
using std::list;            // Doubly-Linked List with size() ( O( 1 ) )

//----< forward_list >------//
using std::forward_list;    // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----< deque >-------------//
using std::deque;           // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----< queue >-------------//
using std::queue;           // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;  // MaxPQ (MaxHeap) & Non-Iterable.
//                          // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----< stack >-------------//
using std::stack;           // Non-Iterable & Use std::deque as underlying data structure

//----< iterator >----------//
using std::next;            // Return an advanced iter without changing original iter
using std::prev;            // Return an decremented iter without changing original iter
using std::distance;        // Calculate distance between 2 iterators

//----< utility >-----------//
using std::pair;
using std::move;            // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >---------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;

//----< memory >------------//
using std::make_unique;
using std::unique_ptr;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

//----< cctype >------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;         // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;         // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----< stdexcept >---------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----< limits >------------//
using std::numeric_limits;

//----< numeric >-----------//
using std::iota;
using std::gcd;
using std::lcm;

//--------------------------//


/**
 *
 * The SegmentTree is a data structure for efficient search of cummulative data.
 * It performs Range Minimum Query and Range Sum Query in O( log( N ) ) time.
 *
 * It can be easily customizable to support Range Max Query, Range Multiplication
 * Query etc.
 *
 * Also it has been develop with for range updates, which means when you perform
 * update operations over a range, the update process affects the least nodes as
 * possible so that the bigger the range you want to update the less time it
 * consumes to update it. Eventually those changes will be propagated to the
 * children and the whole array will be up to date.
 *
 * Example:
 *
 * SegmentTreeHeap st = new SegmentTreeHeap( new Integer[]{ 1, 3, 4, 2, 1, -2, 4 } );
 * st.update( 0, 3, 1 )
 *
 * In the above case only the node that represents the range [0,3] will be
 * updated (and not their children) so in this case the update task will be less
 * than N * log( N )
 *
 * Time Complexity : O( N log ( N ) ) for Constructor
 *                   O( log( N ) ) for all other operations
 * Space Complexity :  O( N )
 *
 **/

class SegmentTree {
private:

    class Node {
    public:
        int from = -1;
        int to = -1;

        int pendingVal = numeric_limits< int >::max();
        int min = numeric_limits< int >::max();
        int sum = numeric_limits< int >::max();

        int size() const {
            return to - from + 1;
        }

        bool isPending() const {
            return pendingVal != numeric_limits< int >::max();
        }

        void unsetPendingVal() {
            pendingVal = numeric_limits< int >::max();
        }

        string toString() const {
            ostringstream oss;
            oss << *this;
            return oss.str();
        }

        friend ostream& operator <<( ostream& out, const Node& h ) {
            out << fixed << setprecision( 2 );
            out << " | " << h.from << " : " << h.to
                << " ; pendingVal : " << h.pendingVal
                << " ; min : " << h.min << " ; sum : " << h.sum << " | ";
            return out;
        }
    };

    vector< Node > heap;
    vector< int > arr;
    int N = 0;

    //
    // Save the temporal values that will be propagated lazily
    //
    void change( int v, int value ) {
        Node * h = &heap[ v ];
        h->pendingVal = value;
        h->min = value;
        h->sum = value * h->size();
        arr[ h->from ] = value;
    }

    //
    // Propagate temporal values to children
    //
    void propagate( int v ) {
        Node * h = &heap[ v ];
        if ( h->isPending() ) {
            change( 2 * v, h->pendingVal );
            change( 2 * v + 1, h->pendingVal );
            h->unsetPendingVal();
        }
    }

    //
    // Test if the range1 contains range2
    //
    bool contains( int from1, int to1, int from2, int to2 ) const {
        return from1 <= from2 && to1 >= to2;
    }

    //
    // Check inclusive intersection, test if range1[ from1, to1 ] intersects
    // range2[ from2, to2 ]
    //
    bool intersects( int from1, int to1, int from2, int to2 ) const {
        return ( from1 >= from2 && from1 <= to2 ) || ( from2 >= from1 && from2 <= to1 );
    }

    //
    // Initialize the Nodes of the Segment tree
    //
    void build( int v, int from, int sz ) {
        Node * h = &heap[ v ];
        h->from = from;
        h->to = from + sz - 1;

        if ( h->size() == 1 ) {
            h->min = arr[ from ];
            h->sum = arr[ from ];
        } else {
            build( 2 * v, from, sz / 2 );
            build( 2 * v + 1, from + sz / 2, sz - sz / 2 );

            h->min = min( heap[ 2 * v ].min, heap[ 2 * v + 1 ].min );
            h->sum = heap[ 2 * v ].sum + heap[ 2 * v + 1 ].sum;
        }
    }

    /**
     *
     * Range Update Operation.
     *
     * With this operation you can update either one position or a range of
     * positions with a given number.
     * 
     * The update operations will update the less it can to update the whole
     * range (Lazy Propagation).
     * 
     * The values will be propagated lazily from top to bottom of the segment tree.
     * 
     * This behavior is really useful for updates on portions of the array
     *
     * Time Complexity: O( log( N ) )
     *
     **/
    void update( int v, int from, int to, int value ) {
        Node * h = &heap[ v ];

        if ( contains( from, to, h->from, h->to ) ) {
            change( v, value );
        }

        if ( h->size() == 1 ) return;

        if ( intersects( from, to, h->from, h->to ) ) {
            propagate( v );

            update( 2 * v, from, to, value );
            update( 2 * v + 1, from, to, value );

            h->min = min( heap[ 2 * v ].min, heap[ 2 * v + 1 ].min );
            h->sum = heap[ 2 * v ].sum + heap[ 2 * v + 1 ].sum;
        }
    }

    /**
     *
     * Range Min Query
     * 
     * Time Complexity: O( log( N ) )
     *
     **/
    int rMinQ( int v, int from, int to ) {
        Node * h = &heap[ v ];

        if ( h->isPending() && contains( h->from, h->to, from, to ) ) {
            return h->pendingVal;
        }

        if ( contains( from, to, h->from, h->to ) ) {
            return h->min;
        }

        if ( intersects( from, to, h->from, h->to ) ) {
            propagate( v );

            int leftMin = rMinQ( 2 * v, from, to );
            int rightMin = rMinQ( 2 * v + 1, from, to );
            return min( leftMin, rightMin );
        }
        return numeric_limits< int >::max();
    }

    /**
     *
     * Range Sum Query
     * 
     * Time Complexity: O( log( N ) )
     *
     **/
    int rSumQ( int v, int from, int to ) {
        Node * h = &heap[ v ];

        if ( h->isPending() && contains( h->from, h->to, from, to ) ) {
            return h->pendingVal * ( to - from + 1 );
        }

        if ( contains( from, to, h->from, h->to ) ) {
            return h->sum;
        }

        if ( intersects( from, to, h->from, h->to ) ) {
            propagate( v );

            int leftSum = rSumQ( 2 * v, from, to );
            int rightSum = rSumQ( 2 * v + 1, from, to );
            return leftSum + rightSum;
        }
        return 0;
    }

public:

    SegmentTree( const vector< int >& arr )
        : arr( arr ),
          N( ( int ) ( 2 * pow( 2, floor( log( arr.size() ) / log( 2 ) + 1 ) ) ) )
    {
        heap.resize( N );
        build( 1, 0, arr.size() );
    }

    virtual ~SegmentTree() {
        // not implemented
    }

    int size() const {
        return arr.size();
    }

    /**
     *
     * Range Update Operation.
     *
     * With this operation you can update either one position or a range of
     * positions with a given number.
     * 
     * The update operations will update the less it can to update the whole
     * range (Lazy Propagation).
     * 
     * The values will be propagated lazily from top to bottom of the segment tree.
     * 
     * This behavior is really useful for updates on portions of the array
     *
     * Time Complexity: O( log( N ) )
     *
     **/
    void update( int from, int to, int value ) {
        update( 1, from, to, value );
    }

    /**
     *
     * Range Min Query
     * 
     * Time Complexity: O( log( N ) )
     *
     **/
    int rMinQ( int from, int to ) {
        return rMinQ( 1, from, to );
    }

    /**
     *
     * Range Sum Query
     * 
     * Time Complexity: O( log( N ) )
     *
     **/
    int rSumQ( int from, int to ) {
        return rSumQ( 1, from, to );
    }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const SegmentTree& st ) {
        out << "\nst:\n";
        out << "\n\nheap:\n";
        for ( int i = 0; i < st.heap.size(); ++i ) {
            out << i << " : " << st.heap[ i ] << endl;
        }

        out << "\n\narr:\n";
        for ( int i = 0; i < st.arr.size(); ++i ) {
            out << i << " : " << st.arr[ i ] << endl;
        }

        return out;
    }

};

int main( int argc, char ** argv ) {

    vector< int > intVec = { 1, 2, 3, 4, 5, 6, 7 };

    SegmentTree st( intVec );
    cout << "DEBUG: st : " << st << endl;
    cout << "DEBUG: st.rSumQ( 0, 3 ) : " << st.rSumQ( 0, 3 ) << endl;
    cout << "DEBUG: st.rSumQ( 1, 3 ) : " << st.rSumQ( 1, 3 ) << endl;
    cout << "DEBUG: st.rSumQ( 3, 7 ) : " << st.rSumQ( 3, 7 ) << endl;
    cout << "DEBUG: st.rSumQ( 0, 10 ) : " << st.rSumQ( 0, 10 ) << endl;

    cout << "DEBUG: st.rMinQ( 0, 3 ) : " << st.rMinQ( 0, 3 ) << endl;
    cout << "DEBUG: st.rSumQ( 0, 3 ) : " << st.rSumQ( 0, 3 ) << endl;

    cout << "DEBUG: st.update( 0, 3, 5 ) : " << endl;
    st.update( 0, 3, 5 );

    cout << "DEBUG: st.rMinQ( 0, 3 ) : " << st.rMinQ( 0, 3 ) << endl;
    cout << "DEBUG: st.rSumQ( 0, 3 ) : " << st.rSumQ( 0, 3 ) << endl;
    cout << "DEBUG: st.rSumQ( 0, 10 ) : " << st.rSumQ( 0, 10 ) << endl;

    return 0;
}
