/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:23:45 by imutavdz          #+#    #+#             */
/*   Updated: 2025/05/01 19:19:05 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	push(t_stack **dest, t_stack **src)
{
	if (!src || !*src || !(*src)->head)
		return ;
	add_head(dest, remove_head(*src));
}

void	pa(t_stack **a, t_stack **b)
{
	if (!a || !b || !(*b) || !(*b)->head)
		return ;
	push(a, b);
	get_move_count(true);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **b, t_stack **a)
{
	if (!a || !b || !(*a) || !(*a)->head)
		return ;
	push(b, a);
	get_move_count(true);
	ft_putendl_fd("pb", 1);
}
