/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <rpontici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:43:16 by rpontici          #+#    #+#             */
/*   Updated: 2025/04/28 19:30:28 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> 
# include <limits.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}			t_node;

/* Validazione input */
int		ft_is_valid_integer_string(char *input_string);
int		ft_check_for_duplicate_numbers(int *number_array, int array_size);
int		ft_convert_string_to_integer_safe(const char *input_string, int *result);
int		ft_convert_string_to_integer_continue(const char *input_string,
			int string_index, int sign_value, int *result);
int		ft_is_list_sorted(t_node *list_head);

/* Utility stringhe */
char	**ft_split_string(char const *input_string, char delimiter);
char	**ft_split_string_continue(char const *input_string, char delimiter,
			char **result_array, int total_words);
char	*ft_create_substring(char const *source_string, unsigned int start_pos,
			size_t substring_length);
void	ft_free_string_array(char **string_array);

/* Parsing argomenti */
int		ft_parse_command_line_arguments(int argc, char **argv, t_node **stack_a);
int		ft_validate_and_convert_arguments(char **split_arguments, int *number_array,
			int argument_count);
int		ft_create_list_from_numbers(int *number_array, int array_size,
			t_node **stack_a);
int		ft_process_split_arguments(char **split_arguments, t_node **stack_a);
int		ft_process_direct_arguments(int argc, char **argv, t_node **stack_a);
int		ft_validate_direct_arguments(int argc, char **argv, int *number_array);

/* Funzioni del main */
int		ft_initialize_and_check(int argc, char **argv, t_node **stack_a);
void	ft_select_sort_method(t_node **stack_a, t_node **stack_b, int list_size);

/* Algoritmi di ordinamento */
void	ft_sort_two_numbers(t_node **stack_a);
void	ft_sort_three_numbers(t_node **stack_a);
void	ft_complete_three_sort(t_node **stack_a);
void	ft_sort_four_or_five_numbers(t_node **stack_a, t_node **stack_b,
			int list_size);
void	ft_sort_using_chunks(t_node **stack_a, t_node **stack_b);
void	ft_normalize_list_values(t_node **stack_a);

/* Operations */
void	ft_swap_top_elements(t_node **list_head);
void	ft_push_element(t_node **destination, t_node **source);
void	ft_rotate_list_up(t_node **list_head);
void	ft_rotate_list_down(t_node **list_head);

/* Funzioni di lista */
void	ft_append_node_to_list(t_node **list_head, t_node *new_node);
void	ft_prepend_node_to_list(t_node **list_head, t_node *new_node);
t_node	*ft_create_new_node(int number);
int		ft_get_list_size(t_node *list_head);
void	ft_free_linked_list(t_node *list_head);

/* Utility per algoritmi di ordinamento */
int		ft_find_value_position(t_node *list_head, int target_value);
int		ft_find_maximum_value(t_node *list_head);
int		ft_find_minimum_position(t_node *stack_a);
void	ft_rotate_to_minimum(t_node **stack_a, int min_position, int list_size);
void	ft_push_chunks_to_stack_b(t_node **stack_a, t_node **stack_b,
			int chunk_size, int total_chunks);
void	ft_rotate_stack_b(t_node **stack_b, int rotation_count, int use_reverse);
void	ft_pull_chunks_to_stack_a(t_node **stack_a, t_node **stack_b);

/* Esistenti */
int		ft_convert_string_to_integer(const char *input_string);
int		ft_validate_duplicates(int argc, char **argv);
t_node	**ft_create_number_list(int argc, char **argv);

#endif