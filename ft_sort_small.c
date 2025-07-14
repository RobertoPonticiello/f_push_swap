#include "ft_push_swap.h"

void	ft_handle_case_five(t_node **stack_a)
{
	ft_rotate_list_down(stack_a);
	write(1, "rra\n", 4);
}

void	ft_execute_three_sort_logic(t_node **stack_a,
			int first, int second, int third)
{
	if (first > second && second < third && first < third)
		ft_handle_case_one(stack_a);
	else if (first > second && second > third && first > third)
		ft_handle_case_two(stack_a);
	else if (first > second && second < third && first > third)
		ft_handle_case_three(stack_a);
	else if (first < second && second > third && first < third)
		ft_handle_case_four(stack_a);
	else if (first < second && second > third && first > third)
		ft_handle_case_five(stack_a);
}

void	ft_sort_four_or_five_numbers(t_node **stack_a, t_node **stack_b,
		int list_size)
{
	int	min_position;
	int	current_size;

	current_size = list_size;
	while (current_size > 3)
	{
		min_position = ft_find_minimum_position(*stack_a);
		ft_rotate_to_minimum(stack_a, min_position, current_size);
		ft_push_element(stack_b, stack_a);
		write(1, "pb\n", 3);
		current_size--;
	}
	ft_sort_three_numbers(stack_a);
	while (*stack_b)
	{
		ft_push_element(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}

int	ft_find_minimum_position(t_node *stack_a)
{
	int		minimum_value;
	int		current_position;
	int		minimum_position;
	t_node	*current_node;

	if (!stack_a)
		return (0);
	minimum_value = stack_a->num;
	minimum_position = 0;
	current_position = 0;
	current_node = stack_a;
	while (current_node)
	{
		if (current_node->num < minimum_value)
		{
			minimum_value = current_node->num;
			minimum_position = current_position;
		}
		current_position++;
		current_node = current_node->next;
	}
	return (minimum_position);
}

void	ft_rotate_to_minimum(t_node **stack_a, int min_position, int list_size)
{
	int	rotation_count;

	if (min_position <= list_size / 2)
	{
		rotation_count = min_position;
		while (rotation_count > 0)
		{
			ft_rotate_list_up(stack_a);
			write(1, "ra\n", 3);
			rotation_count--;
		}
	}
	else
	{
		rotation_count = list_size - min_position;
		while (rotation_count > 0)
		{
			ft_rotate_list_down(stack_a);
			write(1, "rra\n", 4);
			rotation_count--;
		}
	}
}
