/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:54:17 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/05 11:35:36 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"
#define AC_BOLD "\033[1m"
#define AC_ITALIC "\033[3m"

#define FORMAT_COPY_CONTROL(str) std::cout << AC_BOLD << str << AC_NORMAL << std::endl;
#define COPY_CONTROL_FAILURE(err_alert, err_msg) std::cerr << AC_RED << err_alert << err_msg << std::endl;

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	// exception classes
	// (source: https://stackoverflow.com/q/23069183)
	// what member function
	// https://en.cppreference.com/w/cpp/error/exception/what
	// https://eecs280staff.github.io/notes/22_Exceptions.html#:~:text=the%20what()%20member%20function%20is%20a%20virtual%20function
	class GradeTooHighException : public std::exception
	{
	public:
		// override specifier only allowed in c++11
		virtual const char *what() const throw ();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char *what() const throw ();
	};

	// accessors / getters
	const std::string getName(void) const;
	int getGrade(void) const;

	// prefix
	Bureaucrat &operator++();
	Bureaucrat &operator--();

private:
	const std::string name_;
	int grade_;
};

std::ostream &operator<<(std::ostream &out_stream, const Bureaucrat &rhs);

// using an invalid grade must throw an exception: either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
// grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give a grade 2 to the bureaucrat.

#endif
