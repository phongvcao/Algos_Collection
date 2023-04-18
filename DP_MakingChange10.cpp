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

//----< iostream >--------------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----< cstdio >----------------//
using std::printf;
using std::fprintf;
using std::sprintf;
using std::snprintf;

//----< iomanip >---------------//
using std::setprecision;
using std::setw;

//----< ios >-------------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----< sstream >---------------//
using std::stringstream;
using std::ostringstream;
using std::istringstream;

//----< fstream >---------------//
using std::ofstream;
using std::ifstream;

//----< string >----------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;
using std::stoll;

//----< cmath >-----------------//
using std::sqrt;
using std::pow;
using std::log;                 // log( <arg> )
using std::exp;                 // e ^ <arg>
using std::abs;
using std::fabs;
using std::floor;               // Round down to nearest integer double
using std::ceil;                // Round up to nearest integer double
using std::trunc;               // Truncate the fractional part to get the integer part
using std::round;               // Round to nearest integer double

//----< cstdlib >---------------//
using std::rand;
using std::srand;
using std::atoi;
using std::atol;
using std::atoll;

//----< ctime >-----------------//
using std::time;

//----< functional >------------//
using std::hash;
using std::greater;             // lhs > rhs. Used for MinPQ
using std::less;                // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;

//----< array >-----------------//
using std::array;               // Fixed & Unordered Array

//----< vector >----------------//
using std::vector;              // Resizable & Unordered Array

//----< map >-------------------//
using std::map;                 // Ordered Map (Red-Black Tree)
using std::multimap;            // Ordered Map (Red-Black Tree) & Allow duplicated keys

//----< unordered_map >---------//
using std::unordered_map;       // HashMap (SeparateChainingHashST)
using std::unordered_multimap;  // Ordered Map (Red-Black Tree) & Allow duplicated keys

//----< set >-------------------//
using std::set;                 // Ordered Set (Red-Black Tree)
using std::multiset;            // Ordered Set (Red-Black Tree) & Allow duplicated keys

//----< unordered_set >---------//
using std::unordered_set;       // HashSet (SeparateChainingHashST)
using std::unordered_multiset;  // HashSet (SeparateChainingHashST) & Allow duplicated keys

//----< list >------------------//
using std::list;                // Doubly-Linked List with size() ( O( 1 ) )

//----< forward_list >----------//
using std::forward_list;        // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----< deque >-----------------//
using std::deque;               // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----< queue >-----------------//
using std::queue;               // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;      // MaxPQ (MaxHeap) & Non-Iterable.
//                              // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----< stack >-----------------//
using std::stack;               // Non-Iterable & Use std::deque as underlying data structure

//----< tuple >-----------------//
using std::tuple;               // Non-Iterable & Use std::pair as underlying data structure
using std::get;                 // Access & Set element in tuple using get< index >( tuple_var )

//----< bitset >----------------//
using std::bitset;

//----< iterator >--------------//
using std::next;                // Return an advanced iter without changing original iter
using std::prev;                // Return an decremented iter without changing original iter
using std::distance;            // Calculate distance between 2 iterators
using std::inserter;            // Insert element into first arg starting from position in second arg

//----< utility >---------------//
using std::pair;
using std::make_pair;
using std::move;                // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >-------------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;                // Intro-Sort (QuickSort => HeapSort when recursion depth exceeds certain level), NOT IN-PLACE & NOT STABLE
using std::partial_sort;        // HeapSort elements in range ( iterFirst, iterLast ) ( exclusively ). IN-PLACE & NOT STABLE
using std::stable_sort;         // Merge-Sort elements. NOT IN-PLACE & STABLE
using std::sort_heap;           // HeapSort elements. IN-PLACE & NOT STABLE
using std::remove;
using std::swap;
using std::binary_search;
using std::next_permutation;
using std::prev_permutation;
using std::set_intersection;    // Only works on std::set and not std::unordered_set
using std::set_difference;      // Only works on std::set and not std::unordered_set
using std::set_union;
using std::lower_bound;         // Returns iter pointing to first element >= value
using std::upper_bound;         // Returns iter pointing to first element > value
using std::transform;           // Apply the given function to a range and store result in another range
using std::nth_element;

