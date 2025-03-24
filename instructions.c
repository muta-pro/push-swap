/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:53:06 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/24 13:15:22 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void rot_up(t_stack *stack)//moving the head to the tail
{
	t_node *holder;

	if (!stak || !stack->head || !stack->head->next)
		return ;
	holder = stack->head; //node to be moved at the bottom
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = holder;
	stack->prev = stack->tail;
	temp->next = NULL;
	stack->tail = temp;
}

void ra(t_stack **a)
{
	rot_up(&a)

}
void rb(t_stack **b)
{
	rot_up(&b);
}

void push(t_stack *dest, t_stack *src)
{
	t_node *node;

	node = remove_head(src);
	if (!src || !src->head || !dest || !dest)
		return ;
	add_head(dest, node);
}

void pa(t_stack *a, t_stack *b)
{
	push(&a, &b);
}
void pb(t_stack *b, t_stack *a)
{
	push(&b, &a);
}

// void pa(stack *a, stack *b)
// {
// 	if (b->head >= 0)
// 	{
// 		a->[++(a->head)] = b->
// 	}
// }

void swap(t_stack *stack)//single stack operations sa sb
{
	t_node holder;

	if (!stack || !stack->head || !stack->head->next)
		retutn;
	holder = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = holder;
}

void sa(t_stack *a)
{
	swap(&a);
}
void sb(t_stack *b)
{
	swap(&b);
}
void ss(t_stack *a, t_stack *b)
{
	swap(&a);
	swap(&b);
}

void rot_down(t_stack *stack)// reverse rotate rra rrb rrr
{
	t_node holder;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	holder = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	holder->next = stack->head;
	holder->prev = NULL;
	stack->head->prev = holder;
	stack->head = holder;
}

void rra(t_stack *a)
{
	rot_down(&a);
}

void rrb(t_stack *b)
{
	rot_down(&b);
}

void rrr(t_stack *a, t_stack *b)
{
	rot_down(*a);
	rot_down(*b);
}

//WRITE TEST FUNCTIONS