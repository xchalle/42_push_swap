/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:27 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/22 10:57:08 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	len_struct(t_stack *a, t_stack *b)
{
	a->len = 0;
	b->len = 0;
}

void	initiate_sorting(t_stack *a, t_stack *b)
{
	index_list(a, b);
	choose_algo(a, b);
}

int	ft_len(char **tab)
{
	int	i;

	i = 0;
	if (!(tab))
		return (i);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	ft_lenght(char *tab)
{
	int	i;

	i = 0;
	if (!(tab))
		return (i);
	while (tab[i])
		i++;
	return (i);
}

int	free_a(t_stack *a)
{
	free(a);
	write(2, "Error\n", 6);
	return (0);
}
