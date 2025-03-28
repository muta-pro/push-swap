/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:46:15 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/26 23:28:54 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_hfile.h"

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (1);
	fill_stack(a, argc, argv);
	print_stack(a);
	return 0;
}
