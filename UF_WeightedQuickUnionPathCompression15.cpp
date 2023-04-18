//
// Created by Phong Cao on 2019-02-14.
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
#include <numeric>

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
using std::iota;

//
// For static graph, use DFS or BFS
// For graph that is changing or dynamic, use Union-Find
//
// Time Complexity : O( V + E ) for detecting number of connected components
// Space Complexity : O( V + E )
//

//
// For static graph, use DFS or BFS
// For graph that is changing or dynamic, use Union-Find
//
// Time Complexity :
//
// Worst-Case : O( log ( V ) ) per doUnion(), find(), connected()
//              O( 1 ) per getCount()
//              O( E * log( V ) ) for doUnion() of E edges
// Amortized : a( N ) ( inverse-Ackermann complexity ) per doUnion(), find(), connected()
//             O( 1 ) per getCount()
//             O( E * a( V ) ) for doUnion() of E edges
// 
// Space Complexity : O( V + E )
//
//

class WeightedQuickUnionPathCompressionUF {

//
// For static graph, use DFS or BFS
// For graph that is changing or dynamic, use Union-Find
//
// ( DFS / BFS ) Time Complexity : O( V + E ) for detecting number of connected components
// ( DFS / BFS ) Space Complexity : O( V + E )
//

private:
    vector< int > parent;
    vector< int > sz;
    int count = 0;

public:

    WeightedQuickUnionPathCompressionUF( int N )
        : count( N ),
          parent( N, 0 ),
          sz( N, 1 )
    {
        iota( parent.begin(), parent.end(), 0 );
    }

    virtual ~WeightedQuickUnionPathCompressionUF() {
        // not implemented
    }

    int getCount() const {
        return count;
    }

    int find( int p ) {
        int root = p;
        while ( root != parent[ root ] ) root = parent[ root ];
        
        // path compression
        // connect all parents ( newP ) of original p directly to root
        // as we're doing find()
        while ( p != root ) {
            int newP = parent[ p ];
            parent[ p ] = root;
            p = newP;
        }
        return root;
    }

    void doUnion( int p, int q ) {
        int i = find( p );
        int j = find( q );

        if ( i == j ) return;

        if ( sz[ i ] < sz[ j ] ) {
            parent[ i ] = j;
            sz[ j ] += sz[ i ];
        } else {
            parent[ j ] = i;
            sz[ i ] += sz[ j ];
        }
        --count;
    }

    string toString() const {
        string rv = "\n";
        for ( int i = 0; i < parent.size(); ++i ) {
            rv += "\n| i : " + to_string( i ) + " : " + to_string( parent[ i ] ) + " ; sz : " + to_string( sz[ i ] ) + " | ";
        }
        return rv;
    }

    bool connected( int p, int q ) {
        return find( p ) == find( q );
    }
};

int main( int argc, char ** argv ) {

    int intArr[] = { 14, 12, 10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9 };

    WeightedQuickUnionPathCompressionUF wqu( sizeof( intArr ) / sizeof( int ) );
    for ( int i = 0; i < sizeof( intArr ) / sizeof( int ) / 2; ++i ) {
        wqu.doUnion( intArr[ i ], intArr[ sizeof( intArr ) / sizeof( int ) - 1 - i ] );
    }

    cout << "DEBUG: wqu: " << wqu.toString() << endl;

    return 0;
}
