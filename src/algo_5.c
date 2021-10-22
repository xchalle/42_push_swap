/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:51:44 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/18 14:21:43 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	meta_park2(int alen, t_stack *a, t_stack *b)
{
	if (alen >= 2)
	{
		while (a->len - alen > 0)
		{
			reverse_a(a);
			alen++;
		}
		push_a(a, b);
	}
	else
	{
		while (alen > 0)
		{
			rotate_a(a);
			alen--;
		}
		push_a(a, b);
	}
}

void	meta_park(int alen, t_digit *a_temp, t_stack *a, t_stack *b)
{
	alen = 0;
	a_temp = a->first;
	while (alen < a->len)
	{
		if (a_temp->prev->data < b->first->data
			&& a_temp->data > b->first->data)
			break ;
		alen++;
		a_temp = a_temp->next;
	}
	meta_park2(alen, a, b);
}

void	loop_5(int alen, t_stack *a, t_digit *a_temp)
{
	while (alen < a->len)
	{
		if (a_temp->data == a->min)
			break ;
		alen++;
		a_temp = a_temp->next;
	}
	if (alen >= 3)
	{
		while (5 - alen > 0)
		{	
			reverse_a(a);
			alen++;
		}
	}
	else
	{
		while (alen > 0)
		{	
			rotate_a(a);
			alen--;
		}
	}
}

void	algo_5(t_stack *a, t_stack *b)
{
	int		alen;
	t_digit	*a_temp;

	if (a->len == 5)
		push_b(b, a);
	push_b(b, a);
	algo_3(a);
	if (b->len == 2 && a->min == b->last->data)
		swap_b(b);
	if (b->len == 2
		&& (a->max == b->last->data && a->min != b->first->data))
		swap_b(b);
	if (b->first->data == a->min)
		push_a(a, b);
	if (b->first->data == a->max)
	{
		push_a(a, b);
		rotate_a(a);
	}
	alen = 0;
	a_temp = a->first;
	while (b->len != 0)
		meta_park(alen, a_temp, a, b);
	a_temp = a->first;
	loop_5(alen, a, a_temp);
}
