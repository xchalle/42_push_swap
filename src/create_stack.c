/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:52:58 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/21 18:53:12 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

/*void	full_stack_a2_tab(t_stack *a, t_stack *b, t_tab *tab)
{
	int	i;

	i = 0;
	a->min = ft_atoi(tab->tabl[i]);
	a->max = ft_atoi(tab->tabl[i]);
	a->first = ft_create_elem(ft_atoi(tab->tabl[i]), a);
	a->last = a->first;
	a->len++;
	i++;
	while (i < a->c)
	{
		if (check_arg(tab->tabl, i) == 1)
		{
			write(2, "Error\n", 6);
			free_struct_tab(a, b, tab, 1);
			exit(-1);
		}
		a->last->next = ft_create_elem(ft_atoi(tab->tabl[i]), a);
		a->last->next->prev = a->last;
		a->last = a->last->next;
		i++;
		a->len++;
	}
}

void	full_stack_a_tab(t_stack *a,
	t_stack *b, t_tab *tab)
{
	int	i;

	i = 0;
	if (check_arg(tab->tabl, i) == 1)
	{
		write(2, "Error\n", 6);
		free_struct_tab(a, b, tab, 1);
		exit(-1);
	}
	full_stack_a2_tab(a, b, tab);
	if (a->len > 1)
	{
		a->last->next = a->first;
		a->first->prev = a->last;
	}
	if (a->len == 1)
	{
		free_struct_tab(a, b, tab, 1);
		exit(0);
	}
}*/

void	full_stack_a2(t_stack *a, t_stack *b, char **tab)
{
	int	i;

	i = 0;
	a->min = ft_atoi(tab[i]);
	a->max = ft_atoi(tab[i]);
	a->first = ft_create_elem(ft_atoi(tab[i]), a);
	if (!(a->first))
		exit (exit_free_struct_tab(a, b, tab));
	a->last = a->first;
	a->len++;
	i++;
	while (i < ft_len(tab))
	{
		if (check_arg(tab, i) == 1)
			exit (exit_free_struct_tab(a, b, tab));
		a->last->next = ft_create_elem(ft_atoi(tab[i]), a);
		if (!(a->last->next))
			exit (exit_free_struct_tab(a, b, tab));
		a->last->next->prev = a->last;
		a->last = a->last->next;
		i++;
		a->len++;
	}
}

void	full_stack_a(t_stack *a, t_stack *b, char **tab)
{
	int	i;

	i = 0;
	if (check_arg(tab, i) == 1)
	{
		write(2, "Error\n", 6);
		free_struct(a, b);
		free_array(tab);
		exit(-1);
	}
	full_stack_a2(a, b, tab);
	if (a->len > 1)
	{
		a->last->next = a->first;
		a->first->prev = a->last;
	}
	if (a->len == 1)
	{
		free_struct(a, b);
		free_array(tab);
		exit(0);
	}
	free_array(tab);
}

void	choose_algo(t_stack *a, t_stack *b)
{
	if (a->len == 2 || a->len == 3)
		algo_3(a);
	else if (a->len == 4 || a->len == 5)
		algo_5(a, b);
	else if (a->len <= 100)
		quick_algogo(a, b);
	else
		quick_algogo2(a, b);
}
