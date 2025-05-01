/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:53:16 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/22 16:48:06 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (new_node == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
