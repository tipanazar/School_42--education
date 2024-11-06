#include "PhoneBook.hpp"

std::string ft_trim_string(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0, 9) + ".";
        return str;
    }
    str.insert(0, 10 - str.length(), ' ');
    return str;
}

int PhoneBook::get_contacts_number()
{
    return contactsNumber;
}

void PhoneBook::ft_add_contact(Contact &contact)
{
    if (contactsNumber < 8)
    {
        contacts[contactsNumber] = contact;
        contactsNumber++;
    }
    else
    {
        for (int i = 0; i < 7; i++)
            contacts[i] = contacts[i + 1];
        contacts[7] = contact;
    }
}

void PhoneBook::ft_show_list()
{
    std::cout << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < contactsNumber; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << ft_trim_string(contacts[i].getFirstName()) << "|";
        std::cout << ft_trim_string(contacts[i].getLastName()) << "|";
        std::cout << ft_trim_string(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::printContact(int idx)
{
    if (idx >= 0 && idx < contactsNumber)
    {
        contacts[idx].printContact();
    }
    else
    {
        std::cout << "Error: Invalid index" << std::endl;
    }
}