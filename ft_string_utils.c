/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:27:11 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/29 20:27:11 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

static char	*ft_strdup(const char *str)
{
	char	*duplicate;
	size_t	length;
	size_t	index;

	length = ft_strlen(str);
	duplicate = (char *)malloc(sizeof(char) * (length + 1));
	if (!duplicate)
		return (NULL);
	index = 0;
	while (index < length)
	{
		duplicate[index] = str[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}

char	**ft_split_string(char const *input_string, char delimiter)
{
	char	**result_array;
	int		word_count;
	int		index;

	if (!input_string)
		return (NULL);
	word_count = 0;
	index = 0;
	while (input_string[index])
	{
		if (input_string[index] != delimiter
			&& (index == 0 || input_string[index - 1] == delimiter))
			word_count++;
		index++;
	}
	result_array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result_array)
		return (NULL);
	return (ft_split_string_continue(input_string, delimiter, result_array,
			word_count));
}

char	**ft_split_string_continue(char const *input_string, char delimiter,
		char **result_array, int total_words)
{
	int	word_index;
	int	char_index;
	int	start_pos;

	word_index = 0;
	char_index = 0;
	while (word_index < total_words)
	{
		while (input_string[char_index] == delimiter)
			char_index++;
		start_pos = char_index;
		while (input_string[char_index] && input_string[char_index] != delimiter)
			char_index++;
		result_array[word_index] = ft_create_substring(input_string, start_pos,
				char_index - start_pos);
		if (!result_array[word_index])
		{
			ft_free_string_array(result_array);
			return (NULL);
		}
		word_index++;
	}
	result_array[word_index] = NULL;
	return (result_array);
}

char	*ft_create_substring(char const *source_string, unsigned int start_pos,
		size_t substring_length)
{
	char	*substring;
	size_t	index;

	if (!source_string)
		return (NULL);
	if (start_pos >= ft_strlen(source_string))
		return (ft_strdup(""));
	if (substring_length > ft_strlen(source_string) - start_pos)
		substring_length = ft_strlen(source_string) - start_pos;
	substring = (char *)malloc(sizeof(char) * (substring_length + 1));
	if (!substring)
		return (NULL);
	index = 0;
	while (index < substring_length)
	{
		substring[index] = source_string[start_pos + index];
		index++;
	}
	substring[index] = '\0';
	return (substring);
}

void	ft_free_string_array(char **string_array)
{
	int	index;

	if (!string_array)
		return ;
	index = 0;
	while (string_array[index])
	{
		free(string_array[index]);
		index++;
	}
	free(string_array);
}
