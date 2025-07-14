#include "ft_push_swap.h"

static void	ft_sort_integer_array(int *number_array, int array_size)
{
	int	outer_index;
	int	inner_index;
	int	temporary_value;

	outer_index = 0;
	while (outer_index < array_size - 1)
	{
		inner_index = outer_index + 1;
		while (inner_index < array_size)
		{
			if (number_array[outer_index] > number_array[inner_index])
			{
				temporary_value = number_array[outer_index];
				number_array[outer_index] = number_array[inner_index];
				number_array[inner_index] = temporary_value;
			}
			inner_index++;
		}
		outer_index++;
	}
}

static int	*ft_convert_list_to_array(t_node *list_head, int list_size)
{
	int	*number_array;
	int	array_index;

	number_array = malloc(sizeof(int) * list_size);
	if (!number_array)
		return (NULL);
	array_index = 0;
	while (list_head)
	{
		number_array[array_index] = list_head->num;
		array_index++;
		list_head = list_head->next;
	}
	return (number_array);
}

static void	ft_apply_normalization_to_list(t_node *list_head, int *sorted_array,
		int array_size)
{
	int	normalized_value;

	while (list_head)
	{
		normalized_value = 0;
		while (normalized_value < array_size
			&& sorted_array[normalized_value] != list_head->num)
			normalized_value++;
		list_head->num = normalized_value;
		list_head = list_head->next;
	}
}

void	ft_normalize_list_values(t_node **stack_a)
{
	int	list_size;
	int	*number_array;

	list_size = ft_get_list_size(*stack_a);
	if (list_size <= 0)
		return ;
	number_array = ft_convert_list_to_array(*stack_a, list_size);
	if (!number_array)
		return ;
	ft_sort_integer_array(number_array, list_size);
	ft_apply_normalization_to_list(*stack_a, number_array, list_size);
	free(number_array);
}

int	ft_find_maximum_value(t_node *list_head)
{
	int	maximum_value;

	maximum_value = list_head->num;
	while (list_head)
	{
		if (list_head->num > maximum_value)
			maximum_value = list_head->num;
		list_head = list_head->next;
	}
	return (maximum_value);
}
