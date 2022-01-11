#include "iter.hpp"
#include <iostream>

class Grade {

    public :
        Grade(double grade=0): _grade(grade){return ;};
        double getGrade(void){return _grade;};
    private:
        double _grade;
};

std::ostream &operator<<(std::ostream &o, Grade &rhs) { o << rhs.getGrade(); return o;}

int main( void ) {

    int array1[] = {0, 1, 2, 3, 4};
    unsigned int size1 = 5;

    ::iter<int, unsigned int, void>(array1, size1, printArrayElement<int>);

    std::cout << std::endl;
    Grade array2[] = { 15.5, 10.2, 19.9 };
    int size2 = 3;

    iter(array2, size2, printArrayElement<Grade>);
    return 0;
}