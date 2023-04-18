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

// Time Complexities : O( 7 * N ) where N = txt.size()
// Space Complexities : O( 1 )

class RabinKarp {
private:
    
    string pat = "";
    int M = 0;
    int R = 256;
    long patHash = 0;
    long RM = 0;
    long Q = 0;
    bool useMonteCarlo = false;

    bool check( const string& txt, int i ) const {
        if ( useMonteCarlo ) return true;

        for ( int j = 0; j < M; j++ ) {
            if ( pat[ j ] != txt[ i + j ] ) {
                return false;
            }
        }
        return true;
    }

    long getHash( const string& key ) const {
        long h = 0;
        for ( int i = 0; i < M; i++ ) {
            h = ( h * R + key[ i ] ) % Q;
        }
        return h;
    }

public:

    RabinKarp( const string& pat, bool useMonteCarlo=false )
        : pat( pat ),
          M( pat.size() ),
          RM( 1 ),
          Q( ( long )( pow( 2, 31 ) - 1 ) ),
          useMonteCarlo( useMonteCarlo )
    {
        for ( int i = 1; i < M; i++ ) {
            RM = ( RM * R ) % Q;
        }
        patHash = getHash( pat );
    }

    virtual ~RabinKarp() {
        // not implemented
    }

    int search( const string& txt ) const {
        int N = txt.size();
        if ( N < M ) return N;
        long txtHash = getHash( txt );

        if ( patHash == txtHash && check( txt, 0 ) ) {
            return 0;
        }

        for ( int i = M; i < N; i++ ) {
            txtHash = ( txtHash + Q - RM * txt[ i - M ] % Q ) % Q;
            txtHash = ( txtHash * R + txt[ i ] ) % Q;

            int offset = i - M + 1;
            if ( patHash == txtHash && check( txt, offset ) ) {
                return offset;
            }
        }
        return N;
    }

};

int main( int argc, char ** argv ) {

    string s = "abacadabrabracabracadabrabrabracad";
    vector< string > queryVec = {
        "abracadabra", "rab", "bcara", "rabrabracad", "abacad",
    };

    cout << "DEBUG: Monte-Carlo : " << endl;
    for ( int i = 0; i < queryVec.size(); i++ ) {
        RabinKarp rk( queryVec[ i ], true );
        int index = rk.search( s );
        if ( index < s.size() ) {
            printf( "FOUND : %-20s : %d\n", queryVec[ i ].c_str(), index );
        } else {
            printf( "NOT FOUND : %s!!!\n", queryVec[ i ].c_str() );
        }
    }
    
    cout << endl;
    cout << endl;
    cout << "DEBUG: Las Vegas : " << endl;
    for ( int i = 0; i < queryVec.size(); i++ ) {
        RabinKarp rk( queryVec[ i ] );
        int index = rk.search( s );
        if ( index < s.size() ) {
            printf( "FOUND : %-20s : %d\n", queryVec[ i ].c_str(), index );
        } else {
            printf( "NOT FOUND : %s!!!\n", queryVec[ i ].c_str() );
        }
    }


    return 0;
}
