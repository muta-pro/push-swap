/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:33:37 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/01 18:46:28 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
//element selection strategy - with lowest cost to move
//B stack organisation keeping it relatively sorted
//to execute cheapesst move optimising with rr and rrr
void	best_move(t_stack **a, t_stack **b, t_cost cheapest)
{
	int	cost_a;
	int	cost_b;

	cost_a = cheapest.cost_a;
	cost_b = cheapest.cost_b;
	if (cost_a > 0 && cost_b > 0)
	{
		do_rr(a, b, &cost_a, &cost_b);
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		do_rrr(a, b, &cost_a, &cost_b);
	}
	best_move_a(a, cost_a);
	best_move_b(b, cost_b);
	pb(b, a);
}

void	best_move_a(t_stack **a, int cost_a)
{
	int	i;

	i = 0;
	if (cost_a > 0)
	{
		while (i < cost_a)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < -cost_a)
		{
			rra(a);
			i++;
		}
	}
}

void	best_move_b(t_stack **b, int cost_b)
{
	int	i;

	i = 0;
	if (cost_b > 0)
	{
		while (i < cost_b)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		while (i < -cost_b)
		{
			rrb(b);
			i++;
		}
	}
}

void	do_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	int	possible_rot;
	int	i;

	i = 0;
	if (*cost_a < *cost_b)
		possible_rot = *cost_a;
	else
		possible_rot = *cost_b;
	while (i < possible_rot)
	{
		rr(a, b);
		i++;
	}
	*cost_a = *cost_a - possible_rot;
	*cost_b = *cost_b - possible_rot;
}

void	do_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	int	possible_rot;
	int	i;
	int	absolute_a;
	int	absolute_b;

	i = 0;
	absolute_a = -(*cost_a);
	absolute_b = -(*cost_b);
	if (absolute_a < absolute_b)
		possible_rot = absolute_a;
	else
		possible_rot = absolute_b;
	while (i < possible_rot)
	{
		rrr(a, b);
		i++;
	}
	*cost_a = *cost_a + possible_rot;
	*cost_b = *cost_b + possible_rot;
}

	// int	chunk_size;
	// int	top_dist;
	// int	bottom_dist;

	// calc_tot_cost(a, b,  start_pos, end_pos);
	// top_dist = find_t_distance(*a, start_pos, end_pos);
	// bottom_dist = find_b_distance(*a, start_pos, end_pos);
	// if (top_dist == -1 && bottom_dist == -1)
	// 	return ;
	// if ((top_dist != -1 && top_dist <= bottom_dist) || bottom_dist == -1)
	// {
	// 	while (top_dist-- > 0)
	// 		ra(a);
	// }
	// else
	// {
	// 	while (bottom_dist-- > 0)
	// 		rra(a);
	// }
	// chunk_size = end_pos - start_pos;
	// pb(b, a);
	// if ((*b)->head->position < start_pos + chunk_size / 2)
	// 	rb(b);