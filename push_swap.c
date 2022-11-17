/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:28:13 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/17 13:59:52 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap(int argc, t_link **stack_a, t_link **stack_b)
{
	t_link	*stack_to_push;

	if (argc == 4)
		return (ft_sort_three_args(argc, stack_a), 0);
	else if (argc > 4)
		ft_push_a_keep_three(argc, stack_a, stack_b);
	position_calculation((*stack_a), (*stack_b));
	ft_calcul_coast((*stack_a), (*stack_b));
	stack_to_push = ft_find_cheapest((*stack_b));
	while ((*stack_b)->next)
	{
		ft_go_sort_part_one(stack_a, stack_b, stack_to_push);
		ft_pa(stack_a, stack_b);
		ft_give_position((*stack_a));
		ft_give_position((*stack_b));
		position_calculation((*stack_a), (*stack_b));
		ft_calcul_coast((*stack_a), (*stack_b));
		stack_to_push = ft_find_cheapest((*stack_b));
	}
	ft_go_sort_part_one(stack_a, stack_b, stack_to_push);
	ft_pa(stack_a, stack_b);
	return (0);
}

void	ft_sort_three_args(int argc, t_link **stack)
{
	int	fst_arg;
	int	snd_arg;
	int	trd_arg;

	fst_arg = (*stack)->value;
	snd_arg = (*stack)->next->value;
	trd_arg = (*stack)->next->next->value;
	if (fst_arg < snd_arg && snd_arg > trd_arg && fst_arg < trd_arg)
	{
		ft_swap(stack);
		ft_rotate_up(stack);
		write(1, "sa\nra\n", 6);
	}
	else if (fst_arg < snd_arg && snd_arg > trd_arg && fst_arg > trd_arg)
	{
		ft_rotate_down(stack);
		write(1, "rra\n", 4);
	}
	else
		ft_sort_three_args_2(argc, stack);
}

void	ft_sort_three_args_2(int argc, t_link **stack)
{
	int	fst_arg;
	int	snd_arg;
	int	trd_arg;

	fst_arg = (*stack)->value;
	snd_arg = (*stack)->next->value;
	trd_arg = (*stack)->next->next->value;
	if (fst_arg > snd_arg && snd_arg < trd_arg && fst_arg < trd_arg)
	{
		ft_swap(stack);
		write(1, "sa\n", 3);
	}
	else if (fst_arg > snd_arg && fst_arg > trd_arg && snd_arg < trd_arg)
	{
		ft_rotate_up(stack);
		write(1, "ra\n", 3);
	}
	else if (fst_arg > snd_arg && fst_arg > trd_arg && snd_arg > trd_arg)
	{
		ft_swap(stack);
		ft_rotate_down(stack);
		write(1, "sa\nrra\n", 7);
	}
}
