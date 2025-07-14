#include "ft_push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*list_to_array(t_node *lst, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (lst)
	{
		arr[i] = lst->num;
		i++;
		lst = lst->next;
	}
	return (arr);
}

static void	apply_normalization(t_node *lst, int *arr, int size)
{
	int	norm;

	while (lst)
	{
		norm = 0;
		while (norm < size && arr[norm] != lst->num)
			norm++;
		lst->num = norm;
		lst = lst->next;
	}
}

void	normalize_list(t_node **a)
{
	int	size;
	int	*arr;

	size = ft_get_list_size(*a);
	if (size <= 0)
		return ;
	arr = list_to_array(*a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	apply_normalization(*a, arr, size);
	free(arr);
}
