/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:14:16 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/14 12:21:27 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_push
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				lent;
	int				chack_error;
	int				i;
	int				j;
	int long		len_stack;
	int				*table;
	char			**new_argv;
}					t_push;

long long			ft_atoi(const char *str, int *check);
char				*ft_strdup(const char *s1);
t_stack				*new_stack(void);
int					get_lengt(char **argv);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char *s1, char set);
char				**ft_split(const char *s, char c);
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
t_stack				*do_sa(t_stack *stack);
t_stack				*do_sb(t_stack *stack);
t_stack				*do_ra(t_stack *stack);
t_stack				*do_rb(t_stack *stack);
void				do_rr(t_push *stack);
void				do_ss(t_push *stack);
void				ft_free_stack(t_stack *stack);
void				free_table(t_push *push);
void				ft_free_2(char **tab);
int					get_lengt_new_arg(char **new_argv);
void				fill_table(t_push *push);
int					get_big_nbr(t_stack *stack);
t_stack				*get_head(t_stack *stack);
t_stack				*get_end(t_stack *stack);
int					get_big_nbr_pos(t_stack *stack, int nbr);
int					push_swap(t_push *push, int ac);
t_stack				*do_rra(t_stack *stack);
t_stack				*do_rrb(t_stack *stack);
void				do_rrr(t_push *push);
void				do_pb(t_push *stack);
void				do_pa(t_push *stack);
int					ft_isdigit(int c);
t_stack				*next_stack(int value, t_stack *stack);
t_stack				*copy_table_to_stack(int *tbl, int lengt);
int					get_scan_top(t_push *push, int chunk_size, int j);
int					get_scan_end(t_push *push, int chunk_size, int j);
void				push_a_to_b(t_push *push, int chunk_size, int j);
void				solution_for_more_five(t_push *push, int nbr_chunk);
void				solution_for_fiveless(t_push *push);
void				sort_table(t_push *stack);
int					stack_lent(t_stack *stack);
int					chack_if_sort(t_stack *stack);
t_stack				*solution_for_three(t_stack *stack);
void				check_arg_error(char **argv);
void				line_error(t_push *stack);
void				print_stack(t_stack *stack);
void				clean_arg(t_push *vars, char **argv);
void				last_sort(t_push *push, int pos_num, int midle_stack);

#endif