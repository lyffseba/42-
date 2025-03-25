/*HEADER*/
/*
#include <stdio.h>
*/
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
int main(void)
{
    printf("%d\n", ft_strcmp("abc", "abc")); // 0
    printf("%d\n", ft_strcmp("abc", "abd")); // -1
    printf("%d\n", ft_strcmp("abd", "abc")); // 1
    printf("%d\n", ft_strcmp("ab", "abc"));  // -99
    return (0);
}
*/
