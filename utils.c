/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:20:49 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/06 03:05:03 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	is_overflow(char *str)//atol
{
	long long	result;
	int		i;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result > INT_MAX || result * sign < INT_MIN)
			return (1);
	}
	return (0);
}

int	is_valid_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (ft_isdigit(str[i]))
	{
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head || stack->head == stack->head->next)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	has_dup(t_stack *stack, int value)
{
	t_node	*current;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int min_value(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack->head)
		return (0);
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

int position_value(t_stack *stack, t_node value)
{
	t_node current;
	int position;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	position = 0;
	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->nextl
		position++;
	}
	return (-1);
}

void	fill_stack(t_stack *stack, int argc, char *argv[])
{
	int	i;
	int	value;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		value = atoi(argv[i]);//convert each arg into int
		node = new_node(value);
		add_head(stack, node);
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		printf("%d \n", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
void error_exit(const char *msg, t_stack *a, t_stack *b)
{
	write(2, msg, ft_strlen(msg));
	if (a)
		free_stack(&a);
	if (b)
		free_stack(&b);
	exit(1);
}