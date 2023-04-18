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

//----< cmath >-----------------//
using std::sqrt;
using std::pow;
using std::log;                 // log( <arg> )
using std::exp;                 // e ^ <arg>
using std::abs;
using std::floor;               // Round down to nearest integer double
using std::ceil;                // Round up to nearest integer double
using std::trunc;               // Truncate the fractional part to get the integer part
using std::round;               // Round to nearest integer double

//----< cstdlib >---------------//
using std::rand;
using std::srand;

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

//----< iterator >--------------//
using std::next;                // Return an advanced iter without changing original iter
using std::prev;                // Return an decremented iter without changing original iter
using std::distance;            // Calculate distance between 2 iterators

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
using std::sort;                // Intro-Sort elements, but NOT preserve original order of equal elements
using std::partial_sort;        // Sort elements in range ( iterFirst, iterLast ) ( exclusively )
using std::stable_sort;         // Merge-Sort elements & preserve original order of equal elements
using std::remove;
using std::swap;
using std::binary_search;
using std::next_permutation;

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

//------------------------------//

// Time Complexities : O( M ) where M is length of the array
// Space Complexities : O( M ) where M is length of the array

template< typename Value >
class Permutation {
public:

    static bool next_permutation( vector< Value >& arr ) {
        //
        // Following are few observations about the next greater number.
        //
        // 1) If all digits sorted in descending order, then output is always
        //    “Not Possible”. For example, 4321.
        //
        // 2) If all digits are sorted in ascending order, then we need to swap
        //    last two digits. For example, 1234.
        //
        // 3) For other cases, we need to process the number from rightmost side
        // (why? because we need to find the smallest of all greater numbers)
        //
        // You can now try developing an algorithm yourself.
        //
        // Following is the algorithm for finding the next greater number.
        //
        // I) Traverse the given number from rightmost digit, keep traversing
        // till you find a digit which is smaller than the previously traversed
        // digit.
        //
        // For example, if the input number is “53 4 976”, we stop at 4 because 4
        // is smaller than next digit 9. If we do not find such a digit, then
        // output is “Not Possible”.
        //
        // II) Now search the right side of above found digit ‘d’ for the
        // smallest digit greater than ‘d’. For “53 4 976″, the right side of 4
        // contains “976”. The smallest digit greater than 4 is 6.
        //
        // III) Swap the above found two digits, we get 53 6 97 4 in above example.
        //
        // IV) Now sort all digits from position next to ‘d’ to the end of
        // number. The number that we get after sorting is the output.
        //
        // For above example, we sort digits in bold 53 6 97 4. We get “53 6 4 79”
        // which is the next greater number for input 534976.
        //

        if ( arr.size() <= 1 ) return false;

        //
        // I) Traverse the given number from rightmost digit, keep traversing
        // till you find a digit which is smaller than the previously traversed
        // digit.
        //
        // For example, if the input number is “53 4 976”, we stop at 4 because 4
        // is smaller than next digit 9. If we do not find such a digit, then
        // output is “Not Possible”.
        //
        int i = arr.size() - 1;
        while ( arr[ i ] <= arr[ i - 1 ] ) {
            // Here after the loop, i will be at the index of the number
            // that is not greater than next number
            // 
            // If this index happens to be the beginning of the string, then
            // that means we have reached the maximum permutation of arr
            if ( --i == 0 ) return false;
        }

        // Now again we loop reversely & find the first right most number that
        // is larger than arr[ i - 1 ] ( which, as explained above, was the first
        // number that is not greater than the next number )
        int j = arr.size() - 1;
        while ( j > i && arr[ j ] <= arr[ i - 1 ] ) {
            --j;
        }

        // Now we swap arr[ i - 1 ] with arr[ j ].
        swap( arr[ i - 1 ], arr[ j ] );

        // After swapping, we reverse numbers from i to arr.end() whic would
        // generate the next permutation of arr.
        reverse( arr.begin() + i, arr.end() );

        return true;
    }

};

int main( int argc, char ** argv ) {

    vector< int > intVec = { 1, 2, 3, 4, 5 };
    int N = 10000;

    cout << "DEBUG : GENERATING " << N << " PERMUTATIONS:" << endl;

    for ( int n = 0; n < N; n++ ) {
        if ( Permutation< int >::next_permutation( intVec ) ) {
            for ( int i = 0; i < intVec.size(); i++ ) {
                cout << intVec[ i ] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
