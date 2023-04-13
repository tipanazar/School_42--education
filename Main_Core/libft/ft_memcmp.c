#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = s1, *p2 = s2;
    for (size_t i = 0; i < n; i++, p1++, p2++) {
        if (*p1 != *p2) {
            return (*p1 < *p2) ? -1 : 1;
        }
    }
    return 0;
}
