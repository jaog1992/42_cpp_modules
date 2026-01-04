/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:54:47 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/04 18:54:49 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP

# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

/**
 * @brief A stack class template that provides iterators to access elements.
 * 
 * @tparam T The type of elements in the stack.
 * @tparam Container The underlying container used to store elements, defaults to std::deque<T>.
 */
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack( void );
		MutantStack( const MutantStack &aMutantStack );
		~MutantStack( void );
		MutantStack  &operator=( const MutantStack &aMutantStack );

		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		iterator				begin( void );
		iterator				end( void );
		const_iterator			begin( void ) const;
		const_iterator			end( void ) const;

		reverse_iterator		rbegin( void );
		reverse_iterator		rend( void );
		const_reverse_iterator	rbegin( void ) const;
		const_reverse_iterator	rend( void ) const;
};

#include "MutantStack.tpp"

#endif
