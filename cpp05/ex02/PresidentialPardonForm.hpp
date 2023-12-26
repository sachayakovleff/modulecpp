#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public AForm
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
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm& copy);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator = (PresidentialPardonForm& copy);
	void execute(Bureaucrat &bureaucrat);
};