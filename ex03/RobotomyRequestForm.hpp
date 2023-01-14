//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#ifndef EX02_ROBOTOMYREQUESTFORM_H
# define EX02_ROBOTOMYREQUESTFORM_H
# include "Form.hpp"

class RobotomyRequestForm: public Form {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
		virtual void execute(Bureaucrat const &executor) const;
		std::string const &getTarget() const;
	private:
		std::string const _target;
};


#endif //EX02_ROBOTOMYREQUESTFORM_H
