#include "ft_push_swap.h"

void	ft_sort_three_numbers(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->num;
	second = (*stack_a)->next->num;
	third = (*stack_a)->next->next->num;
	ft_execute_three_sort_logic(stack_a, first, second, third);
}

void	ft_complete_three_sort(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->num;
	second = (*stack_a)->next->num;
	third = (*stack_a)->next->next->num;
	ft_execute_three_sort_logic(stack_a, first, second, third);
}

void	ft_sort_two_numbers(t_node **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
	{
		ft_swap_top_elements(stack_a);
		write(1, "sa\n", 3);
	}
}

void	ft_handle_case_one(t_node **stack_a)
{
	ft_swap_top_elements(stack_a);
	write(1, "sa\n", 3);
}

int	ft_parse_command_line_arguments(int argc, char **argv, t_node **stack_a)
{
	char	**split_arguments;
	int		parse_result;

	*stack_a = NULL;
	if (argc == 2)
	{
		split_arguments = ft_split_string(argv[1], ' ');
		if (!split_arguments)
			return (0);
		parse_result = ft_process_split_arguments(split_arguments, stack_a);
		ft_free_string_array(split_arguments);
		return (parse_result);
	}
	else
		return (ft_process_direct_arguments(argc, argv, stack_a));
}
