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
// Time Complexity : O( log N ) for insert() & get()
// Space Complexity : O( N ) for the itemsSet
//
class CustomComparatorSet {
private:

    class Item {
    public:
        int key = 0;
        string name = "";
        
        Item( int key, const string& name )
            : key( key ),
              name( name )
        {
            // empty for now
        }

        Item( const Item& other )
            : key( other.key ),
              name( other.name )
        {
            // empty for now
        }

        virtual ~Item() {
            // empty for now
        }

        // Similar to the functions in cmpItemsWithOtherTypes()
        friend bool operator <( const Item& i1, const Item& i2 ) {
            return i1.key < i2.key;
        }
    };

    struct cmpItemsWithOtherTypes {
        // Beside using this comparator to compare 2 items in the set,
        // we can use the comparator for "binary-searching" item with
        // value "key" using "int key" instead of item of type "Item"
        bool operator ()( const Item& i1, const Item& i2 ) const {
            return i1.key < i2.key;
        }
    };

    set< Item, cmpItemsWithOtherTypes > itemsSet;

public:

    CustomComparatorSet() {
        // not implemented
    }

    virtual ~CustomComparatorSet() {
        // not implemented
    }

    //
    // O( log N )
    //
    void insert( int key, const string& name ) {
        Item item( key, name );
        if ( itemsSet.find( item ) == itemsSet.end() ) {
            itemsSet.insert( item );
        }
    }

    //
    // O( log N )
    //
    string get( int key ) const {
        //
        // set< Value >::find() operation using lower_bound()
        // 
        // We still have to create keyItem first.
        // 
        // Since we're finding lower_bound, the item returned either has
        // startIdx == key or startIdx < key, both of which are valid.
        //
        Item keyItem( key, "" );
        set< Item, cmpItemsWithOtherTypes >::iterator iter = itemsSet.lower_bound( keyItem );
        if ( iter != itemsSet.end() && iter->key == key ) {
            return iter->name;
        } else if ( iter == itemsSet.end() && key < numeric_limits< int >::max() ) {
            return itemsSet.rbegin()->name;
        }
        return "";
    }

    //
    // O( log N )
    //
    string getUpperBound( int key ) {
        Item keyItem( key, "" );
        set< Item, cmpItemsWithOtherTypes >::iterator iter = itemsSet.upper_bound( keyItem );
        if ( iter != itemsSet.end() ) return iter->name;
        return "";
    }

    //
    // O( log N )
    //
    string getLowerBound( int key ) {
        Item keyItem( key, "" );
        set< Item, cmpItemsWithOtherTypes >::iterator iter = itemsSet.lower_bound( keyItem );
        if ( iter != itemsSet.end() ) return iter->name;
        return "";
    }
};


int main( int argc, char ** argv ) {

    vector< int > intArr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20 };

    CustomComparatorSet ccSet;
    for ( int i = 0; i < intArr.size(); i++ ) {
        ccSet.insert( intArr[ i ], "name" + to_string( intArr[ i ] ) );
    }

    // DEBUG : CustomComparatorSet::get( 7 ) : name7
    // DEBUG : CustomComparatorSet::get( 50 ) : name20
    // DEBUG : CustomComparatorSet::get( 15 ) : 
    // DEBUG : CustomComparatorSet::get( 6 ) : name6
    //
    // DEBUG : CustomComparatorSet::getLowerBound( 7 ) : name7
    // DEBUG : CustomComparatorSet::getLowerBound( 50 ) : 
    // DEBUG : CustomComparatorSet::getLowerBound( 15 ) : name20
    // DEBUG : CustomComparatorSet::getLowerBound( 6 ) : name6
    //
    // DEBUG : CustomComparatorSet::getUpperBound( 7 ) : name8
    // DEBUG : CustomComparatorSet::getUpperBound( 50 ) : 
    // DEBUG : CustomComparatorSet::getUpperBound( 15 ) : name20
    // DEBUG : CustomComparatorSet::getUpperBound( 6 ) : name7

    cout << "DEBUG : CustomComparatorSet::get( 7 ) : " << ccSet.get( 7 ) << endl;
    cout << "DEBUG : CustomComparatorSet::get( 50 ) : " << ccSet.get( 50 ) << endl;
    cout << "DEBUG : CustomComparatorSet::get( 15 ) : " << ccSet.get( 15 ) << endl;
    cout << "DEBUG : CustomComparatorSet::get( 6 ) : " << ccSet.get( 6 ) << endl;
    cout << endl;
    cout << "DEBUG : CustomComparatorSet::getLowerBound( 7 ) : " << ccSet.getLowerBound( 7 ) << endl;
    cout << "DEBUG : CustomComparatorSet::getLowerBound( 50 ) : " << ccSet.getLowerBound( 50 ) << endl;
    cout << "DEBUG : CustomComparatorSet::getLowerBound( 15 ) : " << ccSet.getLowerBound( 15 ) << endl;
    cout << "DEBUG : CustomComparatorSet::getLowerBound( 6 ) : " << ccSet.getLowerBound( 6 ) << endl;
    cout << endl;
    cout << "DEBUG : CustomComparatorSet::getUpperBound( 7 ) : " << ccSet.getUpperBound( 7 ) << endl;
    cout << "DEBUG : CustomComparatorSet::getUpperBound( 50 ) : " << ccSet.getUpperBound( 50 ) << endl;
    cout << "DEBUG : CustomComparatorSet::getUpperBound( 15 ) : " << ccSet.getUpperBound( 15 ) << endl;
    cout << "DEBUG : CustomComparatorSet::getUpperBound( 6 ) : " << ccSet.getUpperBound( 6 ) << endl;

    return 0;
}
