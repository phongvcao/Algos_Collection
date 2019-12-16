//
// Created by Phong Cao on 2019-02-19.
//

#include <iostream>
#include <sstream>
#include <fstream>
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
using std::istringstream;
using std::ofstream;
using std::ifstream;
using std::getline;
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

class Vertex {
public:
    int x = 0;
    int y = 0;
    int id = -1;

    Vertex() {
        // not implemented
    }

    Vertex( int id, int x, int y )
            : x( x ),
              y( y ),
              id( id )
    {
        // not implemented
    }

    Vertex( const Vertex& other ) {
        this->x = other.x;
        this->y = other.y;
        this->id = other.id;
    }

    virtual ~Vertex() {
        // not implemented
    }

    friend bool operator ==( const Vertex& v1, const Vertex& v2 ) {
        return ( v1.x == v2.x && v1.y == v2.y );
    }

    friend bool operator !=( const Vertex& v1, const Vertex& v2 ) {
        return ! ( v1 == v2 );
    }

    string toString() const {
        return "| id : " + to_string( id ) + " ; x : " + to_string( x ) + " ; y : " + to_string( y ) + " | ";
    }
};

namespace std {
    template<>
    struct hash< Vertex > {
        size_t operator ()( const Vertex& v1 ) const {
            int hash = 17;
            hash = 31 * hash + std::hash< int >{}( v1.id );
            hash = 31 * hash + std::hash< int >{}( v1.x );
            hash = 31 * hash + std::hash< int >{}( v1.y );
            return hash;
        }
    };
}

template< typename Key, typename Value >
class SeparateChainingHashST {
private:

    class Node {
    public:
        Key key;
        Value value;
        Node * next = NULL;

        Node( Key key, Value value )
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

    int hash( const Key& key ) const {
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

    void put( Key key, Value value ) {
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
        if ( ! contains( key ) ) return;
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

    Value* get( const Key& key ) const {
        Node * ptr = st[ hash( key ) ];
        while ( ptr ) {
            if ( ptr->key == key ) {
                return &( ptr->value );
            }
            ptr = ptr->next;
        }
        return NULL;
    }

    bool contains( const Key& key ) const {
        return get( key ) != NULL;
    }

    int size() const {
        return N;
    }

    queue< Key > getKeys() const {
        queue< Key > q;
        for ( int i = 0; i < M; ++i ) {
            Node * ptr = st[ i ];
            while ( ptr ) {
//                cout << "DEBUG: PUSHING KEY: " << ptr->key << endl;
                q.push( ptr->key );
                ptr = ptr->next;
            }
        }
        return q;
    }
};

class EuclideanGraph {
private:

    int V = 0;
    int E = 0;
    int count = 0;
    SeparateChainingHashST< Vertex, forward_list< Vertex > > adj;

public:

    EuclideanGraph( int V )
            : V( V ),
              adj( V )
    {
        // not implemented
    }

    virtual ~EuclideanGraph() {
        // not implemented
    }

    int getV() const {
        return V;
    }

    int getE() const {
        return E;
    }

    forward_list< Vertex > getAdj( Vertex v ) const {
        return *( adj.get( v ) );
    }

    void addEdge( int x1, int y1, int x2, int y2 ) {
        Vertex v1( -1, x1, y1 );
        Vertex v2( -1, x2, y2 );
        this->addEdge( v1, v2 );
    }

    queue< Vertex > getKeys() const {
        return adj.getKeys();
    }

    void addEdge( Vertex v1, Vertex v2 ) {
        if ( ! adj.contains( v1 ) ) {
            if ( v1.id == -1 ) {
                v1.id = count++;
            }
            forward_list< Vertex > list;
            list.push_front( v2 );
            adj.put( v1, list );
        } else {
            adj.get( v1 )->push_front( v2 );
        }

        if ( ! adj.contains( v2 ) ) {
            if ( v2.id == -1 ) {
                v2.id = count++;
            }
            forward_list< Vertex > list;
            list.push_front( v1 );
            adj.put( v2, list );
        } else {
            adj.get( v2 )->push_front( v1 );
        }
        ++E;
    }

    string toString() const {
        string rv = "\n";
        queue< Vertex > q = adj.getKeys();
        while ( ! q.empty() ) {
            rv += "\n| v : " + q.front().toString() + " : ";
            forward_list< Vertex >* list = adj.get( q.front() );
            for ( Vertex w : *list ) {
                rv += w.toString() + ", ";
            }
            q.pop();
        }
        return rv;
    }

    static int degree( const EuclideanGraph& G, const Vertex& v ) {
        int deg = 0;
        for ( Vertex w : G.getAdj( v ) ) {
            ++deg;
        }
        return deg;
    }

    static int maxDegree( const EuclideanGraph& G ) {
        int maxDeg = 0;
        queue< Vertex > q = G.getKeys();
        while ( ! q.empty() ) {
            int deg = degree( G, q.front() );
            if ( maxDeg < deg ) {
                maxDeg = deg;
            }
            q.pop();
        }
        return maxDeg;
    }

    static int avgDegree( const EuclideanGraph& G ) {
        return 2 * G.getE() / G.getV();
    }

    static int numSelfLoops( const EuclideanGraph& G ) {
        int count = 0;
        queue< Vertex > q = G.getKeys();
        while ( ! q.empty() ) {
            for ( Vertex w : G.getAdj( q.front() ) ) {
                if ( w == q.front() ) {
                    ++count;
                }
            }
            q.pop();
        }
        return count / 2;
    }

};

int main( int argc, char ** argv ) {

    int graphArr[ 16 ][ 2 ] = {
            { 0, 5 },
            { 4, 3 },
            { 0, 1 },
            { 9, 12 },
            { 6, 4 },
            { 5, 4 },
            { 0, 2 },
            { 11, 12 },
            { 9, 10 },
            { 0, 6 },
            { 7, 8 },
            { 9, 11 },
            { 5, 3 },
            { 6, 7 },
            { 7, 9 },
            { 8, 9 }
    };

    EuclideanGraph graph( 13 );
    for ( int i = 0; i < 16; ++i ) {
        Vertex v1( graphArr[ i ][ 0 ], graphArr[ i ][ 0 ], graphArr[ i ][ 0 ] );
        Vertex v2( graphArr[ i ][ 1 ], graphArr[ i ][ 1 ], graphArr[ i ][ 1 ] );
        graph.addEdge( v1, v2 );
    }
    cout << "DEBUG: graph: \n" << graph.toString() << endl;

    return 0;
}
