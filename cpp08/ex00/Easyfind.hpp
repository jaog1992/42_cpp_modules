/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:53:15 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/04 18:53:18 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP

# define EASYFIND_HPP

# include "../incs/Colors.hpp"

# include <stdexcept>
# include <sstream>
# include <algorithm>


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
	typename T::iterator	it = find(container.begin(), container.end(), nbr);
	if (it == container.end()) {
        std::ostringstream oss;
        oss << nbr;
        std::string msg = "The number " + oss.str() + " is not in the cointainer.";
		throw std::runtime_error(msg);
	}
	return it;
}

#endif