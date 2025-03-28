/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:53:06 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/24 21:31:33 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_hfile.h"

void rot_down(t_stack *stack)// reverse rotate rra rrb rrr
{
	t_node holder;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	holder = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	holder->next = stack->head;
	holder->prev = NULL;
	stack->head->prev = holder;
	stack->head = holder;
}

void rra(t_stack *a)
{
	printf("rra\n");
	rot_down(&a);
}

void rrb(t_stack *b)
{
	printf("rrb\n");
	rot_down(&b);
}

void rrr(t_stack *a, t_stack *b)
{
	printf("rrr");
	rot_down(*a);
	rot_down(*b);
}
