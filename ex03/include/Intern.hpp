/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:28:45 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/10 00:39:06 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_three.h"

#ifndef INTERN_HPP
#define INTERN_HPP

class Intern
{
public:
	Intern();
	Intern(const Intern &rhs);
	Intern &operator=(const Intern &rhs);
	~Intern();

	AForm *makeForm(std::string form_name, std::string form_target);

private:
	AForm *create_shrubbery(std::string target);
	AForm *create_robotomy(std::string target);
	AForm *create_presidential(std::string target);
};

#endif
