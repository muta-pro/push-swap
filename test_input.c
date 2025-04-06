/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:46:15 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/06 15:34:44 by imutavdz         ###   ########.fr       */
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
	t_stack	*a = NULL;

	if (!parse_input(argc, argv, &a))
		return (1);
	assign_pos(&a, a->stack_size);
	print_stack(a);
	free_stack(&a);
	return (0);
}
