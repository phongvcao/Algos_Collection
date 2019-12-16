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
// Time Complexities : O( ln ( N ) ) for search miss in TST built with
//                     N random keys over alphabet of size R.
// Space Complexities : 3 * N to 3 * N * w where w is average key length
//
template< typename Value >
class TST {
private:

    class Node {
    public:
        char c;
        Node * left = NULL;
        Node * mid = NULL;
        Node * right = NULL;
        unique_ptr< Value > val = NULL;
        int index = -1;

        Node( char c )
            : c( c )
        {
            // not implemented
        }

        virtual ~Node() {
            // not implemented
        }
    };

    Node * newNode( char c ) {
        nodes.push_back( make_unique< Node >( c ) );
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

        char c = key[ d ];

        if ( c < h->c ) {
            return get( h->left, key, d );
        } else if ( c > h->c ) {
            return get( h->right, key, d );
        } else if ( d < key.size() - 1 ) {
            return get( h->mid, key, d + 1 );
        } else {
            return h;
        }
    }

    void getKeysWithPrefix( Node * h, string prefix, queue< string >& results ) const  {
        if ( ! h ) return;

        getKeysWithPrefix( h->left, prefix, results );

        if ( h->val ) results.push( prefix + h->c );
        getKeysWithPrefix( h->mid, prefix + h->c, results );

        getKeysWithPrefix( h->right, prefix, results );
    }

    void getKeysThatMatch( Node * h, string prefix, int d, const string& pattern, queue< string >& results ) const {
        if ( ! h ) return;

        char c = pattern[ d ];

        if ( c == '.' || c < h->c ) {
            getKeysThatMatch( h->left, prefix, d, pattern, results );
        }

        if ( c == '.' || c == h->c ) {
            if ( h->val && d == pattern.size() - 1 ) results.push( prefix + h->c );
            if ( d < pattern.size() - 1 ) {
                getKeysThatMatch( h->mid, prefix + h->c, d + 1, pattern, results );
            }
        }

        if ( c == '.' || c > h->c ) {
            getKeysThatMatch( h->right, prefix, d, pattern, results );
        }
    }

    Node * put( Node * h, string key, Value val, int d ) {
        char c = key[ d ];
        if ( ! h ) {
            h = newNode( c );
        }

        if ( c < h->c ) {
            h->left = put( h->left, key, val, d );
        } else if ( c > h->c ) {
            h->right = put( h->right, key, val, d );
        } else if ( d < key.size() - 1 ) {
            h->mid = put( h->mid, key, val, d + 1 );
        } else {
            h->val = make_unique< Value >( val );
        }
        return h;
    }

    Node * deleteKey( Node * h, const string& key, int d ) {
        if ( ! h ) return NULL;

        char c = key[ d ];

        if ( c < h->c ) {
            h->left = deleteKey( h->left, key, d );
        } else if ( c > h->c ) {
            h->right = deleteKey( h->right, key, d );
        } else if ( d < key.size() - 1 ) {
            h->mid = deleteKey( h->mid, key, d + 1 );
        } else {
            h->val = NULL;
        }

        if ( ! h->left && ! h->mid && ! h->right ) {
            freeNode( h );
            return NULL;
        }
        return h;
    }

    string toString( Node * h ) const {
        if ( ! h ) return "";
        ostringstream oss;
        oss << toString( h->left );

        oss << "index : " << h->index << " ; char : " << h->c << " ; val : ";
        if ( h->val ) {
            oss << *( h->val );
        } else {
            oss << "NULL";
        }
        oss << " ; left : ";
        if ( h->left ) {
            oss << h->left->c;
        } else {
            oss << "NULL";
        }

        oss << " ; right : ";
        if ( h->right ) {
            oss << h->right->c;
        } else {
            oss << "NULL";
        }
        oss << " ; children : ";
        if ( h->mid ) {
            oss << h->mid->c;
        }
        oss << endl;

        oss << toString( h->right );
        oss << toString( h->mid );
        return oss.str();
    }

    vector< unique_ptr< Node > > nodes;
    Node * root = NULL;
    int N = 0;

public:

    TST() {
        // not implemented
    }

    virtual ~TST() {
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
        queue< string > results;
        getKeysWithPrefix( root, "", results );
        return results;
    }

