/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:06:25 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/01 19:26:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
OBJETIVE; take argv, convert to int, validate ints, with INT_MAX INT+MIN
validates and converts a string arg into an int
returns int value on success m 0 on error.
check dups, fill stack a;
call print error and exit(EXIT_FAILURE)
handle errors and exit
*/
#include "ps.h"

int	is_valid_arg(const char *str, long long *values)
{
	long		output;
	int			overflow;

	if (!is_valid_digit(str))
		return (0);
	output = ft_atol_ps(str, &overflow);
	if (overflow)
		return (0);
	*values = output;
	return (1); //success
}

int	fill_stack(t_stack **a, long long *holder, int size)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < size)
	{
		node = new_node((int)holder[i]);
		if (!node)
			return (0);
		add_tail(a, node);
		i++;
	}
	return (1); //success
}

int	has_dup(long long *holder, int size)
{
	int			i;
	int			j;

	i = 0;
	if (!holder)
		return (0);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (holder[i] == holder[j])
				return (1);//found
			j++;
		}
		i++;
	}
	return (0); //not found
}

int	valid_input(int argc, char *argv[], t_stack **a)
{
	long long	*holder;
	int			i;
	int			size;

	size = argc - 1;
	i = 1;
	holder = malloc(sizeof(long long) * size);
	if (!holder)
		return (0);
	while (i < argc)
	{
		if (!is_valid_arg(argv[i], &holder[i - 1])) //pass-by-reference approach
			clean_exit("Error\n", a, NULL, holder);
		i++;
	}
	if (has_dup(holder, size))
		clean_exit("Error\n", a, NULL, holder);
	if (!fill_stack(a, holder, size))
	{
		free(holder);
		return (0);
	}
	free (holder);
	return (1);
}

void	assign_pos(t_stack *a, int stack_size)
{
	int		*arr;
	// int		i;
	// t_node	*nodes;

	// nodes = a->head;
	// i = 0;
	arr = malloc(sizeof(int) * stack_size);
	if (!arr)
		return ;
	move_values(a, arr);
	sort_arr(arr, stack_size);
	assign_rank(a, arr, stack_size);
	// while (i < stack_size)
	// {
	// 	printf("%d/", arr[i]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// while (nodes)
	// {
	// 	printf("position:%d,\n value:%d\n", nodes->position, nodes->value);
	// 	nodes = nodes->next;
	// }
	free(arr);
}

// int	single_str_parsing(char *str, t_stack *a, t_stack *b)
// {
// 	char	**split;
// 	int		i;
// 	int		value;
// 	t_node	*node;

// 	split = ft_split(str, ' ');
// 	if (!split)
// 		return (error_exit("errpr\n", a, b), 0);
// 	i = 0;
// 	while (split[i])
// 	{
// 		value = is_valid_arg(split[i], a, b);
// 		if (value == 0)
// 			return (free_split(split), 0);
// 		node = new_node(value);
// 		if (!node)
// 		{
// 			free_split(split);
// 			error_exit("error\n", a, b);
// 			return (0);
// 		}
// 		add_tail(a, node);
// 		i++;
// 	}
// 	return (free_split(split), 1);
// }