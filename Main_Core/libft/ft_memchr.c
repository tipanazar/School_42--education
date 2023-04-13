#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n) {
    const unsigned char *p = s;
    for (size_t i = 0; i < n; i++, p++) {
        if (*p == (unsigned char)c) {
            return (void *)p;
        }
    }
    return NULL;
}