    queue< string > getKeysWithPrefix( const string& prefix ) const {
        queue< string > results;
        Node * h = get( root, prefix, 0 );
        if ( ! h ) return results;
        if ( h->val ) results.push( prefix );
        getKeysWithPrefix( h->mid, prefix, results );
        return results;
    }

    queue< string > getKeysThatMatch( const string& pattern ) const {
        queue< string > results;
        getKeysThatMatch( root, "", 0, pattern, results );
        return results;
    }

    string getLongestPrefixOf( const string& query ) const {
        int d = 0;
        int length = 0;
        Node * h = root;

        while ( h && d < query.size() ) {
            char c = query[ d ];

            if ( c < h->c ) {
                h = h->left;
            } else if ( c > h->c ) {
                h = h->right;
            } else {
                ++d;
                if ( h->val ) length = d;
                h = h->mid;
            }
        }
        return query.substr( 0, length );
    }

    void put( string key, Value val ) {
        if ( ! contains( key ) ) ++N;
        root = put( root, key, val, 0 );
    }

    void deleteKey( const string& key ) {
        if ( contains( key ) ) --N;
        root = deleteKey( root, key, 0 );
    }

    string toString() const {
        ostringstream oss;
        oss << toString( root ) << endl;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const TST< Value >& tst ) {
        out << "\ntst:\n";
        out << tst.toString() << endl;
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
    
    TST< int > tst;

    for ( int i = 0; i < strVec.size(); ++i ) {
        tst.put( strVec[ i ], i );
    }
    
    cout << "DEBUG: tst : \n" << tst << endl;
    cout << "DEBUG: tst.size() : " << tst.size() << endl;

    try {
        cout << "DEBUG: tst.get( sea ) : " << tst.get( "sea" ) << endl;
        cout << "DEBUG: tst.get( seashells ) : " << tst.get( "seashells" ) << endl;
    } catch ( const runtime_error& e ) {
        cout << e.what() << endl;
    }
    cout << "DEBUG: tst.contains( shells ) : " << tst.contains( "shells" ) << endl;
    cout << "DEBUG: tst.contains( phong ) : " << tst.contains( "phong" ) << endl;

    cout << "DEBUG: tst.getKeys() : ";
    queue< string > q = tst.getKeys();
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: tst.getKeysWithPrefix( se ) : ";
    q = tst.getKeysWithPrefix( "se" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: tst.getKeysThatMatch( t.e ) : ";
    q = tst.getKeysThatMatch( "t.e" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: tst.getLongestPrefixOf( shellsort ) : " << tst.getLongestPrefixOf( "shellsort" ) << endl;

    cout << "=============================================================" << endl;

    tst.deleteKey( "sea" );
    cout << "DEBUG: tst.deleteKey( sea ) : " << tst << endl;

    tst.deleteKey( "she" );
    cout << "DEBUG: tst.deleteKey( she ) : " << tst << endl;
    
    tst.deleteKey( "sells" );
    cout << "DEBUG: tst.deleteKey( sells ) : " << tst << endl;
    
    cout << "DEBUG: tst.size() : " << tst.size() << endl;

    try {
        cout << "DEBUG: tst.get( sea ) : " << tst.get( "sea" ) << endl;
        cout << "DEBUG: tst.get( seashells ) : " << tst.get( "seashells" ) << endl;
    } catch ( const runtime_error& e ) {
        cout << e.what() << endl;
    }
    cout << "DEBUG: tst.contains( sea ) : " << tst.contains( "sea" ) << endl;
    cout << "DEBUG: tst.contains( she ) : " << tst.contains( "she" ) << endl;
    cout << "DEBUG: tst.contains( sells ) : " << tst.contains( "sells" ) << endl;
    cout << "DEBUG: tst.contains( shells ) : " << tst.contains( "shells" ) << endl;
    cout << "DEBUG: tst.contains( phong ) : " << tst.contains( "phong" ) << endl;

    cout << "DEBUG: tst.getKeysWithPrefix( se ) : ";
    q = tst.getKeysWithPrefix( "se" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: tst.getKeysThatMatch( t.e ) : ";
    q = tst.getKeysThatMatch( "t.e" );
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;
    cout << "DEBUG: tst.getLongestPrefixOf( shellsort ) : " << tst.getLongestPrefixOf( "shellsort" ) << endl;
    cout << "DEBUG: tst.getKeys() : ";
    q = tst.getKeys();
    while ( ! q.empty() ) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    return 0;
}
