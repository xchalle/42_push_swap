/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:52:44 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/22 11:01:34 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	exit_free_struct_tab(t_stack *a, t_stack *b, char **tab)
{
	free_struct_tab(a, b, tab);
	write(2, "Error\n", 6);
	return (0);
}

int	sorted_arg_tab(t_tab *tab, int i)
{
	int	j;

	j = i + 1;
	if (check_arg(tab->tabl, i) == 1)
		return (2);
	if (tab->tab_len > 1)
	{
		while (j < tab->tab_len)
		{
			if (check_arg(tab->tabl, j) == 1)
				return (2);
			if (ft_atoi(tab->tabl[i]) < ft_atoi(tab->tabl[j]))
			{
				j++;
				i++;
			}
			else
				return (0);
		}
	}
	return (1);
}

int	loop_checking_arg(char **argv, int i)
{
	int	j;

	j = i + 1;
	if (check_arg(argv, i) == 1)
		return (2);
	while (argv[j])
	{
		if (check_arg(argv, j) == 1)
			return (2);
		j++;
	}
	return (0);
}

int	sorted_arg(char **argv, int i)
{
	int	j;

	j = i + 1;
	if (check_arg(argv, i) == 1)
		return (2);
	while (argv[j])
	{
		if (check_arg(argv, j) == 1)
			return (2);
		if (ft_atoi(argv[i]) < ft_atoi(argv[j]))
		{
			j++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

t_digit	*ft_create_elem(long long data, t_stack *a)
{
	t_digit	*d;

	d = xmalloc(sizeof(t_digit));
	if (!(d))
		return (NULL);
	d->next = NULL;
	d->prev = NULL;
	d->data = data;
	if (data > a->max)
	{
		a->max = data;
	}
	if (data < a->min)
	{
		a->min = data;
	}
	return (d);
}
