/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:43:23 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 23:43:26 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Intern.hpp
 * @author jde-orma
 * @brief Definition of the Intern class
 * @date 2025-10-10
 * 
 * @details The Intern class is responsible for creating different types of forms
 * based on a provided name and target. It has no unique characteristics and serves
 * solely to fulfill form creation requests.
 */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>
# include <string>
# include <locale>

class Intern {
public:
    Intern(void);
    Intern(const Intern &other);
    ~Intern(void);

    Intern &operator=(const Intern &other);

    /**
     * @brief Creates a form based on the given name and target
     * @param name Name of the form
     * @param target Target of the form
     * @return AForm* Pointer to the created form or nullptr if name is invalid
     */
    AForm *makeForm(const std::string &name, const std::string &target);

private:
    /**
     * @brief Transforms the string to uppercase or lowercase
     * @param str Input string
     * @param type "upper" or "lower"
     * @return std::string Transformed string
     */
    std::string transformCase(const std::string &str, const std::string &type);
};

#endif
