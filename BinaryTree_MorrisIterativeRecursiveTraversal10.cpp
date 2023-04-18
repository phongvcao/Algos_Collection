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

enum TraversalType {
    TRAVERSAL_TYPE_RECURSIVE = 0,
    TRAVERSAL_TYPE_ITERATIVE = 1,
    TRAVERSAL_TYPE_MORRIS = 2,
};

template< typename Value >
class BinaryTree {
private:

    class Node {
    public:
        Value value;
        Node * left = NULL;
        Node * right = NULL;
        int index = -1;

        Node( Value value )
            : value( value )
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

        friend ostream& operator <<( ostream& out, const Node&  h ) {
            out << " | " << h.value;
            if ( h.left ) {
                out << " ; left : " << h.left->value;
            } else {
                out << " ; left : null";
            }

            if ( h.right ) {
                out << " ; right : "  << h.right->value;
            } else {
                out << " ; right : null";
            }

            out << " | \n";
            return out;
        }
    };

    Node * newNode( Value value )  {
        nodesVec.push_back( make_unique< Node >( value ) );
        nodesVec.back()->index = nodesVec.size() - 1;
        return nodesVec.back().get();
    }

    void freeNode( Node * h ) {
        if ( ! h ) return;

        if ( h->index < nodesVec.size() - 1 ) {
            nodesVec[ h->index ].swap( nodesVec.back() );
            nodesVec[ h->index ]->index = h->index;
        }
        nodesVec.pop_back();
    }

    Node * constructBinaryTreeRecursively( Node * h,
                                           const vector< Value >& valuesVec,
                                           int index ) {
        if ( index >= valuesVec.size() ) return NULL;
        if ( ! h ) h = newNode( valuesVec[ index ] );
        
        h->left = constructBinaryTreeRecursively( h->left, valuesVec, index * 2 + 1 );
        h->right = constructBinaryTreeRecursively( h->right, valuesVec, index * 2 + 2 );
        return h;
    }

    void constructBinaryTreeIteratively( const vector< Value >& valuesVec ) {
        if ( valuesVec.empty() ) return;

        queue< Node * > nodesQueue;
        int index = 0;
        root = newNode( valuesVec[ index ] );
        nodesQueue.push( root );

        while ( ! nodesQueue.empty() ) {
            Node * node = nodesQueue.front();
            nodesQueue.pop();

            if ( index * 2 + 1 < valuesVec.size() ) {
                node->left = newNode( valuesVec[ index * 2 + 1 ] );
                nodesQueue.push( node->left );
            }

            if ( index * 2 + 2 < valuesVec.size() ) {
                node->right = newNode( valuesVec[ index * 2 + 2 ] );
                nodesQueue.push( node->right );
            }

            ++index;
        }
    }

    int heightRecursively( Node * h ) const {
        if ( ! h ) return -1;
        return max( heightRecursively( h->left ),
                    heightRecursively( h->right ) ) + 1;
    }

    int heightIteratively() const {
        if ( ! root ) return 0;

        queue< pair< Node *, int > > nodesQueue;
        nodesQueue.push( { root, 0 } );
        int height = 0;

        while ( ! nodesQueue.empty() ) {
            auto [ node, nodeHeight ] = nodesQueue.front();
            nodesQueue.pop();

            height = max( height, nodeHeight );

            if ( node->left ) {
                nodesQueue.push( { node->left, nodeHeight + 1 } );
            }

            if ( node->right ) {
                nodesQueue.push( { node->right, nodeHeight + 1 } );
            }
        }
        return height;
    }

    bool containsRecursively( Node * h, const Value& value ) const {
        if ( ! h ) return false;
        if ( h->value == value ) return true;
        return containsRecursively( h->left, value ) ||
            containsRecursively( h->right, value );
    }

    bool containsIteratively( const Value& value ) const {
        if ( ! root ) return false;

        stack< Node * > dfsStack;
        Node * node = root;

        while ( ! dfsStack.empty() || node ) {
            if ( node ) {
                if ( node->value == value ) return true;
                dfsStack.push( node );
                node = node->left;
            } else {
                node = dfsStack.top();
                dfsStack.pop();
                node = node->right;
            }
        }
        return false;
    }

