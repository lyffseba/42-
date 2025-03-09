/*42HEADER*/

#ifndef DICT_H
# define DICT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

// Prints a string to stdout
void	ft_putstr(char *str);
// Converts string to integer, handles signs and whitespace
int		ft_atoi(char *str);
// Trims leading/trailing spaces from a string
char	*ft_strtrim(char *str);
// Counts lines in a file for dictionary size
int		count_lines(char *filename);
// Counts newlines in a buffer
int		count_newlines(char *buffer, int bytes);
// Parses dictionary file into t_dict array
t_dict	*parse_dict(char *filename, int *size);
// Reads file buffer and populates dictionary
void	read_buffer(int fd, t_dict *dict, int *i);
// Processes buffer to build dictionary entries
void	process_buffer(char *buffer, int bytes, char *line, int *line_pos,
			t_dict *dict, int *i);
// Adds a dictionary entry from a trimmed line
void	add_dict_entry(char *line, t_dict *dict, int *i);
// Frees allocated memory for dictionary
void	free_dict(t_dict *dict, int size);
// Joins two strings with a space separator
char	*ft_strjoin(char *s1, char *s2);
// Returns length of a string
int		ft_strlen(char *str);
// Finds dictionary value for a given key
char	*get_dict_value(char *key, t_dict *dict, int dict_size);
// Converts number to words using dictionary
char	*num_to_words(char *num, t_dict *dict, int dict_size);
// Handles numbers up to 99
char	*handle_small_num(char *num, t_dict *dict, int dict_size);
// Handles numbers larger than 99
char	*handle_large_num(char *num, int len, t_dict *dict, int dict_size);
// Combines group words with scale and remainder
char	*combine_large_num(char *group_words, char *scale, char *num,
			t_dict *dict, int dict_size);
// Checks if string is a valid positive number
int		is_valid_num(char *str);

#endif
