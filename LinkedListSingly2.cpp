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
using std::sort;                // Intro-Sort elements, but NOT preserve original order of equal elements
using std::partial_sort;        // Sort elements in range ( iterFirst, iterLast ) ( exclusively )
using std::stable_sort;         // Merge-Sort elements & preserve original order of equal elements
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

//------------------------------//

template< typename Value >
class SinglyLinkedList {
private:

    class Node {
    public:
        int index = -1;
        Value val;
        Node * next = NULL;

        Node( Value val )
            : val( val )
        {
            // not implemented
        }

        virtual ~Node() {
            // not implemented
        }
    };

    vector< unique_ptr< Node > > nodesVec;
    int N = 0;
    Node * head = NULL;

    Node * newNode( Value val ) {
        nodesVec.push_back( make_unique< Node >( val ) );
        nodesVec.back()->index = nodesVec.size() - 1;
        return nodesVec.back().get();
    }

    Node * freeNode( Node * h ) {
        if ( h->index < nodesVec.size() - 1 ) {
            nodesVec[ h->index ].swap( nodesVec.back() );
            nodesVec[ h->index ]->index = nodesVec.back()->index;
        }
        nodesVec.pop_back();
    }

    Node * reverseRecursively( Node * h ) {
        if ( ! h || ! h->next ) return h;

        Node * newHead = reverseRecursively( h->next );

        h->next->next = h;
        h->next = NULL;
        return newHead;
    }

    Node * reverseIteratively( Node * h ) {
        Node * next = NULL;
        Node * prev = NULL;
        Node * curr = h;

        while ( curr ) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:

    SinglyLinkedList() {
        // not implemented
    }

    virtual ~SinglyLinkedList() {
        // not implemented
    }

    void insert( Value val ) {
        if ( ! head ) {
            head = newNode( val );
        } else {
            Node * nodePtr = head;

            while ( nodePtr->next ) {
                nodePtr = nodePtr->next;
            }

            nodePtr->next = newNode( val );
        }
        ++N;
    }

    void reverse( bool isRecursive = true ) {
        if ( isRecursive ) {
            head = reverseRecursively( head );
        } else {
            head = reverseIteratively( head );
        }
    }

    friend ostream& operator <<( ostream& out, const SinglyLinkedList& sList ) {
        Node * nodePtr = sList.head;
        while ( nodePtr ) {
            cout << nodePtr->val << " , ";
            nodePtr = nodePtr->next;
        }
        return out;
    }
};

int main( int argc, char ** argv ) {

    vector< int > intArr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    SinglyLinkedList< int > sList;
    for ( int i = 0; i < intArr.size(); ++i ) {
        sList.insert( intArr[ i ] );
    }

    cout << "DEBUG : ORIGINAL : " << endl;
    cout << sList << endl;
    
    cout << "DEBUG : Reverse ( recursively ) : " << endl;
    sList.reverse();
    cout << sList << endl;
    
    cout << "DEBUG : Reverse ( iteratively ) : " << endl;
    sList.reverse( false );
    cout << sList << endl;

    return 0;
}
