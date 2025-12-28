/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:20:04 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/28 12:44:01 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file PresidentialPardonForm.cpp
 * @author jde-orma
 * @brief Implementation of PresidentialPardonForm
 * @date 2025-10-10
 */

#include "PresidentialPardonForm.hpp"
#include <iostream>

const unsigned int PresidentialPardonForm::_signGrade = 25;
const unsigned int PresidentialPardonForm::_execGrade = 5;

PresidentialPardonForm::PresidentialPardonForm(void) 
    : AForm("Default Presidential", _signGrade, _execGrade), _target("") 
    {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
    : AForm("Presidential Pardon", _signGrade, _execGrade), _target(target) 
    {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) { 
    *this = other; 
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other)
        _target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

const std::string &PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::executeForm() const {
    std::cout << "✅ " << BLUE << _target << GREEN << " has been pardoned by " << BLUE << "Zaphod Beeblebrox" << RESET << "." << std::endl;
}
