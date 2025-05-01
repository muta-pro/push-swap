/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optima.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:04:03 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/26 00:28:17 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
/*
/calc how many steps we are away from the top to prepare the target
/approach in insertion based sorting alg
finds index in B what should be a the top before pushing to B
return index of B that should be rotatet
*/
int	find_target_b(int position_to_pb, t_stack *b)
{
	t_node	*curr_b;
	int		target;
	int		min_pos;
	int		max_pos;
	int		index;

	if (!b || !b->head)
		return (0);
	curr_b = b->head;
	target = -1; //means not found yet ??
	min_pos = INT_MIN;
	max_pos = max_value(b);
	index = 0;
	while (curr_b)
	{
		if (curr_b->position < position_to_pb)
		{
			if (curr_b->position > min_pos)
			{
				min_pos = curr_b->position;
				target = index;
			}
		}
		curr_b = curr_b->next;
		index++;
	}
	if (target == -1)
		target = max_pos;
	return (target);
}

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

int	max_value(t_stack *stack)
{
	t_node	*curr;
	int		max;
	int		index;
	int		position;

	if (!stack->head)
		return (0);
	index = 0;
	position = 0;
	curr = stack->head;
	max = curr->position;
	while (curr)
	{
		if (curr->position > max)
		{
			max = curr->position;
			index = position;
		}
		curr = curr->next;
		position++;
	}
	return (index); //for rotation calculations
}
// int	find_t_distance(t_stack *a, int start_pos, int end_pos)
// {
// 	t_node	*current;
// 	int		dist;

// 	current = a->head;
// 	dist = 0;
// 	while (current)
// 	{
// 		if (current->position >= start_pos && current->position <= end_pos)
// 			return (dist);
// 		current = current->next;
// 		dist++;
// 	}
// 	return (-1);
// }

// int	find_b_distance(t_stack *a, int start_pos, int end_pos)
// {
// 	t_node	*current;
// 	int		dist;

// 	current = a->tail;
// 	dist = 1;
// 	while (current)
// 	{
// 		if (current->position >= start_pos && current->position <= end_pos)
// 			return (dist);
// 		current = current->prev;
// 		dist++;
// 	}
// 	return (-1);
// }
