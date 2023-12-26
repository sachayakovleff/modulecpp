#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form();
    Form(std::string const name);
    Form(std::string const name, int gradeToSign, int gradeToExec);
	Form(Form& bureaucrat);
	~Form();
	Form& operator = (Form const& bureaucrat);

    void setGradeToSign(int grade);
    void setGradeToExec(int grade);

    int getGradeToSign();
    int getGradeToExec();
    std::string getName();

    void beSigned(Bureaucrat &bureaucrat);
private:
	std::string name;
	bool is_signed;
	int	gradeToSign;
	int gradeToExec;
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade is Too High");
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade Too Low");
        }
    };
};
std::ostream& operator<<(std::ostream& o, const Form& form);

