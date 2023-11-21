/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:34:13 by mbarberi          #+#    #+#             */
/*   Updated: 2023/09/05 19:54:19 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_CLASS_H
#define MUTANTSTACK_CLASS_H

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack<T>() {};
    MutantStack<T>( MutantStack<T> const & o ) { *this = o; };
    ~MutantStack<T>() {};
    MutantStack<T> & operator=( MutantStack<T> const & o ) {
        *this = o;
        return *this;
    };

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // std::stack does not have iterators, but the underlying container
    // (std::deque) has iterators. Therefore we can use the begin() and
    // end() methods from std::deque.
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
};

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void ) {
    return this->c.begin();
}

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin( void ) const {
    return this->c.begin();
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end( void ) {
    return this->c.end();
}

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end( void ) const {
    return this->c.end();
}

#endif
