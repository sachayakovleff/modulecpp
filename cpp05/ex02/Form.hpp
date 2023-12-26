#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm();
    AForm(std::string const name);
    AForm(std::string const name, int gradeToSign, int gradeToExec);
	AForm(AForm& bureaucrat);
	virtual ~AForm();
	AForm& operator=(AForm const& bureaucrat);

    void setGradeToSign(int grade);
    void setGradeToExec(int grade);

    int getGradeToSign();
    int getGradeToExec();
    std::string getName();

    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat& exec) = 0;
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
std::ostream& operator<<(std::ostream& o, const AForm& form);

