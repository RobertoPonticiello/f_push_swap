#include "ft_push_swap.h"

int	ft_process_split_arguments(char **split_arguments, t_node **stack_a)
{
	int	argument_count;
	int	*number_array;

	argument_count = 0;
	while (split_arguments[argument_count])
		argument_count++;
	if (argument_count == 0)
		return (0);
	number_array = (int *)malloc(sizeof(int) * argument_count);
	if (!number_array)
		return (0);
	if (!ft_validate_and_convert_arguments(split_arguments, number_array,
			argument_count))
	{
		free(number_array);
		return (0);
	}
	if (!ft_create_list_from_numbers(number_array, argument_count, stack_a))
	{
		free(number_array);
		return (0);
	}
	free(number_array);
	return (1);
}

int	ft_validate_and_convert_arguments(char **split_arguments, int *number_array,
		int argument_count)
{
	int	index;

	index = 0;
	while (index < argument_count)
	{
		if (!ft_is_valid_integer_string(split_arguments[index])
			|| !ft_constr_safe(split_arguments[index],
				&number_array[index]))
			return (0);
		index++;
	}
	if (ft_check_for_duplicate_numbers(number_array, argument_count))
		return (0);
	return (1);
}

int	ft_create_list_from_numbers(int *number_array, int array_size,
		t_node **stack_a)
{
	int		index;
	t_node	*new_node;

	index = 0;
	while (index < array_size)
	{
		new_node = ft_create_new_node(number_array[index]);
		if (!new_node)
		{
			ft_free_linked_list(*stack_a);
			*stack_a = NULL;
			return (0);
		}
		ft_append_node_to_list(stack_a, new_node);
		index++;
	}
	return (1);
}

int	ft_validate_direct_arguments(int argc, char **argv, int *number_array)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (!ft_is_valid_integer_string(argv[index])
			|| !ft_constr_safe(argv[index],
				&number_array[index - 1]))
			return (0);
		index++;
	}
	if (ft_check_for_duplicate_numbers(number_array, argc - 1))
		return (0);
	return (1);
}

int	ft_process_direct_arguments(int argc, char **argv, t_node **stack_a)
{
	int	*number_array;

	number_array = (int *)malloc(sizeof(int) * (argc - 1));
	if (!number_array)
		return (0);
	if (!ft_validate_direct_arguments(argc, argv, number_array))
	{
		free(number_array);
		return (0);
	}
	if (!ft_create_list_from_numbers(number_array, argc - 1, stack_a))
	{
		free(number_array);
		return (0);
	}
	free(number_array);
	return (1);
}
