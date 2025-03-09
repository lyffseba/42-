/* 42 HEADER */
#include "dict.h"

// Joins two strings with a space separator
char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;	// Result string
	int		len1;		// Length of s1
	int		len2;		// Length of s2
	int		i;		// Index

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 2);	// Space for space and null
	if (!result)
		return (NULL);
	i = 0;
	while (i < len1)	// Copy s1
	{
		result[i] = s1[i];
		i++;
	}
	if (len1 > 0 && len2 > 0)	// Add space if both strings exist
		result[i++] = ' ';
	while (i - (len1 ? 1 : 0) < len2)	// Copy s2
	{
		result[i] = s2[i - (len1 ? 1 : 0)];
		i++;
	}
	result[i] = '\0';	// Null-terminate
	return (result);
}

// Returns length of a string
int	ft_strlen(char *str)
{
	int	len;	// Length counter

	len = 0;
	while (str && str[len])	// Count until null
		len++;
	return (len);
}

// Finds dictionary value for a given key
char	*get_dict_value(char *key, t_dict *dict, int dict_size)
{
	int		i;	// Dictionary index
	int		j;	// Character index

	i = 0;
	while (i < dict_size)	// Loop through dictionary
	{
		j = 0;
		while (dict[i].key[j] && key[j] && dict[i].key[j] == key[j])
			j++;	// Compare characters
		if (!dict[i].key[j] && !key[j])	// Exact match
			return (dict[i].value);
		i++;
	}
	return (NULL);	// No match found
}

// Converts number to words using dictionary
char	*num_to_words(char *num, t_dict *dict, int dict_size)
{
	int		len;	// Number length

	len = ft_strlen(num);
	if (len == 0 || (len == 1 && num[0] == '0'))	// Zero case
		return (ft_strjoin(NULL, get_dict_value("0", dict, dict_size)));
	while (*num == '0')	// Skip leading zeros
	{
		num++;
		len--;
	}
	if (len == 0)	// All zeros
		return (ft_strjoin(NULL, get_dict_value("0", dict, dict_size)));
	if (len <= 2)	// Small number (<= 99)
		return (handle_small_num(num, dict, dict_size));
	return (handle_large_num(num, len, dict, dict_size));	// Large number
}

// Handles numbers up to 99
char	*handle_small_num(char *num, t_dict *dict, int dict_size)
{
	char	*tens[] = {"20", "30", "40", "50", "60", "70", "80", "90"};
	char	*units[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	char	*result;	// Result string

	if (ft_strlen(num) == 1)	// Single digit
		return (ft_strjoin(NULL, get_dict_value(num, dict, dict_size)));
	if (num[0] == '1')	// Teens (10-19)
		return (ft_strjoin(NULL, get_dict_value(num, dict, dict_size)));
	if (num[1] == '0')	// Tens only (20, 30, etc.)
		return (ft_strjoin(NULL, get_dict_value(num, dict, dict_size)));
	result = ft_strjoin(get_dict_value(tens[num[0] - '2'], dict, dict_size),
			get_dict_value(units[num[1] - '0'], dict, dict_size));
	return (result);	// Combine tens and units
}

// Handles numbers larger than 99
char	*handle_large_num(char *num, int len, t_dict *dict, int dict_size)
{
	char	*scales[] = {"100", "1000", "1000000", "1000000000",
			"1000000000000", "1000000000000000", "1000000000000000000",
			"1000000000000000000000", "1000000000000000000000000",
			"1000000000000000000000000000", "1000000000000000000000000000000",
			"1000000000000000000000000000000000",
			"1000000000000000000000000000000000000"};
	int		scale_idx;	// Scale index (hundred, thousand, etc.)
	int		digits_in_group;	// Digits in current group
	char	group[4];	// Current group buffer
	char	*group_words;	// Words for group
	char	*temp;		// Temp pointer

	scale_idx = (len - 1) / 3;	// Determine scale
	digits_in_group = len % 3 ? len % 3 : 3;	// Group size
	group[0] = '\0';
	temp = group;
	while (temp < group + digits_in_group)	// Build group
	{
		*temp = *num;
		temp++;
		num++;
	}
	*temp = '\0';
	group_words = num_to_words(group, dict, dict_size);	// Convert group
	if (scale_idx > 0)	// Apply scale if needed
		return (combine_large_num(group_words, scales[scale_idx - 1],
				num, dict, dict_size));
	return (group_words);	// No scale needed
}

// Combines group words with scale and remainder
char	*combine_large_num(char *group_words, char *scale, char *num,
			t_dict *dict, int dict_size)
{
	char	*temp;	// Temporary joined string
	char	*rest;	// Words for remaining digits
	char	*final;	// Final result

	temp = ft_strjoin(group_words, get_dict_value(scale, dict, dict_size));
	free(group_words);	// Free group words
	rest = num_to_words(num, dict, dict_size);	// Convert rest
	final = ft_strjoin(temp, rest);	// Combine
	free(temp);	// Free temp
	free(rest);	// Free rest
	return (final);
}
