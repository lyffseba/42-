/* HEADER */

/*
#include <stdio.h>
*/

int ft_atoi(char *str)
{
    int result;
    int sign;

    result = 0;
    sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n' || 
           *str == '\v' || *str == '\f' || *str == '\r')
        str++;

    while (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return (sign * result);
}
/*
int main(void)
{
    printf("Test 1: ' ---+--+1234ab567' -> %d (Expected: -1234)\n", ft_atoi(" ---+--+1234ab567"));
    printf("Test 2: '12345' -> %d (Expected: 12345)\n", ft_atoi("12345"));
    printf("Test 3: '   ++42' -> %d (Expected: 42)\n", ft_atoi("   ++42"));
    return (0);
}
*/
