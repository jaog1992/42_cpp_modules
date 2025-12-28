/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:04:04 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/28 14:17:40 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cpp
 * @author jde-orma
 * @brief Test Intern class and form creation
 * @date 2025-10-10
 * 
 * @details This main program tests the Intern class by attempting to create
 * various forms and execute them using a high-ranked Bureaucrat. It also
 * handles invalid form names gracefully.
 */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "../incs/Colors.hpp"
#include <iostream>

/**
 * @brief Helper function to test the intern creating and executing forms.
 * 
 * @param formName Name of the form to create
 * @param formTarget Target of the form
 */
void internJob(const std::string &formName, const std::string &formTarget) {
    Intern intern;
    AForm *form = NULL;

    try {
        Bureaucrat ihartze("Ihartze Basterretxea", 1);
        form = intern.makeForm(formName, formTarget);

        if (form) {
            std::cout << "💼 Signing form..." << std::endl;
            form->beSigned(ihartze);
            std::cout << "⚡ Executing form..." << std::endl;
            form->execute(ihartze);
            delete form;
        } else {
            std::cout << YELLOW << "❌ Error: Form '" << formName << "' not recognized." << RESET << std::endl;
        }
    } catch (const AForm::GradeTooLowException &e) {
        std::cerr << YELLOW << "⚠️  Execution error: " << e.what() << RESET << std::endl;
    } catch (const AForm::FormNotSignedException &e) {
        std::cerr << YELLOW << "⚠️  Execution error: " << e.what() << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << YELLOW << "⚠️  Unexpected error: " << e.what() << RESET << std::endl;
    }
}

int main(void) {
    std::cout << "\n🚀 Intern Job Simulation\n" << std::endl;

    internJob("Robotomy Request", "Gotzone");
    std::cout << "\n" << std::endl;

    internJob("Presidential Pardon", "Natalia");
    std::cout << "\n" << std::endl;

    internJob("Shrubbery Creation", "Sendoa");
    std::cout << "\n" << std::endl;

    internJob("Guggenheim Urdaibai", "DFB");
    std::cout << "\n✅ All jobs attempted.\n" << std::endl;

    return 0;
}
