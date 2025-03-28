/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:20:49 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/26 23:29:02 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_hfile.h"

// int is_sorted(t_stack *stack)
// {
// 	t_node current;

// 	if (!stack || !stack->head)
// 		return (1);
// 	current = stack->head;
// 	while (current->next)
// 	{
// 		if (current->value > stack->next->value)
// 			return (0);
// 		current = current->next;
// 	}
// 	return (1);
// }

int min_value(t_stack *stack)
{
	t_node	*current;
	int 	min;

	if (!stack->head)
		return (0);
	current = stack->head;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
			current = current->next;
	}
	return (min);
}
int max_value(t_stack *stack)
{
	t_node *current;
	int max;

	if (!stack->head)
		return (0);
	current = stack->head;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
			current = current->next;
	}
	return (max);
}

// int position_value(t_stack *stack, t_node value)
// {
// 	t_node current;
// 	int position;

// 	if (!stack || !stack->head)
// 		return (-1);
// 	current = stack->head;
// 	position = 0;
// 	while (current)
// 	{
// 		if (current->value == value)
// 			return (position);
// 		current = current->nextl
// 		position++;
// 	}
// 	return (-1);
// }

void fill_stack(t_stack *stack, int argc, char *argv[])
{
	int i;
	int value;
	t_node *node;

	i = 1;
	while (i < argc)
	{
		value = atoi(argv[i]);//convert each arg into int
		node = new_node(value);
		add_head(stack, node);
		i++;
	}
}

void print_stack(t_stack *stack)
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
