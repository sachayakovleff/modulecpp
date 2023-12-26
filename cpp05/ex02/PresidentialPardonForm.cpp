#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5)
{
	this->target = "";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy) : AForm("", 25, 5)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& copy)
{
	*this = copy;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToExec())
		std::cout << this->target << ", you have been pardonned by, the one and only, Zaphod Beeblebrox! " << std::endl;
	else
		throw ExecException();
}
