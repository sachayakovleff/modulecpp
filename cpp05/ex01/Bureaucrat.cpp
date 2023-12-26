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

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& bureaucrat)
{
    *this = bureaucrat;
    return *this;
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

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
    }
    catch (std::exception& e)
    {
        std::cout << "========EXCEPTION CATCHED========" << std::endl << this->_name << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
    }
}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

std::string Bureaucrat::getName()
{
    return (this->_name);
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& bureaucrat)
{
    o << "Name: " << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade() << std::endl;
    return o;
}
