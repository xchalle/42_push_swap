/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:52:33 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/22 10:57:41 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

/*void	free_tab(t_tab *tab)
{
	int	i;

	i = 0;
	while (i != tab->tab_len)
	{
		free(tab->tabl[i]);
		i++;
	}
	if (tab->tabl)
		free(tab->tabl);
	if (tab)
		free(tab);
}*/

/*int	free_a(t_stack *a)
{
	free(a);
	write(2, "Error\n", 6);
	return (0);
}*/

char	**free_double_array(char **temp, char **tab)
{
	free_array(temp);
	free_array(tab);
	return (NULL);
}

/*char	**free_triple_array(char **temp, char **tab, char **big)
{
	free_array(temp);
	free_array(tab);
	free(big);
	return (NULL);
}*/

int	free_struct(t_stack *a, t_stack *b)
{
	while (a->len != 0)
	{
		a->last = a->first;
		a->first = a->first->next;
		free(a->last);
		a->len--;
	}
	if (b)
		free(b);
	if (a)
		free(a);
	return (0);
}

char	**free_struct_tab(t_stack *a, t_stack *b, char **tab)
{
	int	i;

	i = 0;
	while (a->len != 0)
	{
		a->last = a->first;
		a->first = a->first->next;
		free(a->last);
		a->len--;
	}
	free(b);
	free(a);
	while (i != ft_len(tab))
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	return (NULL);
}

int	check_atoi(char **argv, int i, int o)
{
	int	k;

	k = 0;
	if ((argv[i][0] != '-' && argv[i][0] != '+')
		&& (argv[i][0] < '0' || argv[i][0] > '9') && (argv[i][0] != ' '))
		return (1);
	if ((argv[i][0] == '-' || argv[i][0] == '+'
		|| argv[i][0] == ' ') && (!(argv[i][1])))
		return (1);
	while (argv[i][o])
	{
		if ((argv[i][o] < '0' || argv[i][o] > '9') && (argv[i][o] != ' '))
			return (1);
		o++;
	}
	while (argv[i][k])
	{
		if (argv[i][k] != ' ')
			return (0);
		k++;
	}
	if (k == ft_lenght(argv[i]))
		return (1);
	return (0);
}

int	check_arg(char **argv, int i)
{
	int			o;
	int			j;
	long long	cas;

	o = 1;
	j = 0;
	if (check_atoi(argv, i, o) == 1)
		return (1);
	cas = ft_atoi(argv[i]);
	if (cas > 2147483647 || cas < -2147483648)
		return (1);
	if (i != 0)
	{
		while (j < i)
		{
			if (ft_atoi(argv[j]) == cas)
				return (1);
			j++;
		}
	}
	return (0);
}
