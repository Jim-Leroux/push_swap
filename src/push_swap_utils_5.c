/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:18:02 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/20 13:00:44 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	position_calculation(t_link *stack_a, t_link *stack_b, int a)
{
	t_link	*head_a;
	t_link	*head_b;

	head_a = stack_a;
	head_b = stack_b;
	while (stack_b)
	{
		while (stack_a->next)
		{
			if (stack_b->index > stack_a->index
				&& stack_b->index < stack_a->next->index)
				stack_b->target_pos = stack_a->next->position;
			stack_a = stack_a->next;
		}
		stack_a = head_a;
		stack_b = stack_b->next;
	}
	if (a == 0)
		return ;
	stack_b = head_b;
	position_calculation_2(stack_a, stack_b, a, head_b);
}

int	check_position(t_link *stack_a, t_link *stack_b)
{
	while (stack_a)
	{
		if (stack_b->index > stack_a->index)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

int	find_smallest_index(t_link *stack_a)
{
	t_link	*smallest_index;

	smallest_index = stack_a;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (smallest_index->index > stack_a->index)
			smallest_index = stack_a;
		stack_a = stack_a->next;
	}
	return (smallest_index->position);
}

void	ft_calcul_coast(t_link *stack_a, t_link *stack_b)
{
	int	stack_length_a;
	int	stack_length_b;

	stack_length_b = get_list_length(stack_b);
	stack_length_a = get_list_length(stack_a);
	while (stack_b)
	{
		if (stack_b->position < stack_length_b / 2)
			stack_b->cost_b = stack_b->position;
		else
			stack_b->cost_b = stack_b->position - stack_length_b;
		if (stack_b->target_pos < stack_length_a / 2)
			stack_b->cost_a = stack_b->target_pos;
		else
			stack_b->cost_a = stack_b->target_pos - stack_length_a;
		stack_b = stack_b->next;
	}
}

t_link	*ft_find_cheapest(t_link *stack_b)
{
	t_link	*cheapest;

	cheapest = stack_b;
	while (stack_b->next)
	{
		if (ft_abs(cheapest->cost_a)
			+ ft_abs(cheapest->cost_b) > ft_abs(stack_b->next->cost_a)
			+ ft_abs(stack_b->next->cost_b))
			cheapest = stack_b->next;
		stack_b = stack_b->next;
	}
	return (cheapest);
}
