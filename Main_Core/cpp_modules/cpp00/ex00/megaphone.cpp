#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    for (int idx = 1; argv[idx]; ++idx)
    {
        std::string str = argv[idx];
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        std::cout << str;
    }
    std::cout << std::endl;
    return 0;
}