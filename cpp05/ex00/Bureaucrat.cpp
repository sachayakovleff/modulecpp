#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    this->_name = "What a name";
    this->grade = 1;
}

Bureaucrat::Bureaucrat(std::string const name)
{
    this->_name = name;
    this->grade = 1;
}

Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat)
{
    this->_name = bureaucrat._name;
    this->grade = bureaucrat.grade;
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

void Bureaucrat::addGrade()
{
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade -= 1;
}

void Bureaucrat::removeGrade()
{
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade += 1;
}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

std::string Bureaucrat::getName()
{
    return (this->_name);
}
