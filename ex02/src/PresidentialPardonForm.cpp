/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:40:27 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/09 23:15:21 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_two.h"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
					 : AForm("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
					 : AForm(rhs)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	AForm::operator=(rhs);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= get_exec_grade() && get_sign_status())
		// Informs that <target> has been pardoned by Zaphod Beeblebrox.
		std::cout << "President Zaphod Beeblebrox has pardoned " << get_target() << "." << std::endl;
	else if (!get_sign_status())
		throw FormUnsignedException();
	else if (executor.getGrade() > get_exec_grade())
		throw GradeTooLowException();
}
