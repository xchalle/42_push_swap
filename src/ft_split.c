/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:53:12 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/20 15:22:33 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sep(char *str, char *charset, int j)
{
	int	m;

	m = 0;
	while (charset[m])
	{
		if (charset[m] == str[j])
			return (0);
		m++;
	}
	return (1);
}

void	ft_appli2(char *str, char *charset, char **tab, int compteur)
{
	int		i;
	int		k;
	int		o;

	o = 0;
	k = 0;
	i = 0;
	while (str[i] && o < compteur)
	{
		while (is_sep(str, charset, i) == 0 && str[i])
		{
			i++;
		}
		k = 0;
		while (is_sep(str, charset, i) == 1 && str[i])
		{
			tab[o][k] = str[i];
			i++;
			k++;
		}
		tab[o][k] = '\0';
		o++;
	}
}

int	ft_appli(char *str, char *charset, char **tab, int compteur)
{
	int		i;
	int		k;
	int		o;

	o = 0;
	k = 0;
	i = 0;
	while (str[i] && o < compteur)
	{
		while (is_sep(str, charset, i) == 0 && str[i])
			i++;
		k = 0;
		while (is_sep(str, charset, i) == 1 && str[i])
		{
			k++;
			i++;
		}
		tab[o] = xmalloc(sizeof(char) * (k + 1));
		if (!(tab[o]))
			return (1);
		o++;
	}
	ft_appli2(str, charset, tab, compteur);
	return (0);
}

t_tab	*ft_call(void)
{
	t_tab	*tab;

	tab = xmalloc(sizeof(t_tab));
	if (!(tab))
		return (NULL);
	tab->tab_len = 0;
	tab->i = 0;
	tab->word = 0;
	return (tab);
}

t_tab	*ft_split(char *str, char *charset)
{
	t_tab	*tab;

	tab = ft_call();
	if (!(tab))
		return (NULL);
	while (str[tab->i])
	{
		tab->word = 0;
		while (is_sep(str, charset, tab->i) == 0 && str[tab->i])
			tab->i++;
		while (is_sep(str, charset, tab->i) == 1 && str[tab->i])
		{
			tab->word++;
			tab->i++;
		}
		if (tab->word >= 1)
			tab->tab_len++;
	}
	tab->tabl = xmalloc(sizeof(char *) * (tab->tab_len));
	if (!(tab->tabl))
		return (NULL);
	if (ft_appli(str, charset, tab->tabl, tab->tab_len) == 1)
		return (NULL);
	return (tab);
}
