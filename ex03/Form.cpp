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

Form::Form(): _name("default"), _target("default_target"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
}

Form::Form(std::string const &name, std::string const &target, unsigned int gradeToSign,
		   unsigned int gradeToExecute) : _name(name),
		   								  _target(target),
										  _isSigned(false),
										  _gradeToSign(gradeToSign),
										  _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src.getName()),
							  _target(src.getTarget()),
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
		throw Bureaucrat::GradeTooLowException();
	else if (this->_isSigned)
		throw Form::AlreadySignedException();
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
		std::cerr << bureaucrat.getName() << " couldn’t sign " << this->_name << " because " << e.what() << std::endl;
	}
}

std::string const &Form::getTarget() const
{
	return (_target);
}


// NotSignedException
Form::NotSignedException::NotSignedException() throw() {}

Form::NotSignedException::NotSignedException(NotSignedException const &src) throw()
{
	*this = src;
}

Form::NotSignedException::~NotSignedException() throw() {}

Form::NotSignedException &Form::NotSignedException::operator=(NotSignedException const &src) throw()
{
	(void)src;
	return (*this);
}

const char *Form::NotSignedException::what() const throw()
{
	return ("Form not signed");
}

// Already signed exception
Form::AlreadySignedException::AlreadySignedException() throw(){}

Form::AlreadySignedException::AlreadySignedException(AlreadySignedException const &src) throw()
{
	*this = src;
}

Form::AlreadySignedException::~AlreadySignedException() throw() {}

Form::AlreadySignedException &Form::AlreadySignedException::operator=(AlreadySignedException const &src) throw()
{
	(void)src;
	return (*this);
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("Form already signed");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getIsSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign()
		<< " to sign and grade " << form.getGradeToExecute() << " to execute.";
	return (out);
}