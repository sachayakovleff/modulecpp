#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("user1");
    Bureaucrat b2("user2");
    Bureaucrat b3("user3");
    Bureaucrat b4("user4");
    Bureaucrat b5("user5");

    std::cout << "========INITIALIZATION========" << std::endl;
    std::cout << b1.getName() << ": "<< b1.getGrade() << std::endl;
    std::cout << b2.getName() << ": "<< b2.getGrade() << std::endl;
    std::cout << b3.getName() << ": "<< b3.getGrade() << std::endl;
    std::cout << b4.getName() << ": "<< b4.getGrade() << std::endl;
    std::cout << b5.getName() << ": "<< b5.getGrade() << std::endl << std::endl;

    std::cout << "======TRYING INITIALIZE=======" << std::endl;
    try
    {
        b1.setGrade(140);
        std::cout << b1.getName() << ": "<< b1.getGrade() << std::endl;
        b3.setGrade(5);
        std::cout << b3.getName() << ": "<< b3.getGrade() << std::endl;
        b2.setGrade(160);
        std::cout << b2.getName() << ": "<< b2.getGrade() << std::endl;
        b4.setGrade(0);
        std::cout << b4.getName() << ": "<< b4.getGrade() << std::endl;
        b5.setGrade(-5);
        std::cout << b5.getName() << ": "<< b5.getGrade() << std::endl << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "========EXCEPTION CATCHED========" << std::endl << e.what() << std::endl << std::endl;
    }
    std::cout << "======TRYING ADD GRADE=======" << std::endl;
    try
    {
        b3.addGrade();
        std::cout << b3.getName() << ": "<< b3.getGrade() << std::endl;
        b3.addGrade();
        std::cout << b3.getName() << ": "<< b3.getGrade() << std::endl;
        b3.addGrade();
        std::cout << b3.getName() << ": "<< b3.getGrade() << std::endl;
        b3.addGrade();
        std::cout << b3.getName() << ": "<< b3.getGrade() << std::endl;
        b3.addGrade();
        std::cout << b3.getName() << ": "<< b3.getGrade() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "========EXCEPTION CATCHED========" << std::endl << e.what() << std::endl << std::endl;
    }
    std::cout << "=======RESULT=======" << std::endl;    
    std::cout << b1.getName() << ": "<< b1.getGrade() << std::endl;
    std::cout << b2.getName() << ": "<< b2.getGrade() << std::endl;
    std::cout << b3.getName() << ": "<< b3.getGrade() << std::endl;
    std::cout << b4.getName() << ": "<< b4.getGrade() << std::endl;
    std::cout << b5.getName() << ": "<< b5.getGrade() << std::endl;
}
