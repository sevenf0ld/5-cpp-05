/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:10:27 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/09 09:42:44 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_one.h"

const int Form::sign_grade_ = 10;
const int Form::exec_grade_ = 25;

Form::Form()
	: name_("def"), is_signed_(false)
{
}

Form::Form(std::string name)
	: name_(name), is_signed_(false)
{
}

Form::Form(const Form &rhs)
	: name_(rhs.name_), is_signed_(rhs.is_signed_)
{
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		is_signed_ = rhs.is_signed_;
	return (*this);
}

Form::~Form()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
	if (sign_grade_ < MAX_GRADE)
		return ("Grade to sign is too high (1 is the maximum).");
	return ("Grade to execute is too high (1 is the maximum).");
}

const char *Form::GradeTooLowException::what() const throw()
{
	if (sign_grade_ > MIN_GRADE)
		return ("Grade to sign is too low (150 is the minimum.)");
	return ("Grade to execute is too low (150 is the minimum.)");
}

const std::string Form::get_name(void) const
{
	return (name_);
}

bool Form::get_sign_status(void) const
{
	return (is_signed_);
}

int Form::get_sign_grade(void) const
{
	return (sign_grade_);
}

int Form::get_exec_grade(void) const
{
	return (exec_grade_);
}

void Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= sign_grade_ && !is_signed_)
		is_signed_ = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out_stream, const Form &obj)
{
	out_stream << std::boolalpha << AC_MAGENTA << "\t" << obj.get_name()
			   << " is " << (obj.get_sign_status() ? "signed" : "not signed") << std::endl
			   << "to sign:\t" << obj.get_sign_grade() << std::endl
			   << "to execute:\t" << obj.get_exec_grade() << AC_NORMAL << std::endl;
	return (out_stream);
}
