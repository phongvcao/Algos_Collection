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
using std::move;            // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >---------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;

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

template< typename Key, typename Value >
class RedBlackBST {
private:

    static const bool RED = true;
    static const bool BLACK = false;

    class Node {
    public:
        Key key;
        Value value;
        Node * left = NULL;
        Node * right = NULL;
        int N = 0;
        bool color = RED;
        // Index of unique_ptr< Node > in nodesVec
        int index = -1;

        Node( Key key, Value value, int N, bool color )
            : key( key ),
              value( value ),
              N( N ),
              color( color )
        {
            // not implemented
        }

        virtual ~Node() {
            // not implemented
        }

        string toString() const {
            ostringstream oss;
            oss << *this;
            return oss.str();
        }

        friend ostream& operator <<( ostream& out, const Node& h ) {
            out << " | " << h.key << " : " << h.value << " ; size : " << h.N << " ; color : " << h.color;
            if ( h.left ) {
                out << " ; left : " << h.left->key;
            } else {
                out << " ; left : null";
            }

            if ( h.right ) {
                out << " ; right : " << h.right->key;
            } else {
                out << " ; right : null";
            }
            out << " | \n";
            return out;
        }

    };

    Node * root = NULL;

    // To delete a Node from nodesVec, we swap the Node to be deleted with the last node in the vector,
    // Update their index accordingly, then pop_back() to destroy the element.

    bool isRed( Node * h ) const {
        if ( ! h ) return false;
        return h->color == RED;
    }

    Node * rotateLeft( Node * h ) {
        Node * x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = size( h->left ) + size( h->right ) + 1;
        return x;
    }

    Node * rotateRight( Node * h ) {
        Node * x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = size( h->left ) + size( h->right ) + 1;
        return x;
    }

    void flipColors( Node * h ) {
        h->color = ! h->color;
        h->left->color = ! h->left->color;
        h->right->color = ! h->right->color;
    }

    Node * moveRedLeft( Node * h ) {
        flipColors( h );
        if ( isRed( h->right->left ) ) {
            h->right = rotateRight( h->right );
            h = rotateLeft( h );
            flipColors( h );
        }
        return h;
    }

    Node * moveRedRight( Node * h ) {
        flipColors( h );
        if ( isRed( h->left->left ) ) {
            h = rotateRight( h );
            flipColors( h );
        }
        return h;
    }

    Node * balance( Node * h ) {
        if ( isRed( h->right ) ) h = rotateLeft( h );
        if ( isRed( h->left ) && isRed( h->left->left ) ) h = rotateRight( h );
        if ( isRed( h->left ) && isRed( h->right ) ) flipColors( h );

        h->N = size( h->left ) + size( h->right ) + 1;
        return h;
    }

    void freeNode( Node * h ) {
        if ( h->index < nodesVec.size() - 1 ) {
            nodesVec[ h->index ].swap( nodesVec.back() );
            nodesVec[ h->index ]->index = h->index;
        }
        nodesVec.pop_back();
    }

    Node * newNode( Key key, Value value, int N, bool color ) {
        nodesVec.push_back( make_unique< Node >( key, value, N, color ) );
        nodesVec.back()->index = nodesVec.size() - 1;
        return nodesVec.back().get();
    }

    Node * put( Node * h, Key key, Value value ) {
        if ( ! h ) return newNode( key, value, 1, RED );
        if ( key < h->key ) {
            h->left = put( h->left, key, value );
        } else if ( key > h->key ) {
            h->right = put( h->right, key, value );
        } else {
            h->value = value;
        }

        if ( isRed( h->right ) && ! isRed( h->left ) ) h = rotateLeft( h );
        if ( isRed( h->left ) && isRed( h->left->left ) ) h = rotateRight( h );
        if ( isRed( h->left ) && isRed( h->right ) ) flipColors( h );

        h->N = size( h->left ) + size( h->right ) + 1;
        return h;
    }

    int size( Node * h ) const {
        if ( ! h ) {
            return 0;
        } else {
            return h->N;
        }
    }

    int height( Node * h, int count ) const {
        if ( ! h ) return count;
        int leftHeight = height( h->left, count + 1 );
        int rightHeight = height( h->right, count + 1 );
        return leftHeight < rightHeight ? rightHeight : leftHeight;
    }

    string toString( Node * h ) const {
        if ( ! h ) return "";
        string rv = toString( h->left );
        rv += h->toString();
        rv += toString( h->right );
        return rv;
    }

    Node * get( Node * h, const Key& key ) const {
        if ( ! h ) return NULL;
        if ( key < h->key ) {
            return get( h->left, key );
        } else if ( key > h->key ) {
            return get( h->right, key );
        } else {
            return h;
        }
    }

