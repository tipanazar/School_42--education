#include <unistd.h>

void	ft_union(char **argv)
{
	int	i;
	int	j;
	int	gate;

	i = 0;
	// first check
	while (argv[1][i])
	{
		j = 0;
		gate = 1;
		while (j < i)
		{
			if (argv[1][i] == argv[1][j])
			{
				{
					gate = 0;
					break ;
				}
			}
			j++;
		}
		if (gate == 1)
			write(1, &argv[1][i], 1);
		i++;
	}
	// second string
	i = 0;
    while (argv[2][i] != '\0')
	{
		j = 0;
		gate = 1;
		while (argv[1][j])
		{
			if(argv[1][j] == argv[2][i])
			{
			gate = 0;
			}
			j++;

		}
		j = 0;
		while (j < i)
		{
			if (argv[2][j] == argv[2][i])
			{
				gate = 0;
				break ;
			}
			j++;
		}
		if (gate == 1)
			write(1, &argv[2][i], 1);
		i++;
	}
}

int	main(int ac, char **argv)
{
	if (ac == 3)
	{
		ft_union(argv);
	}
	write(1, "\n", 1);
	return (0);
}