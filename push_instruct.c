/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:23:45 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/26 22:43:12 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_hfile.h"

void	push(t_stack **dest, t_stack **src)
{
	t_node	*node;

	if (!src || !*src || !(*src)->head || !dest || !*dest)
		return ;
	node = remove_head(*src);
	add_head(*dest, node);
}

void	pa(t_stack *a, t_stack *b)
{
	printf("pa\n");
	push(&a, &b);
}

void	pb(t_stack *a, t_stack *b)
{
	printf("pb\n");
	push(&b, &a);
}

//WRITE TEST FUNCTIONS
// void pa(stack *a, stack *b)
// {
// 	if (b->head >= 0)
// 	{
// 		a->[++(a->head)] = b->
// 	}
// }