//----< memory >----------------//
using std::make_unique;
using std::unique_ptr;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

//----< cctype >----------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;             // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;             // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----< stdexcept >-------------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----< limits >----------------//
using std::numeric_limits;

//----< numeric >---------------//
using std::iota;
using std::gcd;
using std::lcm;
using std::partial_sum;         // Calculate partial_sum of range beginIter, endIter and put result to 3rd argument outIter

//------------------------------//

//
// The 'FAST' method for solving DP problems
// 1. F_irst solution
// 2. A_nalyze the first solution
// 3. Identify the S_ubproblems
// 4. T_urn the solution around
//
// Top-Down DP  => Recursive
// Bottom-Up DP => Iterative
//

class MakingChange {
private:

    static int makeChangeTopDownDP( int coinsLeft, const vector< int >& coinsVec,
                                    vector< int >& cache ) {
        if ( cache[ coinsLeft ] >= 0 ) return cache[ coinsLeft ];

        int minCoins = numeric_limits< int >::max();
        for ( int i = 0; i < coinsVec.size(); i++ ) {
            if ( coinsLeft - coinsVec[ i ] >= 0 ) {
                minCoins = min( minCoins, makeChangeTopDownDP( coinsLeft - coinsVec[ i ], coinsVec, cache ) );
            }
        }

        cache[ coinsLeft ] = minCoins + 1;
        return cache[ coinsLeft ];
    }

public:

    //
    // Time Complexity : O( coinsVec.size() ^ N )
    // Space Complexity : O( coinsVec.size() ^ N )
    //
    static int makeChangeRecursively( int coinsLeft, const vector< int >& coinsVec ) {
        if ( coinsLeft == 0 ) return 0;

        int minCoins = numeric_limits< int >::max();
        for ( int i = 0; i < coinsVec.size(); i++ ) {
            if ( coinsLeft - coinsVec[ i ] >= 0 ) {
                minCoins = min( minCoins, makeChangeRecursively( coinsLeft - coinsVec[ i ], coinsVec ) );
            }
        }

        return minCoins + 1;
    }

    //
    // Time Complexity : O( coinsVec.size() * N )
    // Space Complexity : O( N )
    //
    static int makeChangeTopDownDP( int coinsLeft, const vector< int >& coinsVec ) {
        vector< int > cache( coinsLeft + 1, -1 );
        cache[ 0 ] = 0;

        return makeChangeTopDownDP( coinsLeft, coinsVec, cache );
    }

    //
    // Time Complexity : O( coinsVec.size() * N )
    // Space Complexity : O( N )
    //
    static int makeChangeBottomUpDP( int coinsLeft, const vector< int >& coinsVec ) {
        vector< int > cache( coinsLeft + 1, -1 );
        cache[ 0 ] = 0;

        for ( int i = 1; i < coinsLeft + 1; i++ ) {
            int curMinCoins = numeric_limits< int >::max();
            for ( int j = 0; j < coinsVec.size(); j++ ) {
                if ( i - coinsVec[ j ] >= 0 ) {
                    curMinCoins = min( curMinCoins, cache[ i - coinsVec[ j ] ] + 1 );
                }
            }
            cache[ i ] = curMinCoins;
        }

        return cache[ coinsLeft ];
    }

};

int main( int argc, char ** argv ) {

    vector< int > coins = { 10, 6, 1 };

    cout << "DEBUG : MakingChange::makeChangeRecursively( 49 ) : "
         << MakingChange::makeChangeRecursively( 49, coins ) << endl;
    cout << "DEBUG : MakingChange::makeChangeTopDownDP( 49 ) : "
         << MakingChange::makeChangeTopDownDP( 49, coins ) << endl;
    cout << "DEBUG : MakingChange::makeChangeBottomUpDP( 49 ) : "
         << MakingChange::makeChangeBottomUpDP( 49, coins ) << endl;

    return 0;
}
