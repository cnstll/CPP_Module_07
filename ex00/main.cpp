#include "whatever.hpp"
#include <iostream>
#include <string>

class OverComplicatedChar {

    public:
        OverComplicatedChar( char c=0 ) : _thisIsAChar( c ) {};
        OverComplicatedChar( OverComplicatedChar const &src ) : _thisIsAChar( src.getThisDarnChar() ) {};
        ~OverComplicatedChar(){};

        OverComplicatedChar const &operator= ( OverComplicatedChar const & rhs ) { _thisIsAChar = rhs.getThisDarnChar(); return *this; };

        char getThisDarnChar(void) const { return _thisIsAChar;};

        bool operator==( OverComplicatedChar const & rhs ) const { return _thisIsAChar == rhs._thisIsAChar; };
        bool operator>( OverComplicatedChar const & rhs ) const { return _thisIsAChar > rhs._thisIsAChar; };
        bool operator<( OverComplicatedChar const & rhs ) const { return _thisIsAChar < rhs._thisIsAChar; };

    private:
        char _thisIsAChar;
};

std::ostream &operator<<( std::ostream &o, OverComplicatedChar const & rhs ){ return (o << rhs.getThisDarnChar()); }

void printTestTitle(const std::string &title){

    std::cout << ">>>>" << title << "<<<<" << std::endl;
};

int main( void ) {

    int a = 2;
    int b = 3;

    printTestTitle("Test Int");
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap<int>( a, b );
    std::cout <<"swap...\n";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;

    std::cout << std::endl;
    printTestTitle("Test String");
    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap<std::string>(c, d);
    std::cout <<"swap...\n";
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;

    std::cout << std::endl;
    double e = 2.4;
    double f = 3.3;

    printTestTitle("Test double");
    std::cout << "e = " << e << ", f = " << f << std::endl;
    ::swap<double>( e, f );
    std::cout <<"swap...\n";
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min<double>( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max<double>( e, f ) << std::endl;

    std::cout << std::endl;
    char i = 'a';
    char j = 'b';

    printTestTitle("Test char");
    std::cout << "i = " << i << ", j = " << j << std::endl;
    ::swap<char>( i, j );
    std::cout <<"swap...\n";
    std::cout << "i = " << i << ", j = " << j << std::endl;
    std::cout << "min( i, j ) = " << ::min<char>( i, j ) << std::endl;
    std::cout << "max( i, j ) = " << ::max<char>( i, j ) << std::endl;

    std::cout << std::endl;
    OverComplicatedChar g('B'); 
    OverComplicatedChar h('C');

    printTestTitle("OverComplicatedChar Class");
    std::cout << "g = " << g << ", h = " << h << std::endl;
    ::swap<OverComplicatedChar>( g, h );
    std::cout <<"swap...\n";
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min( g, h ) = " << ::min<OverComplicatedChar>( g, h ) << std::endl;
    std::cout << "max( g, h ) = " << ::max<OverComplicatedChar>( g, h ) << std::endl;

    return 0;
}