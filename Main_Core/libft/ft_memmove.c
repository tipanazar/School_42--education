#include "libft.h"

void* ft_memmove(void* dest, const void* src, size_t num) {
    unsigned char* p_dest = dest;
    const unsigned char* p_src = src;
    if (p_src < p_dest) {
        p_dest += num - 1;
        p_src += num - 1;
        while (num--) {
            *p_dest-- = *p_src--;
        }
    } else {
        while (num--) {
            *p_dest++ = *p_src++;
        }
    }
    return dest;
}
