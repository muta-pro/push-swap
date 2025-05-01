/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:28:13 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/24 20:06:01 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
//doubly linked list
//add/remove head tail are crucial for push and reverse op

t_node	*remove_head(t_stack *stack)
{
	t_node	*holder;

	if (!stack || !stack->head)
		return (NULL);
	holder = stack->head;
	if (stack->head == stack->tail)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = stack->head->next;
		if (stack->head)
			stack->head->prev = NULL;
	}
	holder->next = NULL;
	holder->prev = NULL;
	stack->stack_size--;
	return (holder);
}

t_node	*remove_tail(t_stack *stack)
{
	t_node	*holder;

	if (!stack || !stack->tail)
		return (NULL);
	holder = stack->tail;
	if (stack->head == stack ->tail)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
	}
	holder->next = NULL;
	holder->prev = NULL;
	stack->stack_size--;
	return (holder);
}

void	add_head(t_stack **stack, t_node *node)
{
	if (!stack || !node || !*stack) //if node is null
		return ;
	if (!(*stack)->head) //empty list
	{
		(*stack)->head = node;
		(*stack)->tail = node;
	}
	else
	{
		node->next = (*stack)->head;//new A node points next to B
		(*stack)->head->prev = node;//prev pointer of B points to A node
		(*stack)->head = node;//head pointer points to A node
	}
	(*stack)->stack_size++;
}

void	add_tail(t_stack **stack, t_node *node)
{
	if (!stack || !node || !*stack)
		return ;
	if (!(*stack)->tail)
	{
		(*stack)->tail = node;
		(*stack)->head = node;
	}
	else
	{
		node->prev = (*stack)->tail; //new node A prev points to B
		(*stack)->tail->next = node; //pointing next B to node A
		(*stack)->tail = node;
	}
	(*stack)->stack_size++;
}

void	clean_exit(const char *msg, t_stack **a, t_stack **b, void *ptr)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (ptr)
		free(ptr);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}
