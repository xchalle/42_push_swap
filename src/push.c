/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:53:55 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/14 13:53:58 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	intra_swap(t_stack *src)
{
	src->first = src->first->next;
	src->first->prev = src->last;
	src->last->next = src->first;
}

void	push(t_stack *src, t_stack *dst)
{
	t_digit	*tmp;

	if (src->len < 1)
		return ;
	tmp = src->first;
	if (src->len == 1)
		src->first = 0;
	if (src->len > 1)
		intra_swap(src);
	tmp->next = tmp;
	tmp->prev = tmp;
	if (dst->len != 0)
	{
		tmp->next = dst->first;
		tmp->prev = dst->last;
		dst->last->next = tmp;
		dst->first->prev = tmp;
	}
	else
		dst->last = tmp;
	dst->first = tmp;
	src->len--;
	dst->len++;
}

void	push_a(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *b, t_stack *a)
{
	push(a, b);
	write(1, "pb\n", 3);
}
