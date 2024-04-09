/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:54:17 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/09 10:45:30 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_two.h"

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class AForm;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

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

	const std::string getName(void) const;
	int getGrade(void) const;

	Bureaucrat &operator++();
	Bureaucrat &operator--();

	void signForm(AForm &obj);

private:
	const std::string name_;
	int grade_;
};

std::ostream &operator<<(std::ostream &out_stream, const Bureaucrat &obj);

#endif
