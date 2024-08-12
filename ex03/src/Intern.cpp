/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:31:08 by maiman-m          #+#    #+#             */
/*   Updated: 2024/08/12 18:21:38 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_three.h"

Intern::Intern()
{
}

Intern::Intern(const Intern &rhs)
{
	(void)rhs;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
	Intern_pmf pmf;

	switch (hash_form(form_name))
	{
	case SHRUBBERY:
		pmf = &Intern::create_shrubbery;
		break;
	case ROBOTOMY:
		pmf = &Intern::create_robotomy;
		break;
	case PRESIDENTIAL:
		pmf = &Intern::create_presidential;
		break;
	default:
		throw InvalidFormException();
	}
	std::cout << AC_YELLOW << "Intern creates " << form_name << "." << AC_NORMAL << std::endl;
	return ((this->*pmf)(form_target));
}

const char *Intern::InvalidFormException::what() const throw()
{
	return ("Invalid form.");
}

forms Intern::hash_form(std::string form_name)
{
	if (form_name == "ShrubberyCreationForm")
		return (SHRUBBERY);
	else if (form_name == "RobotomyRequestForm")
		return (ROBOTOMY);
	else if (form_name == "PresidentialPardonForm")
		return (PRESIDENTIAL);
	else
		return (INVALID);
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
