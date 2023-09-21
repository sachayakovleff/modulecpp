/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:41:57 by syakovle          #+#    #+#             */
/*   Updated: 2023/08/27 20:34:21 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
{
    std::cout << "Creation d'un contact" << this << std::endl;
}

Contact::~Contact()
{
    std::cout << "Destruction d'un contact" << this << std::endl;
}

void    Contact::SetFirstName(std::string str)
{
    this->firstname = str;
}

void    Contact::SetLastName(std::string str)
{
    this->lastname = str;
}

void    Contact::SetNickName(std::string str)
{
    this->nickname = str;
}

void    Contact::SetPhoneNumber(std::string str)
{
    this->phonenumber = str;
}

void    Contact::SetSecret(std::string str)
{
    this->secret = str;
}

std::string Contact::GetFirstName(void)
{
    return (this->firstname);
}

std::string Contact::GetLastName(void)
{
    return (this->lastname);
}

std::string Contact::GetNickName(void)
{
    return (this->nickname);
}

std::string Contact::GetPhoneNumber(void)
{
    return (this->phonenumber);
}

std::string Contact::GetSecret(void)
{
    return (this->secret);
}