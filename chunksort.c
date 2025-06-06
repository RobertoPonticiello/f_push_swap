/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:27:11 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/29 20:27:11 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_find_value_position(t_node *stack, int value)
{
	int		position;
	t_node	*current;

	position = 0;
	current = stack;
	while (current)
	{
		if (current->num == value)
			return (position);
		position++;
		current = current->next;
	}
	return (position);
}

void	ft_push_chunks_to_stack_b(t_node **stack_a, t_node **stack_b,
		int chunk_size, int num_chunks)
{
	int	current_chunk;
	int	stack_b_size;

	current_chunk = 1;
	while (*stack_a)
	{
		if ((*stack_a)->num < current_chunk * chunk_size)
		{
			ft_push_element(stack_b, stack_a);
			write(1, "pb\n", 3);
			if (*stack_b && (*stack_b)->num < (current_chunk * chunk_size) - (chunk_size / 2))
			{
				ft_rotate_list_up(stack_b);
				write(1, "rb\n", 3);
			}
		}
		else
		{
			ft_rotate_list_up(stack_a);
			write(1, "ra\n", 3);
		}
		stack_b_size = ft_get_list_size(*stack_b);
		if (stack_b_size >= current_chunk * chunk_size && current_chunk < num_chunks)
			current_chunk++;
	}
}

void	ft_rotate_stack_b(t_node **stack_b, int rotation_count, int use_reverse)
{
	int	index;

	index = 0;
	while (index < rotation_count)
	{
		if (use_reverse)
		{
			ft_rotate_list_down(stack_b);
			write(1, "rrb\n", 4);
		}
		else
		{
			ft_rotate_list_up(stack_b);
			write(1, "rb\n", 3);
		}
		index++;
	}
}

void	ft_pull_chunks_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	int	max_value;
	int	position;
	int	stack_b_size;

	while (*stack_b)
	{
		max_value = ft_find_maximum_value(*stack_b);
		position = ft_find_value_position(*stack_b, max_value);
		stack_b_size = ft_get_list_size(*stack_b);
		if (position <= stack_b_size / 2)
			ft_rotate_stack_b(stack_b, position, 0);
		else
			ft_rotate_stack_b(stack_b, stack_b_size - position, 1);
		ft_push_element(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}

void	ft_sort_using_chunks(t_node **stack_a, t_node **stack_b)
{
	int	total_size;
	int	num_chunks;
	int	chunk_size;

	total_size = ft_get_list_size(*stack_a);
	if (total_size <= 100)
		num_chunks = 5;
	else
		num_chunks = 11;
	chunk_size = total_size / num_chunks + 1;
	ft_push_chunks_to_stack_b(stack_a, stack_b, chunk_size, num_chunks);
	ft_pull_chunks_to_stack_a(stack_a, stack_b);
}
