#pragma once
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;
class RobotomyRequestForm;
class PresidentialPardonForm;
class ShrubberyCreationForm;

class Intern
{
public:
	Intern();
	Intern(Intern &copy);
	~Intern();
	Intern& operator = (Intern& copy);
	AForm* makeForm(std::string name, std::string target);
	class InvalidFormException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("invalid form type");
		}
	};
};
