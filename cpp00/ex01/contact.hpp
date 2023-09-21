#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>


class   Contact
{
    public:
        Contact();
        ~Contact();
        void SetFirstName(std::string str);
        void SetLastName(std::string str);
        void SetNickName(std::string str);
        void SetPhoneNumber(std::string str);
        void SetSecret(std::string str);
        std::string GetFirstName(void);
        std::string GetLastName(void);
        std::string GetNickName(void);
        std::string GetPhoneNumber(void);
        std::string GetSecret(void);
    
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string secret;
};

#endif