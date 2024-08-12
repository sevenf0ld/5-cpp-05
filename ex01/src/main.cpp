/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:12:44 by maiman-m          #+#    #+#             */
/*   Updated: 2024/07/25 15:23:42 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_one.h"

int main(void)
{
	/* ============================================================================== */
	/* 								min max form creations							  */
	/* ============================================================================== */
	FORMAT_TEST("MIN MAX FORM CREATIONS");
	Form max("A1", 1, 1);
	Form min("Z150", 150, 150);
	std::cout << max << std::endl
			  << min << std::endl;

	/* ============================================================================== */
	/* 							beyond min max form creations						  */
	/* ============================================================================== */
	FORMAT_TEST("BEYOND MAX FORM CREATION");
	try
	{
		Form beyond_max_sign("B01", 0, 1);
	}
	catch (const Form::GradeTooHighException &e)
	{
		EXCEPTION_MSG(e.what());
	}

	FORMAT_TEST("BEYOND MIN FORM CREATION");
	try
	{
		Form beyond_min_exec("C150151", 150, 151);
	}
	catch (const Form::GradeTooLowException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	std::cout << std::endl;

	/* ============================================================================== */
	/* 								M1025 sign attempts								  */
	/* ============================================================================== */
	FORMAT_TEST("M1025 FORM CREATION");
	Form exm("M1025", 10, 25);
	std::cout << exm << std::endl;

	FORMAT_TEST("BUREAUCRAT OF GRADE 11 SIGNING M1025 ATTEMPT");
	Bureaucrat eleven("Eleven", 11);
	std::cout << eleven << std::endl;
	try
	{
		eleven.signForm(exm);
	}
	catch (const Form::GradeTooLowException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	std::cout << std::endl;

	FORMAT_TEST("VERIFY FORM M1025");
	std::cout << exm << std::endl;

	FORMAT_TEST("BUREAUCRAT OF GRADE 9 SIGNING M1025 ATTEMPT");
	Bureaucrat nine("Nine", 9);
	std::cout << nine << std::endl;
	try
	{
		nine.signForm(exm);
	}
	catch (const Form::GradeTooLowException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	std::cout << std::endl;

	FORMAT_TEST("VERIFY FORM M1025");
	std::cout << exm << std::endl;
}
