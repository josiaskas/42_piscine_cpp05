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

#ifndef EX02_FORM_H
# define EX02_FORM_H
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	public:
		Form();
		Form(std::string const &name, std::string const &target, unsigned gradeToSign, unsigned int gradeToExecute);
		Form(Form const &src);
		virtual ~Form();
		Form &operator=(Form const &src);

		void beSigned(Bureaucrat const &bureaucrat);
		void signForm(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

		std::string const &getName() const;
		std::string const &getTarget() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;
		bool getIsSigned() const;

		class NotSignedException : public std::exception {
			public:
			NotSignedException() throw();
			NotSignedException(NotSignedException const &src) throw();
			virtual ~NotSignedException() throw();
			NotSignedException &operator=(NotSignedException const &src) throw();
			virtual const char *what() const throw();
		};
		class AlreadySignedException : public std::exception {
			public:
			AlreadySignedException() throw();
			AlreadySignedException(AlreadySignedException const &src) throw();
			virtual ~AlreadySignedException() throw();
			AlreadySignedException &operator=(AlreadySignedException const &src) throw();
			virtual const char *what() const throw();
		};

	private:
		std::string const _name;
		std::string const _target;
		bool _isSigned;
		unsigned int const _gradeToSign;
		unsigned int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, Form const &src);

#endif //EX02_FORM_H
