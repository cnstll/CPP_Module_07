//   Array<int> numbers(MAX_VAL);
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>

template <typename T>
class Array {

    public:
        Array( void ) : _arrayPtr(0), _size(0) {return ;};
        Array( unsigned int n ) : _arrayPtr(new T[n]), _size(n){
            for (unsigned int i=0; i < n; i++){
                _arrayPtr[i] = static_cast<T>(0);
            }
            return ;
        };
        ~Array( void ){ delete [] _arrayPtr;};

        void copyArray( Array const &src, unsigned int _size) {

           for (unsigned int index = 0; index < _size; index++){
               this->_arrayPtr[index] = src._arrayPtr[index];
           } 
        };

        void deepCopy( Array const &src ) { 

            if (src._arrayPtr) {
                this->_size = src._size;
                this->_arrayPtr = new T[this->_size];
                copyArray(src, _size);
            }
        };
        Array( const Array<T> &src ) { *this = src; return ;};

        Array &operator= (Array const &rhs) { deepCopy(rhs); return *this;};

        T &operator[] (unsigned int index) { 
            if (index < 0 || index >= this->size()) {
               throw std::range_error("index out of array range");
            };
            return _arrayPtr[index];
        };

        void  display(void){

            for (unsigned int i=0; i < _size; i++){
                std::cout << _arrayPtr[i] << " ";
            }
            std::cout << "\n";
        };
        unsigned int size( void ) const { return _size;};

    private:

        T *_arrayPtr;
        unsigned int _size;
        

};

#endif