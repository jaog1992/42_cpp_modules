/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:18:31 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 23:19:22 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file AForm.cpp
 * @author jde-orma
 * @brief Implementation of the AForm class.
 * @date 2025-10-10
 *
 * @details Contains the logic for signing and executing forms,
 *          including exception handling.
 */

#include "AForm.hpp"
#include <iostream>

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */
AForm::AForm(void) : _name(""), _signGrade(150), _execGrade(150), _signed(false) {}

AForm::AForm(const std::string &name, unsigned int signGrade, unsigned int execGrade)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}


AForm::AForm(const AForm &other) 
    : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade) {
    *this = other;
}

AForm::~AForm(void) {}

/* ------------ OVERLOADS ------------ */
AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        _signed = other._signed;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << form.getName() 
       << " [SignGrade: " << form.getSignGrade()
       << ", ExecGrade: " << form.getExecGrade()
       << ", Signed: " << (form.getSigned() ? "Yes" : "No") << "]";
    return os;
}

/* ------------ GETTERS ------------ */
const std::string &AForm::getName() const { return _name; }
unsigned int AForm::getSignGrade() const { return _signGrade; }
unsigned int AForm::getExecGrade() const { return _execGrade; }
bool AForm::getSigned() const { return _signed; }

/* ------------ SETTER ------------ */
void AForm::setSigned(bool sign) { _signed = sign; }

/* ------------ OTHER METHODS ------------ */
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= _signGrade)
        _signed = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    executeForm();
}