/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:35:21 by jkasongo          #+#    #+#             */
/*   Updated: 2023/01/13 14:32:48 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, unsigned int gradeToSign,
		   unsigned int gradeToExecute) : _name(name),
										  _isSigned(false),
										  _gradeToSign(gradeToSign),
										  _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src.getName()),
							  _isSigned(src.getIsSigned()),
							  _gradeToSign(src.getGradeToSign()),
							  _gradeToExecute(src.getGradeToExecute())
{}

Form::~Form() {}

Form &Form::operator=(Form const &src)
{
	if (this != &src)
	{
		_isSigned = src.getIsSigned();
	}
	return (*this);
}

const std::string &Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

unsigned int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

unsigned int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}

void	Form::signForm(const Bureaucrat &bureaucrat)
{
	try
	{
		beSigned(bureaucrat);
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << bureaucrat.getName() << " couldn’t sign " << this->_name << " because " << e.what() << std::endl;
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute.";
	return (out);
}


