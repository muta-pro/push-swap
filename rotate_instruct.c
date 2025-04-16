/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:24:14 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/12 00:09:01 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	rot_up(t_stack **stack) //moving the head to the tail
{
	if (!stack || !(*stack))
		return ;
	add_tail(stack, remove_head(*stack));
}

void	ra(t_stack **a)
{
	if (!a || !(*a) || (*a)->stack_size < 2)
		return ;
	rot_up(a);
	printf("ra\n");
}

void	rb(t_stack **b)
{
	if (!b || !(*b) || (*b)->stack_size < 2)
		return ;
	rot_up(b);
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	if ((!a || !(*a) || (*a)->stack_size < 2)
		&& (!b || !(*b) || (*b)->stack_size < 2))
		return ;
	rot_up(a);
	rot_up(b);
	printf("rr\n");
}
