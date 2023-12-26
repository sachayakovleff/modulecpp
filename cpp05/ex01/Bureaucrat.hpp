#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string _name;
        int grade;
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade is Too High");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade Too Low");
                }
        };
    public:
        Bureaucrat();
		Bureaucrat(std::string const name);
		Bureaucrat(Bureaucrat &bureaucrat);
		~Bureaucrat();
        Bureaucrat & operator = (Bureaucrat const &bureaucrat);
        void setGrade(int grade);
        void addGrade();
        void removeGrade();
        void signForm(Form &form);
        int getGrade();
        std::string getName();
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& bureaucrat);

#endif
