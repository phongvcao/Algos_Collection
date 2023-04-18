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
// Time Complexity : O( 32 ) for all operations except Constructor
//                   O( 1 ) for Constructor
//
// Space Complexity : O( R * N * 32 ) where 32 is number of bits of an int
//
//
class BitwiseTrieSETConcise {
private:

    static const int R = 2;

    class Node {
    public:
        int index = -1;
        bool isEnd = false;
        vector< Node * > next;

        Node()
            : next( R, NULL )
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

    string getZeroPadded( string key ) const {
        while ( key.size() < height ) {
            key = "0" + key;
        }
        return key.substr( key.size() - height, height );
    }

    vector< unique_ptr< Node > > nodesVec;
    Node * root = NULL;
    int N = 0;
    int height = 0;

    Node * get( const string& key ) const {
        if ( ! root ) return NULL;
        Node * node = root;
        int index = 0;
        while ( index < key.size() && node ) {
            node = node->next[ key[ index++ ] - '0' ];
        }
        return node;
    }

    string toString( Node * h ) const {
        ostringstream oss;
        oss << " ; children : ";
        for ( int c = 0; c < R; c++ ) {
            if ( h->next[ c ] ) {
                oss << ( char )( c + '0' ) << ", ";
            }
        }

        oss << endl;

        for ( int c = 0; c < R; c++ ) {
            if ( h->next[ c ] ) {
                oss << "index : " << h->next[ c ]->index << " ; char : "
                    << ( char )( '0' + c ) << " ; isEnd : " << h->next[ c ]->isEnd
                    << toString( h->next[ c ] );
            }
        }
        return oss.str();
    }

public:

    BitwiseTrieSETConcise( int height )
        : height( height )
    {
        // not implemented
    }

    virtual ~BitwiseTrieSETConcise() {
        // not implemented
    }

    void put( string key ) {
        key = getZeroPadded( key );

        if ( ! root ) root = newNode();
        Node * node = root;
        for ( int i = 0; i < key.size(); i++ ) {
            if ( ! node->next[ key[ i ] - '0' ] ) {
                node->next[ key[ i ] - '0' ] = newNode();
            }
            node = node->next[ key[ i ] - '0' ];
            if ( i == key.size() - 1 && ! node->isEnd ) {
                node->isEnd = true;
                ++N;
            }
        }
    }

    int size() const {
        return N;
    }

    bool contains( const string& key ) const {
        Node * rv = get( key );
        if ( ! rv || ! rv->isEnd ) {
            return false;
        }
        return true;
    }

    queue< string > getKeys() const {
        return getKeysWithPrefix( "" );
    }

    queue< string > getKeysWithPrefix( const string& prefix ) const {
        queue< string > results;

        //
        // Match as many chars as we can before doing BFS
        //
        Node * node = get( prefix );

        if ( ! node ) return results;

        //
        // Here we do a BFS through the TrieSET
        //
        queue< pair< Node *, string > > nodesQueue;
        nodesQueue.push( { node, prefix } );

        while ( ! nodesQueue.empty() ) {
            pair< Node *, string > nodePair = nodesQueue.front();
            nodesQueue.pop();
            node = nodePair.first;
            string curPrefix = nodePair.second;

            //
            // If we reach current node that has isEnd == true, that means
            // curPrefix is a key with prefix "prefix" ( because we start the
            // BFS from node = get( prefix ), so we have matched as many chars
            // as we can before the BFS )
            //
            if ( node->isEnd ) results.push( curPrefix );

            for ( int c = 0; c < R; c++ ) {
                if ( node->next[ c ] ) {
                    nodesQueue.push( { node->next[ c ], curPrefix + ( char )( c + '0' ) } );
                }
            }
        }
        return results;
    }

    queue< string > getKeysThatMatch( const string& pattern ) const {
        queue< string > results;
        Node * node = root;

        if ( ! root ) return results;

        //
        // Here we do a BFS through the TrieSET
        //
        queue< pair< Node *, string > > nodesQueue;
        nodesQueue.push( { node, "" } );

        while ( ! nodesQueue.empty() ) {
            pair< Node *, string > nodePair = nodesQueue.front();
            nodesQueue.pop();

            node = nodePair.first;
            string curPrefix = nodePair.second;
            int index = curPrefix.size();

            //
            // If we hit end of pattern and also the current node isEnd == true,
            // that means curPrefix matches pattern.
            //
            if ( index == pattern.size() && node->isEnd ) {
                results.push( curPrefix );
                continue;
            }

            char c = pattern[ index ];
            if ( c == '.' ) {
                for ( int ch = 0; ch < R; ch++ ) {
                    if ( node->next[ ch ] ) {
                        nodesQueue.push( { node->next[ ch ], curPrefix + ( char )( ch + '0' ) } );
                    }
                }
            } else {
                if ( node->next[ c - '0' ] ) {
                    nodesQueue.push( { node->next[ c - '0' ], curPrefix + ( char )c } );
                }
            }
        }
        return results;
    }

