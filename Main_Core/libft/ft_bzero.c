#include "libft.h"

void ft_bzero(void *ptr, size_t num)
{
    ft_memset(ptr, 0, num);
}