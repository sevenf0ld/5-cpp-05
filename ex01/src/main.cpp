/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:12:44 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/08 11:41:03 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_one.h"

int main(void)
{
	FORMAT_TEST("FORM CREATIONS");
	Form max("A1");
	Form min("Z150");
	std::cout << max << std::endl
			  << min << std::endl;
	std::cout << std::endl;

	FORMAT_TEST("BUREAUCRAT OF GRADE 11 SIGN ATTEMPT");
	Bureaucrat eleven("Eleven", 11);
	std::cout << eleven << std::endl;
	try
	{
		eleven.signForm(max);
	}
	catch (Form::GradeTooLowException &e)
	{
		;
	}
	std::cout << std::endl;

	FORMAT_TEST("VERIFY FORM A1");
	std::cout << max << std::endl;

	FORMAT_TEST("BUREAUCRAT OF GRADE 9");
	Bureaucrat nine("Nine", 9);
	std::cout << nine << std::endl;
	try
	{
		nine.signForm(max);
	}
	catch (Form::GradeTooLowException &e)
	{
		;
	}
	std::cout << std::endl;

	FORMAT_TEST("VERIFY FORM A1");
	std::cout << max<< std::endl;
}
