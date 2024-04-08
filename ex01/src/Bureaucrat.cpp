/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:09:30 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/08 10:49:08 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_one.h"

Bureaucrat::Bureaucrat()
	: name_("def"), grade_(MIN_GRADE)
{
	FORMAT_COPY_CONTROL("Default ctor called.");
}

// catching exceptions in member-initalizer list
// (source: https://stackoverflow.com/a/160164)
Bureaucrat::Bureaucrat(std::string name, int grade)
try : name_(name), grade_(grade)
{
	FORMAT_COPY_CONTROL("Parameterized ctor called.");
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
}
catch (const GradeTooHighException &e)
{
	COPY_CONTROL_FAILURE("Parameterized ctor failed: ", e.what());
}
catch (const GradeTooLowException &e)
{
	COPY_CONTROL_FAILURE("Parameterized ctor failed: ", e.what());
}
// Bureaucrat::Bureaucrat(std::string name, int grade)
//		  : name_(name), grade_(grade)
//{
//	FORMAT_COPY_CONTROL("Parameterized ctor called.");
//	if (grade < 1)
//		throw GradeTooHighException();
//	else if (grade > 150)
//		throw GradeTooLowException();
//	else
//		grade_ = grade;
// }

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
	: name_(rhs.name_), grade_(rhs.grade_)
{
	FORMAT_COPY_CONTROL("Copy ctor called.");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		grade_ = rhs.grade_;
	FORMAT_COPY_CONTROL("Assignment operator called.");
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	FORMAT_COPY_CONTROL("Dtor called.");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (1 is the highest grade).");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (150 is the lowest grade).");
}

const std::string Bureaucrat::getName(void) const
{
	return (name_);
}

int Bureaucrat::getGrade(void) const
{
	return (grade_);
}

Bureaucrat &Bureaucrat::operator++()
{
	if (grade_ - 1 < MAX_GRADE)
		throw GradeTooHighException();
	else
	{
		grade_ -= 1;
		return (*this);
	}
}

Bureaucrat &Bureaucrat::operator--()
{
	if (grade_ + 1 > MIN_GRADE)
		throw GradeTooLowException();
	else
	{
		grade_ += 1;
		return (*this);
	}
}

std::ostream &operator<<(std::ostream &out_stream, const Bureaucrat &obj)
{
	out_stream << AC_CYAN << obj.getName() << ", bureaucrat grade " << obj.getGrade() << AC_NORMAL;
	return (out_stream);
}

void Bureaucrat::signForm(const Form &obj)
{
	if (grade_ <= obj.get_sign_grade())
		std::cout << name_ << " signed " << obj.get_name() << std::endl;
	else
		std::cout << name_ << " couldn't sign " << obj.get_name() << " because grade is too low." << std::endl;
}
