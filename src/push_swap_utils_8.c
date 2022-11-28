/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:15:21 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/28 12:39:07 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	position_calculation_2(t_link *stack_a, t_link *stack_b, int a,
		t_link *head_b)
{
	while (stack_b)
	{
		if (check_position(stack_a, stack_b) || check_position_2(stack_a,
				stack_b))
			stack_b->target_pos = find_smallest_index(stack_a);
		stack_b = stack_b->next;
	}
	stack_b = head_b;
	if (a == 1)
	{
		ft_rotate_down(&stack_a);
		position_calculation(stack_a, stack_b, 0);
		ft_rotate_up(&stack_a);
	}
}

int	check_position_2(t_link *stack_a, t_link *stack_b)
{
	while (stack_a->next)
	{
		if (stack_b->index < stack_a->index)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

void	ft_free_stack(t_link **stack_a)
{
	t_link	*tmp;

	while ((*stack_a))
	{
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		free(tmp);
	}
	free(*stack_a);
}
