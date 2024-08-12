/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:12:44 by maiman-m          #+#    #+#             */
/*   Updated: 2024/08/12 18:26:33 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_three.h"

void test_subject_file(void)
{
	Intern someRandomIntern;
	AForm *rrf;

	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	std::cout << std::endl;

	Bureaucrat robotomy_officer("Robotomy Officer", 1);
	robotomy_officer.signForm(*rrf);
	robotomy_officer.executeForm(*rrf);

	delete rrf;
	std::cout << std::endl
			  << std::endl;
}

void test_additional_shrubbery(void)
{
	Intern shrubbery_intern;
	AForm *scf;

	scf = shrubbery_intern.makeForm("ShrubberyCreationForm", "Stardew");
	std::cout << std::endl;

	Bureaucrat shrubbery_officer("Shrubbery Officer", 1);
	shrubbery_officer.signForm(*scf);
	shrubbery_officer.executeForm(*scf);

	delete scf;
	std::cout << std::endl
			  << std::endl;
}

void test_additional_presidential(void)
{
	Intern presidential_intern;
	AForm *ppf;

	ppf = presidential_intern.makeForm("PresidentialPardonForm", "Valley");
	std::cout << std::endl;

	Bureaucrat presidential_officer("Presidential Officer", 1);
	presidential_officer.signForm(*ppf);
	presidential_officer.executeForm(*ppf);

	delete ppf;
	std::cout << std::endl
			  << std::endl;
}

void test_invalid(void)
{
	Intern intern;
	AForm *invalid;

	(void)invalid;

	try
	{
		invalid = intern.makeForm("non-existent", "oblivion");
	}
	catch (const Intern::InvalidFormException &e)
	{
		EXCEPTION_MSG(e.what());
	}
	std::cout << std::endl;
}

int main(void)
{
	test_subject_file();
	test_additional_shrubbery();
	test_additional_presidential();
	test_invalid();
}
