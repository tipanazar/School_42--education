#include <limits.h>
#include <unistd.h>

void	ft_prchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_print_num(int num)
{
	if (num == 2147483647)
	{
		write(1, "2147483647\n", 11);
		return ;
	}
	else if (num == -2147483648)
	{
		write(1, "-2147483648\n", 12);
		return ;
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		ft_print_num(-num);
	}
	else
	{
		if (num > 9)
		{
			ft_print_num(num / 10);
			ft_prchar(num % 10 + 48);
		}
		else
		{
			ft_prchar(num + 48);
		}
	}
}

int	main(void)
{
	ft_print_num(-12345677);
}