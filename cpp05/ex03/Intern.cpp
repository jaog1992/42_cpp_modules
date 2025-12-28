/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:43:48 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/28 14:20:06 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Intern.cpp
 * @author jde-orma
 * @brief Implementation of the Intern class
 * @date 2025-10-10
 * 
 * @details Implements constructors, destructor, assignment operator, and
 * makeForm functionality. The Intern can dynamically create AForm-derived
 * objects based on string identifiers.
 */

#include "Intern.hpp"

/* ---------------- CONSTRUCTORS & DESTRUCTOR ---------------- */

Intern::Intern(void) {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    *this = other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void) {
    std::cout << "Intern destructor called" << std::endl;
}

/* ---------------- OPERATOR OVERLOAD ---------------- */

Intern &Intern::operator=(const Intern &other) {
    (void)other; // no member to copy
    return *this;
}

/* ---------------- FORM CREATION ---------------- */

static AForm *createShrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *createPresidentialForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
    const std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formTypes[3])(const std::string &target) = {
        createShrubberyForm,
        createRobotomyForm,
        createPresidentialForm
    };

    for (int i = 0; i < 3; i++) {
        if (forms[i] == transformCase(name, TOLOWER)) {
            std::cout << BLUE << "Intern creates " << forms[i] << RESET << std::endl;
            return formTypes[i](target);
        }
    }
    std::cerr << YELLOW << "Intern couldn't create form: unknown form name '" << BLUE << name << "'" << RESET << std::endl;
    return NULL;
}

/* ---------------- STRING UTILITY ---------------- */

std::string Intern::transformCase(const std::string &str, const int &type) {
    std::string dst;
    std::locale loc;

    if (type == TOUPPER) {
        for (std::size_t i = 0; i < str.length(); ++i)
            dst += std::toupper(str[i], loc);
    } else if (type == TOLOWER) {
        for (std::size_t i = 0; i < str.length(); ++i)
            dst += std::tolower(str[i], loc);
    } else {
        return str;
    }
    return dst;
}
