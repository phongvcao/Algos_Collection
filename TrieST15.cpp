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
using std::make_pair;
using std::move;            // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >---------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;
using std::remove;

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

//
// Time Complexity : O( M ) for all operations except Constructor 
//                     O( 1 ) for Constructor for Constructor
//                     O( log_R ( N ) ) for search miss in TrieST built with
//                     N random keys over alphabet of size R.
// Space Complexity : R * N to R * N * w where w is average key length
//
template< typename Value >
class TrieST {
private:

    static const int R;

    class Node {
    public:
        unique_ptr< Value > val;
        vector< Node * > next;
        int index = -1;

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
        nodes.push_back( make_unique< Node >() );
        nodes.back()->index = nodes.size() - 1;
        return nodes.back().get();
    }

    void freeNode( Node * h ) {
        if ( h->index < nodes.size() - 1 ) {
            nodes[ h->index ].swap( nodes.back() );
            nodes[ h->index ]->index = h->index;
        }
        nodes.pop_back();
    }

    Node * get( Node * h, const string& key, int d ) const {
        if ( ! h ) return NULL;
        if ( d == key.size() ) return h;
        char c = key[ d ];
        return get( h->next[ c ], key, d + 1 );
    }

    void getKeysWithPrefix( Node * h, string prefix, queue< string >& results ) const {
        if ( ! h ) return;
        if ( h->val ) results.push( prefix );
        for ( int c = 0; c < R; c++ ) {
            prefix += ( char ) c;
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
                prefix += ( char ) ch;
                getKeysThatMatch( h->next[ ch ], prefix, pattern, results );
                prefix.pop_back();
            }
        } else {
            prefix += ( char ) c;
            getKeysThatMatch( h->next[ c ], prefix, pattern, results );
            prefix.pop_back();
        }
    }

    int getLongestPrefixOf( Node * h, const string& query, int d, int length ) const {
        if ( ! h ) return length;
        if ( h->val ) length = d;
        if ( d == query.size() ) return length;
        char c = query[ d ];
        return getLongestPrefixOf( h->next[ c ], query, d + 1, length );
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
        h->next[ c ] = put( h->next[ c ], key, val, d + 1 );
        return h;
    }

    Node * deleteKey( Node * h, const string& key, int d ) {
        if ( ! h ) return NULL;

        if ( d == key.size() ) {
            if ( h->val ) --N;
            h->val = NULL;
        } else {
            char c = key[ d ];
            h->next[ c ] = deleteKey( h->next[ c ], key, d + 1 );
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
                oss << ( char ) c << ", ";
            }
        }

        oss << endl;

        for ( int c = 0; c < R; c++ ) {
            if ( h->next[ c ] ) {
                oss << "index : " << h->next[ c ]->index << " ; char : "
                    << ( char ) c << " ; val : ";
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

    vector< unique_ptr< Node > > nodes;
    Node * root = NULL;
    int N = 0;

public:

    TrieST() {
        // not implemented
    }

    virtual ~TrieST() {
        // not implemented
    }

    int size() const {
        return N;
    }

    bool empty() const {
        return size() == 0;
    }

    Value get( const string& key ) const {
        Node * rv = get( root, key, 0 );
        if ( ! rv || ! rv->val ) {
            throw runtime_error( "Key not exist : " + key );
        } else {
            return *( rv->val );
        }
    }

    bool contains( const string& key ) const {
        try {
            Value val = get( key );
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
        getKeysThatMatch( root, "", pattern, results );
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
        root = put( root, key, val, 0 );
    }

    void deleteKey( const string& key ) {
        root = deleteKey( root, key, 0 );
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
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const TrieST< Value >& st ) {
        out << "\nst:\n";
        out << st.toString() << endl;
        return out;
    }

};

template< typename Value >
const int TrieST< Value >::R = 256;

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
    
    TrieST< int > trieST;

    for ( int i = 0; i < strVec.size(); ++i ) {
        trieST.put( strVec[ i ], i );
    }
    
    cout << "DEBUG: trieST : \n" << trieST << endl;
    cout << "DEBUG: trieST.size() : " << trieST.size() << endl;

    try {
        cout << "DEBUG: trieST.get( sea ) : " << trieST.get( "sea" ) << endl;
        cout << "DEBUG: trieST.get( seashells ) : " << trieST.get( "seashells" ) << endl;
    } catch ( const runtime_error& e ) {
        cout << e.what() << endl;
    }
    cout << "DEBUG: trieST.contains( shells ) : " << trieST.contains( "shells" ) << endl;
    cout << "DEBUG: trieST.contains( phong ) : " << trieST.contains( "phong" ) << endl;

    cout << "DEBUG: trieST.getKeysWithPrefix( se ) : ";
    queue< string > q = trieST.getKeysWithPrefix( "se" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: trieST.getKeysThatMatch( t.e ) : ";
    q = trieST.getKeysThatMatch( "t.e" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: trieST.getLongestPrefixOf( shellsort ) : " << trieST.getLongestPrefixOf( "shellsort" ) << endl;

    cout << "=============================================================" << endl;

    trieST.deleteKey( "sea" );
    cout << "DEBUG: trieST.deleteKey( sea ) : " << trieST << endl;

    trieST.deleteKey( "she" );
    cout << "DEBUG: trieST.deleteKey( she ) : " << trieST << endl;
    
    trieST.deleteKey( "sells" );
    cout << "DEBUG: trieST.deleteKey( sells ) : " << trieST << endl;
    
    cout << "DEBUG: trieST.size() : " << trieST.size() << endl;

    try {
        cout << "DEBUG: trieST.get( sea ) : " << trieST.get( "sea" ) << endl;
        cout << "DEBUG: trieST.get( seashells ) : " << trieST.get( "seashells" ) << endl;
    } catch ( const runtime_error& e ) {
        cout << e.what() << endl;
    }
    cout << "DEBUG: trieST.contains( sea ) : " << trieST.contains( "sea" ) << endl;
    cout << "DEBUG: trieST.contains( she ) : " << trieST.contains( "she" ) << endl;
    cout << "DEBUG: trieST.contains( sells ) : " << trieST.contains( "sells" ) << endl;
    cout << "DEBUG: trieST.contains( shells ) : " << trieST.contains( "shells" ) << endl;
    cout << "DEBUG: trieST.contains( phong ) : " << trieST.contains( "phong" ) << endl;

    cout << "DEBUG: trieST.getKeysWithPrefix( se ) : ";
    q = trieST.getKeysWithPrefix( "se" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: trieST.getKeysThatMatch( t.e ) : ";
    q = trieST.getKeysThatMatch( "t.e" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;
    cout << "DEBUG: trieST.getLongestPrefixOf( shellsort ) : " << trieST.getLongestPrefixOf( "shellsort" ) << endl;

    return 0;
}
