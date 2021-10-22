/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:21 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/14 13:54:23 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *src)
{
	t_digit	*tmp2;
	t_digit	*tmp3;

	if (src->len < 2)
		return ;
	if (src->len == 2)
	{
		tmp2 = src->first;
		tmp3 = src->last;
		src->first = tmp3;
		src->last = tmp2;
		return ;
	}
	tmp2 = src->first->next;
	tmp3 = src->first->next->next;
	src->last->next = tmp2;
	tmp2->prev = src->last;
	tmp2->next = src->first;
	src->first->prev = tmp2;
	src->first->next = tmp3;
	tmp3->prev = src->first;
	src->first = tmp2;
}

void	swap_a(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}
