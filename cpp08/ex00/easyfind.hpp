/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:53:15 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/19 13:29:44 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <sstream>
# include <algorithm>


// C++ Standard Library implementation of find
//
//	template<class InputIterator, class T>
//	  InputIterator find (InputIterator first, InputIterator last, const T& val)
//	{
//	  while (first!=last) {
//	    if (*first==val) return first;
//	    ++first;
//	  }
//	  return last;
//	}
/**
 * @brief Finds an element in a container.
 *
 * @tparam T The type of the container.
 * @param container The container in which to search for the element.
 * @param nbr The integer to find in the container.
 * @return typename T::iterator An iterator to the found element.
 * @throw std::runtime_error if the element is not found in the container.
 */
template <typename T>
typename T::iterator	easyfind( T &container, int nbr ) {

	typename T::iterator	it = std::find(container.begin(), container.end(), nbr);
	
	if (it == container.end()) {
        std::ostringstream oss;
        oss << nbr;
        std::string msg = "The number " + oss.str() + " is not in the container.";
		throw std::runtime_error(msg);
	}
	
	return it;
}

#endif