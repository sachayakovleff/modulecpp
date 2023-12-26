#include "Form.hpp"

Form::Form()
{
	this->is_signed = false;
	this->gradeToExec = 1;
	this->gradeToSign = 1;
	this->name = "";
}

Form::Form(std::string const name)
{
	this->is_signed = false;
	this->gradeToExec = 1;
	this->gradeToSign = 1;
	this->name = name;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExec)
{
	this->name = name;
	this->gradeToSign = gradeToSign;
	this->gradeToExec = gradeToExec;
}

Form::Form(Form& bureaucrat)
{
	*this = bureaucrat;
}

Form::~Form()
{
}

Form& Form::operator=(Form const& bureaucrat)
{
	*this = bureaucrat;
	return (*this);
}

void Form::setGradeToSign(int grade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
	else
		this->gradeToSign = grade;
}

void Form::setGradeToExec(int grade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
	else
		this->gradeToExec = grade;
}

int Form::getGradeToSign()
{
	return this->gradeToSign;
}

int Form::getGradeToExec()
{
	return this->gradeToExec;
}

std::string Form::getName()
{
	return this->name;
}

void Form::beSigned(Bureaucrat& bureaucrat)
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

std::ostream& operator<<(std::ostream& o, Form& form)
{
	o << "name: " << form.getName() << " grade to exec: " << form.getGradeToExec() << " grade to sign: " << form.getGradeToSign() << std::endl;
	return (o);
}
