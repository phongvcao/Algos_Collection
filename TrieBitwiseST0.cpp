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

template< typename Value >
class BitwiseTrieST {
private:

    static const int R; 

    class Node {
    public:

        int index = -1;
        unique_ptr< Value > val;
        vector< Node * > next;

        Node()
            : next( R, NULL )
        {
            // empty for now
        }

        virtual ~Node() {
            // empty for now
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

    Node * get( Node * h, const string& key, int d ) const {
        if ( ! h ) return NULL;
        if ( d == key.size() ) return h;
        char c = key[ d ];
        return get( h->next[ c - '0' ], key, d + 1 );
    }

    void getKeysWithPrefix( Node * h, string prefix, queue< string >& results ) const {
        if ( ! h ) return;
        if ( h->val ) results.push( prefix );
        for ( int c = 0; c < R; c++ ) {
            prefix += ( char )( '0' + c );
            getKeysWithPrefix( h->next[ c ], prefix, results );
            prefix.pop_back();
        }
    }

    void getKeysThatMatch( Node * h, string prefix, const string& pattern, queue< string >& results ) const {
        if ( ! h ) return;
        int d = prefix.size();
        if ( h->val && d == pattern.size() ) results.push( prefix );
        if ( d == pattern.size() ) return;
        char c = pattern[ d ];
        if ( c == '.' ) {
            for ( int ch = 0; ch < R; ch++ ) {
                prefix += ( char )( '0' + ch );
                getKeysThatMatch( h->next[ ch ], prefix, pattern, results );
                prefix.pop_back();
            }
        } else {
            prefix += ( char ) c;
            getKeysThatMatch( h->next[ c - '0' ], prefix, pattern, results );
            prefix.pop_back();
        }
    }

    int getLongestPrefixOf( Node * h, const string& query, int d, int length ) const {
        if ( ! h ) return length;
        if ( h->val ) length = d;
        if ( d == query.size() ) return length;
        char c = query[ d ];
        return getLongestPrefixOf( h->next[ c - '0' ], query, d + 1, length );
    }

    Node * put( Node * h, string key, Value val, int d ) {
        if ( ! h ) {
            h = newNode();
        }

        if ( d == key.size() ) {
            if ( ! h->val ) ++N;
            h->val = make_unique< Value >( val );
            return h;
        }

        char c = key[ d ];
        h->next[ c - '0' ] = put( h->next[ c - '0' ], key, val, d + 1 );
        return h;
    }

    Node * deleteKey( Node * h, const string& key, int d ) {
        if ( ! h ) return NULL;

        if ( d == key.size() ) {
            if ( h->val ) --N;
            h->val = NULL;
        } else {
            char c = key[ d ];
            h->next[ c - '0' ] = deleteKey( h->next[ c - '0' ], key, d + 1 );
        }

        if ( h->val ) return h;
        for ( int c = 0; c < R; c++ ) {
            if ( h->next[ c ] ) return h;
        }
        freeNode( h );
        return NULL;
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
                    << ( char )( '0' + c ) << " ; val : ";
                if ( h->next[ c ]->val ) {
                    oss << *( h->next[ c ]->val );
                } else {
                    oss << "NULL";
                }
                oss << toString( h->next[ c ] );
            }
        }
        return oss.str();
    }

    string getZeroPadded( string key ) const {
        while ( key.size() < height ) {
            key = "0" + key;
        }
        return key.substr( key.size() - height, height );
    }

    vector< unique_ptr< Node > > nodesVec;
    int N = 0;
    Node * root = NULL;
    int height = 0;

public:

    BitwiseTrieST( int height )
        : height( height )
    {
        // empty for now
    }

    virtual ~BitwiseTrieST() {
        // empty for now
    }

    int size() const {
        return N;
    }

    bool empty() const {
        return size() == 0;
    }

    Value get( const string& key ) const {
        Node * rv = get( root, getZeroPadded( key ), 0 );
        if ( ! rv || ! rv->val ) {
            throw runtime_error( "Key not exist : " + key );
        } else {
            return *( rv->val );
        }
    }

    bool contains( const string& key ) const {
        try {
            Value val = get( getZeroPadded( key ) );
        } catch ( const runtime_error& e ) {
            return false;
        }
        return true;
    }

    queue< string > getKeys() const {
        return getKeysWithPrefix( "" );
    }

    queue< string > getKeysWithPrefix( const string& prefix ) const {
        queue< string > results;
        Node * h = get( root, prefix, 0 );
        getKeysWithPrefix( h, prefix, results );
        return results;
    }

    queue< string > getKeysThatMatch( const string& pattern ) const {
        queue< string > results;
        getKeysThatMatch( root, "", getZeroPadded( pattern ), results );
        return results;
    }

    string getLongestPrefixOf( const string& query ) const {
        int length = getLongestPrefixOf( root, query, 0, -1 );
        if ( length == -1 ) {
            return "";
        } else {
            return query.substr( 0, length );
        }
    }

