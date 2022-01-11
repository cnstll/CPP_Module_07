#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <exception>

template <typename T>
void printArrayElement(T element){

    std::cout << element << std::endl;
}

template <typename T, typename U, typename V>
void   iter(T *array, U size, V (*f)(T)){

    U index = 0;
    while (index < size){

        (f)(array[index]);
        index++;
    }
}
#endif