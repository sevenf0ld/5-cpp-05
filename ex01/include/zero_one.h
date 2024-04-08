/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_one.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:15:26 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/08 10:50:23 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEROONE_HPP
#define ZEROONE_HPP

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
#define COPY_CONTROL_FAILURE(err_alert, err_msg) std::cerr << AC_RED << err_alert << err_msg << AC_NORMAL << std::endl;
#define FORMAT_TEST(str) std::cout << AC_BOLD << AC_ITALIC << "[ " << str << " ]" << AC_NORMAL << std::endl;

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#endif
