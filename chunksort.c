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
	return (-1);
}

void	ft_push_chunks_to_stack_b(t_node **stack_a, t_node **stack_b,
		int chunk_size, int total_chunks)
{
	int	chunk_index;
	int	stack_b_size;
	int	value_position;
	int	current_value;
	int	range_start;
	int	range_end;

	chunk_index = 0;
	while (chunk_index < total_chunks)
	{
		range_start = chunk_index * chunk_size;
		range_end = range_start + chunk_size - 1;
		current_value = range_start;
		while (current_value <= range_end)
		{
			value_position = ft_find_value_position(*stack_a, current_value);
			if (value_position != -1)
			{
				if (value_position <= ft_get_list_size(*stack_a) / 2)
				{
					while (value_position > 0)
					{
						ft_rotate_list_up(stack_a);
						write(1, "ra\n", 3);
						value_position--;
					}
				}
				else
				{
					while (value_position < ft_get_list_size(*stack_a))
					{
						ft_rotate_list_down(stack_a);
						write(1, "rra\n", 4);
						value_position++;
					}
				}
				ft_push_element(stack_b, stack_a);
				write(1, "pb\n", 3);
				stack_b_size = ft_get_list_size(*stack_b);
				if (stack_b_size > 1)
				{
					if (chunk_index < total_chunks / 2)
					{
						ft_rotate_list_up(stack_b);
						write(1, "rb\n", 3);
					}
					else
					{
						ft_rotate_list_down(stack_b);
						write(1, "rrb\n", 4);
					}
				}
			}
			current_value++;
		}
		chunk_index++;
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
	int	stack_b_size;
	int	max_value;
	int	position;

	stack_b_size = ft_get_list_size(*stack_b);
	while (stack_b_size > 0)
	{
		max_value = ft_find_maximum_value(*stack_b);
		position = ft_find_value_position(*stack_b, max_value);
		if (position <= stack_b_size / 2)
		{
			while (position > 0)
			{
				ft_rotate_list_up(stack_b);
				write(1, "rb\n", 3);
				position--;
			}
		}
		else
		{
			while (position < stack_b_size)
			{
				ft_rotate_list_down(stack_b);
				write(1, "rrb\n", 4);
				position++;
			}
		}
		ft_push_element(stack_a, stack_b);
		write(1, "pa\n", 3);
		stack_b_size--;
	}
}

void	ft_sort_using_chunks(t_node **stack_a, t_node **stack_b)
{
	int	list_size;
	int	chunk_size;
	int	total_chunks;

	list_size = ft_get_list_size(*stack_a);
	if (list_size <= 100)
		chunk_size = 20;
	else
		chunk_size = 50;
	total_chunks = list_size / chunk_size;
	if (list_size % chunk_size != 0)
		total_chunks++;
	ft_push_chunks_to_stack_b(stack_a, stack_b, chunk_size, total_chunks);
	ft_pull_chunks_to_stack_a(stack_a, stack_b);
}
