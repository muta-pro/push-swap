/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:06:25 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/06 15:34:53 by imutavdz         ###   ########.fr       */
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

static int	is_valid_arg(char *str, t_stack *a, t_stack *b)
{
	long	value;
	int		overflow;

	if (!is_valid_digit(str))
		return (error_exit("Error\n", a, b), 0);
	if (is_overflow(str))
	{
		error_exit("Error\n", a, b);
		return (0);
	}
	value = ft_atol_ps(str, &overflow);
	if (overflow)
		return (error_exit("error\n", a, b), 0);
	if (has_dup(a, (int)value))
	{
		return (error_exit("Error\n", a, b), 0);
	}
	return ((int)value);
}

int	single_str_parsing(char *str, t_stack *a, t_stack *b)
{
	char	**split;
	int		i;
	int		value;
	t_node	*node;

	split = ft_split(str, ' ');
	if (!split)
		return (error_exit("errpr\n", a, b), 0);
	i = 0;
	while (split[i])
	{
		value = is_valid_arg(split[i], a, b);
		if (value == 0)
			return (free_split(split), 0);
		node = new_node(value);
		if (!node)
		{
			free_split(split);
			error_exit("error\n", a, b);
			return (0);
		}
		add_tail(a, node);
		i++;
	}
	return (free_split(split), 1);
}

int	multi_args_parsing(int argc, char **argv[], t_stack *a, t_stack *b)
{
	int		i;
	int		value;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		value = is_valid_arg(*argv[i], a, b);
		if (value == 0)
			return (0);
		node = new_node(value);
		if (!node)
			return (error_exit("error\n", a, b), 0);
		add_tail(a, node);
		i++;
	}
	return (1);
}

int	parse_input(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int	result;

	if (argc < 2)
		return (0);
	if (argc == 2)
		result = single_str_parsing(argv[1], a, b);
	else
		result = multi_args_parsing(argc, &argv, a, b);
	if (result)
		assign_pos(a);
	return (result);
}
