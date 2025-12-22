/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 22:42:10 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 22:50:46 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Form.hpp
 * @author jde-orma
 * @brief Declaration of the Form class for managing bureaucratic forms.
 * @details A Form has a name, required grades for signing and execution, and a signed status.
 *          Bureaucrats can attempt to sign the form, and exceptions are thrown if the grades
 *          are out of bounds.
 * @date 2025-10-10
 */

#ifndef FORM_HPP
# define FORM_HPP

# include "../incs/Colors.hpp"
# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat; ///< Forward declaration to handle circular dependency

/* ------------------------ CLASS DECLARATION ------------------------ */

/**
 * @class Form
 * @brief Represents a bureaucratic form with signing and execution constraints.
 * 
 * Each Form has:
 *  - A name (immutable)
 *  - Required grade to sign
 *  - Required grade to execute
 *  - Signed status
 * 
 * Forms can be signed by Bureaucrats whose grade meets or exceeds the required threshold.
 */
class Form {
	private:
		const std::string _name;       ///< Name of the form (constant)
		const unsigned int _signGrade; ///< Minimum grade to sign
		const unsigned int _execGrade; ///< Minimum grade to execute
		bool _signed;                  ///< Indicates if the form has been signed

	public:
		/* ---------------- CONSTRUCTORS & DESTRUCTOR ---------------- */

		Form( const std::string &name, const int signGrade, const int execGrade, bool isSigned = false );
		Form( const Form &otherForm );
		~Form( void );

		/* ---------------- OPERATOR OVERLOAD ---------------- */

		Form &operator=( const Form &otherForm );

		/* ---------------- GETTERS ---------------- */

		const std::string &getName( void ) const;
		const unsigned int &getSignGrade( void ) const;
		const unsigned int &getExecGrade( void ) const;
		bool getSigned( void ) const;

		/* ---------------- SIGNING ---------------- */

		/**
		 * @brief Allows a Bureaucrat to sign the form.
		 * @param bureaucrat Bureaucrat attempting to sign the form.
		 * @throws GradeTooLowException if the Bureaucrat's grade is insufficient.
		 */
		void beSigned( const Bureaucrat &bureaucrat );

	public:
		/* ---------------- CUSTOM EXCEPTIONS ---------------- */

		/**
		 * @class GradeTooHighException
		 * @brief Thrown when a grade exceeds the maximum allowed for signing/execution.
		 */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Form grade too high! ⬆️";
				}
		};

		/**
		 * @class GradeTooLowException
		 * @brief Thrown when a grade is below the minimum required for signing/execution.
		 */
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Form grade too low! ⬇️";
				}
		};
};

/* ---------------- STREAM OVERLOAD ---------------- */

/**
 * @brief Overloads the output stream operator to display Form information.
 * @param os Output stream
 * @param otherForm Form to display
 * @return Reference to the output stream
 */
std::ostream &operator<<( std::ostream &os, const Form &otherForm );

#endif
