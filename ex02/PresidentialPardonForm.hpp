//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
# include "Form.hpp"

class PresidentialPardonForm: public Form {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
		virtual void execute(Bureaucrat const &executor) const;
};

#endif //PRESIDENTIALPARDONFORM_H
