#include "libft.h"

char* strdup(const char* str) {
    size_t len = strlen(str) + 1; // довжина рядка, включаючи '\0'
    char* new_str = malloc(len); // виділення пам'яті для нового рядка
    if (new_str == NULL) {
        return NULL; // якщо не вдалося виділити пам'ять, повертаємо NULL
    }
    memcpy(new_str, str, len); // копіювання рядка в новий буфер
    return new_str;
}
