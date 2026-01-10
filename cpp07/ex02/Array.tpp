/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:08:03 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 16:27:24 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP

# define ARRAY_TPP

# include "Array.hpp"
# include <stdexcept>
# include <cstddef>

/**
 * @file Array.tpp
 * @brief Implementation of templated Array methods.
 */

template <typename T>
Array<T>::Array( void ) : _data(), _size(0) {
}

template <typename T>
Array<T>::Array( unsigned int size ) : _data(new T[size]()), _size(size) {
}

template <typename T>
Array<T>::Array( const Array &otherArray ) : _data(NULL), _size(0) {
    *this = otherArray;
}

template <typename T>
Array<T>::~Array( void ) {
    delete[] _data;
}

template <typename T>
Array<T> & Array<T>::operator=( const Array &otherArray ) {
    if (this != &otherArray) {
        delete[] _data;

        _size = otherArray._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            _data[i] = otherArray._data[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

template <typename T>
std::size_t Array<T>::size() const {
    return _size;
}
#endif