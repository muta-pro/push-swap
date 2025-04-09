/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:46:15 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/09 01:27:03 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//print stack should show value + position
#include "ps.h"
// int main(int argc, char *argv[])
// {
// 	t_stack *a;
// 	t_stack *b;

// 	a = init_stack();
// 	b = init_stack();
// 	if (!a || !b)
// 		return (1);
// 	fill_stack(a, argc, argv);
// 	print_stack(a);
// 	return 0;
// }

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!valid_input(argc, argv))
		return (error_exit("error\n"));
	a = init_stack();
	if (!a)
		error_exit("Error\n");
	b = init_stack();
	if (!b)
	{
		error_exit("Error\n");
		free_stack(&a);
		free_stack(&b);
	}
	fill_stack(&a, argv, argc -1);
	assign_pos(&a, argc - 1);
	if (a->stack_size > 0 && !is_sorted(a))
		ultimate_sorter(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
