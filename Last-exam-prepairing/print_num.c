#include <limits.h>
#include <unistd.h>

void	ft_print_num(num)
{
	if (num == 2147483647)
	{
		write(1, "2147483647\n", 11);
        return;
	}
	else if (num == -2147483648)
	{
		write(1, "-2147483648\n", 12);
        return;
	} else if (num < 0) {
        write(1, "-", 1);
        ft_print_num(-num);
    }   else {
        if (num > 9) {
            
        }
    }
}

int	main(void)
{
	printf("%d\n", INT_MIN);
	// ft_print_num(32);
}