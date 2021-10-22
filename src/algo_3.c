/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:51:21 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/18 17:11:15 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_order(t_stack *a)
{
	if (a->last->data > a->last->prev->data
		&& a->last->data < a->first->data)
		rotate_a(a);
	else if (a->last->data > a->last->prev->data
		&& a->last->data > a->first->data)
		swap_a(a);
	else if (a->last->data < a->last->prev->data
		&& a->last->data < a->first->data)
	{
		swap_a(a);
		reverse_a(a);
	}
}

void	algo_3(t_stack *a)
{
	if (a->len == 2 && a->first->data > a->last->data)
	{
		swap_a(a);
		return ;
	}
	if (a->first->data < a->first->next->data)
	{
		if (a->last->data < a->last->prev->data
			&& a->last->data > a->first->data)
		{
			swap_a(a);
			rotate_a(a);
		}
		else if (a->last->data < a->last->prev->data
			&& a->last->data < a->first->data)
			reverse_a(a);
	}
	else if (a->first->data > a->first->next->data)
		find_order(a);
}
