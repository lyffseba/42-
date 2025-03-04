/*HEADER*/

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	result;

	result = 1;
	if (*str == '\0')
		return (result);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			result = 0;
	}
	return (result);
}

int	main(void)
{
	char	*buff;

	buff = "123";
	int test = ft_str_is_numeric(buff);
	printf("Is numeric: %d\n", test);
	return (0);
}

