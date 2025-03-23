/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:21:36 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/23 18:38:30 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//divide input into parts, push and sort smaller chunks efficiently
//optimize rotations and push operations
//split stack A into partitions
//chunk_size based on input size
//move each to stack B
//sort_chunks insert_sort or select_sort
//merge stack pushing to stack A
//hybrid strategy - prepocessing step
//user  radix on final pass
