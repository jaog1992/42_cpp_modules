/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:19:44 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 23:19:51 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file PresidentialPardonForm.hpp
 * @author jde-orma
 * @brief Declaration of the PresidentialPardonForm class
 * @date 2025-10-10
 */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm {
private:
    static const unsigned int _signGrade;
    static const unsigned int _execGrade;
    std::string _target;

protected:
    void executeForm() const;

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm(void);

    const std::string &getTarget() const;
};

#endif
