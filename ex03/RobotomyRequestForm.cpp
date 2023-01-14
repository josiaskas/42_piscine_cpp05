//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
		: Form("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
		: Form(src), _target(src._target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	(void)src;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned()){
		throw Form::NotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()){
		throw Form::GradeTooLowException();
	}
	std::cout << "** Noise noise noise **" << std::endl;
	if (rand() % 2){
		std::cout << _target << " has been robotomized successfully."
				  << std::endl;
	}
	else{
		std::cout << "Robotomization failed." << std::endl;
	}
}