    string getLongestPrefixOf( const string& query ) const {
        if ( ! root ) return "";
        
        int length = -1;
        Node * node = root;
        for ( int i = 0; i < query.size(); i++ ) {
            if ( ! node ) break;
            if ( node->isEnd ) length = i;
            node = node->next[ query[ i ] - '0' ];
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

        //
        // Free the key in TrieSET in a DFS manner
        //
        stack< pair< Node *, char > > freeStack;
        while ( index < key.size() && node ) {
            node = node->next[ key[ index ] - '0' ];
            if ( ! node ) break;
            freeStack.push( { node, key[ index ] } );
            ++index;
        }

        if ( ! node || ! node->isEnd ) return;

        node->isEnd = false;
        --N;
        while ( ! freeStack.empty() ) {
            pair< Node *, char > nodePair = freeStack.top();
            freeStack.pop();

            node = nodePair.first;
            char c = nodePair.second;

            bool hasChildren = false;
            for ( int ch = 0; ch < R; ++ch ) {
                if ( node->next[ ch ] ) {
                    hasChildren = true;
                    break;
                }
            }

            if ( ! hasChildren ) {
                if ( ! freeStack.empty() ) {
                    freeStack.top().first->next[ c - '0' ] = NULL;
                }
                freeNode( node );
            }
        }
    }

    string toString() const {
        ostringstream oss;
        oss << "index : " << root->index << " ; char : '' ; isEnd : " << root->isEnd;
        oss << toString( root );

        oss << "\nkeys:\n";
        queue< string > q = getKeys();
        while ( ! q.empty() ) {
            oss << q.front() << ", ";
            q.pop();
        }
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const BitwiseTrieSETConcise& trieSet ) {
        out << "\ntrieSet:\n";
        out << trieSet.toString() << endl;
        return out;
    }

};

int main( int argc, char ** argv ) {

    vector< int > intVec = { 14, 12, 10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9, 11, 13 };
    
    BitwiseTrieSETConcise bTrieSet( 4 );

    for ( int i = 0; i < intVec.size(); ++i ) {
        bTrieSet.put( bitset< 32 >( intVec[ i ] ).to_string() );
    }
    
    cout << "DEBUG: bTrieSet : \n" << bTrieSet << endl;
    cout << "DEBUG: bTrieSet.size() : " << bTrieSet.size() << endl;

    cout << "DEBUG: bTrieSet.contains( 12 ) : " << bTrieSet.contains( bitset< 32 >( 12 ).to_string() ) << endl;
    cout << "DEBUG: bTrieSet.contains( 15 ) : " << bTrieSet.contains( bitset< 32 >( 15 ).to_string() ) << endl;

    cout << "DEBUG: bTrieSet.getKeysWithPrefix( 11 ) : ";
    queue< string > q = bTrieSet.getKeysWithPrefix( "11" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: bTrieSet.getKeysThatMatch( 01.0 ) : ";
    q = bTrieSet.getKeysThatMatch( "01.0" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: bTrieSet.getLongestPrefixOf( 1000000 ) : " << bTrieSet.getLongestPrefixOf( "1000000" ) << endl;

    cout << "=============================================================" << endl;

    bTrieSet.deleteKey( bitset< 4 >( 10 ).to_string() );
    cout << "DEBUG: bTrieSet.deleteKey( 10 ) : " << bTrieSet << endl;

    bTrieSet.deleteKey( bitset< 4 >( 8 ).to_string() );
    cout << "DEBUG: bTrieSet.deleteKey( 8 ) : " << bTrieSet << endl;
    
    bTrieSet.deleteKey( bitset< 4 >( 11 ).to_string() );
    cout << "DEBUG: bTrieSet.deleteKey( 11 ) : " << bTrieSet << endl;
    
    cout << "DEBUG: bTrieSet.size() : " << bTrieSet.size() << endl;

    cout << "DEBUG: bTrieSet.contains( 10 ) : " << bTrieSet.contains( bitset< 4 >( 10 ).to_string() ) << endl;
    cout << "DEBUG: bTrieSet.contains( 11 ) : " << bTrieSet.contains( bitset< 4 >( 11 ).to_string() ) << endl;
    cout << "DEBUG: bTrieSet.contains( 13 ) : " << bTrieSet.contains( bitset< 4 >( 13 ).to_string() ) << endl;
    cout << "DEBUG: bTrieSet.contains( 14 ) : " << bTrieSet.contains( bitset< 4 >( 14 ).to_string() ) << endl;
    cout << "DEBUG: bTrieSet.contains( 15 ) : " << bTrieSet.contains( bitset< 4 >( 15 ).to_string() ) << endl;

    cout << "DEBUG: bTrieSet.getKeysWithPrefix( 11 ) : ";
    q = bTrieSet.getKeysWithPrefix( "11" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: bTrieSet.getKeysThatMatch( 01.0 ) : ";
    q = bTrieSet.getKeysThatMatch( "01.0" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;
    cout << "DEBUG: bTrieSet.getLongestPrefixOf( 1000000 ) : " << bTrieSet.getLongestPrefixOf( "1000000" ) << endl;

    return 0;
}
