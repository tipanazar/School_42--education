int ft_atoi(const char *str) {
    int sign = 1;
    int result = 0;

    // Skip any leading white space
    while (*str == ' ') {
        str++;
    }

    // Check for a sign
    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    // Convert digits to an integer
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}
