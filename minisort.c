/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:09:43 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/14 23:05:54 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
/*
assign positions to each variable insted of value to sort
*/

void	three_sort(t_stack *a)
{
	int	one;
	int	two;
	int	three;

	if (!a || !a->head || !a->head->next || !a->head->next->next)
		return ;
	one = a->head->position;
	two = a->head->next->position;
	three = a->head->next->next->position;
	if (one > two && two < three && one < three) /*213*/
		sa(&a);
	else if (two < one && one > three && two > three) /*321*/
	{
		ra(&a);
		sa(&a);
	}
	else if (one < two && two > three && one > three) /*231*/
		rra(&a);
	else if (one < two && two > three && one < three) /*132*/
	{
		sa(&a);
		ra(&a);
	}
	else if (one > two && two < three && one > three) /*312*/
		ra(&a);
}

void	four_sort(t_stack **a, t_stack **b)
{
	int		min_rank;
	t_node	*curr;
	int		count;

	curr = (*a)->head;
	count = 0;
	min_rank = min_value(*a);
	while (curr && curr->position != min_rank)
	{
		count++;
		curr = curr->next;
	}
	if (count < (*a)->stack_size / 2)
		while ((*a)->head->position != min_rank)
			ra(a);
	else
		while ((*a)->head->position != min_rank)
			rra(a);
	pb(b, a);
	three_sort(*a);
	pa(a, b);
}

void	five_sort(t_stack **a, t_stack **b)
{
	int		min_rank;
	t_node	*curr;
	int		count;

	count = 0;
	curr = (*a)->head;
	min_rank = min_value(*a);
	while (curr && curr->position != min_rank)
	{
		count++;
		curr = curr->next;
	}
	if (count < (*a)->stack_size / 2)
		while ((*a)->head->position != min_rank)
			ra(a);
	else
		while ((*a)->head->position != min_rank)
			rra(a);
	pb(b, a);
	four_sort(a, b);
	pa(a, b);
}

void	minisort(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
		sa(&a);
	else if (size == 3)
		three_sort(a);
	else if (size == 4)
		four_sort(&a, &b);
	else if (size == 5)
		five_sort(&a, &b);
}
