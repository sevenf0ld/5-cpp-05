/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:12:44 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/09 15:56:22 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_two.h"

void test_shrubbery(void)
{
	FORMAT_TEST("SHRUBBERY TEST");

	ShrubberyCreationForm shrubbery("Shrubbery");
	std::cout << shrubbery << std::endl;
	std::cout << std::endl;

	FORMAT_TEST("BUREAUCRAT OF GRADE 144 SHRUBBERY SIGN AND EXECUTE ATTEMPT");
	Bureaucrat person("ONE-FOUR-FOUR", 144);
	std::cout << person << std::endl;

	try
	{
		person.signForm(shrubbery);
		person.executeForm(shrubbery);
	}
	catch (AForm::GradeTooLowException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	catch (AForm::FormUnsignedException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	std::cout << std::endl;

	FORMAT_TEST("VERIFY SHRUBBERY FORM");
	std::cout << shrubbery << std::endl;
}

void test_robotomy(void)
{
	FORMAT_TEST("ROBOTOMY TEST");

	RobotomyRequestForm robotomy("Robotomy");
	std::cout << robotomy << std::endl;
	std::cout << std::endl;

	FORMAT_TEST("BUREAUCRAT OF GRADE 77 ROBOTOMY SIGN AND EXECUTE ATTEMPT");
	Bureaucrat person("SEVEN-SEVEN", 77);
	std::cout << person << std::endl;

	try
	{
		person.signForm(robotomy);
	}
	catch (AForm::GradeTooLowException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	std::cout << std::endl;

	FORMAT_TEST("VERIFY ROBOTOMY FORM");
	std::cout << robotomy << std::endl;

	try
	{
		person.executeForm(robotomy);
	}
	catch (AForm::FormUnsignedException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	catch (AForm::GradeTooLowException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	std::cout << std::endl;

	FORMAT_TEST("VERIFY ROBOTOMY FORM");
	std::cout << robotomy << std::endl;
}

void test_presidential(void)
{
	FORMAT_TEST("PRESIDENTIAL TEST");

	PresidentialPardonForm robotomy("Robotomy");
	std::cout << robotomy << std::endl;
	std::cout << std::endl;

	FORMAT_TEST("BUREAUCRAT OF GRADE 77 ROBOTOMY SIGN AND EXECUTE ATTEMPT");
	Bureaucrat person("SEVEN-SEVEN", 77);
	std::cout << person << std::endl;

	try
	{
		person.signForm(robotomy);
	}
	catch (AForm::GradeTooLowException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	std::cout << std::endl;

	FORMAT_TEST("VERIFY ROBOTOMY FORM");
	std::cout << robotomy << std::endl;

	try
	{
		person.executeForm(robotomy);
	}
	catch (AForm::FormUnsignedException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	catch (AForm::GradeTooLowException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	std::cout << std::endl;

	FORMAT_TEST("VERIFY ROBOTOMY FORM");
	std::cout << robotomy << std::endl;
}

int main(void)
{
	test_shrubbery();
	std::cout << std::endl;
	test_robotomy();
	std::cout << std::endl;
	test_presidential();
}
