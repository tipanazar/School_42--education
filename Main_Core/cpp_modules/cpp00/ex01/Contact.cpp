#include "Contact.hpp"

std::string Contact::getDarkestSecret() { return _darkestSecret; }
std::string Contact::getFirstName() { return _firstName; }
std::string Contact::getLastName() { return _lastName; }
std::string Contact::getNickname() { return _nickname; }
std::string Contact::getPhoneNumber() { return _phoneNumber; }

void Contact::setContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}

void Contact::printContact()
{
    std::cout << "First name: " << _firstName << std::endl;
    std::cout << "Last name:" << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone number: " << _phoneNumber << std::endl;
    std::cout << "Darkest secret: " << _darkestSecret << std::endl;
    std::cout << std::endl;
}
