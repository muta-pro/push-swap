/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:24:14 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/06 15:35:30 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	rot_up(t_stack **stack)//moving the head to the tail
{
	t_node	*holder;

	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	holder = (*stack)->head; //node to be moved at the bottom
	(*stack)->head = (*stack)->head->next;
	(*stack)->head->prev = NULL;
	(*stack)->tail->next = holder;
	holder->prev = (*stack)->tail;
	holder->next = NULL;
	(*stack)->tail = holder;
}

void	ra(t_stack *a)
{
	printf("ra\n");
	rot_up(&a);
}

void	rb(t_stack *b)
{
	printf("rb\n");
	rot_up(&b);
}

void	rr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	rot_up(&a);
	rot_up(&b);
}