    void preOrderTraversalRecursively( Node * h, vector< Value >& output ) {
        if ( ! h ) return;

        output.push_back( h->value );
        preOrderTraversalRecursively( h->left, output );
        preOrderTraversalRecursively( h->right, output );
    }

    void preOrderTraversalIteratively( vector< Value >& output ) {
        if ( ! root ) return;

        stack< Node * > dfsStack;
        Node * node = root;

        while ( ! dfsStack.empty() || node ) {
            if ( node ) {
                output.push_back( node->value );
                dfsStack.push( node );
                node = node->left;
            } else {
                node = dfsStack.top();
                dfsStack.pop();
                node = node->right;
            }
        }
    }

    void preOrderTraversalMorris( vector< Value >& output ) {
        if ( ! root ) return;

        Node * node = root;
        Node * pred = NULL;

        while ( node != NULL) {
            if ( node->left != NULL ) {
                pred = node->left;
                while ( pred->right && pred->right != node ) {
                    pred = pred->right;
                }
                if ( ! pred->right ) {
                    output.push_back( node->value );
                    pred->right = node;
                    node = node->left;
                } else {
                    pred->right = NULL;
                    node = node->right;
                }
            } else {
                output.push_back( node->value );
                node = node->right;
            }
        }
    }

    void inOrderTraversalRecursively( Node * h, vector< Value >& output ) {
        if ( ! h ) return;

        inOrderTraversalRecursively( h->left, output );
        output.push_back( h->value );
        inOrderTraversalRecursively( h->right, output );
    }
    
    void inOrderTraversalIteratively( vector< Value >& output ) {
        if ( ! root ) return;

        stack< Node * > dfsStack;
        Node * node = root;

        while ( ! dfsStack.empty() || node ) {
            if ( node ) {
                dfsStack.push( node );
                node = node->left;
            } else {
                node = dfsStack.top();
                dfsStack.pop();
                output.push_back( node->value );
                node = node->right;
            }
        }
    }

    void inOrderTraversalMorris( vector< Value >& output ) {
        if ( ! root ) return;

        Node * node = root;
        Node * pred = NULL;

        while ( node ) {
            if ( node->left ) {
                pred = node->left;
                while ( pred->right && pred->right != node ) {
                    pred = pred->right;
                }
                if ( ! pred->right ) {
                    pred->right = node;
                    node = node->left;
                } else {
                    output.push_back( node->value );
                    pred->right = NULL;
                    node = node->right;
                }
            } else {
                output.push_back( node->value );
                node = node->right;
            }
        }
    }

    void postOrderTraversalRecursively( Node * h, vector< Value >& output ) {
        if ( ! h ) return;

        postOrderTraversalRecursively( h->left, output );
        output.push_back( h->value );
        postOrderTraversalRecursively( h->right, output );
    }

    void postOrderTraversalIteratively( vector< Value >& output ) {
        if ( ! root ) return;

        stack< Node * > dfsStack;
        Node * node = root;
        Node * prev = NULL;

        while ( ! dfsStack.empty() || node ) {
            if ( node ) {
                dfsStack.push( node );
                node = node->left;
            } else {
                node = dfsStack.top();

                if ( ! node->right || node->right == prev ) {
                    dfsStack.pop();
                    output.push_back( node->value );
                    prev = node;
                    node = NULL;
                } else {
                    node = node->right;
                }
            }
        }
    }
    
    void postOrderTraversalMorris( vector< Value >& output ) {
        if ( ! root ) return;

        Node * node = root;
        Node * dummy = newNode( -1 );
        Node * pred = NULL;

        dummy->left = node;
        node = dummy;

        while ( node ) {
            if ( node->left ) {
                pred = node->left;
                while ( pred->right && pred->right != node ) {
                    pred = pred->right;     
                }

                if ( ! pred->right ) {
                    pred->right = node;
                    node = node->left;
                } else {
                    Node * temp = pred;
                    reverse( node->left, pred );
                    while ( temp != node->left ) {
                        output.push_back( temp->value );
                        temp = temp->right;
                    }
                    output.push_back( temp->value );
                    reverse( pred, node->left );
                    pred->right = NULL;
                    node = node->right;
                }
            } else {
                node = node->right;
            }
        }
    }

