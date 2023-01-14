/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:35:12 by jkasongo          #+#    #+#             */
/*   Updated: 2023/01/13 14:32:12 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		virtual ~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &src);

		const std::string& getName() const;
		unsigned int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
			GradeTooHighException() throw();
			GradeTooHighException(GradeTooHighException const &src) throw();
			virtual ~GradeTooHighException() throw();
			GradeTooHighException &operator=(GradeTooHighException const &src) throw();
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
			GradeTooLowException() throw();
			GradeTooLowException(GradeTooLowException const &src) throw();
			virtual ~GradeTooLowException() throw();
			GradeTooLowException &operator=(GradeTooLowException const &src) throw();
			virtual const char *what() const throw();
		};

	private:
		std::string const _name;
		unsigned int _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src);

#endif