    void put( string key, Value val ) {
        root = put( root, getZeroPadded( key ), val, 0 );
    }

    void deleteKey( const string& key ) {
        root = deleteKey( root, getZeroPadded( key ), 0 );
    }

    string toString() const {
        ostringstream oss;
        oss << "index : " << root->index << " ; char : '' ; val : ";
        if ( root->val ) {
            oss << *( root->val );
        } else {
            oss << "NULL";
        }
        oss << toString( root );

        oss << "\nkeys:\n";
        queue< string > q = getKeys();
        while ( ! q.empty() ) {
            oss << q.front() << ", ";
            q.pop();
        }
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const BitwiseTrieST< Value >& st ) {
        out << "\nst:\n";
        out << st.toString() << endl;
        return out;
    }

};

template< typename Value >
const int BitwiseTrieST< Value >::R = 2;

int main( int argc, char ** argv ) {

    vector< int > intVec = { 14, 12, 10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9, 11, 13 };
    
    BitwiseTrieST< int > bTrieST( 4 );

    for ( int i = 0; i < intVec.size(); ++i ) {
        bTrieST.put( bitset< 32 >( intVec[ i ] ).to_string(), intVec[ i ] );
    }
    
    cout << "DEBUG: bTrieST : \n" << bTrieST << endl;
    cout << "DEBUG: bTrieST.size() : " << bTrieST.size() << endl;

    try {
        cout << "DEBUG: bTrieST.get( 14 ) : " << bTrieST.get( bitset< 32 >( 14 ).to_string() ) << endl;
        cout << "DEBUG: bTrieST.get( 15 ) : " << bTrieST.get( bitset< 32 >( 15 ).to_string() ) << endl;
    } catch ( const runtime_error& e ) {
        cout << e.what() << endl;
    }
    cout << "DEBUG: bTrieST.contains( 12 ) : " << bTrieST.contains( bitset< 32 >( 12 ).to_string() ) << endl;
    cout << "DEBUG: bTrieST.contains( 15 ) : " << bTrieST.contains( bitset< 32 >( 15 ).to_string() ) << endl;

    cout << "DEBUG: bTrieST.getKeysWithPrefix( 11 ) : ";
    queue< string > q = bTrieST.getKeysWithPrefix( "11" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: bTrieST.getKeysThatMatch( 01.0 ) : ";
    q = bTrieST.getKeysThatMatch( "01.0" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: bTrieST.getLongestPrefixOf( 1000000 ) : " << bTrieST.getLongestPrefixOf( "1000000" ) << endl;

    cout << "=============================================================" << endl;

    bTrieST.deleteKey( bitset< 4 >( 10 ).to_string() );
    cout << "DEBUG: bTrieST.deleteKey( 10 ) : " << bTrieST << endl;

    bTrieST.deleteKey( bitset< 4 >( 8 ).to_string() );
    cout << "DEBUG: bTrieST.deleteKey( 8 ) : " << bTrieST << endl;
    
    bTrieST.deleteKey( bitset< 4 >( 11 ).to_string() );
    cout << "DEBUG: bTrieST.deleteKey( 11 ) : " << bTrieST << endl;
    
    cout << "DEBUG: bTrieST.size() : " << bTrieST.size() << endl;

    try {
        cout << "DEBUG: bTrieST.get( 10 ) : " << bTrieST.get( bitset< 4 >( 10 ).to_string() ) << endl;
        cout << "DEBUG: bTrieST.get( 15 ) : " << bTrieST.get( bitset< 4 >( 15 ).to_string() ) << endl;
    } catch ( const runtime_error& e ) {
        cout << e.what() << endl;
    }
    cout << "DEBUG: bTrieST.contains( 10 ) : " << bTrieST.contains( bitset< 4 >( 10 ).to_string() ) << endl;
    cout << "DEBUG: bTrieST.contains( 11 ) : " << bTrieST.contains( bitset< 4 >( 11 ).to_string() ) << endl;
    cout << "DEBUG: bTrieST.contains( 13 ) : " << bTrieST.contains( bitset< 4 >( 13 ).to_string() ) << endl;
    cout << "DEBUG: bTrieST.contains( 14 ) : " << bTrieST.contains( bitset< 4 >( 14 ).to_string() ) << endl;
    cout << "DEBUG: bTrieST.contains( 15 ) : " << bTrieST.contains( bitset< 4 >( 15 ).to_string() ) << endl;

    cout << "DEBUG: bTrieST.getKeysWithPrefix( 11 ) : ";
    q = bTrieST.getKeysWithPrefix( "11" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: bTrieST.getKeysThatMatch( 01.0 ) : ";
    q = bTrieST.getKeysThatMatch( "01.0" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;
    cout << "DEBUG: bTrieST.getLongestPrefixOf( 1000000 ) : " << bTrieST.getLongestPrefixOf( "1000000" ) << endl;

    return 0;
}
