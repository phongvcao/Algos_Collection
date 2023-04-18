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
using std::stoi;                            // PREFERRED stoi() over atoi() since stoi() allows conversion from binary & hex strings to int.
using std::stol;                            // PREFERRED stol() over atol() since stoi() allows conversion from binary & hex strings to int.
using std::stoll;                           // PREFERRED stoll() over atoll() since stoi() allows conversion from binary & hex strings to int.

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
using std::atoi;                            // DEPRECATED: Preferred stoi() over atoi() since stoi() allows conversion from binary & hex strings to int.
using std::atol;                            // DEPRECATED: Preferred stol() over atol() since stoi() allows conversion from binary & hex strings to int.
using std::atoll;                           // DEPRECATED: Preferred stoll() over atoll() since stoi() allows conversion from binary & hex strings to int.

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
using std::numeric_limits;                  // ::lowest() & ::max() for smallest & biggest representable value, respectively
                                            // ::infinity() only works for `double` / `float` / 'long double'. ::has_infinity() == false for ALL other types.

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

class TrieSETConcise {
private:

    static const int R = 256;

    class Node {
    public:
        vector< Node * > next;
        int index = -1;
        bool isEnd = false;

        Node()
            : next( R, nullptr )
        {
            // not implemented
        }

        virtual ~Node() {
            // not implemented
        }
    };

    Node * newNode() {
        nodesVec.push_back( make_unique< Node >() );
        nodesVec.back()->index = nodesVec.size() - 1;
        return nodesVec.back().get();
    }

    void freeNode( Node * h ) {
        if ( h->index < nodesVec.size() - 1 ) {
            nodesVec[ h->index ].swap( nodesVec.back() );
            nodesVec[ h->index ]->index = h->index;
        }
        nodesVec.pop_back();
    }

    Node * get( const string& key ) const {
        if ( ! root ) return nullptr;

        Node * node = root;
        int index = 0;

        while ( index < key.size() && node ) {
            node = node->next[ key[ index++ ] ];
        }
        return node;
    }

    string toString( Node * h ) const {
        if ( ! h ) return "";
        ostringstream oss;
        oss << " ; children : ";
        for ( int c = 0; c < R; c++ ) {
            if ( h->next[ c ] ) {
                oss << ( char ) c << ", ";
            }
        }

        oss << endl;

        for ( int c = 0; c < R; c++ ) {
            if ( h->next[ c ] ) {
                oss << "index : " << h->next[ c ]->index << " ; char : " << ( char ) c
                    << " ; isEnd : " << h->next[ c ]->isEnd;
                oss << toString( h->next[ c ] );
            }
        }
        return oss.str();
    }
    
    vector< unique_ptr< Node > > nodesVec;
    int N = 0;
    Node * root = nullptr;

public:

    TrieSETConcise() {
        // not implemented
    }

    virtual ~TrieSETConcise() {
        // not implemented
    }

    int size() const {
        return N;
    }

    bool empty() const {
        return size() == 0;
    }

    bool contains( const string& key ) const {
        Node * rv = get( key );
        if ( ! rv || ! rv->isEnd ) return false;
        return true;
    }

    void put( const string& key ) {
        if ( ! root ) root = newNode();
        Node * node = root;

        for ( int i = 0; i < key.size(); ++i ) {
            if ( ! node->next[ key[ i ] ] ) {
                node->next[ key[ i ] ] = newNode();
            }
            node = node->next[ key[ i ] ];
            if ( i == key.size() - 1 && ! node->isEnd ) {
                node->isEnd = true;
                ++N;
            }
        }
    }

    queue< string > getKeysWithPrefix( const string& prefix ) const {
        queue< string > results;

        Node * node = get( prefix );
        if ( ! node ) return results;

        queue< pair< Node *, string > > nodesQueue;
        nodesQueue.push( { node, prefix } );

        while ( ! nodesQueue.empty() ) {
            auto [ node, curPrefix ] = nodesQueue.front();
            nodesQueue.pop();

            if ( node->isEnd ) results.push( curPrefix );

            for ( int c = 0; c < R; ++c ) {
                if ( node->next[ c ] ) {
                    nodesQueue.push( { node->next[ c ], curPrefix + ( char )c } );
                }
            }
        }
        return results;
    }

    queue< string > getKeys() const {
        return getKeysWithPrefix( "" );
    }

    queue< string > getKeysThatMatch( const string& pattern) const {
        queue< string > results;

        if ( ! root ) return results;

        queue< pair< Node *, string > > nodesQueue;
        Node * node = root;
        nodesQueue.push( { node, "" } );
        
        while ( ! nodesQueue.empty() && node ) {
            auto [ node, curPrefix ] = nodesQueue.front();
            nodesQueue.pop();

            int index = curPrefix.size();
            if ( index == pattern.size() && node->isEnd ) {
                results.push( curPrefix );
                continue;
            }

            char c = pattern[ index ];

            if ( c == '.' ) {
                for ( int ch = 0; ch < R; ++ch ) {
                    if ( node->next[ ch ] ) {
                        nodesQueue.push( { node->next[ ch ], curPrefix + ( char )ch } );
                    }
                }
            } else {
                if ( node->next[ c ] ) {
                    nodesQueue.push( { node->next[ c ], curPrefix + ( char )c } );
                }
            }
        }

        return results;
    }

