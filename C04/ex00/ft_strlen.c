/*HEADER*/
/*
#include <stdio.h>
*/
int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}
/*
int	main(void)
{
	char str[20] = "hey there!";
	printf("Test_1: %d\n", ft_strlen(str));
	return (0);
}
*/
