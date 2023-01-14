//
// Created by Josias Mutshaila kasongo on 2023-01-14.
//

#ifndef EX03_INTERN_H
# define EX03_INTERN_H
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# define FORM_COUNT 3

class Intern {
	public:
		Intern();
		Intern(Intern const &src);
		virtual ~Intern();
		Intern &operator=(Intern const &src);
		Form *makeForm(std::string const &formName, std::string const &target);

		class FormNotFoundException: public std::exception {
			public:
				FormNotFoundException() throw();
				FormNotFoundException(FormNotFoundException const &src) throw();
				virtual ~FormNotFoundException() throw();
				FormNotFoundException &operator=(FormNotFoundException const &src) throw();
				virtual const char *what() const throw();
		};
	private:
		std::string _formNames[FORM_COUNT];
		Form *createRobotomyRequestForm(std::string const &target);
		Form *createPresidentialPardonForm(std::string const &target);
		Form *createShrubberyCreationForm(std::string const &target);
};


#endif //EX03_INTERN_H
