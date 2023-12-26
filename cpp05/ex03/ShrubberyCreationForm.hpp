#pragma once

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"


class ShrubberyCreationForm : public AForm
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
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm& copy);
	ShrubberyCreationForm & operator = (ShrubberyCreationForm& copy);

	void execute(Bureaucrat& exec);
	void drawtree(std::string target);
};