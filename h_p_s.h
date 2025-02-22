/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_p_s.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:29:57 by imutavdz          #+#    #+#             */
/*   Updated: 2025/02/22 18:55:46 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

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
	char a;
} t_stack;

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"


#endif