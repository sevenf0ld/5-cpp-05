/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:11:32 by maiman-m          #+#    #+#             */
/*   Updated: 2024/08/12 18:25:00 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_three.h"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45, target)
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
	FORMAT_DTOR("Robotomy dtor called.");
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << " * drilling noises * ";
	if (executor.getGrade() <= get_exec_grade() && get_sign_status())
	{
		if (rand() % 2)
			std::cout << get_target() << " robotomized successfully." << std::endl;
		else
			std::cout << "Robotomy failed. ";
	}
	else if (!get_sign_status())
		throw FormUnsignedException();
	else if (executor.getGrade() > get_exec_grade())
		throw GradeTooLowException();
}
