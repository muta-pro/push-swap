/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:32:52 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/25 01:12:30 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_hfile.h"
//this file is to test my doubly linked list functions
//first we create the node and see it exist.
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
//we test
t_stack *init_stack()
{
	t_stack *stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->stack_size = 0;
	return (stack);
}

void add_head(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return;
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->stack_size++;
}
void	free_node(t_node *node)
{
	if (node)
		free(node);
	node = NULL;
}

void free_stack(t_stack **stack)
{
	t_node *node;
	t_node *next_node;

	if (!stack || !*stack)
		return;
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

int main()
{
	t_node *node = new_node(99);
	printf("node values\n");
	printf("value:%p\n", node->next);
	printf("value:%d\n", node->value);
	printf("value:%p\n", node->prev);
	printf("value:%p\n", node);
	printf("_\n");

	t_stack *stack = init_stack();
	printf("stack values\n");
	printf("value:%p\n", stack->head);
	printf("value:%p\n", stack->tail);
	printf("value:%d\n", stack->stack_size);
	printf("_\n");

	add_head(stack, node);
	printf("added head\n");
	printf("value:%p\n", stack->head);
	printf("value:%p\n", stack->tail);
	printf("value:%d\n", stack->stack_size);
	printf("_\n");
	printf("value:%p\n", stack->head->prev);
	printf("value:%p\n", stack->head->next);
	printf("value:%d\n", stack->head->value);
	printf("value:%p\n", stack->head);

	t_node *node1 = new_node(01);
	printf("node1 values\n");
	printf("value:%p\n", node1->next);
	printf("value:%d\n", node1->value);
	printf("value:%p\n", node1->prev);
	printf("value:%p\n", node1);
	printf("_\n");

	add_head(stack, node1);
	printf("stack values\n");
	printf("value:%p\n", stack->head);
	printf("value:%p\n", stack->tail);
	printf("value:%d\n", stack->stack_size);
	printf("_\n");
	printf("value:%p\n", stack->head->prev);
	printf("value:%p\n", stack->head->next);
	printf("value:%d\n", stack->head->value);
	printf("value:%p\n", stack->head);
	printf("_\n");
	free_stack(&stack);
	if (stack == NULL)
		printf("free stack!\n");
	return (0);
}