    Node * lowestCommonAncestorRecursively( Node * h,
                                            const Value& value1,
                                            const Value& value2 ) const {
        if ( ! h ) return nullptr;

        if ( h->value == value1 || h->value == value2 ) {
            return h;
        }

        Node * leftLCA = lowestCommonAncestorRecursively( h, value1, value2 );
        Node * rightLCA = lowestCommonAncestorRecursively( h, value1, value2 );

        if ( leftLCA && rightLCA ) return h;

        return leftLCA ? leftLCA : rightLCA;
    }

    Node * getNodeWithValueIteratively( const Value& value ) {
        if ( ! root ) return nullptr;

        stack< Node * > dfsStack;
        Node * node = root;

        while ( ! dfsStack.empty() || node ) {
            if ( node ) {
                if ( node->value == value ) {
                    return node;
                }
                dfsStack.push( node );
                node = node->left;
            } else {
                node = dfsStack.top();
                dfsStack.pop();
                node = node->right;
            }
        }
        return nullptr;
    }

    Node * lowestCommonAncestorIteratively( const Value& value1,
                                            const Value& value2 ) const {
        if ( ! root ) return nullptr;

        Node * node1 = getNodeWithValueIteratively( value1 );
        if ( ! node1 ) return nullptr;

        Node * node2 = getNodeWithValueIteratively( value2 );
        if ( ! node2 ) return nullptr;

        if ( root == node1 || root == node2 ) {
            return root;
        }

        stack< Node * > dfsStack;
        Node * node = root;
        unordered_map< Node *, Node * > parentMap;

        while ( ! parentMap[ node1 ] || ! parentMap[ node2 ] ) {
            if ( node ) {
                dfsStack.push( node );
                if ( node->left ) parentMap[ node->left ] = node;
                node = node->left;
            } else {
                node = dfsStack.top();
                dfsStack.pop();
                if ( node->right ) parentMap[ node->right ] = node;
                node = node->right;
            }
        }

        unordered_set< Node * > ancestor;
        while ( node1 ) {
            ancestor.insert( node1 );
            node1 = parentMap[ node1 ];
        }

        while ( ancestor.find( node2 ) == ancestor.end() ) {
            node2 = parentMap[ node2 ];
        }
        return node2;
    }
    
    string toString( Node * h ) const {
        if ( ! h ) return "";
        string rv = toString( h->left );
        rv += h->toString();
        rv += toString( h->right );
        return rv;
    }

    Node * root = NULL;
    vector< unique_ptr< Node > > nodesVec;

public:

    BinaryTree( const vector< Value >& valuesVec,
                const TraversalType& traversalType ) {
        switch ( traversalType ) {
            case TRAVERSAL_TYPE_RECURSIVE:
                root = constructBinaryTreeRecursively( root, valuesVec, 0 );
                break;
            case TRAVERSAL_TYPE_ITERATIVE:
                constructBinaryTreeIteratively( valuesVec );
                break;
            case TRAVERSAL_TYPE_MORRIS:
                constructBinaryTreeIteratively( valuesVec );
                break;
        }
    }

    virtual ~BinaryTree() {
        // not implemented
    }

    int size() const {
        return nodesVec.size();
    }

    int height( const TraversalType& traversalType ) const {
        switch ( traversalType ) {
            case TRAVERSAL_TYPE_RECURSIVE:
                return heightRecursively( root );
            case TRAVERSAL_TYPE_ITERATIVE:
                return heightIteratively();
            case TRAVERSAL_TYPE_MORRIS:
                return heightIteratively();
        }
        return 0;
    }

    bool contains( const Value& value,
                   const TraversalType& traversalType ) const {
        switch ( traversalType ) {
            case TRAVERSAL_TYPE_RECURSIVE:
                return containsRecursively( root, value );
            case TRAVERSAL_TYPE_ITERATIVE:
                return containsIteratively( value );
            case TRAVERSAL_TYPE_MORRIS:
                return containsIteratively( value );
        }
        return false;
    }

