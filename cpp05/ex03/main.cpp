#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Bureaucrat b1("user1");
    Bureaucrat b2("user2");
    Bureaucrat b3("user3");
    Bureaucrat b4("user4");
    Bureaucrat b5("user5");

    std::cout << "========INITIALIZATION========" << std::endl;
    std::cout << b1.getName() << ": " << b1.getGrade() << std::endl;
    std::cout << b2.getName() << ": " << b2.getGrade() << std::endl;
    std::cout << b3.getName() << ": " << b3.getGrade() << std::endl;
    std::cout << b4.getName() << ": " << b4.getGrade() << std::endl;
    std::cout << b5.getName() << ": " << b5.getGrade() << std::endl << std::endl;

    std::cout << "======TRYING INITIALIZE=======" << std::endl;
    try
    {
        b1.setGrade(140);
        std::cout << b1.getName() << ": " << b1.getGrade() << std::endl;
        b3.setGrade(5);
        std::cout << b3.getName() << ": " << b3.getGrade() << std::endl;
        b2.setGrade(160);
        std::cout << b2.getName() << ": " << b2.getGrade() << std::endl;
        b4.setGrade(0);
        std::cout << b4.getName() << ": " << b4.getGrade() << std::endl;
        b5.setGrade(-5);
        std::cout << b5.getName() << ": " << b5.getGrade() << std::endl << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "========EXCEPTION CATCHED========" << std::endl << e.what() << std::endl << std::endl;
    }
    std::cout << "======TRYING ADD GRADE=======" << std::endl;
    try
    {
        b3.addGrade();
        std::cout << b3.getName() << ": " << b3.getGrade() << std::endl;
        b3.addGrade();
        std::cout << b3.getName() << ": " << b3.getGrade() << std::endl;
        b3.addGrade();
        std::cout << b3.getName() << ": " << b3.getGrade() << std::endl;
        b3.addGrade();
        std::cout << b3.getName() << ": " << b3.getGrade() << std::endl;
        b3.addGrade();
        std::cout << b3.getName() << ": " << b3.getGrade() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "========EXCEPTION CATCHED========" << std::endl << e.what() << std::endl << std::endl;
    }
    {std::cout << "=======RESULT=======" << std::endl;
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    std::cout << b4 << std::endl;
    std::cout << b5 << std::endl;}
    
    ShrubberyCreationForm s1("ShrubberyCreationForm");
    PresidentialPardonForm p1("PresidentialPardonForm");
    RobotomyRequestForm r1("RobotomyRequestForm");
    
    try
    {
        b1.setGrade(1);
        b1.executeForm(r1);
    }
    catch(std::exception &e)
    {
        std::cout << "========EXCEPTION CATCHED========" << std::endl << e.what() << std::endl << std::endl;
    }
    AForm* i;
    Intern intern;

    i = intern.makeForm("shrubbery creation", "hi");
    i->execute(b1);
    /*AForm f1("f1", 10, 5);
    try
    {
        b1.setGrade(150);
        std::cout << "=======TRYING TO SIGN FORM========" << std::endl;
        b1.signForm(f1);
    }
    catch(std::exception& e)
    {
        std::cout << "========EXCEPTION CATCHED========" << std::endl << e.what() << std::endl << std::endl;
    }
    */
}
