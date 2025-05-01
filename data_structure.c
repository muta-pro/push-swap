/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:38:01 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/11 16:40:01 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
//doubly linked list

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_node(t_node *node)
{
	if (node)
		free(node);
	node = NULL;
}

void	free_stack(t_stack **stack)
{
	t_node	*node;
	t_node	*next_node;

	if (!stack || !*stack)
		return ;
	node = (*stack)->head;
	while (node)
	{
		next_node = node->next;
		free_node(node);
		node = next_node;
	}
	free(*stack);
	*stack = NULL;
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->stack_size = 0;
	return (stack);
}
