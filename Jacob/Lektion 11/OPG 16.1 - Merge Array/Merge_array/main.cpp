#include <iostream>
#include <iterator>
#include <vector>

#include <array>
#include <ostream>
#include <iomanip>

using namespace std;

template < class ForwardIt1 >
void mergeArray ( ForwardIt1 first , ForwardIt1 mid , ForwardIt1 last) ;

template < class ForwardIt1 , class BinaryPredicate >
void mergeArray ( ForwardIt1 first , ForwardIt1 mid , ForwardIt1 last, BinaryPredicate p ) ;


int main()
{
    std :: ostream_iterator <double > outputD {std :: cout , " "};
    std :: vector <double > a{1 ,2 ,4 ,5 ,1 ,3 ,4 ,7};
    std :: cout << " Before merge : ";
    std :: copy (a. begin () , a.end () , outputD ) ;
    std :: cout << std :: endl ;

    mergeArray (a. begin () , a. begin () +4 , a.end () ) ;

    std :: cout << " After merge : ";
    std :: copy (a. begin () , a.end () , outputD ) ;
    std :: cout << std :: endl ;



    std :: vector <double > b{7 ,4 ,3 ,1 ,5 ,4 ,2 ,1};
    std :: cout << " Before merge : ";
    std :: copy (b. begin () , b.end () , outputD ) ;
    std :: cout << std :: endl ;

    std :: greater <double > g;
    mergeArray (b. begin () , b. begin () +4 , b.end () , g) ;

    std :: cout << " After merge : ";
    std :: copy (b. begin () , b.end () , outputD ) ;

    return 0;
}

template < class ForwardIt1 >
void mergeArray(ForwardIt1 first , ForwardIt1 mid , ForwardIt1 last) {

}

template < class ForwardIt1 , class BinaryPredicate >
void mergeArray ( ForwardIt1 first , ForwardIt1 mid , ForwardIt1 last, BinaryPredicate p ) {

}
