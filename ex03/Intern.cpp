//
// Created by Josias Mutshaila kasongo on 2023-01-14.
//

#include "Intern.h"

Intern::Intern(){
	_formNames[0] = "robotomy request";
	_formNames[1] = "presidential pardon";
	_formNames[2] = "shrubbery creation";
}

Intern::Intern(Intern const &src)
{
	_formNames[0] = src._formNames[0];
	_formNames[1] = src._formNames[1];
	_formNames[2] = src._formNames[2];
}

Intern::~Intern(){}

Intern &Intern::operator=(Intern const &src)
{
	if (this != &src)
	{
		_formNames[0] = src._formNames[0];
		_formNames[1] = src._formNames[1];
		_formNames[2] = src._formNames[2];
	}
	return *this;
}

Form *Intern::makeForm(std::string const &formName, std::string const &target)
{
	for (int i = 0; i < FORM_COUNT; i++)
	{
		if (formName == _formNames[i])
		{
			switch (i)
			{
				case 0:
					return createRobotomyRequestForm(target);
				case 1:
					return createPresidentialPardonForm(target);
				case 2:
					return createShrubberyCreationForm(target);
				default:
					throw Intern::FormNotFoundException();
			}
		}
	}
	throw Intern::FormNotFoundException();
	return NULL;  // never reached
}

Form *Intern::createRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::createPresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::createShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

Intern::FormNotFoundException::FormNotFoundException() throw() {}

Intern::FormNotFoundException::FormNotFoundException(
		FormNotFoundException const &src) throw()
{
	(void)src;
}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}

Intern::FormNotFoundException &Intern::FormNotFoundException::operator=(
		FormNotFoundException const &src) throw()
{
	(void)src;
	return *this;
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}
