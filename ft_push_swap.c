/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:27:11 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/29 20:27:11 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_validate_duplicates(int argc, char **argv)
{
	int	current_index;
	int	compare_index;

	current_index = 1;
	while (current_index < argc)
	{
		compare_index = current_index + 1;
		while (compare_index < argc)
		{
			if (ft_convert_string_to_integer(argv[compare_index])
				== ft_convert_string_to_integer(argv[current_index]))
				return (1);
			compare_index++;
		}
		current_index++;
	}
	return (0);
}

t_node	**ft_create_number_list(int argc, char **argv)
{
	t_node	**number_list;
	int		index;

	number_list = (t_node **)malloc(sizeof(t_node *) * (argc - 1));
	if (!number_list)
		return (NULL);
	index = 0;
	while (index < argc - 1)
	{
		number_list[index] = ft_create_new_node(ft_convert_string_to_integer(argv[index + 1]));
		if (!number_list[index])
		{
			ft_free_linked_list(*number_list);
			free(number_list);
			return (NULL);
		}
		if (index > 0)
			ft_append_node_to_list(number_list, number_list[index]);
		index++;
	}
	return (number_list);
}

int	ft_initialize_and_check(int argc, char **argv, t_node **stack_a)
{
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!ft_parse_command_line_arguments(argc, argv, stack_a))
			return (0);
	}
	else
	{
		if (!ft_process_direct_arguments(argc, argv, stack_a))
			return (0);
	}
	return (1);
}

void	ft_select_sort_method(t_node **stack_a, t_node **stack_b, int list_size)
{
	if (list_size == 2)
		ft_sort_two_numbers(stack_a);
	else if (list_size == 3)
		ft_sort_three_numbers(stack_a);
	else if (list_size <= 5)
		ft_sort_four_or_five_numbers(stack_a, stack_b, list_size);
	else
		ft_sort_using_chunks(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		list_size;

	stack_a = NULL;
	stack_b = NULL;
	if (!ft_initialize_and_check(argc, argv, &stack_a))
	{
		ft_free_linked_list(stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	list_size = ft_get_list_size(stack_a);
	if (ft_is_list_sorted(stack_a))
	{
		ft_free_linked_list(stack_a);
		return (0);
	}
	ft_select_sort_method(&stack_a, &stack_b, list_size);
	ft_free_linked_list(stack_a);
	ft_free_linked_list(stack_b);
	return (0);
}
