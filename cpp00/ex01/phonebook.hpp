/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:11:20 by syakovle          #+#    #+#             */
/*   Updated: 2023/08/27 22:55:46 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "contact.hpp"


class   PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        std::string GetFirstName(int number);
        void SetFirstName(std::string str, int number);
        void AddContact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string secret);
        void ShowContacts();
        void ShowContactId(int id);
        bool IsValid(int id);
    
    private:
        Contact contact[8];
};

#endif