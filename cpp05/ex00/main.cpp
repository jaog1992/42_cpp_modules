/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:04:04 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/26 18:14:35 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cpp
 * @author jde-orma
 * @brief Main entry point demonstrate the Bureaucrat class usage and exception handling.
 * @date 2025-10-10
 */

#include "Bureaucrat.hpp"
#include "../incs/Colors.hpp"

# define EXIT_SUCCESS   0
# define EXIT_FAILURE   1

/**
 * @brief Safely tries to raise a Bureaucrat’s grade and handles any exceptions.
 * 
 * @param employee Reference to the Bureaucrat whose grade will be modified.
 */
void	tryPromote( Bureaucrat &employee ) {
	try {
		employee.incrementGrade();
		std::cout << BLUE << employee << RESET << std::endl;
	} catch(const Bureaucrat::GradeTooHighException &e) {
		std::cerr << YELLOW << "⚠️ Bureaucrat promotion failed for " << employee.getName() << ": " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Safely tries to lower a Bureaucrat’s grade and handles any exceptions.
 * 
 * @param employee Reference to the Bureaucrat whose grade will be modified.
 */
void	tryDemote( Bureaucrat &employee ) {
	try {
		employee.decrementGrade();
		std::cout << BLUE << employee << RESET << std::endl;
	} catch(const Bureaucrat::GradeTooLowException &e) {
		std::cerr << YELLOW << "⚠️ Bureaucrat demotion failed for " << employee.getName() << ": " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Creates a Bureaucrat object and catches exceptions for invalid grades.
 * 
 * @param name The Bureaucrat's name.
 * @param grade The initial grade value.
 * @return Bureaucrat Either the successfully created Bureaucrat or a default instance if creation failed.
 */
Bureaucrat *makeBureaucrat( const std::string &name, int grade ) {
	try {
		return new Bureaucrat(name, grade);
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << "❌ Error while creating Bureaucrat " << name << ": " << e.what() << RESET << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << "❌ Error while creating Bureaucrat " << name << ": " << e.what() << RESET << std::endl;
	}
	return NULL;
}

/**
 * @brief Demonstrates the Bureaucrat class with several grade adjustments and exception cases.
 */
int	main( void ) {
    
    std::cout << MAGENTA << "\n--- Creating Bureaucrats ---\n" << RESET;
	
	Bureaucrat	*inazio = makeBureaucrat("Inazio", -150);
	Bureaucrat	*ihartze = makeBureaucrat("Ihartze", 150);
	Bureaucrat	*natalia = makeBureaucrat("Natalia", 3);
	Bureaucrat	*elsa = makeBureaucrat("Elsa", 151);
	Bureaucrat	*onintza = makeBureaucrat("Onintza", 0);

	std::cout << MAGENTA << "\n--- Testing promotions and demotions ---\n" << RESET;

	if (inazio) tryDemote(*inazio);
	if (ihartze) tryDemote(*ihartze);
	if (ihartze) tryPromote(*ihartze);
	if (natalia) tryPromote(*natalia);
	if (natalia) tryPromote(*natalia);
	if (natalia) tryPromote(*natalia);
	if (natalia) tryDemote(*natalia);

	std::cout << MAGENTA << "\n--- Testing copy constructor and assignment ---\n" << RESET;
	if (natalia) {
		Bureaucrat copyOfNatalia(*natalia);
		std::cout << GREEN << "Copied Bureaucrat: " << BLUE << copyOfNatalia << RESET << std::endl;
	}

	if (ihartze) {
		Bureaucrat assigned = *ihartze;
		std::cout << GREEN << "Assigned Bureaucrat: " << BLUE << assigned << RESET << std::endl;
	}

	std::cout << MAGENTA << "\n--- End of Tests ---\n" << RESET;

	delete inazio;
	delete ihartze;
	delete natalia;
	delete elsa;
	delete onintza;

	return (EXIT_SUCCESS);
}
