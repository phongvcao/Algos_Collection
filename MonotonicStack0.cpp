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
using std::unordered_multimap;              // HashMap (SeparateChainingHashST) & Allow duplicated keys

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
// Time Complexity : O( N ) for push()
//                   O( 1 ) for others
// Space Complexity : O( N )
//

template< typename Value >
class MonoStack {
private:
    stack< Value > innerStack;
    int monoType = MONO_INCREASING;

    bool isValid( Value val ) const {
        if ( monoType == MONO_INCREASING ) {
            return val <= innerStack.top();
        } else {
            return val >= innerStack.top();
        }
    }

public:

    //
    // Increasing ( or Non-Decreasing ) from bottom to top ( push()'s order )
    // Keep pop()-ing TOP elements until val <= innerStack.top()
    //
    // So for an increasing monoStack applied over the array. the vector< int >
    // is divided into 3 parts:
    //     - The smallest element (so far) of the entire array is at the bottom
    //     of the stack
    //     - The smallest element on the right (if going right-left) or left
    //     ( if going left-right) of the smallestElementSoFar is the minimum
    //     of the popped-out elements
    //     - The incoming elements, if smaller than the smallestElementSoFar,
    //     will be popped
    //     - The incoming elements can be either smaller or larger than the
    //     minimum popped-out element
    //
    // => So a increasing monoStack is a little bit like a reversed-heap, where
    // the minimum element is always at the bottom, and the min element of
    // the right or left part of the minimumElement ( depending on whether we're
    // looping from right-to-left or left-to-right of the array while applying
    // the monoStack ) is the minimum popped-out element
    //
    // => The number of popped-out elements equal the amount of
    // contiguously-larger-than-incoming-element on the left ( if traversing
    // left-to-right ) or on the right ( if traversing right-to-left ) of
    // incoming-element on the array.
    //
    static const int MONO_INCREASING;

    //
    // Decreasing ( or Non-Increasing ) from bottom to top ( push()'s order )
    // Keep pop()-ing TOP elements until val >= innerStack.top()
    //
    // So for a decreasing monoStack applied over the array. the vector< int >
    // is divided into 3 parts:
    //     - The largest element (so far) of the entire array is at the bottom
    //     of the stack
    //     - The largest element on the right (if going right-left) or left
    //     ( if going left-right) of the largestElementSoFar is the maximum
    //     of the popped-out elements
    //     - The incoming elements, if larger than the largestElementSoFar,
    //     will be popped
    //     - The incoming elements can be either larger or smaller than the
    //     maximum popped-out element
    //
    // => So a decreasing monoStack is a little bit like a reversed-heap, where
    // the maximum element is always at the bottom, and the max element of
    // the right or left part of the maximumElement ( depending on whether we're
    // looping from right-to-left or left-to-right of the array while applying
    // the monoStack ) is the maximum popped-out element
    //
    // => The number of popped-out elements equal the amount of
    // contiguously-smaller-than-incoming-element on the left ( if traversing
    // left-to-right ) or on the right ( if traversing right-to-left ) of
    // incoming-element on the array.
    //
    static const int MONO_DECREASING;

    MonoStack( int monoType )
        : monoType( monoType )
    {
        // empty for now
    }

    virtual ~MonoStack() {
        // empty for now
    }

    void push( Value val ) {
        while ( ! innerStack.empty() && ! isValid( val ) ) {
            innerStack.pop();
        }
        innerStack.push( val );
    }

    void pop() {
        innerStack.pop();
    }

    int size() const {
        return innerStack.size();
    }

    bool empty() const {
        return innerStack.empty();
    }

    Value top() const {
        return innerStack.top();
    }

};

template< typename Value >
const int MonoStack< Value >::MONO_INCREASING = -1;
template< typename Value >
const int MonoStack< Value >::MONO_DECREASING = 1;


int main( int argc, char ** argv ) {

    vector< int > intArr = { 14, 12, 10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9, 11, 13 };

    MonoStack< int > s1( MonoStack< int >::MONO_INCREASING );
    for ( int i = 0; i < intArr.size(); i++ ) {
        s1.push( intArr[ i ] );
    }
    cout << "DEBUG : Monotonic Increasing Stack : " << endl;
    while ( ! s1.empty() ) {
        cout << s1.top() << ", ";
        s1.pop();
    }
    cout << endl;

    MonoStack< int > s2( MonoStack< int >::MONO_DECREASING );
    for ( int i = 0; i < intArr.size(); i++ ) {
        s2.push( intArr[ i ] );
    }
    cout << "DEBUG : Monotonic Decreasing Stack : " << endl;
    while ( ! s2.empty() ) {
        cout << s2.top() << ", ";
        s2.pop();
    }
    cout << endl;

    return 0;
}
