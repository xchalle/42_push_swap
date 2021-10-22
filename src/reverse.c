/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:03 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/14 13:54:05 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse(t_stack *src)
{
	if (src->len == 0)
		return ;
	src->first = src->last;
	src->last = src->last->prev;
}

void	reverse_a(t_stack *a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	reverse_b(t_stack *b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	reverse_r(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
