/*HEADER*/
/*
#include <stdio.h>
*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return(0);
	while (n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}
/*
int	main(void)
{
	char s1[] = "abc";
	char s2[] = "abc";
	printf("%d\n", ft_strncmp(s1, s2, 3));
	return (0);
}
*/
