/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:06:25 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/06 03:44:07 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
OBJETIVE; take argv, convert to int, validate ints, with INT_MAX INT+MIN
check dups, fill stack a;
call print error and exit(EXIT_FAILURE)
handle errors and exit
*/
#include "ps.h"

static int	is_valid_arg(char *str, t_stack *a, t_stack *b)
{
	long	value;
	int		int_value;

	if (!is_valid_digit(str))
	{
		error_exit("Error\n", a, b);
		return (0);
	}
	if (is_overflow(str))
	{
		error_exit("Error\n", a, b);
		return (0);
	}
	int_value = (int)value;
	if (!has_dup(a, value))
	{
		error_exit("Error\n", a, b);
		return (0);
	}
	return (1);
}

int	parse_input(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int			i;
	char		**split;

	split = NULL;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			error_exit("error", a, b);
		return (0);
	}
	i = 0;
	while (split)
	{
		if (!is_valid_arg(split[i], a, b))
		{
			free_split(split);
			return (0);
		}
		fill_stack(a, argc, argv);
		add_tail(*a, new_node);
		assign_pos(&a);
	}
}
