/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:32:38 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/05 18:43:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

	rrr(a, b);
	printf("A\n");
	print_stack(a);
	printf("B\n");
	print_stack(b);
	return 0;
}
