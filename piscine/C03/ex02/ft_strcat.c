/*HEADER*/
/*
#include <stdio.h>
*/
char	*ft_strcat(char *dest, char *src)
{
	char *start = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}
/*
int	main(void)
{
	char	*src;
	char	dest[20];

	src = " Codam!";
	dest[0] = 'H';
	dest[1] = 'e';
	dest[2] = 'l';
	dest[3] = 'l';
	dest[4] = 'o';
	dest[5] = '\0';
	printf("Test_1: %s\n", ft_strcat(dest, src));
	return (0);
}
*/
