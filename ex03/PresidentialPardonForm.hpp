//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#ifndef EX02_PRESIDENTIALPARDONFORM_H
# define EX02_PRESIDENTIALPARDONFORM_H
# include "Form.hpp"

class PresidentialPardonForm: public Form {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
		virtual void execute(Bureaucrat const &executor) const;
		std::string const &getTarget() const;
	private:
		std::string const _target;
};



#endif //EX02_PRESIDENTIALPARDONFORM_H
