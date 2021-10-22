/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:53:38 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/22 11:47:24 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

static int	g_fail_at = 100000000;

void	*xmalloc(size_t size)
{
	static int	s = 0;

	s++;
	if (s == g_fail_at)
	{
		return (NULL);
	}
	else
	{
		return (malloc(size));
	}
}

int	exit_free_struct(t_stack *a, t_stack *b)
{
	free_struct(a, b);
	write(2, "Error\n", 6);
	return (0);
}

int	argc_2(t_stack *a, t_stack *b, char **tab)
{
	int	i;

	if (ft_len(tab) == 0)
	{
		free_struct_tab(a, b, tab);
		exit(0);
	}
	i = sorted_arg(tab, 0);
	if (i == 1)
	{
		free_struct_tab(a, b, tab);
		exit(0);
	}
	if (i == 2)
	{
		free_struct_tab(a, b, tab);
		write(2, "Error\n", 6);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**tab;

	if (argc < 2)
		return (0);
	a = xmalloc(sizeof(t_stack));
	if (!(a))
		return (0);
	b = xmalloc(sizeof(t_stack));
	if (!(b))
		return (free_a(a));
	len_struct(a, b);
	b->c = 0;
	a->c = argc;
	tab = create_tab(argv, 2, a, b);
	if (!(tab))
		return (exit_free_struct(a, b));
	argc_2(a, b, tab);
	full_stack_a(a, b, tab);
	initiate_sorting(a, b);
	free_struct(a, b);
	return (0);
}