    Value lowestCommonAncestor( const Value& value1, const Value& value2,
                                const TraversalType& traversalType ) const {
        switch ( traversalType ) {
            case TRAVERSAL_TYPE_RECURSIVE:
                return lowestCommonAncestorRecursively( root, value1, value2);
            case TRAVERSAL_TYPE_ITERATIVE:
                return lowestCommonAncestorIteratively( value1, value2 );
            case TRAVERSAL_TYPE_MORRIS:
                return lowestCommonAncestorIteratively( value1, value2 );
        }
    }

    vector< Value > preOrderTraversal( const TraversalType& traversalType ) {
        vector< Value > output;
        switch ( traversalType ) {
            case TRAVERSAL_TYPE_RECURSIVE:
                preOrderTraversalRecursively( root, output );
                break;
            case TRAVERSAL_TYPE_ITERATIVE:
                preOrderTraversalIteratively( output );
                break;
            case TRAVERSAL_TYPE_MORRIS:
                preOrderTraversalMorris( output );
                break;
        }
        return output;
    }

    vector< Value > inOrderTraversal( const TraversalType& traversalType ) {
        vector< Value > output;
        switch ( traversalType ) {
            case TRAVERSAL_TYPE_RECURSIVE:
                inOrderTraversalRecursively( root, output );
                break;
            case TRAVERSAL_TYPE_ITERATIVE:
                inOrderTraversalIteratively( output );
                break;
            case TRAVERSAL_TYPE_MORRIS:
                inOrderTraversalMorris( output );
                break;
        }
        return output;
    }

    vector< Value > postOrderTraversal( const TraversalType& traversalType ) {
        vector< Value > output;
        switch ( traversalType ) {
            case TRAVERSAL_TYPE_RECURSIVE:
                postOrderTraversalRecursively( root, output );
                break;
            case TRAVERSAL_TYPE_ITERATIVE:
                postOrderTraversalIteratively( output );
                break;
            case TRAVERSAL_TYPE_MORRIS:
                postOrderTraversalMorris( output );
                break;
        }
        return output;
    }

    string toString() const {
        if ( ! root ) return "";
        string rv = "\nROOT : " + root->toString() + "\n";
        rv += toString( root );
        return rv;
    }
};