    Node * min( Node * h ) const {
        if ( ! h ) return NULL;
        if ( ! h->left ) return h;
        return min( h->left );
    }

    Node * max( Node * h ) const {
        if ( ! h ) return NULL;
        if ( ! h->right ) return h;
        return max( h->right );
    }

    int rank( Node * h, const Key& key ) const {
        if ( ! h ) return 0;
        if ( key < h->key ) {
            return rank( h->left, key );
        } else if ( key > h->key ) {
            return rank( h->right, key ) + 1 + size( h->left );
        } else {
            return size( h->left );
        }
    }

    Node * select( Node * h, int k ) const {
        if ( ! h ) return NULL;
        int sz = size( h->left );
        if ( k < sz ) {
            return select( h->left, k );
        } else if ( k > sz ) {
            return select( h->right, k - 1 - sz );
        } else {
            return h;
        }
    }

    Node * floor( Node * h, const Key& key ) const {
        if ( ! h ) return NULL;
        if ( key < h->key ) {
            return floor( h->left, key );
        } else if ( key == h->key ) {
            return h;
        }

        Node * temp = floor( h->right, key );
        if ( temp ) {
            return temp;
        }
        return h;
    }

    Node * ceiling( Node * h, const Key& key ) const {
        if ( ! h ) return NULL;
        if ( key > h->key ) {
            return ceiling( h->right, key );
        } else if ( key == h->key ) {
            return h;
        }

        Node * temp = ceiling( h->left, key );
        if ( temp ) {
            return temp;
        }
        return h;
    }

    Node * deleteMin( Node * h ) {
        if ( ! h ) return NULL;
        if ( ! h->left ) {
            freeNode( h );
            return NULL;
        }
        if ( ! isRed( h->left ) && ! isRed( h->left->left ) ) {
            h = moveRedLeft( h );
        }
        h->left = deleteMin( h->left );
        return balance( h );
    }

    Node * deleteMax( Node * h ) {
        if ( ! h ) return NULL;

        if ( isRed( h->left ) ) {
            h = rotateRight( h );
        }

        if ( ! h->right ) {
            freeNode( h );
            return NULL;
        }
        if ( ! isRed( h->right ) && ! isRed( h->right->left ) ) {
            h = moveRedRight( h );
        }
        h->right = deleteMax( h->right );
        return balance( h );
    }

    Node * deleteKey( Node * h, const Key& key ) {
        if ( ! h ) return NULL;
        if ( key < h->key ) {
            if ( ! h->left ) return NULL;

            if ( ! isRed( h->left ) && ! isRed( h->left->left ) ) {
                h = moveRedLeft( h );
            }

            h->left = deleteKey( h->left, key );
        } else {
            if ( isRed( h->left ) ) {
                h = rotateRight( h );
            }

            if ( key == h->key && ! h->right ) {
                freeNode( h );
                return NULL;
            }

            if ( ! isRed( h->right ) && ! isRed( h->right->left ) ) {
                h = moveRedRight( h );
            }

            if ( key == h->key ) {
                Node * temp = h;
                cout << "DEBUG: TEMP: " << temp->toString() << endl;
                h = min( temp->right );
                h->right = deleteMin( temp->right );
                h->left = temp->left;
                freeNode( temp );
            } else {
                h->right = deleteKey( h->right, key );
            }
        }
        return balance( h );
    }

    void getKeys( Node * h, queue< Key >& q, const Key& low, const Key& high ) const {
        if ( ! h ) return;
        if ( h->key < low ) return;
        if ( h->key > high ) return;
        getKeys( h->left, q, low, high );
        q.push( h->key );
        getKeys( h->right, q, low, high );
    }

public:

    vector< unique_ptr< Node > > nodesVec;

    RedBlackBST() {
        // not implemented
    }

    virtual ~RedBlackBST() {
        // not implemented
    }
    
    void printNodeVec() const {
        for ( const unique_ptr< Node >& ptr : nodesVec ) {
            cout << ptr->toString() << endl;
        }
    }

    void put( Key key, Value value ) {
        root = put( root, key, value );
        root->color = BLACK;
    }

    int size() const {
        return size( root );
    }

    bool empty() const {
        return size() == 0;
    }

    int height() const {
        return height( root, -1 );
    }

    string toString() const {
        if ( ! root ) return "";
        string rv = "\nROOT : " + root->toString() + "\n";
        rv += toString( root );
        return rv;
    }

    Value get( const Key& key ) const {
        Node * rv = get( root, key );
        if ( rv ) {
            return rv->value;
        } else {
            throw runtime_error( "Key not found" );
        }
    }

    bool contains( const Key& key ) const {
        return get( root, key ) != NULL;
    }

    Key min() const {
        Node * rv = min( root );
        if ( rv ) {
            return rv->key;
        } else {
            throw runtime_error( "Min not found" );
        }
    }

