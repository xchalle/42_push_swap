/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:50:26 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/14 13:50:38 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	data_ext(t_digit *digit, t_stack *b, t_digit *b_temp, int blen)
{
	if (digit->data > b->max)
	{
		while (blen < b->len)
		{
			if (b_temp->data == b->max)
				break ;
			blen++;
			b_temp = b_temp->next;
		}
		b->max = digit->data;
	}
	if (digit->data < b->min)
	{
		while (blen < b->len)
		{
			if (b_temp->data == b->max)
				break ;
			blen++;
			b_temp = b_temp->next;
		}
		b->min = digit->data;
	}
	return (blen);
}

/*void	assign_var(t_digit *high_temp, t_stack *a,
	int *low_count, int *high_count)
{
	*high_count = 0;
	*low_count = 1;
	high_temp = a->first;
	if (*high_count == 1)
		high_temp++;
}*/

void	algo_loop(t_stack *b, t_stack *a, int loop)
{
	t_digit	*high_temp;
	t_digit	*low_temp;

	while (b->len < 20 * loop && a->len != 0)
	{
		a->high_count = 0;
		a->low_count = 1;
		high_temp = a->first;
		while (high_temp->index > 20 * loop)
		{
			a->high_count++;
			high_temp = high_temp->next;
		}
		low_temp = a->last;
		while (low_temp->index > 20 * loop)
		{
			a->low_count++;
			low_temp = low_temp->prev;
		}
		if (a->low_count < a->high_count)
			reverse_stack(a->low_count, a, b, low_temp);
		else
			rotate_stack(a->high_count, a, b, high_temp);
		push_b(b, a);
	}
}

int	quick_algogo(t_stack *a, t_stack *b)
{
	int		loop;

	loop = 1;
	while (a->len > 0)
	{	
		algo_loop(b, a, loop);
		loop++;
	}
	while (b->first->data != b->max)
		reverse_b(b);
	while (b->len != 0)
		push_a(a, b);
	return (0);
}

void	algo_loop2(t_stack *b, t_stack *a, int loop)
{
	t_digit	*high_temp;
	t_digit	*low_temp;

	while (b->len < 40 * loop && a->len != 0)
	{
		a->high_count = 0;
		a->low_count = 1;
		high_temp = a->first;
		while (high_temp->index > 40 * loop)
		{
			a->high_count++;
			high_temp = high_temp->next;
		}
		low_temp = a->last;
		while (low_temp->index > 40 * loop)
		{
			a->low_count++;
			low_temp = low_temp->prev;
		}
		if (a->low_count < a->high_count)
			reverse_stack(a->low_count, a, b, low_temp);
		else
			rotate_stack(a->high_count, a, b, high_temp);
		push_b(b, a);
	}
}

int	quick_algogo2(t_stack *a, t_stack *b)
{
	int		loop;

	loop = 1;
	while (a->len > 0)
	{	
		algo_loop2(b, a, loop);
		loop++;
	}
	while (b->first->data != b->max)
		reverse_b(b);
	while (b->len != 0)
		push_a(a, b);
	return (0);
}
