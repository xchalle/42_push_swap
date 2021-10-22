/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:27 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/22 10:42:22 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

char	**free_array(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**free_array_int(char **tab, int o)
{
	int	i;

	i = 0;
	while (i < o)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_ass(int *o, int *len, char **big, int j)
{
	*o = 0;
	if (j == 2)
		*len = ft_len(big);
	return (big);
}

char	**ft_ass2(int *len, char **tab, char **temp)
{
	*len = *len + ft_len(tab);
	free_array(temp);
	return (tab);
}

void	if_exit(char **tab, char **temp, t_stack *a, t_stack *b)
{
	if (!(tab))
		exit(exit_free_struct_tab(a, b, temp));
}
