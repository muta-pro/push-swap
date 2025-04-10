/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:20:49 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/09 20:30:56 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

long	ft_atol_ps(const char *str, int *overflow)//atol
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	*overflow = 0; //the output parameter
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str++ - '0');
		if (is_overflow(result, sign))
		{
			*overflow = 1;
			return (result);
		}
	}
	return ((long)(result * sign));
}

int	is_overflow(long long result, int sign)
{
	if (sign == 1 && result > INT_MAX)
		return (1);
	else if (sign == -1 && result > (long long)INT_MAX + 1)
		return (1);
	return (0);
}

int	is_valid_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]))
	{
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	has_dup(long long *holder, int size)
{
	int			i;
	int			j;

	i = 0;
	if (!holder)
		return (0);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (holder[i] == holder[j])
				return (1);//found
			j++;
		}
		i++;
	}
	return (0); //not found
}

// int	is_sorted(t_stack *stack)
// {
// 	t_node	*current;

// 	if (!stack || !stack->head || stack->head == stack->head->next)
// 		return (1);
// 	current = stack->head;
// 	while (current->next)
// 	{
// 		if (current->value > current->next->value)
// 			return (0);
// 		current = current->next;
// 	}
// 	return (1); //is sorted
// }

// void	fill_stack(t_stack *stack, int argc, char *argv[])
// {
// 	int	i;
// 	int	value;
// 	t_node	*node;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		value = atoi(argv[i]);//convert each arg into int
// 		node = new_node(value);
// 		add_head(stack, node);
// 		i++;
// 	}
// }
// int min_value(t_stack *stack)
// {
// 	t_node	*current;
// 	int		min;

// 	if (!stack->head)
// 		return (0);
// 	current = stack->head;
// 	min = current->value;
// 	while (current)
// 	{
// 		if (current->value < min)
// 			min = current->value;
// 		current = current->next;
// 	}
// 	return (min);
// }
// int max_value(t_stack *stack)
// {
// 	t_node *current;
// 	int max;

// 	if (!stack->head)
// 		return (0);
// 	current = stack->head;
// 	max = current->value;
// 	while (current)
// 	{
// 		if (current->value > max)
// 			max = current->value;
// 			current = current->next;
// 	}
// 	return (max);
// }

// int position_value(t_stack *stack, t_node value)
// {
// 	t_node current;
// 	int position;

// 	if (!stack || !stack->head)
// 		return (-1);
// 	current = stack->head;
// 	position = 0;
// 	while (current)
// 	{
// 		if (current->value == value)
// 			return (position);
// 		current = current->nextl
// 		position++;
// 	}
// 	return (-1);
// }

void	print_stack(t_stack *stack)
{
	t_node	*temp;
	int count;

	temp = stack->head;
	count = 0;
	while (count < stack->stack_size)
	{
		printf("%d \n", temp->value);
		temp = temp->next;
		count++;
	}
	printf("\n");
}

void	clean_exit(const char *msg, t_stack **a, t_stack **b, void *ptr)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (ptr)
		free(ptr);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}
