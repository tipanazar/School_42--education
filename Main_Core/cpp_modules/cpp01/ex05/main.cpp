#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;
    std::string level;

    std::cout << "Write a prompt or write 'EXIT' to... guess what - exit" << std::endl
              << std::endl;
    std::getline(std::cin, level);
    while (level != "EXIT")
    {
        harl.complain(level);
        std::cout << std::endl;
        std::getline(std::cin, level);
    }

    // harl.complain("DEBUG");
    // harl.complain("INFO");
    // harl.complain("WARNING");
    // harl.complain("ERROR");
    // harl.complain("UNKNOWN");

    return 0;
}