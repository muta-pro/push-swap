/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:46:15 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/09 22:51:32 by imutavdz         ###   ########.fr       */
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
	t_stack		*a;
	t_stack		*b;
	// int			size;

	if (argc < 2)
		return (0);
	// size = argc - 1;
	a = init_stack();
	if (!a)
		return (0);
	if (!valid_input(argc, argv, a))
		clean_exit("Error\n", &a, NULL, NULL);
	b = init_stack();
	if (!b)
		clean_exit("Error\n", &a, NULL, NULL);
	print_stack(a);
	// assign_pos(&a, size);
	// if (a->stack_size > 1 && !is_sorted(a))
	// 	ultimate_sorter(&a, &b);
	// else
	// {
	// 	free_stack(&a);
	// 	free_stack(&b);
	// }
	return (0);
}
