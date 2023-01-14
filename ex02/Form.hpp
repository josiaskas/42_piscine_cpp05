/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:35:21 by jkasongo          #+#    #+#             */
/*   Updated: 2023/01/13 14:32:48 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_FORM_H
# define EX01_FORM_H
# include <iostream>
# include "Bureaucrat.hpp"

class Form {
	public:
		Form(std::string const &name, unsigned gradeToSign, unsigned int gradeToExecute);
		Form(Form const &src);
		~Form();
		Form &operator=(Form const &src);
		std::string const &getName() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat const &bureaucrat);
		void signForm(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const _name;
		bool _isSigned;
		unsigned int const _gradeToSign;
		unsigned int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, Form const &src);

#endif //EX01_FORM_H
