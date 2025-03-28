/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:24:14 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/26 23:17:50 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_hfile.h"

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
