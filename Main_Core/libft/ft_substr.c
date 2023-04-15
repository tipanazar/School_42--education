#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int idx = 0;
    char *substr;
    // int strlen = ft_strlen(s);
    int strlen = 1;
    if (strlen <= start)
        substr = malloc(1);
    else
        substr = (char *)malloc(len - start + 1);
    if (!substr)
        return NULL;

    while (start <= len && s[start])
    {
        substr[idx++] = s[start++];
    }
    substr[idx] = '\0';
    return substr;
}

int main (void ) {
    char str[] = "test string";
    printf("%d",ft_isprint(str[0]));
    // printf(ft_substr(str, 0, 3));
}