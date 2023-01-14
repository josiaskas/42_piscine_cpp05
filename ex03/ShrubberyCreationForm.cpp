//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form(
		"ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
		: Form(src), _target(src._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (this != &src)
	{
		Form::operator=(src);
	}
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (!getIsSigned())
		throw Form::NotSignedException();
	else
	{
		std::ofstream file;
		try {
			file.open(_target + "_shrubbery");
			if (!file.is_open())
				throw ShrubberyCreationForm::FileNotOpenException();
			writeTree(file);
		}
		catch (std::exception &e) {
			throw ShrubberyCreationForm::FileNotOpenException();
		}
	}
}

char const *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("File issues during execution");
}

void ShrubberyCreationForm::writeTree(std::ofstream &file) const
{
	file.open(_target + "_shrubbery");
	file << "         v" << std::endl;
	file << "        >X<" << std::endl;
	file << "         A" << std::endl;
	file << "        d$b" << std::endl;
	file << "      .d\\$$b." << std::endl;
	file << "    .d$i$$\\$$b." << std::endl;
	file << "   .d$$@b\\$$$ib." << std::endl;
	file << "  .d$$i$$b\\$$$$b." << std::endl;
	file << "  d$$$$@$b\\$$$$$i" << std::endl;
	file << " d$$$$$$i$$\\$$$$$" << std::endl;
	file << "d$$$$$$$$@$b\\$$$$b" << std::endl;
	file << "$$$$$$$$$$i$$\\$$$$" << std::endl;
	file << "$$$$$$$$$$$@b\\$$$b" << std::endl;
	file << "$$$$$$$$$$$$i$$\\$$" << std::endl;
	file << "$$$$$$$$$$$$$@b\\$$" << std::endl;
	file << "$$$$$$$$$$$$$$i$$\\" << std::endl;
	file << "$$$$$$$$$$$$$$$@b\\" << std::endl;
	file << "$$$$$$$$$$$$$$$$i$" << std::endl;
	file << "$$$$$$$$$$$$$$$$$@" << std::endl;
	file << "$$$$$$$$$$$$$$$$$$" << std::endl;
	file.close();
}

std::string const &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

