//
// Created by Phong Cao on 2019-03-02.
//


// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <iostream>
#include <iomanip>
#include <ios>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
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

//----<iostream>------------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----<iomanip>-------------//
using std::setprecision;
using std::setw;

//----<ios>-----------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----<sstream>-------------//
using std::ostringstream;
using std::istringstream;

//----<fstream>-------------//
using std::ofstream;
using std::ifstream;

//----<string>--------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;

//----<cmath>---------------//
using std::sqrt;
using std::pow;

//----<cstdlib>-------------//
using std::rand;
using std::srand;

//----<ctime>---------------//
using std::time;

//----<functional>----------//
using std::hash;
using std::greater;
using std::less;
using std::less_equal;
using std::greater_equal;

//----<vector>--------------//
using std::vector;          // Unordered Array

//----<map>-----------------//
using std::map;             // Ordered Map (Red-Black Tree)

//----<unordered_map>-------//
using std::unordered_map;   // HashMap (SeparateChainingHashST)

//----<set>-----------------//
using std::set;             // Ordered Set (Red-Black Tree)

//----<unordered_set>-------//
using std::unordered_set;   // HashSet (SeparateChainingHashST)

//----<list>----------------//
using std::list;            // Doubly-Linked List with size() ( O( 1 ) )

//----<forward_list>--------//
using std::forward_list;    // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----<deque>---------------//
using std::deque;           // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----<queue>---------------//
using std::queue;           // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;  // MaxPQ (MaxHeap) & Non-Iterable.
// => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----<stack>---------------//
using std::stack;           // Non-Iterable & Use std::deque as underlying data structure

//----<iterator>------------//
using std::next;            // Return an advanced iter without changing original iter

//----<utility>-------------//
using std::pair;

//----<algorithm>-----------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;

//----<memory>--------------//
using std::make_shared;
using std::shared_ptr;

//----<cctype>--------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;         // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;         // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----<stdexcept>-----------//
using std::invalid_argument;

//--------------------------//

template< typename Key >
class MinPQ {
private:

    vector< Key > pq;
    int N = 0;

    bool greater( int i, int j ) {
        return pq[ i ] > pq[ j ];
    }

    void exchange( int i, int j ) {
        Key temp = pq[ i ];
        pq[ i ] = pq[ j ];
        pq[ j ] = temp;
    }

    void swim( int k ) {
        while ( k > 1 && greater( k / 2, k ) ) {
            exchange( k / 2, k );
            k /= 2;
        }
    }

    void sink( int k ) {
        while ( 2 * k <= N ) {
            int j = 2 * k;
            if ( j < N && greater( j, j + 1 ) ) ++j;
            if ( ! greater( k, j ) ) break;
            exchange( j, k );
            k = j;
        }
    }

public:

    MinPQ( int maxN )
        : pq( maxN + 1 )
    {
        // not implemented
    }

    virtual ~MinPQ() {
        // not implemented
    }

    void push( Key key ) {
        pq[ ++N ] = key;
        swim( N );
    }

    Key pop() {
        Key min = pq[ 1 ];
        exchange( 1, N-- );
        sink( 1 );
        return min;
    }

    Key top() const {
        return pq[ 1 ];
    }

    int size() const {
        return N;
    }

    bool empty() const {
        return size() == 0;
    }

    friend ostream& operator <<( ostream& out, MinPQ< Key > minPQ ) {
        while ( ! minPQ.empty() ) {
            out << minPQ.pop() << ", ";
        }
        return out;
    }
};

int main( int argc, char ** argv ) {

    int intArr[] = { 14, 12, 10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9, 11, 13 };
    MinPQ< int > minPQ( sizeof( intArr ) / sizeof( int ) );

    for ( int i = 0; i < sizeof( intArr ) / sizeof( int ); ++i ) {
        minPQ.push( intArr[ i ] );
    }

    cout << "DEBUG: minPQ.toStringDelMin(): \n" << minPQ << endl;

    return 0;
}
