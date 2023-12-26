#pragma once

#include "Form.hpp"


class RobotomyRequestForm : public AForm
{
private:
	std::string target;
	class ExecException : public std::exception
	{
	public:

		virtual const char* what() const throw()
		{
			return (" Execution failed");
		}
	};
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
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm& copy);
	RobotomyRequestForm& operator = (RobotomyRequestForm& copy);
	void execute(Bureaucrat& exec);
	void robotomize() const;
};