/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:04:04 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/22 13:15:09 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cpp
 * @author jde-orma
 * @brief Test program for Bureaucrat and AForm derived classes
 * @date 2025-10-10
 *
 * @details This main program tests signing and executing AForm-derived forms:
 * ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm.
 * It shows grade checking, exceptions, and successful/failed executions.
 */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

// Helper function to safely execute a form
void tryExecute(AForm &form, Bureaucrat &executor) {
    try {
        form.execute(executor);
        std::cout << GREEN << executor.getName() << " executed " << form.getName() << " ✅" << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << YELLOW << "⚠️  Form execution error: " << e.what() << RESET << std::endl;
    }
}

// Create Bureaucrat safely with grade check
Bureaucrat createBureaucrat(const std::string &name, int grade) {
    try {
        Bureaucrat b(name, grade);
        return b;
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << YELLOW << "⚠️  Bureaucrat constructor error: " << e.what() << RESET << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << YELLOW << "⚠️  Bureaucrat constructor error: " << e.what() << RESET << std::endl;
    }
    return Bureaucrat();
}

int main(void) {
    // Create forms
    PresidentialPardonForm importantForm("VeryImportantPerson");
    RobotomyRequestForm robotomyForm("TargetRobot");
    ShrubberyCreationForm shrubberyForm("HomeGarden");
    ShrubberyCreationForm notSignedForm("NotSigned");

    // Create bureaucrats
    Bureaucrat ihartze = createBureaucrat("Ihartze", 75);
    Bureaucrat natalia = createBureaucrat("Natalia", 15);

    std::cout << "\n💼 Signing forms...\n";

    ihartze.signForm(importantForm);
    ihartze.signForm(robotomyForm);
    ihartze.signForm(shrubberyForm);

    natalia.signForm(importantForm);
    natalia.signForm(robotomyForm);
    natalia.signForm(shrubberyForm);

    std::cout << "\n⚡ Executing forms...\n";

    tryExecute(importantForm, ihartze);     
    tryExecute(importantForm, natalia);   

    tryExecute(robotomyForm, ihartze);      
    tryExecute(robotomyForm, natalia);    

    tryExecute(shrubberyForm, ihartze);     
    tryExecute(shrubberyForm, natalia);   

    std::cout << "\n🚀 Using Bureaucrat executeForm helper...\n";

    try { natalia.executeForm(shrubberyForm); } catch (const std::exception &e) { std::cerr << YELLOW << e.what() << RESET << std::endl; }
    try { natalia.executeForm(robotomyForm); } catch (const std::exception &e) { std::cerr << YELLOW << e.what() << RESET << std::endl; }
    try { natalia.executeForm(importantForm); } catch (const std::exception &e) { std::cerr << YELLOW << e.what() << RESET << std::endl; }

    try { ihartze.executeForm(shrubberyForm); } catch (const std::exception &e) { std::cerr << YELLOW << e.what() << RESET << std::endl; }
    try { ihartze.executeForm(robotomyForm); } catch (const std::exception &e) { std::cerr << YELLOW << e.what() << RESET << std::endl; }
    try { ihartze.executeForm(importantForm); } catch (const std::exception &e) { std::cerr << YELLOW << e.what() << RESET << std::endl; }

    std::cout << "\n❌ Attempt to execute not signed form...\n";
    try {
        notSignedForm.execute(natalia);
    } catch (const std::exception &e) {
        std::cerr << YELLOW << "⚠️  Form execution error: " << e.what() << RESET << std::endl;
    }

    return 0;
}
