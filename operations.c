/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:53:06 by imutavdz          #+#    #+#             */
/*   Updated: 2025/02/22 18:55:52 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void pull_up(t_stack *stack)
{
	if (!stack->uppest || !stack->uppest->next)
		return;
	t_node *prev_up = stack->uppest;
	t_node *next_up = stack->uppest->next;
	t_node *prev_low = stack->lowest;	
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