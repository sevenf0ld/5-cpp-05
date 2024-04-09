/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:31:08 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/10 00:43:27 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_three.h"

Intern::Intern()
{
}

Intern::Intern(const Intern &rhs)
{
	(void) rhs;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void) rhs;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
}

AForm *Intern::create_shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::create_robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::create_presidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}
