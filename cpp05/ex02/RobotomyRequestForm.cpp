/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:21:03 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/28 12:43:45 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file RobotomyRequestForm.cpp
 * @author jde-orma
 * @brief Implementation of RobotomyRequestForm
 * @date 2025-10-10
 *
 * @details Performs a robotomy procedure with a 50% chance of success.
 */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

const unsigned int RobotomyRequestForm::_signGrade = 72;
const unsigned int RobotomyRequestForm::_execGrade = 45;

RobotomyRequestForm::RobotomyRequestForm(void) 
    : AForm("Default Robotomy", _signGrade, _execGrade), _target("") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request", _signGrade, _execGrade), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other)
        _target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

const std::string &RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::executeForm() const {
    std::cout << "* Bzzzz... Drill noises *" << std::endl;
    if (rand() % 2)
        std::cout << "✅ " << BLUE << _target << GREEN << " has been robotomized successfully." << RESET << std::endl;
    else
        std::cout << "❌ " << BLUE << _target << RED << " robotomy failed." << RESET << std::endl;
}
