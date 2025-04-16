/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:46:15 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/13 23:39:18 by imutavdz         ###   ########.fr       */
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

	if (argc < 2)
		return (0);
	a = init_stack();
	if (!a)
		return (0);
	if (!valid_input(argc, argv, &a))
		clean_exit("Error\n", &a, NULL, NULL);
	b = init_stack();
	if (!b)
		clean_exit("Error\n", &a, NULL, NULL);
	print_stack(a);
	assign_pos(a, a->stack_size);
	if (a->stack_size > 1 && !is_sorted(a))
	{
		sa(&a);
		print_stack(a);
		printf("stack B\n");
		print_stack(b);
	}
	else
		clean_exit("byebye! is sorted :)\n", &a, &b, NULL);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
