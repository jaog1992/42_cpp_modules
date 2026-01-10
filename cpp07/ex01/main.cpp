/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:05:13 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 15:44:07 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

#include <iostream>

/**
 * @brief Function template that prints an element to the standard output.
 *
 * @tparam T The type of the element to print.
 * @param element The element to be printed.
 */
template <typename T>
void	printElement( T element ) {
	std::cout << "Elemento: " << element << std::endl;
}

/**
 * @brief Main function demonstrating the use of the `iter` function template.
 */
int main() {
	int myArray[] = {1, 2, 3, 4, 5};
	::iter(myArray, 5, printElement<int>);

	const double myArray2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(myArray2, 5, printElement<double>);

	std::string myArray3[] = {"CAF", "Signalling", "rules"};
	::iter(myArray3, 3, printElement<std::string>);

	return 0;
}