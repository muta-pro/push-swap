/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:38:01 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/24 13:15:15 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "h_p_s.h"

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

// int main()
// {
// 	t_node *test_n;

// 	test_n = new_node(3);
// 	printf("%d\n", test_n->value);
// 	return (0);
// }

static void	free_node(int value)
{
	t_node	prev;
	t_node	curr;

	prev = NULL;
	curr = ?

}
void free_stack(t_stack **stack)
{
	//free nodes
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
	stack->size = 0;
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
t_node *remove_head(t_stack *stack, t_node node)
{
	t_node *holder;

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
		stack->head->prev = NULL;
	}
	holder->next = NULL;
	holder->prev = NULL;
	stack->stack_size--;
	return (holder);
}


void print_stack(t_stack **stack)
{
	t_node *temp;

	temp = stack->head;
	while (temp)
	{
		printf("%d \n", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
