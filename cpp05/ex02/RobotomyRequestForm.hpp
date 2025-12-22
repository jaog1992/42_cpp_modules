/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:20:26 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 23:20:32 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file RobotomyRequestForm.hpp
 * @author jde-orma
 * @brief Declaration of the RobotomyRequestForm class
 * @date 2025-10-10
 *
 * @details Concrete form class that simulates robotomizing the target.
 */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm {
private:
    static const unsigned int _signGrade;
    static const unsigned int _execGrade;
    std::string _target;

protected:
    void executeForm() const;

public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(void);

    const std::string &getTarget() const;
};

#endif
