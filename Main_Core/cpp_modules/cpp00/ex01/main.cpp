#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void ft_process_add(PhoneBook &phoneBook)
{
    Contact contact;

    std::string first_name, second_name, nickname, phone_number, darkest_secret, wish_to_try_again;

    std::cout << "First Name: ";
    std::getline(std::cin, first_name);
    std::cout << "Second Name: ";
    std::getline(std::cin, second_name);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone Number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkest_secret);
    if (first_name.empty() || second_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty())
    {
        std::cout << "Error: All fields are required, wish to try again?" << std::endl;
        std::cout << "Enter y(yes) or n(no)" << std::endl;
        std::getline(std::cin, wish_to_try_again);

        if (wish_to_try_again == "yes" || wish_to_try_again == "y")
        {
            ft_process_add(phoneBook);
        }
        return;
    }
    contact.setContact(first_name, second_name, nickname, phone_number, darkest_secret);
    phoneBook.ft_add_contact(contact);
}

void ft_process_search(PhoneBook &phoneBook)
{
    std::string index;

    phoneBook.ft_show_list();
    while (1)
    {

        std::cout << "Enter index or type EXIT: ";
        std::getline(std::cin, index);
        if (index == "EXIT")
            break;
        if (index.empty())
        {
            std::cout << "Error: Index is required" << std::endl;
            continue;
        }
        try
        {
            int idx = std::stoi(index);
            if (idx < 0 || idx >= phoneBook.get_contacts_number())
            {
                std::cout << "Error: Invalid index" << std::endl;
                continue;
            }
            phoneBook.printContact(idx);
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Error: Please enter a valid integer index or type EXIT" << std::endl;
        }
        catch (const std::out_of_range &e)
        {
            std::cout << "Error: Index out of range" << std::endl;
        }
    }
}

int main()
{
    PhoneBook phoneBook;

    while (1)
    {
        std::string input;
        std::cout << "Enter ADD, SEARCH or EXIT: ";
        std::getline(std::cin, input);
        if (input == "EXIT")
            break;
        if (input == "ADD")
            ft_process_add(phoneBook);
        if (input == "SEARCH")
            ft_process_search(phoneBook);
    }
}