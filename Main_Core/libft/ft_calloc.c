#include "libft.h"

void* ft_calloc(size_t num, size_t size) {
    void* ptr = malloc(num * size);
    if (ptr != NULL) {
        // Zero out the allocated memory
        ft_memset(ptr, 0, num * size);
    }
    return ptr;
}
