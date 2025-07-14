#include "ft_push_swap.h"

void	ft_handle_case_two(t_node **stack_a)
{
	ft_swap_top_elements(stack_a);
	write(1, "sa\n", 3);
	ft_rotate_list_down(stack_a);
	write(1, "rra\n", 4);
}

void	ft_handle_case_three(t_node **stack_a)
{
	ft_rotate_list_up(stack_a);
	write(1, "ra\n", 3);
}

void	ft_handle_case_four(t_node **stack_a)
{
	ft_swap_top_elements(stack_a);
	write(1, "sa\n", 3);
	ft_rotate_list_up(stack_a);
	write(1, "ra\n", 3);
}
