/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:05:03 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/21 13:54:22 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./get_next_line.h"
# include "./push_swap.h"

int		ft_is_sorted(t_link *stack_a);
void	ft_check(t_link **stack_a, t_link **stack_b, int fd);
void	ft_check_part_2(t_link **stack_a, t_link **stack_b, int fd,
			char *line_read);

#endif
