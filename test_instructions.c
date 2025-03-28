/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:32:38 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/26 23:28:50 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_hfile.h"

// int main(int argc, char *argv[])
// {
// 	t_stack *a, *b;
// 	a = init_stack();
// 	b = init_stack();
// 	fill_stack(b, argc, argv);
// 	// sb(b);
// 	ss(a, b);
// 	print_stack(b);
// 	printf("\n");
// 	print_stack(a);
// 	return 0;
// }
int main(int argc, char *argv[])
{
	t_stack *a, *b;
	a = init_stack();
	b = init_stack();
	fill_stack(a, argc, argv);
	fill_stack(b, argc, argv);
	ra(a);
	rb(b);
	print_stack(b);
	printf("\n");
	print_stack(a);
	return 0;
}
