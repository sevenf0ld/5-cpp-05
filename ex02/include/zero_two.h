/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_two.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:15:26 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/09 13:37:57 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEROTWO_HPP
#define ZEROTWO_HPP

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

#define COPY_CONTROL_FAILURE(err_alert, err_msg) std::cerr << AC_RED << err_alert << err_msg << AC_NORMAL << std::endl;
#define FORMAT_TEST(str) std::cout << AC_BOLD << AC_ITALIC << "[ " << str << " ]" << AC_NORMAL << std::endl;
#define EXCEPTION_MSG(err_msg) std::cerr << AC_RED << err_msg << AC_NORMAL << std::endl;

#define MAX_GRADE 1
#define MIN_GRADE 150
#define COLUMN_WIDTH 23

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include <fstream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#endif
