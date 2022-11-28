/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:30:20 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/28 12:39:56 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../include/get_next_line.h"

typedef struct s_link
{
	int				value;
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_link	*next;
}					t_link;

int					check_argv(char *argv);
int					ft_abs(int value);
int					ft_str_is_numeric(char *str);
int					ft_str_is_numeric_2(char *str);
int					ft_sorted_array(t_link *stack);
int					get_list_length(t_link *stack);
int					ft_check_args(int argc, char **argv);
int					find_smallest_index(t_link *stack_a);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_number_is_unique(int argc, char **argv);
int					check_position_2(t_link *stack_a, t_link *stack_b);
int					check_position(t_link *stack_a, t_link *stack_b);
int					ft_push_swap(int argc, t_link **stack_a, t_link **stack_b);

long int			ft_atoi(const char *nptr);

static int			ft_size(int n);
static int			ft_char(int n);

static char			*ft_int_min(int n);
static char			*ft_negative(int n);

t_link				*ft_lstnew(int content);
t_link				*ft_lstlast(t_link *lst);
t_link				*ft_find_cheapest(t_link *stack_b);
t_link				*ft_lstadd_back(t_link **lst, t_link *new);

void				ft_swap(t_link **stack);
void				print_list(t_link *stack);
void				ft_ordre(t_link **stack_a);
void				ft_rotate_up(t_link **stack);
void				ft_rotate_down(t_link **stack);
void				ft_give_index(t_link *stack_a);
void				ft_free_stack(t_link **stack_a);
void				position_calculation_2(t_link *stack_a, t_link *stack_b,
						int a, t_link *head_b);
void				ft_give_position(t_link *stack);
void				ft_five_or_less(int argc, t_link *stack);
void				ft_pa(t_link **stack_a, t_link **stack_b);
void				ft_ss(t_link **stack_a, t_link **stack_b);
void				ft_rr(t_link **stack_a, t_link **stack_b);
void				ft_rrr(t_link **stack_a, t_link **stack_b);
void				ft_go_sort_part_one(t_link **stack_a, t_link **stack_b,
						t_link *stack_to_push);
void				ft_go_sort_part_two(t_link **stack_a, t_link **stack_b,
						t_link *stack_to_push);
void				ft_push(t_link **stack_a, t_link **stack_b);
void				ft_sort_three_args(int argc, t_link **stack);
void				ft_give_cost(t_link *stack_a, t_link *stack_b);
void				ft_sort_three_args_2(int argc, t_link **stack);
void				ft_calcul_coast(t_link *stack_a, t_link *stack_b);
void				position_calculation(t_link *stack_a, t_link *stack_b,
						int a);
void				push_rest_keep_three(t_link **stack_a, t_link **stack_b);
void				*ft_args_to_stack(t_link **stack_a, int argc, char **argv);
void				push_bottom_value(int argc, t_link **stack_a,
						t_link **stack_b);
void				ft_push_a_keep_three(int argc, t_link **stack,
						t_link **stack_a);

char				*ft_itoa(int n);
static int			ft_size(int n);
static int			ft_char(int n);
static char			*ft_negative(int n);
static char			*ft_int_min(int n);

#endif
