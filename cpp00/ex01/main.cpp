/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:53:11 by syakovle          #+#    #+#             */
/*   Updated: 2023/09/07 02:55:21 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string.h>
#include <ios>
#include<limits>
#include <stdlib.h>

void    ft_search(PhoneBook *pb)
{
    int id = 0;

    pb->ShowContacts();
    if (!pb->IsValid(0))
        return ;
    std::cout << "Select a contact id to print: ";
    while (true)
    {
        std::cin >> id;
        if (!std::cin.good())
        {
            std::cout << "Exited phonebook with an EOF" << std::endl;
            exit(1);
        }
        if (std::cin.fail() || std::cin.eof() == 1)
        {
            std::cout << "Please select a valid ID:";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue ;
        }
        if (id < 8 && id >= 0 && pb->IsValid(id))
        {
            pb->ShowContactId(id);
            return ;
        }
        else
            std::cout << std::endl << "Please select a valid ID";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    }
}

std::string getarg(std::string line)
{
    std::string res;

    res = "";
    while (true)
    {
        std::cout << line;
        std::cin >> res;
        if (res.empty())
            std::cout << "Must not be empty";
        else
            return (res);
    }
}

void   ft_add(PhoneBook *pb)
{
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string secret;
    
    firstname = getarg("Choose a firstname: ");
    lastname = getarg("Choose a lastname: ");
    nickname = getarg("Choose a nickname: ");
    phonenumber = getarg("Choose a phonenumber: ");
    secret = getarg("Choose a darkest secret: ");
    pb->AddContact(firstname, lastname, nickname, phonenumber, secret);
}

int main()
{
    std::string option;
    PhoneBook   pb = PhoneBook();
    while (true)
    {
        std::cout << "- ADD: save a new contact" << std::endl;
        std::cout << "- SEARCH: search and print contact info" << std::endl;
        std::cout << "- EXIT: quit the program" << std::endl;
        std::cout << "Choose an option: ";
        if (!getline(std::cin, option))
        {
            std::cout << "Exited phonebook with an EOF\n" << std::endl;
            exit (1);
        }
        if (option == "EXIT")
        {
            std::cout << std::endl << "exit" << std::endl;
            break ;
        }
        else if (option == "ADD")
            ft_add(&pb);
        else if (option == "SEARCH")
            ft_search(&pb);
        else
            std::cout << std::endl << "Please choose a valid option" << std::endl;
        std::cout << std::endl << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return (0);
}