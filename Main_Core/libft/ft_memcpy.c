#include "libft.h"

void* ft_memcpy(void* dest, const void* src, size_t num) {
    unsigned char* p_dest = dest;
    const unsigned char* p_src = src;
    while (num--) {
        *p_dest++ = *p_src++;
    }
    return dest;
}
