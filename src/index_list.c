/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:53:22 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/21 13:30:48 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	apply_index(t_stack *a, long long *array)
{
	int	i;

	i = 0;
	while (a->first->data != a->last->data)
	{
		i = 0;
		while (a->first->data != array[i])
			i++;
		if (a->first->data == array[i])
			a->first->index = i + 1;
		a->first = a->first->next;
	}
	i = 0;
	while (a->first->data != array[i])
		i++;
	if (a->first->data == array[i])
		a->first->index = i + 1;
	a->first = a->first->next;
}

void	index_loop_suit(long long *array, int *i, int *temp, int *temp2)
{
	*temp2 = array[*i];
	array[*i] = *temp;
	*temp = *temp2;
	*i = *i + 1;
}

void	index_loop(t_stack *a, long long *array, int i)
{
	int		temp;
	int		temp2;

	temp = 0;
	temp2 = 0;
	while (a->first->data != a->last->next->data)
	{
		i = 0;
		while (a->first->data > array[i] && array[i] != -2147483648000001)
			i++;
		if (array[i] == -2147483648000001)
			array[i] = a->first->data;
		if (a->first->data < array[i])
		{
			temp = array[i];
			array[i] = a->first->data;
			i++;
			while (array[i] != -2147483648000001)
				index_loop_suit(array, &i, &temp, &temp2);
			array[i] = temp;
		}
		a->first = a->first->next;
	}
}

void	index_list(t_stack *a, t_stack *b)
{
	long long	*array;
	int			i;

	i = 0;
	array = xmalloc(sizeof(long long) * (a->len + 1));
	if (!(array))
		exit(exit_free_struct(a, b));
	while (i <= a->len)
	{
		array[i] = -2147483648000001;
		i++;
	}
	array[0] = a->first->data;
	a->first = a->first->next;
	index_loop(a, array, i);
	i = 0;
	apply_index(a, array);
	free(array);
}
