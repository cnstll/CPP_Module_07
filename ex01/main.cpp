#include "iter.hpp"
#include <iostream>
#include <string>

class Grade {

    public :
        Grade(double grade=0): _grade(grade){return ;};
        double getGrade(void){return _grade;};
    private:
        double _grade;
};

void printTestTitle(const std::string &title){

    std::cout << ">>>>" << title << "<<<<" << std::endl;
};

std::ostream &operator<<(std::ostream &o, Grade &rhs) { o << rhs.getGrade(); return o;}

int main( void ) {

    int array1[] = {0, 1, 2, 3, 4};
    unsigned int size1 = 5;

    printTestTitle("Test Array of Int");
    ::iter<int, unsigned int, void>(array1, size1, printArrayElement<int>);

    std::cout << std::endl;
    printTestTitle("Test Array of Strings");
    std::string array2[] = { "banana", "kiwi", "apple", "pumpkin" };
    int size2 = 4;

    iter(array2, size2, printArrayElement<std::string>);

    std::cout << std::endl;
    printTestTitle("Test Array of Class Elements");
    Grade array3[] = { 15.5, 10.2, 19.9 };
    int size3 = 3;

    iter(array3, size3, printArrayElement<Grade>);
    return 0;
}