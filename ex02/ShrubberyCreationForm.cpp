//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", "default", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form(
		"ShrubberyCreationForm", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
		: Form(src){}

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
		throw Bureaucrat::GradeTooLowException();
	else if (!getIsSigned())
		throw Form::NotSignedException();
	else
	{
		std::ofstream file;
		try {
			file.open(this->getTarget() + "_shrubbery");
			if (!file.is_open())
				throw ShrubberyCreationForm::FileNotOpenException();
			writeTree(file);
			file.close();
		}
		catch (std::exception &e) {
			throw ShrubberyCreationForm::FileNotOpenException();
		}
	}
}

void ShrubberyCreationForm::writeTree(std::ofstream &file)
{
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
}


ShrubberyCreationForm::FileNotOpenException::FileNotOpenException() throw() {}

ShrubberyCreationForm::FileNotOpenException::FileNotOpenException(
		FileNotOpenException const &src) throw()
{
	*this = src;
}

ShrubberyCreationForm::FileNotOpenException::~FileNotOpenException() throw() {}

ShrubberyCreationForm::FileNotOpenException & ShrubberyCreationForm::FileNotOpenException::operator=(
		FileNotOpenException const &src) throw()
{
	(void)src;
	return *this;
}

char const *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("File issues during execution");
}