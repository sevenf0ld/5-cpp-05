/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:11:15 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/09 23:14:45 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_three.h"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	// error: is private within this context

	// error: passing ‘const std::string’ {aka ‘const std::__cxx11::basic_string<char>’} as ‘this’ argument discards qualifiers [-fpermissive]
	//name_ = "ShrubberyCreationForm";
	// assignment of read-only members
	//sign_grade_ = 145;
	//exec_grade_ = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
					 : AForm("ShruberryCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
					 : AForm(rhs)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	AForm::operator=(rhs);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= get_exec_grade() && get_sign_status())
	{
		// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
		std::string	outfile(get_target());
		outfile = outfile.append("_shrubbery");
		std::ofstream	output_file(outfile.c_str());
		if (!output_file)
			std::cerr << "Failed to create " << outfile << "." << std::endl;
		output_file << "	      .         " << std::endl
					<< "	   __/ \\__      " << std::endl
					<< "	   \\     /      " << std::endl
					<< "	   /.'o'.\\      " << std::endl
					<< "	    .o.'.       " << std::endl
					<< "	   .'.'o'.      " << std::endl
					<< "	  o'.o.'.o.     " << std::endl
					<< "	 .'.o.'.'.o.    " << std::endl
					<< "	.o.'.o.'.o.'.   " << std::endl
					<< "	   [_____]      " << std::endl
					<< "	    \\___/       " << std::endl;
		output_file.close();
	}
	else if (!get_sign_status())
		throw FormUnsignedException();
	else if (executor.getGrade() > get_exec_grade())
		throw GradeTooLowException();
}
