/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optima.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:04:03 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/17 01:52:25 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
/*

*/

int	position_target(t_stack *stack, int target)
{
	t_node	*current;
	int		position;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	position = 0;
	while (current)
	{
		if (current->position == target)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	find_t_distance(t_stack *a, int start_pos, int end_pos)
{
	t_node	*current;
	int		dist;

	current = a->head;
	dist = 0;
	while (current)
	{
		if (current->position >= start_pos && current->position <= end_pos)
			return (dist);
		current = current->next;
		dist++;
	}
	return (-1);
}

int	find_b_distance(t_stack *a, int start_pos, int end_pos)
{
	t_node	*current;
	int		dist;

	current = a->tail;
	dist = 1;
	while (current)
	{
		if (current->position >= start_pos && current->position <= end_pos)
			return (dist);
		current = current->prev;
		dist++;
	}
	return (-1);
}

int	min_value(t_stack *stack)
{
	t_node	*current;
	int		min_rank;

	if (!stack->head)
		return (-1);
	current = stack->head;
	min_rank = current->position;
	while (current)
	{
		if (current->position < min_rank)
			min_rank = current->position;
		current = current->next;
	}
	return (min_rank);
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