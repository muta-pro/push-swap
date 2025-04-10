/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:06:25 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/09 22:52:44 by imutavdz         ###   ########.fr       */
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
		clean_exit("Error: invalid digit\n", NULL, NULL, NULL);
	output = ft_atol_ps(str, &overflow);
	if (overflow)
		clean_exit("Error: overflow\n", NULL, NULL, NULL);
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

int	valid_input(int argc, char *argv[], t_stack *a)
{
	long long	*holder;
	int			i;
	int			size;

	size = argc - 1;
	i = 1;
	holder = malloc(sizeof(long long) * size); //?
	if (!holder)
		return (0);
	while (i < argc)
	{
		if (!is_valid_arg(argv[i], &holder[i - 1])) //pass-by-reference approach
			clean_exit("Error\n", NULL, NULL, holder);
		i++;
	}
	if (has_dup(holder, size))
		clean_exit("Error: has duplicate\n", NULL, NULL, holder);
	if (!fill_stack(&a, holder, size))
	{
		free(holder);
		return (0);
	}
	free (holder);
	return (1);
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