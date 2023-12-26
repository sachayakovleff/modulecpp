#include "Form.hpp"

AForm::AForm()
{
	this->is_signed = false;
	this->gradeToExec = 1;
	this->gradeToSign = 1;
	this->name = "";
}

AForm::AForm(std::string const name)
{
	this->is_signed = false;
	this->gradeToExec = 1;
	this->gradeToSign = 1;
	this->name = name;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExec)
{
	this->name = name;
	this->gradeToSign = gradeToSign;
	this->gradeToExec = gradeToExec;
}

AForm::AForm(AForm& bureaucrat)
{
	*this = bureaucrat;
}

AForm::~AForm()
{
}

AForm& AForm::operator=(AForm const& bureaucrat)
{
	*this = bureaucrat;
	return (*this);
}

void AForm::setGradeToSign(int grade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
	else
		this->gradeToSign = grade;
}

void AForm::setGradeToExec(int grade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
	else
		this->gradeToExec = grade;
}

int AForm::getGradeToSign()
{
	return this->gradeToSign;
}

int AForm::getGradeToExec()
{
	return this->gradeToExec;
}

std::string AForm::getName()
{
	return this->name;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->is_signed == true)
		std::cout << bureaucrat.getName() << " couldn't sign " << this->name << " because it is already signed" << std::endl;
	else if (bureaucrat.getGrade() > this->gradeToSign)
		throw (GradeTooLowException());
	else
	{
		std::cout << bureaucrat.getName() << " signed " << this->name << std::endl; this->is_signed = true;
	}
}

std::ostream& operator<<(std::ostream& o, AForm& form)
{
	o << "name: " << form.getName() << " grade to exec: " << form.getGradeToExec() << " grade to sign: " << form.getGradeToSign() << std::endl;
	return (o);
}
