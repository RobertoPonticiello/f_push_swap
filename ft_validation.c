#include "ft_push_swap.h"

int	ft_is_valid_integer_string(char *input_string)
{
	int	index;

	index = 0;
	if (input_string[index] == '-' || input_string[index] == '+')
		index++;
	if (!input_string[index])
		return (0);
	while (input_string[index])
	{
		if (input_string[index] < '0' || input_string[index] > '9')
			return (0);
		index++;
	}
	return (1);
}

int	ft_check_for_duplicate_numbers(int *number_array, int array_size)
{
	int	index;
	int	compare_index;

	index = 0;
	while (index < array_size)
	{
		compare_index = index + 1;
		while (compare_index < array_size)
		{
			if (number_array[index] == number_array[compare_index])
				return (1);
			compare_index++;
		}
		index++;
	}
	return (0);
}

int	ft_constr_safe(const char *input_string, int *result)
{
	int	index;
	int	sign_value;

	index = 0;
	sign_value = 1;
	while (input_string[index] == ' ' || (input_string[index] >= 9
			&& input_string[index] <= 13))
		index++;
	if (input_string[index] == '-' || input_string[index] == '+')
	{
		if (input_string[index] == '-')
			sign_value = -1;
		index++;
	}
	return (ft_constr_continue(input_string, index,
			sign_value, result));
}

int	ft_constr_continue(const char *input_string,
		int string_index, int sign_value, int *result)
{
	long long	number;

	number = 0;
	while (input_string[string_index] >= '0'
		&& input_string[string_index] <= '9')
	{
		number = number * 10 + (input_string[string_index] - '0');
		if ((number * sign_value) > INT_MAX || (number * sign_value) < INT_MIN)
			return (0);
		string_index++;
	}
	if (input_string[string_index] != '\0')
		return (0);
	*result = (int)(number * sign_value);
	return (1);
}

int	ft_is_list_sorted(t_node *list_head)
{
	t_node	*current_node;

	if (!list_head)
		return (1);
	current_node = list_head;
	while (current_node->next)
	{
		if (current_node->num > current_node->next->num)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}
