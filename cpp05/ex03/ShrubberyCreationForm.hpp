/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:21:37 by jde-orma          #+#    #+#             */
/*   Updated: 2025/10/10 23:22:26 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ShrubberyCreationForm.hpp
 * @author jde-orma
 * @brief Declaración de la clase ShrubberyCreationForm
 * @date 2025-10-10
 *
 * @details Clase concreta que genera un archivo ASCII de árboles para un objetivo dado.
 */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm {
private:
    static const unsigned int _signGrade;
    static const unsigned int _execGrade;
    std::string _target;

protected:
    void executeForm() const;

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm(void);

    const std::string &getTarget() const;
};

#endif
