/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:32:03 by jkasongo          #+#    #+#             */
/*   Updated: 2022/12/23 09:44:38 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Form f("Constitution", 0, 0);
		std::cerr << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f("Bad Law", 151, 151);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("John", 1);
		Bureaucrat b("Joseph", 23);
		Form f("Flight authorization", 1, 1);
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		f.signForm(b);
		std::cout << "calling the manager" << std::endl;
		std::cout << a << std::endl;
		f.signForm(a);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
