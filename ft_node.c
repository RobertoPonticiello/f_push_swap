#include "ft_push_swap.h"

void	ft_append_node_to_list(t_node **list_head, t_node *new_node)
{
	t_node	*current_node;

	if (!list_head || !new_node)
		return ;
	if (!*list_head)
	{
		*list_head = new_node;
		return ;
	}
	current_node = *list_head;
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = new_node;
}

void	ft_prepend_node_to_list(t_node **list_head, t_node *new_node)
{
	if (!list_head || !new_node)
		return ;
	new_node->next = *list_head;
	*list_head = new_node;
}

t_node	*ft_create_new_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = number;
	new_node->next = NULL;
	return (new_node);
}

int	ft_get_list_size(t_node *list_head)
{
	int	node_count;

	node_count = 0;
	while (list_head)
	{
		node_count++;
		list_head = list_head->next;
	}
	return (node_count);
}

void	ft_free_linked_list(t_node *list_head)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = list_head;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
