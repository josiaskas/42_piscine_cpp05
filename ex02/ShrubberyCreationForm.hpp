//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
# include "Form.hpp"

class ShrubberyCreationForm: public Form {
	public:
		ShrubberyCreationForm();
		explicit ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
		virtual void execute(Bureaucrat const &executor) const;

		class FileNotOpenException: public std::exception {
			public:
				FileNotOpenException() throw();
				FileNotOpenException(FileNotOpenException const &src) throw();
				virtual ~FileNotOpenException() throw();
				FileNotOpenException &operator=(FileNotOpenException const &src) throw();
				virtual const char *what() const throw();
		};
	private:
		static void writeTree(std::ofstream &file) ;
};


#endif //SHRUBBERYCREATIONFORM_H
