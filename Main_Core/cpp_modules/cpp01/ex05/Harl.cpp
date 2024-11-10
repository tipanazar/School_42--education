#include <iostream>
#include <string>
#include <map>
#include "Harl.hpp"

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*funcs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int idx = 0; idx < 4; idx++)
    {
        if (level == levels[idx])
        {
            (this->*funcs[idx])();
            return;
        }
    }
    std::cout << "Error unkown level: " << level << std::endl;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now. I want a free meal." << std::endl;
}