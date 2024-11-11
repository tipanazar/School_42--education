#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    std::cout << "Memory address of the string variable | " << &str << std::endl;
    std::cout << "Memory address held by stringPTR      | " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF      | " << &stringREF << std::endl;
    std::cout << "Value of the string variable          | " << str << std::endl;
    std::cout << "Value pointed to by stringPTR         | " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF         | " << stringREF << std::endl;

    return 0;
}

/*
    Pointer: stringPTR is a pointer to str, initialized with the address of str.

    Reference: stringREF is a reference to str, which acts as an alias for str.

    Output: The program prints the memory addresses of str, stringPTR, and stringREF,
    followed by the values of str, the value pointed to by stringPTR,
    and the value referred to by stringREF.
*/