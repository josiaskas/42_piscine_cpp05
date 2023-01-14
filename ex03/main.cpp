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
#include "Intern.h"

int main()
{
	try
	{
		Intern someRandomIntern;
		Form *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender2");
		std::cout << *rrf << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender3");
		std::cout << *rrf << std::endl;
		delete rrf;

		rrf = someRandomIntern.makeForm("fake name", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

