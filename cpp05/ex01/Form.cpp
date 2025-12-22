/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 22:41:51 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 22:58:46 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Form.cpp
 * @author jde-orma
 * @brief Contains the implementation of the Form class, which enforces signing and execution requirements
 * based on bureaucratic rank restrictions.
 * @details Each Form object requires specific grades to be signed or executed.
 * Attempting to create or sign a form with invalid grades triggers exceptions.
 * @date 2025-10-10
 */

#include "Form.hpp"

class Bureaucrat;

/* ---------------- CONSTRUCTORS & DESTRUCTOR ---------------- */

// Default constructor removed to avoid creating an invalid Form with grade 0

/**
 * @brief Constructs a Form instance with custom initialization values.
 *
 * @param name Name assigned to the form.
 * @param signGrade Minimum grade required for signing.
 * @param execGrade Minimum grade required for execution.
 * @param isSigned Indicates if the form is initially signed.
 * 
 * @throws GradeTooHighException If either grade is set above the allowed limit (1).
 * @throws GradeTooLowException If either grade is set below the allowed limit (150).
 */
Form::Form( const std::string &name, const int signGrade, const int execGrade, bool isSigned )
	: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(isSigned) {
	std::cout << GREEN << "Form parameterized constructor called" << RESET << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

/**
 * @brief Copy constructor.
 * 
 * Creates a new Form as a deep copy of another one.
 *
 * @param otherForm The instance to duplicate.
 */
Form::Form( const Form &otherForm )
	: _name(otherForm._name), _signGrade(otherForm._signGrade),
	  _execGrade(otherForm._execGrade), _signed(otherForm._signed) {
	*this = otherForm;
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destructor.
 * 
 * Cleans up the Form instance and outputs a message to the console.
 */
Form::~Form( void ) {
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}


/* ---------------- OPERATOR OVERLOADS ---------------- */

/**
 * @brief Assignment operator overload.
 *
 * Copies the sign status from another form but not the immutable attributes (name or grade).
 * 
 * @param otherForm Reference to the source object.
 * @return Reference to the updated Form.
 */
Form &Form::operator=( const Form &otherForm ) {
	if (this != &otherForm)
		_signed = otherForm._signed;
	return *this;
}

/**
 * @brief Stream output operator overload.
 *
 * Enables printing form information using standard streams.
 * 
 * @param os Output stream.
 * @param otherForm The form to be displayed.
 * @return The same output stream for chaining.
 */
std::ostream &operator<<( std::ostream &os, const Form &otherForm ) {
	os << otherForm.getName() 
       << " [SignGrade: " << otherForm.getSignGrade()
       << ", ExecGrade: " << otherForm.getExecGrade()
       << ", Signed: " << (otherForm.getSigned() ? "Yes" : "No") << "]";
	return os;
}


/* ---------------- ACCESSOR METHODS ---------------- */

/**
 * @brief Returns the form's name.
 *
 * @return Constant reference to the name string.
 */
const std::string &Form::getName( void ) const {
	return _name;
}

/**
 * @brief Returns the grade threshold for signing.
 *
 * @return Constant reference to the sign grade value.
 */
const unsigned int &Form::getSignGrade( void ) const {
	return _signGrade;
}

/**
 * @brief Returns the grade threshold for execution.
 *
 * @return Constant reference to the execution grade value.
 */
const unsigned int &Form::getExecGrade( void ) const {
	return _execGrade;
}

/**
 * @brief Checks if the form is signed.
 *
 * @return `true` if signed, otherwise `false`.
 */
bool Form::getSigned( void ) const {
	return _signed;
}


/* ---------------- BUSINESS LOGIC ---------------- */

/**
 * @brief Allows a Bureaucrat to sign the form if their grade meets the requirement.
 *
 * @param bureaucrat The Bureaucrat attempting to sign.
 * 
 * @throws GradeTooLowException When the Bureaucrat's grade is insufficient to sign.
 */
void Form::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}
