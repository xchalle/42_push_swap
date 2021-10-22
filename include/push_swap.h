/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:45 by xchalle           #+#    #+#             */
/*   Updated: 2021/10/22 10:54:05 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"

typedef struct s_digit
{
	int				index;
	long long		data;
	struct s_digit	*next;
	struct s_digit	*prev;
}			t_digit;

typedef struct s_tab
{
	char	**tabl;
	int		tab_len;
	int		i;
	int		word;
}			t_tab;

typedef struct s_num
{
	long long	max;
	long long	min;
}				t_num;

typedef struct s_stack
{
	int			len;
	int			high_count;
	int			low_count;
	long long	min;
	long long	max;
	int			c;
	t_digit		*first;
	t_digit		*last;
}	t_stack;

void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	reverse_a(t_stack *a);
void	reverse_b(t_stack *b);
void	reverse_r(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_r(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *b, t_stack *a);
void	algo_5(t_stack *a, t_stack *b);
void	algo_3(t_stack *a);
int		quick_algogo(t_stack *a, t_stack *b);
int		quick_algogo2(t_stack *a, t_stack *b);
t_tab	*ft_split(char *str, char *charset);
char	**ft_split2(char const *s, char c);
void	reverse_stack(int count, t_stack *a, t_stack *b, t_digit *digit);
void	rotate_stack(int count, t_stack *a, t_stack *b, t_digit *digit);
int		data_ext(t_digit *digit, t_stack *b, t_digit *b_temp, int blen);
t_digit	*ft_create_elem(long long data, t_stack *a);
int		sorted_arg(char **argv, int i);
int		sorted_arg_tab(t_tab *tab, int i);
void	exit_arg(void);
void	exit_tab(t_tab *tab, int i);
void	choose_algo(t_stack *a, t_stack *b);
void	full_stack_a(t_stack *a, t_stack *b, char **tab);
void	full_stack_a_tab(t_stack *a, t_stack *b, t_tab *tab);
void	index_list(t_stack *a, t_stack *b);
void	apply_index(t_stack *a, long long *array);
int		argc_2(t_stack *a, t_stack *b, char **tab);
int		argc_else(t_stack *a, t_stack *b, char **argv, int argc);
int		check_arg(char **argv, int i);
int		check_atoi(char **argv, int i, int o);
char	**free_struct_tab(t_stack *a, t_stack *b, char **tab);
int		free_struct(t_stack *a, t_stack *b);
int		free_a(t_stack *a);
char	**free_double_array(char **temp, char **tab);
void	free_tab(t_tab *tab);
void	len_struct(t_stack *a, t_stack *b);
void	initiate_sorting(t_stack *a, t_stack *b);
int		loop_checking_arg(char **argv, int i);
char	**create_tab(char **argv, int j, t_stack *a, t_stack *b);
int		ft_len(char **tab);
int		ft_lenght(char *tab);
char	**free_array(char **tab);
char	**free_array_int(char **tab, int o);
void	*xmalloc(size_t size);
int		exit_free_struct_tab(t_stack *a, t_stack *b, char **tab);
int		exit_free_struct(t_stack *a, t_stack *b);
char	**ft_ass(int *o, int *len, char **big, int j);
char	**ft_ass2(int *len, char **tab, char **temp);
void	if_exit(char **tab, char **temp, t_stack *a, t_stack *b);


#endif
