#include "ft_push_swap.h"

int	ft_constr(const char *input_string)
{
	int	sign_value;
	int	result;

	result = 0;
	sign_value = 1;
	while (*input_string == 32 || (*input_string >= 9 && *input_string <= 13))
		input_string++;
	if (*input_string == '-' || *input_string == '+')
	{
		if (*input_string == '-')
			sign_value = -1;
		input_string++;
	}
	while (*input_string >= '0' && *input_string <= '9')
	{
		result = result * 10 + *input_string - '0';
		input_string++;
	}
	return (sign_value * result);
}

void	ft_swap_top_elements(t_node **list_head)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!*list_head || !(*list_head)->next)
		return ;
	first_node = *list_head;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*list_head = second_node;
}

void	ft_push_element(t_node **destination, t_node **source)
{
	t_node	*temp_node;

	if (!*source)
		return ;
	temp_node = *source;
	*source = (*source)->next;
	temp_node->next = *destination;
	*destination = temp_node;
}

void	ft_rotate_list_up(t_node **list_head)
{
	t_node	*first_node;
	t_node	*last_node;

	if (!*list_head || !(*list_head)->next)
		return ;
	first_node = *list_head;
	last_node = *list_head;
	while (last_node->next)
		last_node = last_node->next;
	*list_head = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	ft_rotate_list_down(t_node **list_head)
{
	t_node	*last_node;
	t_node	*second_last_node;

	if (!*list_head || !(*list_head)->next)
		return ;
	last_node = *list_head;
	second_last_node = NULL;
	while (last_node->next)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;
	last_node->next = *list_head;
	*list_head = last_node;
}
