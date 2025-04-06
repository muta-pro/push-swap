/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:23:55 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/05 18:43:08 by imutavdz         ###   ########.fr       */
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

void	sa(t_stack *a)
{
	printf("sa\n");
	swap(&a);
}
void	sb(t_stack *b)
{
	printf("sb\n");
	swap(&b);
}
void	ss(t_stack *a, t_stack *b)
{
	printf("ss\n");
	swap(&a);
	swap(&b);
}
