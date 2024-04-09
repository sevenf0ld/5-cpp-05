/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:11:32 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/09 15:38:24 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_two.h"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
					 : AForm("RobotomRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
					 : AForm(rhs)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	AForm::operator=(rhs);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << " * drilling noises * ";
	if (executor.getGrade() <= get_exec_grade() && get_sign_status())
	{
		// Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.
		std::cout << get_target() << " robotomized successfully 50% of the time." << std::endl;
		return ;
	}
	else if (executor.getGrade() > get_exec_grade())
		throw GradeTooLowException();
	else if (!get_sign_status())
		throw FormUnsignedException();
	std::cout << "Robotomy failed." << std::endl;
}
