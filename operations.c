/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:53:06 by imutavdz          #+#    #+#             */
/*   Updated: 2025/02/22 20:10:53 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void rot_up(t_stack *stack)
{
	t_node *prev_up;
	t_node *next_up;
	t_node *prev_low;

	if (!stack->uppest || !stack->uppest->next)
		return;
	prev_up = stack->uppest;
	prev_low = stack->lowest;
	next_up = stack->uppest->next;
	stack->top = new_top;
    stack->bottom = old_top;
    old_bottom->next = old_top;
    old_top->prev = old_bottom;
    old_top->next = NULL;
}

void push(t_stack *stack, int value)
{
	t_node *node;

	node = new_node(value);
	if (!node)
		return ;
	if (!stack->uppest)
	{
		stack->lowest = node;
		stack->uppest = node;
	}
	else
	{
		node->prev = stack->uppest;
		stack->uppest->next = node;
		stack->uppest = node;
	}
	stack->size++;
}