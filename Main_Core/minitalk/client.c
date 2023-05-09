// ! header !

#include "minitalk.h"

void ft_message_handler(char *str, int pidserv)
{
    int base;
    char ch;
    while (*str)
    {
        base = 128;
        ch = *str++;
        while (base > 0)
        {
            if (ch >= base)
            {
                kill(pidserv, SIGUSR1);
                ch -= base;
            }
            else
                kill(pidserv, SIGUSR2);
            base /= 2;
            usleep(250);
        }
    }
}

int main(int argc, char **argv)
{
    int pidserv;

    if (argc != 3)
    {
        ft_printf("Invalid input!\n");
        return 1;
    }

    pidserv = ft_atoi(argv[1]);
    ft_message_handler(argv[2], pidserv);
    
    return 0;
}