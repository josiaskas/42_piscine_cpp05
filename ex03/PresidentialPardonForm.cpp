//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
		: Form("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(
		PresidentialPardonForm const &src) : Form(src), _target(src._target)
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
		throw Form::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox."
			  << std::endl;
}

std::string const &PresidentialPardonForm::getTarget() const
{
	return _target;
}

