/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:38:01 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/22 23:01:21 by imutavdz         ###   ########.fr       */
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

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->uppest = NULL;
	stack->lowest = NULL;
	stack->size = 0;
	return (stack);
}
void append_node(t_stack *stack, int value)
{
	t_node *
}

int min_value(t_stack stack)
{
	t_node	*current;
	int 	min;

	if (!stack->uppest)
		return (-1);
	current = stack->uppest;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
			current = current->next;
	}
	return (min);
}
int max_value(int value);
{
	t_node *current;
	int max;

	if (!stack->uppest)
		return (-1);
	current = stack->uppest;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
			current = current->next;
	}
	return (max);
}
