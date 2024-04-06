/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:12:44 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/06 10:03:41 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	FORMAT_TEST("ORTHODOX CANONICAL FORM TEST");
	Bureaucrat def;
	Bureaucrat copy(def);
	Bureaucrat assign;
	assign = def;
	std::cout << std::endl;

	FORMAT_TEST("MAX AND MIN GRADE TEST");
	Bureaucrat max("max", 1);
	Bureaucrat min("min", 150);
	std::cout << "\t" << max << std::endl << "\t" << min << std::endl;
	std::cout << std::endl;

	FORMAT_TEST("BEYOND MAX AND MIN GRADE TEST");
	try
	{
		Bureaucrat beyond_max("beyond_max", 0);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		;
	}
	try
	{
		Bureaucrat beyond_min("beyond_min", 151);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		;
	}
	std::cout << std::endl;

	FORMAT_TEST("DECREMENT MAX GRADE TEST");
	std::cout << max << " to " << --max << std::endl;
	std::cout << std::endl;

	FORMAT_TEST("INCREMENT AS PER SUBJECT PDF");
	Bureaucrat subject("subject", 3);
	std::cout << subject << " to " << ++subject << std::endl;
	std::cout << std::endl;

	FORMAT_TEST("DECREMENT BEYOND THE MIN GRADE TEST");
	try
	{
		--min;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << min << std::endl;
	std::cout << std::endl;

	++max;
	FORMAT_TEST("INCCREMENT BEYOND THE MAX GRADE TEST");
	try
	{
		++max;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << max << std::endl;
	std::cout << std::endl;
}