int main( int argc, char ** argv ) {

    vector< int > valuesVec = { 14, 12, 10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9 };

    BinaryTree< int > btRecursively( valuesVec, TRAVERSAL_TYPE_RECURSIVE );

    cout << "DEBUG: btRecursively: " << endl;
    cout << btRecursively.toString() << endl;

    cout << "DEBUG: btRecursively.size(): " << endl;
    cout << btRecursively.size() << endl;

    cout << "DEBUG: btRecursively.height(): " << endl;
    cout << btRecursively.height( TRAVERSAL_TYPE_RECURSIVE ) << endl;

    for ( int i = 0; i < valuesVec.size(); i++ ) {
        cout << "DEBUG: btRecursively.contains( " << valuesVec[ i ] << " ): " << endl;
        cout << btRecursively.contains( 9, TRAVERSAL_TYPE_RECURSIVE ) << endl;
    }

    cout << "DEBUG: btRecursively.contains( " << 100 << " ): " << endl;
    cout << btRecursively.contains( 100, TRAVERSAL_TYPE_RECURSIVE ) << endl;

    cout << "DEBUG: btRecursively.preOrderTraversal(): " << endl;
    vector< int > outputVec = btRecursively.preOrderTraversal( TRAVERSAL_TYPE_RECURSIVE );
    for (const int& value : outputVec ) {
        cout << " | " << value;
    }
    cout << " | " << endl;

    cout << "DEBUG: btRecursively.inOrderTraversal(): " << endl;
    outputVec = btRecursively.inOrderTraversal( TRAVERSAL_TYPE_RECURSIVE );
    for (const int& value : outputVec ) {
        cout << " | " << value;
    }
    cout << " | " << endl;

    cout << "DEBUG: btRecursively.postOrderTraversal(): " << endl;
    outputVec = btRecursively.postOrderTraversal( TRAVERSAL_TYPE_RECURSIVE );
    for (const int& value : outputVec ) {
        cout << " | " << value;
    }
    cout << " | " << endl;

    BinaryTree< int > btIteratively( valuesVec, TRAVERSAL_TYPE_ITERATIVE );

    cout << "DEBUG: btIteratively: " << endl;
    cout << btIteratively.toString() << endl;

    cout << "DEBUG: btIteratively.size(): " << endl;
    cout << btIteratively.size() << endl;

    cout << "DEBUG: btIteratively.height(): " << endl;
    cout << btIteratively.height( TRAVERSAL_TYPE_ITERATIVE ) << endl;

    for ( int i = 0; i < valuesVec.size(); i++ ) {
        cout << "DEBUG: btIteratively.contains( " << valuesVec[ i ] << " ): " << endl;
        cout << btRecursively.contains( 9, TRAVERSAL_TYPE_ITERATIVE ) << endl;
    }

    cout << "DEBUG: btIteratively.contains( " << 100 << " ): " << endl;
    cout << btIteratively.contains( 100, TRAVERSAL_TYPE_ITERATIVE ) << endl;

    cout << "DEBUG: btIteratively.preOrderTraversal(): " << endl;
    outputVec = btRecursively.preOrderTraversal( TRAVERSAL_TYPE_ITERATIVE );
    for (const int& value : outputVec ) {
        cout << " | " << value;
    }
    cout << " | " << endl;

    cout << "DEBUG: btIteratively.inOrderTraversal(): " << endl;
    outputVec = btIteratively.inOrderTraversal( TRAVERSAL_TYPE_ITERATIVE );
    for (const int& value : outputVec ) {
        cout << " | " << value;
    }
    cout << " | " << endl;

    cout << "DEBUG: btIteratively.postOrderTraversal(): " << endl;
    outputVec = btRecursively.postOrderTraversal( TRAVERSAL_TYPE_ITERATIVE );
    for (const int& value : outputVec ) {
        cout << " | " << value;
    }
    cout << " | " << endl;
    
    BinaryTree< int > btMorris( valuesVec, TRAVERSAL_TYPE_MORRIS );

    cout << "DEBUG: btMorris: " << endl;
    cout << btMorris.toString() << endl;

    cout << "DEBUG: btMorris.size(): " << endl;
    cout << btMorris.size() << endl;

    cout << "DEBUG: btMorris.height(): " << endl;
    cout << btMorris.height( TRAVERSAL_TYPE_MORRIS ) << endl;

    for ( int i = 0; i < valuesVec.size(); i++ ) {
        cout << "DEBUG: btMorris.contains( " << valuesVec[ i ] << " ): " << endl;
        cout << btMorris.contains( 9, TRAVERSAL_TYPE_MORRIS ) << endl;
    }

    cout << "DEBUG: btMorris.contains( " << 100 << " ): " << endl;
    cout << btMorris.contains( 100, TRAVERSAL_TYPE_MORRIS ) << endl;
    
    cout << "DEBUG: btMorris.preOrderTraversal(): " << endl;
    outputVec = btMorris.preOrderTraversal( TRAVERSAL_TYPE_MORRIS );
    for (const int& value : outputVec ) {
        cout << " | " << value;
    }
    cout << " | " << endl;

    cout << "DEBUG: btMorris.inOrderTraversal(): " << endl;
    outputVec = btMorris.inOrderTraversal( TRAVERSAL_TYPE_MORRIS );
    for (const int& value : outputVec ) {
        cout << " | " << value;
    }
    cout << " | " << endl;

    cout << "DEBUG: btMorris.postOrderTraversal(): " << endl;
    outputVec = btMorris.postOrderTraversal( TRAVERSAL_TYPE_MORRIS );
    for (const int& value : outputVec ) {
        cout << " | " << value;
    }
    cout << " | " << endl;

    return 0;
}
