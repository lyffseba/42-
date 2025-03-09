/* 42 HEADER */

#include "dict.h"

int	main(int argc, char **argv)
{
	// Dictionary
	t_dict	*dict;
	// Number of dictionary entries
	int		dict_size;
	// Resulting string
	char	*result;
	// Dictionary file path
	char	*dict_file;

	// Check argument count
	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	dict_file = (argc == 2) ? "numbers.dict" : argv[1];
	dict = parse_dict(dict_file, &dict_size);
	// Check dictionary parsing failure
	if (!dict)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	// Check number validity
	if (ft_atoi(argv[argc - 1]) < 0 || !is_valid_num(argv[argc - 1]))
	{
		ft_putstr("Error\n");
		free_dict(dict, dict_size);
		return (1);
	}
	result = num_to_words(argv[argc - 1], dict, dict_size);
	if (!result)
		ft_putstr("Dict Error\n");
	else
	{
		ft_putstr(result);
		ft_putstr("\n");
		free(result);
	}
	free_dict(dict, dict_size);
	return (0);
}

// Checks if string contains only digits
int	is_valid_num(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
