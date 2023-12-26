#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137)
{
	this->target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
	this->target = name;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy) : AForm(copy.getName(), 145, 137)
{
	this->target = copy.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm& copy)
{
	*this = copy;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat& exec)
{
	if (exec.getGrade() > 137)
	{
		throw (ExecException());
	}
	else
		drawtree(exec.getName());
}

void ShrubberyCreationForm::drawtree(std::string target)
{
	std::string name;
	name = target;
	name += "_shrubbery";
	std::ofstream output(name.c_str());
	if (!output.good())
		throw(ExecException());
	output << "               ,@@@@@@@, " << std::endl;
	output << "       ,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl;
	output << "    ,&&&&&&&&,@@@@@/@@@@@@,8888\\88/8o " << std::endl;
	output << "   ,&& &&&&&&&,@@@  @@@/@@@88  88888/88' " << std::endl;
	output << "   &&&&&&&/&&&&@\\@@/ /@@@88888\\88888'" << std::endl;
	output << "    &&&&/ %&&&&&@@\\ V /@@' `88\\8 `/88' " << std::endl;
	output << "    `&&\\ ` /&&'    |.|        \\ '|8' " << std::endl;
	output << "        |o|        | |         | | " << std::endl;
	output << "        |.|        | |         | | " << std::endl;
	output << "     \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	output.close();
	std::cout << "Shrubberysation finished" << std::endl;
}

