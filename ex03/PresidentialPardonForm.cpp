//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(
		"PresidentialPardonForm", "default", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
		: Form("PresidentialPardonForm", target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(
		PresidentialPardonForm const &src) : Form(src)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	(void)src;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw Form::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox."
			  << std::endl;
}

