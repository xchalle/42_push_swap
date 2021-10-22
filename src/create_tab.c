/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:27 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/22 10:43:54 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

char	**loop_tab2(char **temp, char **big, int o)
{
	int	k;
	int	r;

	r = 0;
	while (temp[r] != NULL)
	{
		k = 0;
		big[o] = xmalloc(sizeof(char) * (ft_lenght(temp[r]) + 1));
		if (!(big[o]))
			return (free_array_int(big, o));
		while (temp[r][k])
		{
			big[o][k] = temp[r][k];
			k++;
		}	
		big[o][k] = '\0';
		o++;
		r++;
	}
	big[o] = 0;
	return (big);
}

char	**loop_tab(char **big, char **temp, int *o, int len)
{
	int	k;

	while (*o < len)
	{
		k = 0;
		big[*o] = xmalloc(sizeof(char) * (ft_lenght(temp[*o]) + 1));
		if (!(big[*o]))
			return (free_array_int(big, *o));
		while (temp[*o][k])
		{
			big[*o][k] = temp[*o][k];
			k++;
		}
		big[*o][k] = '\0';
		*o = *o + 1;
	}
	return (big);
}

char	**ft_split_extended(char **argv, char **big, t_stack *a, t_stack *b)
{
	big = ft_split2(argv[1], ' ');
	if (!(big))
		exit(exit_free_struct(a, b));
	return (big);
}

char	**create_tab(char **argv, int j, t_stack *a, t_stack *b)
{
	char	**big;
	char	**temp;
	char	**tab;
	int		o;
	int		len;

	big = NULL;
	big = ft_split_extended(argv, big, a, b);
	while (argv[j])
	{
		temp = ft_ass(&o, &len, big, j);
		tab = ft_split2(argv[j++], ' ');
		if_exit(tab, temp, a, b);
		big = xmalloc(sizeof(char *) * (ft_len(tab) + len + 1));
		if (!(big))
			return (free_double_array(temp, tab));
		big = loop_tab(big, temp, &o, len);
		if (!(big))
			return (free_double_array(temp, tab));
		temp = ft_ass2(&len, tab, temp);
		big = loop_tab2(temp, big, o);
		if_exit(big, temp, a, b);
		free_array(temp);
	}
	return (big);
}
