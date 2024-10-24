#pragma once
#include <iostream>
#include "Contact.hpp"

class Contact;

class PhoneBook
{
private:
    Contact contacts[8];
    int contactsNumber;

public:
    PhoneBook() : contactsNumber(0) {}
    void ft_add_contact(Contact &contact);
    void ft_show_list();
    void printContact(int idx);
    int get_contacts_number();
};