    Key max() const {
        Node * rv = max( root );
        if ( rv ) {
            return rv->key;
        } else {
            throw runtime_error( "Max not found" );
        }
    }

    int rank( const Key& key ) const {
        return rank( root, key );
    }

    Key select( int k ) const {
        Node * rv = select( root, k );
        if ( rv ) {
            return rv->key;
        } else {
            throw runtime_error( "Cannot select a satisfying key" );
        }
    }

    Key floor( const Key& key ) const {
        Node * rv = floor( root, key );
        if ( rv ) {
            return rv->key;
        } else {
            throw runtime_error( "Cannot find floor for key" );
        }
    }

    Key ceiling( const Key& key ) const {
        Node * rv = ceiling( root, key );
        if ( rv ) {
            return rv->key;
        } else {
            throw runtime_error( "Cannot find ceiling for key" );
        }
    }

    void deleteMin() {
        if ( ! root ) return;
        if ( ! isRed( root->left ) && ! isRed( root->right ) ) {
            root->color = RED;
        }
        root = deleteMin( root );
        if ( ! empty() ) root->color = BLACK;
    }

    void deleteMax() {
        if ( ! root ) return;
        if ( ! isRed( root->left ) && ! isRed( root->right ) ) {
            root->color = RED;
        }
        root = deleteMax( root );
        if ( ! empty() ) root->color = BLACK;
    }

    void deleteKey( const Key& key ) {
        if ( ! root ) return;
        if ( ! isRed( root->left ) && ! isRed( root->right ) ) {
            root->color = RED;
        }
        root = deleteKey( root, key );
        if ( ! empty() ) root->color = BLACK;
    }

    queue< Key > getKeys() const {
        return getKeys( min(), max() );
    }

    queue< Key > getKeys( const Key& low, const Key& high ) const {
        queue< Key > q;
        if ( low > high) return q;
        getKeys( root, q, low, high );
        return q;
    }

};

template< typename Key, typename Value >
const bool RedBlackBST< Key, Value >::RED;

template< typename Key, typename Value >
const bool RedBlackBST< Key, Value >::BLACK;

int main( int argc, char ** argv ) {

    string keyArr[] = { "S", "E", "A", "R", "C", "H", "X", "M", "P", "L", "L", "L", "L" };
    string valueArr[] = { "S", "E", "A", "R", "C", "H", "X", "M", "P", "L", "L", "L", "L" };

    RedBlackBST< string, string > bst;
    for ( int i = 0; i < sizeof( keyArr ) / sizeof( string ); ++i ) {
        bst.put( keyArr[ i ], valueArr[ i ] );
    }

    cout << "DEBUG: bst: " << endl;
    cout << bst.toString() << endl;

    cout << "DEUBG: bst.size(): ";
    cout << bst.size() << endl;

    cout << "DEBUG: bst.height(): ";
    cout << bst.height() << endl;

    cout << "DEBUG: bst.min(): ";
    cout << bst.min() << endl;

    cout << "DEBUG: bst.max(): ";
    cout << bst.max() << endl;

    cout << "DEBUG: bst.get( L ): ";
    cout << bst.get( "L" ) << endl;

    cout << "DEBUG: bst.floor( C ): ";
    cout << bst.floor( "C" ) << endl;

    cout << "DEBUG: bst.ceiling( C ): ";
    cout << bst.ceiling( "C" ) << endl;

    cout << "DEBUG: bst.getKeys(): ";
    queue< string > q = bst.getKeys();
    while ( ! q.empty() ) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    bst.deleteMin();
    cout << "DEBUG: bst.getKeys() (AFTER deleteMin()): ";
    q = bst.getKeys();
    while ( ! q.empty() ) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    bst.deleteMax();
    cout << "DEBUG: bst.getKeys() (AFTER deleteMax()): ";
    q = bst.getKeys();
    while ( ! q.empty() ) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    cout << "DEBUG: bst.floor( C ): " << bst.floor( "C" ) << endl;
    cout << "DEBUG: bst.floor( D ): " << bst.floor( "D" ) << endl;

    cout << "DEBUG: bst.contains( C ): " << bst.contains( "C" ) << endl;
    cout << "DEBUG: bst.contains( D ): " << bst.contains( "D" ) << endl;

    bst.deleteKey( "L" );
    cout << "DEBUG: bst.delete( L ): " << bst.toString() << endl;

    cout << "DEBUG: bst.rank( S ): " << bst.rank( "S" ) << endl;
    cout << "DEBUG: bst.select( 5 ): " << bst.select( 5 ) << endl;
    cout << "DEBUG: bst.nodesVec.size(): " << bst.nodesVec.size() << endl;
    cout << "DEBUG: bst.printNodeVec(): " << endl;
    bst.printNodeVec();

    return 0;
}