    string getLongestPrefixOf( const string& query ) const {
        if ( ! root ) return "";

        int length = -1;
        Node * node = root;
        for ( int i = 0; i < query.size(); ++i ) {
            if ( ! node ) break;
            if ( node->isEnd ) length = i;
            node = node->next[ query[ i ] ];
        }

        if ( length != -1 ) {
            return query.substr( 0, length );
        }

        return "";
    }

    void deleteKey( const string& key ) {
        if ( ! root ) return;

        Node * node = root;
        int index = 0;

        stack< pair< Node *, char > > freeStack;

        while ( index < key.size() && node ) {
            node = node->next[ key[ index ] ];
            if ( ! node ) break;
            freeStack.push( { node, key[ index ] } );
            ++index;
        }

        if ( ! node || ! node->isEnd ) return;

        node->isEnd = false;
        --N;

        while ( ! freeStack.empty() ) {
            auto [ node, c ] = freeStack.top();
            freeStack.pop();

            bool hasChildren = false;
            for ( int ch = 0; ch < R; ++ch ) {
                if ( node->next[ ch ] ) {
                    hasChildren = true;
                    break;
                }
            }

            if ( ! hasChildren ) {
                if ( ! freeStack.empty() ) {
                    freeStack.top().first->next[ c ] = nullptr;
                }
                freeNode( node );
            }
        }
    }

    string toString() const {
        ostringstream oss;
        oss << "index : " << root->index << " ; char : '' ; isEnd : " << root->isEnd;
        oss << toString( root );
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const TrieSETConcise& trieSet ) {
        out << "\ntrieSet:\n";
        out << trieSet.toString() << endl;
        return out;
    }
};

int main( int argc, char ** argv ) {

    vector< string > strVec = {
        "she",
        "sells",
        "sea",
        "shells",
        "by",
        "the",
        "sea",
        "shore",
    };
    
    TrieSETConcise trieSet;

    for ( int i = 0; i < strVec.size(); ++i ) {
        trieSet.put( strVec[ i ] );
    }
    
    cout << "DEBUG: trieSet : \n" << trieSet << endl;
    cout << "DEBUG: trieSet.size() : " << trieSet.size() << endl;

    cout << "DEBUG: trieSet.contains( shells ) : " << trieSet.contains( "shells" ) << endl;
    cout << "DEBUG: trieSet.contains( phong ) : " << trieSet.contains( "phong" ) << endl;

    cout << "DEBUG: trieSet.getKeysWithPrefix( se ) : ";
    queue< string > q = trieSet.getKeysWithPrefix( "se" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: trieSet.getKeysThatMatch( t.e ) : ";
    q = trieSet.getKeysThatMatch( "t.e" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: trieSet.getLongestPrefixOf( shellsort ) : " << trieSet.getLongestPrefixOf( "shellsort" ) << endl;

    cout << "=============================================================" << endl;

    trieSet.deleteKey( "sea" );
    cout << "DEBUG: trieSet.deleteKey( sea ) : " << trieSet << endl;

    trieSet.deleteKey( "she" );
    cout << "DEBUG: trieSet.deleteKey( she ) : " << trieSet << endl;
    
    trieSet.deleteKey( "sells" );
    cout << "DEBUG: trieSet.deleteKey( sells ) : " << trieSet << endl;
    
    cout << "DEBUG: trieSet.size() : " << trieSet.size() << endl;

    cout << "DEBUG: trieSet.contains( sea ) : " << trieSet.contains( "sea" ) << endl;
    cout << "DEBUG: trieSet.contains( she ) : " << trieSet.contains( "she" ) << endl;
    cout << "DEBUG: trieSet.contains( sells ) : " << trieSet.contains( "sells" ) << endl;
    cout << "DEBUG: trieSet.contains( shells ) : " << trieSet.contains( "shells" ) << endl;
    cout << "DEBUG: trieSet.contains( phong ) : " << trieSet.contains( "phong" ) << endl;

    cout << "DEBUG: trieSet.getKeysWithPrefix( se ) : ";
    q = trieSet.getKeysWithPrefix( "se" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: trieSet.getKeysThatMatch( t.e ) : ";
    q = trieSet.getKeysThatMatch( "t.e" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;
    cout << "DEBUG: trieSet.getLongestPrefixOf( shellsort ) : " << trieSet.getLongestPrefixOf( "shellsort" ) << endl;

    return 0;
}
