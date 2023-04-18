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

// Time Complexities : O( N * log( log( N ) ) )
// Space Complexities : O( sqrt( high ) + n ) where n = high - low + 1

class SegmentedSieve {
private:

    void buildSimpleSieve( int N, vector< int >& results ) const {
        vector< bool > isPrimes( N + 1, true );
        isPrimes[ 0 ] = false;
        isPrimes[ 1 ] = false;

        for ( int i = 2; i * i <= N; i++ ) {
            if ( isPrimes[ i ] ) {
                for ( int j = i * i; j <= N; j += i ) {
                    isPrimes[ j ] = false;
                }
            }
        }

        for ( int i = 2; i <= N; i++ ) {
            if ( isPrimes[ i ] ) {
                results.push_back( i );
            }
        }
    }

    vector< int > primes;
    vector< bool > isComposites;
    int low = 0;
    int high = 0;

public:

    SegmentedSieve( int low, int high )
        : low( low ),
          high( high ),
          isComposites( high - low + 1 + 1, false )
    {
        int limit = floor( sqrt( high ) ) + 1;
        vector< int > initialPrimes;
        buildSimpleSieve( limit, initialPrimes );

        if ( low < 2 ) low = 2;

        for ( int i = 0; i < initialPrimes.size(); i++ ) {
            int lowBound = low / initialPrimes[ i ] * initialPrimes[ i ];

            if ( lowBound < low ) lowBound += initialPrimes[ i ];

            if ( lowBound == initialPrimes[ i ] ) lowBound += initialPrimes[ i ];

            for ( int j = lowBound; j <= high; j += initialPrimes[ i ] ) {
                isComposites[ j - low ] = true;
            }
        }

        for ( int i = low; i <= high; i++ ) {
            if ( ! isComposites[ i - low ] ) {
                primes.push_back( i );
            }
        }
    }

    virtual ~SegmentedSieve() {
        // not implemented
    }

    bool isPrime( int num ) const {
        if ( num < low || num > high ) throw runtime_error( "Key not exist" );
        return ! isComposites[ num - low ];
    }

    vector< int > getPrimes() const {
        return primes;
    }

    string toString() const {
        ostringstream oss;
        oss << *this << endl;
        return oss.str();
    }

    friend ostream& operator <<( ostream& out, const SegmentedSieve& sieve ) {
        out << "\nsieve:\n";
        for ( int i = 0; i < sieve.primes.size(); i++ ) {
            out << sieve.primes[ i ] << ", ";
        }
        return out;
    }

};

int main( int argc, char ** argv ) {
    
    SegmentedSieve segmentedSieve1( 0, 50 );
    cout << endl;
    cout << "DEBUG : segmentedSieve( 0, 50 ) : " << segmentedSieve1 << endl;
    
    SegmentedSieve segmentedSieve2( 40, 50 );
    cout << endl;
    cout << "DEBUG : segmentedSieve( 40, 50 ) : " << segmentedSieve2 << endl;

    SegmentedSieve segmentedSieve3( 31, 47 );
    cout << endl;
    cout << "DEBUG : segmentedSieve( 31, 47 ) : " << segmentedSieve3 << endl;

    SegmentedSieve segmentedSieve4( 1, 31 );
    cout << endl;
    cout << "DEBUG : segmentedSieve( 1, 31 ) : " << segmentedSieve4 << endl;


    return 0;
}
