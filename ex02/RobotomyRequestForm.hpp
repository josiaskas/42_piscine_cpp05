//
// Created by Josias Mutshaila kasongo on 2023-01-13.
//

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
# include "Form.hpp"

class RobotomyRequestForm: public Form {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
		virtual void execute(Bureaucrat const &executor) const;
};


#endif //ROBOTOMYREQUESTFORM_H
