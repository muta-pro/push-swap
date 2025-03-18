/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_p_s.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:29:57 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/18 00:50:44 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
// # include "libft/libft.h"

typedef struct s_node
{
	int value;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_stack
{
	int *uppest;
	int *lowest;
	int size;
} t_stack;

void    sa(t_stack *a);           
void    sb(t_stack *b);           
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *b, t_stack *a);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

#endif