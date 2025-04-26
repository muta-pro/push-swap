/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:23:55 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/26 01:33:59 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	swap(t_stack **stack)//single stack operations sa sb
{
	int	holder;

	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	holder = (*stack)->head->value;
	(*stack)->head->value = (*stack)->head->next->value;
	(*stack)->head->next->value = holder;
}

void	sa(t_stack **a)
{
	if (!a || !(*a) || (*a)->stack_size < 2)
		return ;
	swap(a);
	get_move_count(true);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b)
{
	if (!b || !(*b) || (*b)->stack_size < 2)
		return ;
	swap(b);
	get_move_count(true);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	if ((!b || !a || !(*b) || !(*a))
		&& ((*a)->stack_size < 2 || (*b)->stack_size < 2))
		return ;
	swap(a);
	swap(b);
	get_move_count(true);
	ft_putendl_fd("ss", 1);
}
