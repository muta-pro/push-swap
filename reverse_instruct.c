/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:53:06 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/12 00:01:42 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
//we use nested functions to reverse rotate

void	rot_down(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	add_head(stack, remove_tail(*stack));
}

void	rra(t_stack **a)
{
	if (!a || !(*a) || (*a)->stack_size < 2)
		return ;
	rot_down(a);
	printf("rra\n");
}

void	rrb(t_stack **b)
{
	if (!b || !(*b) || (*b)->stack_size < 2)
		return ;
	rot_down(b);
	printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((!a || !(*a) || (*a)->stack_size < 2)
		&& (!b || !(*b) || (*b)->stack_size < 2))
		return ;
	rot_down(a);
	rot_down(b);
	printf("rrr\n");
}

// void	rot_down(t_stack **stack)// reverse rotate rra rrb rrr
// {
// 	t_node	*holder;

// 	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
// 		return ;
// 	holder = (*stack)->tail;
// 	(*stack)->tail = (*stack)->tail->prev;
// 	(*stack)->tail->next = NULL;
// 	holder->next = (*stack)->head;
// 	holder->prev = NULL;
// 	(*stack)->head->prev = holder;
// 	(*stack)->head = holder;
// }