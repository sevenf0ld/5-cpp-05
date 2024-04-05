/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:12:44 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/05 11:42:17 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat def;
	Bureaucrat copy(def);
	Bureaucrat assign;
	assign = def;

	Bureaucrat max("max", 1);
	Bureaucrat min("min", 150);
	Bureaucrat beyond_max("beyond_max", 0);
	Bureaucrat beyond_min("beyond_min", 151);
}
