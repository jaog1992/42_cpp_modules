/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 08:53:27 by nquecedo          #+#    #+#             */
/*   Updated: 2026/01/31 18:20:33 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <sstream>
#include "../incs/Colors.hpp"

class RPN
{
	private:
		/**
		 * @brief Internal stack used for RPN evaluation.
		 */
		std::stack<int> _stack;

	public:
		/**
		 * @brief Default constructor.
		 */
		RPN();

		/**
		 * @brief Destructor.
		 */
		~RPN();

		/**
		 * @brief Copy constructor.
		 * @param other Source object to copy.
		 */
		RPN(const RPN& other);

		/**
		 * @brief Assignment operator.
		 * @param other Source object to assign from.
		 * @return Reference to this.
		 */
		RPN& operator=(const RPN& other);

		/**
		 * @brief Evaluate a space-separated RPN expression.
		 *
		 * The expression is provided as a C-string where tokens are separated
		 * by spaces. Valid tokens are single-digit integers and the operators
		 * `+ - * /`. On error the function throws a `std::runtime_error` with
		 * an explanatory message.
		 *
		 * @param argumento Null-terminated C-string with the RPN expression.
		 */
		void calculate(const char *argumento);
};

#endif
