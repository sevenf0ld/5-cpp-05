/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:10:27 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/09 22:55:44 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_three.h"

AForm::AForm()
	: name_("AForm"), is_signed_(false), sign_grade_(10), exec_grade_(25), target_(NULL)
{
}

AForm::AForm(std::string name, int sign, int exec, std::string target)
	: name_(name), is_signed_(false), sign_grade_(sign), exec_grade_(exec), target_(target)
{
}

AForm::AForm(const AForm &rhs)
	: name_(rhs.name_), is_signed_(rhs.is_signed_), sign_grade_(rhs.sign_grade_), exec_grade_(rhs.exec_grade_), target_(rhs.target_)
{
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		is_signed_ = rhs.is_signed_;
	return (*this);
}

AForm::~AForm()
{
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const std::string AForm::get_name(void) const
{
	return (name_);
}

bool AForm::get_sign_status(void) const
{
	return (is_signed_);
}

int AForm::get_sign_grade(void) const
{
	return (sign_grade_);
}

int AForm::get_exec_grade(void) const
{
	return (exec_grade_);
}

void AForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= sign_grade_ && !is_signed_)
		is_signed_ = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out_stream, const AForm &obj)
{
	out_stream << "|"
			   << std::setw(COLUMN_WIDTH + 13) << "Name"
			   << "|"
			   << std::setw(COLUMN_WIDTH) << "Sign Status"
			   << "|"
			   << std::setw(COLUMN_WIDTH) << "Sign Grade"
			   << "|"
			   << std::setw(COLUMN_WIDTH) << "Exec Grade"
			   << "|"
			   << std::setw(COLUMN_WIDTH) << "Target"
			   << "|" << std::endl;
	out_stream << "|"
			   << std::setw(COLUMN_WIDTH + 13) << obj.get_name()
			   << "|"
			   << std::setw(COLUMN_WIDTH) << (obj.get_sign_status() ? "Signed" : "Unsigned")
			   << "|"
			   << std::setw(COLUMN_WIDTH) << obj.get_sign_grade()
			   << "|"
			   << std::setw(COLUMN_WIDTH) << obj.get_exec_grade()
			   << "|"
			   << std::setw(COLUMN_WIDTH) << obj.get_target()
			   << "|" << std::endl;
	return (out_stream);
}

const std::string AForm::get_target(void) const
{
	return (target_);
}

const char *AForm::FormUnsignedException::what() const throw()
{
	return ("Form unsigned.");
}
