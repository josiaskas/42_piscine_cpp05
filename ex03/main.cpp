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

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat b("John", 1);
		std::cout << b << std::endl;

		ShrubberyCreationForm f("home");
		std::cout << f << std::endl;

		//try to execute a non-signed form
		b.executeForm(f);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Greta", 2);
		std::cout << b << std::endl;

		ShrubberyCreationForm f("garden");
		std::cout << f << std::endl;

		//sign the form
		f.signForm(b);

		b.executeForm(f);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Joseph", 2);
		std::cout << b << std::endl;

		RobotomyRequestForm f("Babar");
		std::cout << f << std::endl;

		//sign the form
		f.signForm(b);

		b.executeForm(f);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Elon", 2);
		std::cout << b << std::endl;

		PresidentialPardonForm f("Kanye");
		std::cout << f << std::endl;

		//sign the form
		f.signForm(b);

		b.executeForm(f);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//	try {
	//		Bureaucrat b("Michael", 2);
	//		std::cout << b << std::endl;
	//
	//		// bad files
	//		ShrubberyCreationForm f("../../../../../../../../../sss/");
	//		std::cout << f << std::endl;
	//
	//		//sign the form
	//		f.signForm(b);
	//
	//		b.executeForm(f);
	//	}
	//	catch (std::exception &e)
	//	{
	//		std::cerr << e.what() << std::endl;
	//	}
	return (0);
}
