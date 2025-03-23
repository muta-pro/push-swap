/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:52:30 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/23 18:38:19 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//for large datasets: complexity O(Nk)
//process numbers bit by bit using bitwise operations
//use stacks to temp hold numbers
//sort numbers based on LSMS
//track positions carefully