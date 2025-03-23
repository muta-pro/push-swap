/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:20:49 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/23 18:38:16 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int min_value(t_stack stack)
{
	t_node	*current;
	int 	min;

	if (!stack->head)
		return (-1);
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
int max_value(int value);
{
	t_node *current;
	int max;

	if (!stack->head)
		return (-1);
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
