/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:41:54 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/04 11:49:43 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <exception>
#include <stddef.h>

template <typename T>
class Array {
public:
    Array<T>();
    Array<T>( unsigned int n );
    Array<T>( Array<T> const & o );
    ~Array<T>();

    Array<T> & operator=( Array<T> const & o );
    T & operator[]( const int index ) const;

    unsigned int size() const;

    class OOBException : public std::exception {
    public:
        virtual const char * what() const throw();
    };

private:
    T * _array;
    unsigned int _size;
};

template <typename T>
Array<T>::Array()
    : _size( 0 ) {
    this->_array = NULL;
}

template <typename T>
Array<T>::Array( unsigned int n )
    : _size( n ) {
    this->_array = new T[ n ](); // adding () make sure the memory is initialized to 0
}

template <typename T>
Array<T>::Array( Array<T> const & o )
    : _array( new T[ o.size() ] )
    , _size( o.size() ) {
    for ( size_t i = 0; i < this->_size; i++ )
        _array[ i ] = o._array[ i ];
}

template <typename T>
Array<T>::~Array() {
    delete[] this->_array;
}

template <typename T>
Array<T> & Array<T>::operator=( Array<T> const & o ) {
    this->_size = o._size;
    delete[] this->_array;
    this->_array = new T[ this->_size ];
    if ( this->_array && o._array )
        for ( size_t i = 0; i < this->_size; i++ )
            this->_array[ i ] = o._array[ i ];
    return *this;
}

template <typename T>
T & Array<T>::operator[]( const int index ) const {
    if ( index < 0 || static_cast<unsigned int>( index ) >= this->_size )
        throw Array::OOBException();
    return this->_array[ index ];
}

template <typename T>
unsigned int Array<T>::size() const {
    return this->_size;
}

template <typename T>
const char * Array<T>::OOBException::what() const throw() {
    return ( "Index out of range!" );
}

#endif
