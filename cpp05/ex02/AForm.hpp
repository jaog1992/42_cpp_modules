/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:17:00 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 23:18:12 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file AForm.hpp
 * @author jde-orma
 * @brief Declaration of the abstract AForm class for form management.
 * @date 2025-10-10
 *
 * @details Abstract base class that handles signing and execution of forms,
 *          verifying bureaucrat grade restrictions.
 */

#ifndef AFORM_H
# define AFORM_H

# include "Bureaucrat.hpp"
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string _name;       ///< Nombre del formulario
    const unsigned int _signGrade; ///< Grade required to sign
    const unsigned int _execGrade; ///< Grade required to execute
    bool _signed;                  ///< Signed status

protected:
    virtual void executeForm() const = 0; ///< Acción específica del formulario

public:
    AForm(void);
    AForm(const std::string &name, unsigned int signGrade, unsigned int execGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm(void) = 0;

    const std::string &getName() const;
    unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;
    bool getSigned() const;

    void setSigned(bool sign);

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const;

    // Exceptions
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Grade too high to sign or execute";
            }
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Grade too low to sign or execute";
            }
    };

    class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Form is not signed";
            }
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
