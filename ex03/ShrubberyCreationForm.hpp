//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#ifndef EX02_SHRUBBERYCREATIONFORM_H
# define EX02_SHRUBBERYCREATIONFORM_H
# include "Form.hpp"

class ShrubberyCreationForm: public Form {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
		virtual void execute(Bureaucrat const &executor) const;
		std::string const &getTarget() const;

		class FileNotOpenException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		std::string const _target;
		void writeTree(std::ofstream &file) const;
};


#endif //EX02_SHRUBBERYCREATIONFORM_H
