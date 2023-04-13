unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int idx;

    idx = 0;
    if (size)
    {
        while (src[idx] && idx < (size - 1))
        {
            dest[idx] = src[idx];
            idx++;
        }
        dest[idx] = '\0';
    }
    while (src[idx])
        idx++;
    return (idx);
}