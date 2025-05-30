/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moremoreutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:34:39 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/29 20:40:19 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
