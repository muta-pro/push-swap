/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:30:23 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/24 20:56:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
//how much to bring element to the top
//how much to position the target at the top
//calculate the total cost and choose the one with minimum cost
//calcuate cost already determened by position in current chunk
// t_cost	find_cheapest(t_stack **a, t_stack **b);
//Finds which node in B to place above, based on the element's position.

int	calc_cost_to_top(t_stack *a, int position)
{
	int		cost;
	t_node	*curr;
	int		index;

	index = 0;
	curr = a->head;
	while (curr && curr->position != position)
	{
		curr = curr->next;
		index++;
	}
	if (index <= a->stack_size / 2)
		cost = index;
	else
		cost = -(a->stack_size - index);
	return (cost);
}

int	calc_cost_top_target(t_stack *b, int target_pos)
{
	t_node	*curr;
	int		index;

	curr = b->head;
	index = 0;
	while (curr && curr->position != target_pos)
	{
		curr = curr->next;
		index++;
	}
	if (index <= b->stack_size / 2)
		return (index); //rb
	else
		return (-(b->stack_size - index)); //rrb
}

int	calc_cost_total(int cost_a, int cost_b)
{
	int	absolute_a;
	int	absolute_b;

	if (cost_a < 0)
		absolute_a = -cost_a;
	else
		absolute_a = cost_a;
	if (cost_b < 0)
		absolute_b = -cost_b;
	else
		absolute_b = cost_b;
//chek if both are movin in same direction, up or down
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (absolute_a > absolute_b)
			return (absolute_a);
		else
			return (absolute_b);
	}
	else
		return (absolute_a + absolute_b);
}

//loop A in the curr chunk and calc total cost
//where should node go in B
//how much cost rotate A and B
//combine cost
//track cheapest
t_cost	find_cheapest(t_stack **a, t_stack **b, int start_pos, int end_pos)
{
	t_node	*curr;
	t_cost	cheapest;
	t_cost	temp;
	int		best_tot;

	best_tot = INT_MAX;
	curr = (*a)->head;
	while (curr)
	{
		if (curr->position >= start_pos && curr->position <= end_pos)
		{
			temp.pos_to_pb = curr->position;
			temp.target_a = find_target_pos(curr->position, *b);
			temp.cost_a = calc_cost_to_top(*a, curr->position);
			temp.cost_b = calc_cost_top_target(*b, temp.target_a);
			temp.totalcost = calc_cost_total(temp.cost_a, temp.cost_b);
			if (temp.totalcost < best_tot)
			{
				best_tot = temp.totalcost;
				cheapest = temp;
			}
		}
		curr = curr->next;
	}
	return (cheapest); //the best move we found so far
}
