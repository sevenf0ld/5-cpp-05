/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:15:07 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/08 11:05:43 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_one.h"

class Form
{
public:
	Form(std::string name, int sign_grade, int exec_grade);
	Form(const Form &rhs);
	Form &operator=(const Form &rhs);
	~Form();

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

	const std::string get_name(void) const;
	bool get_sign_status(void) const;
	int get_sign_grade(void) const;
	int get_exec_grade(void) const;

	void beSigned(const Bureaucrat &obj);

private:
	Form();

	const std::string name_;
	bool is_signed_;
	const int sign_grade_;
	const int exec_grade_;
};

std::ostream &operator<<(std::ostream &out_stream, const Form &obj);
