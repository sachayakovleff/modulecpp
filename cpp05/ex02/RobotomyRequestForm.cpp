#include "RobotomyRequestForm.hpp"
#include "cstdlib"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45)
{
	this->target = "";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy) : AForm("", 72, 45)
{
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& copy)
{
	*this = copy;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat& exec)
{
	if (exec.getGrade() <= this->getGradeToExec())
		robotomize();
	else
		throw (ExecException());
}

void RobotomyRequestForm::robotomize() const
{
	srand(time(NULL));
	if (rand() % 2 == 0)
	{
		std::cout << "Beep.. " << this->target << " has been successfully robotomized" << std::endl;
	}
	else
	{
		std::cout << "Robotomization failed" << std::endl;
	}
}
