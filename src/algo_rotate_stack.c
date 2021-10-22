/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rotate_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:52:20 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/14 13:52:23 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	rotate_stack4(int count, t_stack *b, t_stack *a, int blen)
{
	while (blen > 0 && count > 0)
	{
		rotate_r(a, b);
		blen--;
		count--;
	}
	while (count > 0)
	{
		rotate_a(a);
		count--;
	}
	while (blen > 0)
	{
		rotate_b(b);
		blen--;
	}
}

void	rotate_stack3(int count, t_stack *b, t_stack *a, int blen)
{
	if (blen > b->len / 2)
	{
		if (count + b->len - blen < b->len)
		{
			while (count > 0)
			{
				rotate_a(a);
				count--;
			}
			while (b->len - blen > 0)
			{
				reverse_b(b);
				blen++;
			}
		}
		else
			rotate_stack4(count, b, a, blen);
	}
}

void	rotate_stack2(int count, t_stack *b, t_stack *a, int blen)
{
	if (blen <= b->len / 2)
	{
		while (blen > 0 && count > 0)
		{
			rotate_r(a, b);
			blen--;
			count--;
		}
		while (count > 0)
		{
			rotate_a(a);
			count--;
		}
		while (blen > 0)
		{
			rotate_b(b);
			blen--;
		}
	}
	rotate_stack3(count, b, a, blen);
}

void	rotate_stack(int count, t_stack *a, t_stack *b, t_digit *digit)
{
	int		blen;
	t_digit	*b_temp;

	blen = 0;
	b_temp = b->first;
	if (b->len == 0)
	{
		b->max = digit->data;
		b->min = digit->data;
	}
	if (digit->data > b->min && digit->data < b->max)
	{
		while (blen < b->len)
		{
			if (b_temp->prev->index > digit->index
				&& b_temp->index < digit->index)
				break ;
			blen++;
			b_temp = b_temp->next;
		}
	}
	blen = data_ext(digit, b, b_temp, blen);
	rotate_stack2(count, b, a, blen);
}
