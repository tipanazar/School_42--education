#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
    size_t needle_len = strlen(needle);
    if (needle_len == 0)
    {
        return (char *)haystack;
    }
    for (size_t i = 0; i < n && haystack[i] != '\0'; i++)
    {
        if (haystack[i] == needle[0])
        {
            if (strncmp(&haystack[i], needle, needle_len) == 0)
            {
                return (char *)&haystack[i];
            }
        }
    }
    return NULL;
}
