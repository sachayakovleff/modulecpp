#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern& copy)
{
	(void)copy;
}


Intern::~Intern()
{
}

Intern& Intern::operator=(Intern& copy)
{
	(void) copy;
	return *this;
}

AForm* new_Robotomy(std::string target)
{
	AForm* f = new RobotomyRequestForm(target);
	return (f);
}

AForm* new_President(std::string target)
{
	AForm* f = new PresidentialPardonForm(target);
	return (f);
}

AForm* new_Shrub(std::string target)
{
	AForm* f = new ShrubberyCreationForm(target);
	return (f);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm* (*fct[3])(std::string target) = { new_Robotomy, new_President, new_Shrub };
	std::string names[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	AForm *form = NULL;

	for (int i = 0; i < 3; i++)
	{
		std::cout << names[i] << name << std::endl;
		if (names[i] == name)
		{
			form = (fct)[i](target);
			if (form != NULL)
			{
				std::cout << "Intern creates " << name << std::endl;
				return (form);
			}
		}
	}
	throw (InvalidFormException());
}
