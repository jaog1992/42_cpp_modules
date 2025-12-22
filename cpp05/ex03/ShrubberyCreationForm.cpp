/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:22:21 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 23:34:04 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ShrubberyCreationForm.cpp
 * @author jde-orma
 * @brief Implementation of ShrubberyCreationForm
 * @date 2025-10-10
 *
 * @details Creates a <target>_shrubbery file with ASCII tree art.
 */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

const unsigned int ShrubberyCreationForm::_signGrade = 145;
const unsigned int ShrubberyCreationForm::_execGrade = 137;

ShrubberyCreationForm::ShrubberyCreationForm(void) 
    : AForm("Default Shrubbery", _signGrade, _execGrade), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation", _signGrade, _execGrade), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) { *this = other; }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other)
        _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

const std::string &ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::executeForm() const {
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs) {
        std::cerr << "Error: could not open file for shrubbery." << std::endl;
        return;
    }

    ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    ofs << "    ,&&%&%&&%,@@@@@/@@@@@@,8888888/8o\n";
    ofs << "   ,%&&&&&%&&%,@@@@@@@/@@@88888888/88'\n";
    ofs << "   %&&%&%&/%&&%@@@@@/ /@@@88888888888'\n";
    ofs << "   %&&%/ %&@%&&@@ @ V /@@' `8888 `/88'\n";
    ofs << "   `&%& ` /%&'    |.|        8 '|8'\n";
    ofs << "       |o|        | |         | |\n";
    ofs << "       |.|        | |         | |\n";
    ofs << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

    ofs.close();
}
