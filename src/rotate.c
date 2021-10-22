/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:11 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/14 13:54:13 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack *src)
{
	if (src->len == 0)
		return ;
	src->last = src->first;
	src->first = src->last->next;
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack *a, t_stack *b)
{
	rotate(b);
	rotate(a);
	write(1, "rr\n", 3);
}
