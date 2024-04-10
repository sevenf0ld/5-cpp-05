/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:15:07 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/10 19:01:05 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_two.h"

#ifndef AFORM_HPP
#define AFORM_HPP

class AForm
{
public:
	AForm();
	AForm(std::string name, int sign, int exec, std::string target);
	AForm(const AForm &rhs);
	AForm &operator=(const AForm &rhs);
	virtual ~AForm();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormUnsignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	const std::string get_name(void) const;
	bool get_sign_status(void) const;
	int get_sign_grade(void) const;
	int get_exec_grade(void) const;
	const std::string get_target(void) const;

	void beSigned(Bureaucrat &obj);
	virtual void execute(Bureaucrat const &executor) const = 0;

private:
	const std::string name_;
	bool is_signed_;
	const int sign_grade_;
	const int exec_grade_;
	const std::string target_;
};

std::ostream &operator<<(std::ostream &out_stream, const AForm &obj);

#endif
