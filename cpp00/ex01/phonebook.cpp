#include "phonebook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Creation d'un point" << this << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Destruction de l'objet" << this << std::endl;
}

std::string PhoneBook::GetFirstName(int number)
{
    return (this->contact[number].GetFirstName());
}

void PhoneBook::SetFirstName(std::string str, int number)
{
    this->contact[number].SetFirstName(str);
}

void PhoneBook::AddContact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string secret)
{
    int i;

    i = 7;
    while (i >= 1)
    {
        this->contact[i].SetFirstName(this->contact[i - 1].GetFirstName());
        this->contact[i].SetLastName(this->contact[i - 1].GetLastName());
        this->contact[i].SetNickName(this->contact[i - 1].GetNickName());
        this->contact[i].SetPhoneNumber(this->contact[i - 1].GetPhoneNumber());
        this->contact[i].SetSecret(this->contact[i - 1].GetSecret());
        i--;
    }
    this->contact[i].SetFirstName(firstname);
    this->contact[i].SetLastName(lastname); 
    this->contact[i].SetNickName(nickname); 
    this->contact[i].SetPhoneNumber(phonenumber); 
    this->contact[i].SetSecret(secret); 
}

void    ft_printinfo(std::string getvalue)
{
    int countchar = 0;

    while (countchar < 9 && getvalue[countchar])
    {
        std::cout << getvalue[countchar];
        countchar++;
    }
    if (countchar == 9 && getvalue[countchar] && getvalue[countchar + 1])
        std::cout << ".";
    else if (countchar == 9 && getvalue[countchar] && !getvalue[countchar + 1])
        std::cout << getvalue[countchar];
    else
    {
        while (countchar <= 9)
        {
            std::cout << " ";
            countchar++;
        }
    }
    std::cout << "|";
}

void    PhoneBook::ShowContacts()
{
    int i = 0;

    std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
    while (i < 8)
    {
        if (this->contact->GetFirstName() == "")
            return ;
        std::cout << "|" << i << "         |";
        ft_printinfo(this->contact[i].GetFirstName());
        ft_printinfo(this->contact[i].GetLastName());
        ft_printinfo(this->contact[i].GetNickName());
        i++;
        std::cout << std::endl;
    }
}

void    PhoneBook::ShowContactId(int id)
{
    std::cout << "Firstname: "<< this->contact[id].GetFirstName() << std::endl;
    std::cout << "Lastname: " << this->contact[id].GetLastName() << std::endl;
    std::cout << "Nickname: " << this->contact[id].GetNickName() << std::endl;
    std::cout << "Phone number: " << this->contact[id].GetPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->contact[id].GetSecret() << std::endl;
}

bool    PhoneBook::IsValid(int id)
{
    if (this->contact[id].GetFirstName() == "")
        return (false);
    return true;
}