//
// Created by Phong Cao on 2019-02-15.
//

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iterator>
#include <functional>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::ostringstream;
using std::sqrt;
using std::pow;
using std::rand;
using std::srand;
using std::time;
using std::endl;
using std::hash;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;
using std::vector;           // Unordered Array
using std::map;              // Ordered Map (Red-Black Tree)
using std::unordered_map;    // HashMap (SeparateChainingHashST)
using std::set;              // Ordered Set (Red-Black Tree)
using std::unordered_set;    // HashSet (SeparateChainingHashST)
using std::pair;
using std::list;             // Doubly-Linked List with size() ( O( 1 ) )
using std::forward_list;     // Singly-Linked List without size() function ( so O( N ) if we need to get size() )
using std::deque;            // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque
using std::queue;            // Non-Iterable & Use std::deque as underlying data structure
using std::stack;            // Non-Iterable & Use std::deque as underlying data structure
using std::next;             // Return an advanced iter without changing original iter
using std::fill;
using std::max;
using std::min;
using std::find;
using std::make_shared;
using std::shared_ptr;
using std::make_unique;
using std::unique_ptr;

template< typename Key, typename Value >
class SeparateChainingHashST {
private:

    class Node {
    public:
        Key key;
        Value value;
        Node * next = NULL;

        Node( const Key& key, const Value& value )
            : key( key ),
              value( value )
        {
            // not implemented
        }

        virtual ~Node() {
            // not implemented
        }

        friend ostream& operator <<( ostream& out, const Node& h ) {
            out << " | key : " << h.key << " ; value : " << h.value;
            if ( h.next ) {
                out << " ; next : " << h.next->key;
            } else {
                out << " ; next : null";
            }
            out << " | ";
            return out;
        }

        string toString() const {
            ostringstream oss;
            oss << *this;
            return oss.str();
        }
    };

    int hash( const Key& key ) {
        return std::hash< Key >{}( key ) % M;
    }

    int M = 17;
    int N = 0;
    vector< Node * > st;
    vector< unique_ptr< Node > > nodeVec;

public:

    SeparateChainingHashST( int M )
        : M( M )
    {
        st.resize( M );
    }

    SeparateChainingHashST()
        : SeparateChainingHashST( 17 )
    {
        // not implemented
    }

    virtual ~SeparateChainingHashST() {
        // not implemented
    }

    int size() const {
        return N;
    }

    void put( const Key& key, const Value& value ) {
        Node * ptr = st[ hash( key ) ];
        if ( ptr ) {
            if ( ptr->key == key ) {
                ptr->value = value;
                return;
            }

            while ( ptr->next ) {
                if ( ptr->key == key ) {
                    ptr->value = value;
                    return;
                }

                ptr = ptr->next;
            }
            nodeVec.push_back( make_unique< Node >( key, value ) );
            ptr->next = nodeVec.back().get();
        } else {
            nodeVec.push_back( make_unique< Node >( key, value ) );
            st[ hash( key ) ] = nodeVec.back().get();
        }
        ++N;
    }

    void deleteKey( const Key& key ) {
        Node * ptr = st[ hash( key ) ];
        Node * beforePtr = NULL;
        while ( ptr ) {
            if ( key == ptr->key ) {
                if ( beforePtr ) {
                    beforePtr->next = ptr->next;
                } else {
                    st[ hash( key ) ] = NULL;
                }
                --N;
            }
            beforePtr = ptr;
            ptr = ptr->next;
        }
    }

    string toString() const {
        string rv = "\n";
        for ( int i = 0; i < M; ++i ) {
            Node * ptr = st[ i ];
            while ( ptr ) {
                rv += "\n| i : " + to_string( i ) + ptr->toString();
                ptr = ptr->next;
            }
        }
        return rv;
    }

    Value get( const Key& key ) const {
        Node * rv = st[ hash( key ) ];
        if ( rv ) {
            return rv->value;
        } else {
            Value val;
            return val;
        }
    }

    bool contains( const Key& key ) const {
        return get( key ) != NULL;
    }

    queue< Key > getKeys() {
        queue< Key > q;
        for ( int i = 0; i < M; ++i ) {
            Node * ptr = st[ i ];
            while ( ptr ) {
                q.push( ptr->key );
                ptr = ptr->next;
            }
        }
        return q;
    }
};

int main( int argc, char ** argv ) {
    string keyArr[] = { "E", "A", "S", "Y", "Q", "U", "T", "I", "O", "N" };
    string valueArr[] = { "E", "A", "S", "Y", "Q", "U", "T", "I", "O", "N" };
    SeparateChainingHashST< string, string > hashST( 17 );

    for ( int i = 0; i < sizeof( keyArr ) / sizeof( string ); ++i ) {
        hashST.put( keyArr[ i ], valueArr[ i ] );
    }

    cout << hashST.toString() << endl;

    queue< string > keysQueue = hashST.getKeys();
    while ( ! keysQueue.empty() ) {
        cout << keysQueue.front() << " ";
        keysQueue.pop();
    }

    return 0;
}
