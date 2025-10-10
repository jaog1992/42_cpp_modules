/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:04:04 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 22:40:26 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cpp
 * @author jde-orma
 * @brief Main entry point demonstrate the Form class usage and exception handling.
 * @date 2025-10-10
 */
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "../incs/Colors.hpp"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

Bureaucrat createBureaucrat( const std::string &name, int grade ) {
	try {
		Bureaucrat	one(name, grade);
		return one;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << "❌ Bureaucrat constructor error: " << e.what() << RESET << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << "❌ Bureaucrat constructor error: " << e.what() << RESET << std::endl;
	}
	return Bureaucrat();
}

int	main( void ) {
	std::cout << MAGENTA << "\n===== 🗂️ FORM SIGNING SIMULATION =====" << RESET << std::endl;

	Form veryImportant("Very Important Form", 10, 2, false);
	Form important("Important Form", 45, 10, false);
	Form notImportant("Not Important Form", 100, 60, false);

	Bureaucrat ihartze = createBureaucrat("Ihartze", 75);
	Bureaucrat natalia = createBureaucrat("Natalia", 15);

	std::cout << "\n" << BLUE << ">>> Trying with Ihartze (grade 75)" << RESET << std::endl;
	ihartze.signForm(veryImportant);
	ihartze.signForm(important);
	ihartze.signForm(notImportant);

	std::cout << "\n" << BLUE << ">>> Trying with Natalia (grade 15)" << RESET << std::endl;
	natalia.signForm(veryImportant);
	natalia.signForm(important);
	natalia.signForm(notImportant);

	std::cout << MAGENTA << "\n===== ✅ TESTS COMPLETED =====" << RESET << std::endl;
	return (EXIT_SUCCESS);
}
