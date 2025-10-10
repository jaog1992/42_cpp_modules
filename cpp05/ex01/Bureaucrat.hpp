/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:42:25 by jde-orma          #+#    #+#             */
/*   Updated: 2024/11/21 14:42:25 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**
 * @file Bureaucrat.hpp
 * @author jde-orma
 * @brief Header file for the Bureaucrat class declaration.
 * @date 2025-10-10
 */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "../incs/Colors.hpp"

class Form; // Forward declaration

/**
 * @class Bureaucrat
 * @brief Models a government employee with a specific rank.
 *
 * This class stores a Bureaucrat's name and grade. Grades must remain within
 * defined boundaries; if not, exceptions are thrown. The grade can be adjusted
 * using the increment and decrement methods.
 */
class Bureaucrat {
	private:
		static const int	HIGHEST_GRADE = 1; ///< Maximum possible rank.
		static const int	LOWEST_GRADE = 150; ///< Minimum possible rank.

		const std::string	_name; ///< Bureaucrat’s name (immutable).
		unsigned int		_grade; ///< Bureaucrat’s grade (modifiable).

	public:
		Bureaucrat( void );
		Bureaucrat( const std::string &name, unsigned int grade );
		Bureaucrat( const Bureaucrat &otherBureaucrat );
		~Bureaucrat( void );

		Bureaucrat & operator=( const Bureaucrat &otherBureaucrat );

		const std::string	&getName( void ) const;
		const unsigned int	&getGrade( void ) const;

		void	incrementGrade( void );
		void	decrementGrade( void );
		bool	checkGrade( unsigned int grade ) const;

		void	signForm( Form &form ); // Required by ex01

	public:
		/**
		 * @class GradeTooHighException
		 * @brief Exception thrown when a grade exceeds the upper limit.
		 */
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade too high! ⬆️";
				}			
		};

		/**
		 * @class GradeTooLowException
		 * @brief Exception thrown when a grade falls below the lower limit.
		 */
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade too low! ⬇️";
				}
		};
};

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &aBureaucrat );

#endif
