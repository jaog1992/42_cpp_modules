/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:17:08 by jde-orma          #+#    #+#             */
/*   Updated: 2024/11/21 15:17:08 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Bureaucrat.cpp
 * @author jde-orma
 * @brief Source file containing the implementation of the Bureaucrat class.
 * @date 2025-10-10
 *
 * @details This file defines the behavior of the Bureaucrat class, including its constructors, 
 * destructor, operator overloads, and methods to handle grade management. The class ensures 
 * that each bureaucrat's grade remains within valid limits, throwing exceptions otherwise.
 */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "../incs/Colors.hpp"

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Default constructor that initializes a Bureaucrat with preset values.
 */
Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(LOWEST_GRADE) {
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}

/**
 * @brief Constructs a Bureaucrat with a given name and grade.
 *
 * @param name Name assigned to the Bureaucrat.
 * @param grade Initial grade value.
 * @throw GradeTooHighException if the grade is above the maximum limit.
 * @throw GradeTooLowException if the grade is below the minimum limit.
 */
Bureaucrat::Bureaucrat( const std::string &name, unsigned int grade ) : _name(name), _grade(grade) {
	checkGrade(_grade);
	std::cout << GREEN << "Bureaucrat " << BLUE << name << GREEN << " is created with grade " << BLUE << grade << RESET << std::endl;
}

/**
 * @brief Copy constructor. Creates a new Bureaucrat from another instance.
 *
 * @param otherBureaucrat Reference to the Bureaucrat to copy.
 */
Bureaucrat::Bureaucrat( const Bureaucrat &otherBureaucrat ) 
	: _name(otherBureaucrat.getName()), _grade(otherBureaucrat.getGrade()) {
	std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destructor for the Bureaucrat class.
 */
Bureaucrat::~Bureaucrat( void ) {
	std::cout << RED << "Bureaucrat destructor called for " << BLUE << _name << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Assignment operator overload.
 *
 * @param otherBureaucrat The Bureaucrat to copy data from.
 * @return Bureaucrat& Reference to the current instance.
 */
Bureaucrat & Bureaucrat::operator=( const Bureaucrat &otherBureaucrat ) {
	if (this != &otherBureaucrat) {
		_grade = otherBureaucrat.getGrade();
	}
	return *this;
}

/**
 * @brief Stream insertion operator overload for easy Bureaucrat output.
 *
 * @param os Output stream.
 * @param otherBureaucrat Bureaucrat instance to print.
 * @return std::ostream& Reference to the output stream.
 */
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &otherBureaucrat) {
	os << otherBureaucrat.getName() << ", bureaucrat grade " << otherBureaucrat.getGrade() << ".";
	return os;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Returns the Bureaucrat's name.
 * 
 * @return const std::string& Reference to the name string.
 */
const std::string	&Bureaucrat::getName( void ) const {
	return _name;
}

/**
 * @brief Returns the Bureaucrat's current grade.
 * 
 * @return const unsigned int& Reference to the grade value.
 */
const unsigned int	&Bureaucrat::getGrade( void ) const {
	return _grade;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Raises the Bureaucrat’s rank by one level.
 * 
 * @throw GradeTooHighException if the grade becomes higher than the maximum allowed.
 */
void	Bureaucrat::incrementGrade( void ) {
	if (checkGrade(_grade - 1)) {
		_grade--;
	}
}

/**
 * @brief Lowers the Bureaucrat’s rank by one level.
 * 
 * @throw GradeTooLowException if the grade exceeds the lowest allowed value.
 */
void	Bureaucrat::decrementGrade( void ) {
	if (checkGrade(_grade + 1)) {
		_grade++;
	}
}

/**
 * @brief Validates that a given grade is within acceptable limits.
 * 
 * @param grade Grade value to verify.
 * @return true If the grade is valid.
 * @throw GradeTooHighException If the grade is above the permitted maximum.
 * @throw GradeTooLowException If the grade is below the permitted minimum.
 */
bool	Bureaucrat::checkGrade( unsigned int grade ) const {
	if (grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	} else if (grade > LOWEST_GRADE ) {
		throw GradeTooLowException();
	} else {
		return true;
	}
	return false;
}

/**
 * @brief Evaluates if the form cand be signed.
 * 
 * @param form AForm to sign.
 * @throw GradeTooHighException If the grade is above the permitted maximum.
 * @throw GradeTooLowException If the grade is below the permitted minimum.
 */
void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
		std::cout << "✅ " << BLUE << _name << GREEN << " signed the " << MAGENTA << form.getName() << RESET << std::endl;
    } catch (const std::exception &e) {
		std::cerr << "⚠️  " << BLUE << _name << YELLOW <<" couldn’t sign the " << MAGENTA << form.getName() << YELLOW 
		          << ": " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm &form) const {
    try {
        form.execute(*this);
		std::cout << "✅ " << BLUE << _name << GREEN << " executed the " << MAGENTA << form.getName() << RESET << std::endl;
    } catch (const std::exception &e) {
		std::cerr << "⚠️  " << BLUE << _name << YELLOW <<" couldn’t execute the " << MAGENTA << form.getName() << YELLOW 
		    << ": " << e.what() << RESET << std::endl;
    }
}
