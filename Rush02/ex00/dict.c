/* 42 HEADER */
#include "dict.h"

// Counts lines in file to determine dictionary size
int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	buffer[1024];
	int		bytes;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		count += count_newlines(buffer, bytes);
		bytes = read(fd, buffer, 1024);
	}
	close(fd);
	return (count);
}

// Counts newlines in a buffer
int	count_newlines(char *buffer, int bytes)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < bytes)
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

// Trims leading/trailing spaces from string
char	*ft_strtrim(char *str)
{
	char	*start;
	char	*end;
	char	*result;
	int		len;

	start = str;
	while (*start == ' ' || *start == '\t')
		start++;
	end = start;
	while (*end && *end != '\n')
		end++;
	while (end > start && (*(end - 1) == ' ' || *(end - 1) == '\t'))
		end--;
	len = end - start;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	len = 0;
	while (start < end)
	{
		result[len] = *start;
		start++;
		len++;
	}
	result[len] = '\0';
	return (result);
}

// Parses dictionary file into t_dict array
t_dict	*parse_dict(char *filename, int *size)
{
	t_dict	*dict;
	int		fd;
	int		i;

	*size = count_lines(filename);
	if (*size < 0)
		return (NULL);
	dict = malloc(sizeof(t_dict) * (*size));
	if (!dict)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(dict);
		return (NULL);
	}
	i = 0;
	read_buffer(fd, dict, &i);
	close(fd);
	*size = i;
	return (dict);
}

// Reads file buffer and populates dictionary
void	read_buffer(int fd, t_dict *dict, int *i)
{
	char	buffer[1024];
	char	line[1024];
	int		bytes;
	int		line_pos;

	line_pos = 0;
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		process_buffer(buffer, bytes, line, &line_pos, dict, i);
		bytes = read(fd, buffer, 1024);
	}
	if (line_pos > 0)
	{
		line[line_pos] = '\0';
		add_dict_entry(line, dict, i);
	}
}

// Processes buffer to build dictionary entries
void	process_buffer(char *buffer, int bytes, char *line, int *line_pos,
			t_dict *dict, int *i)
{
	int		j;
	char	*trimmed;

	j = 0;
	while (j < bytes)
	{
		if (buffer[j] == '\n' && *line_pos > 0)
		{
			line[*line_pos] = '\0';
			trimmed = ft_strtrim(line);
			if (trimmed && *trimmed)
				add_dict_entry(trimmed, dict, i);
			free(trimmed);
			*line_pos = 0;
		}
		else if (buffer[j] != '\n')
		{
			line[*line_pos] = buffer[j];
			(*line_pos)++;
		}
		j++;
	}
}

// Adds a dictionary entry from a trimmed line
void	add_dict_entry(char *line, t_dict *dict, int *i)
{
	char	*colon;

	colon = line;
	while (*colon && *colon != ':')
		colon++;
	if (*colon == ':')
	{
		*colon = '\0';
		dict[*i].key = ft_strtrim(line);
		dict[*i].value = ft_strtrim(colon + 1);
		if (dict[*i].key && dict[*i].value)
			(*i)++;
	}
}

// Frees dictionary memory
void	free_dict(t_dict *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}
