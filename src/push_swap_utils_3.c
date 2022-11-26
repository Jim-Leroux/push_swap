/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:55:17 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/25 15:19:57 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rr(t_link **stack_a, t_link **stack_b)
{
	ft_rotate_up(stack_a);
	ft_rotate_up(stack_b);
}

void	ft_rrr(t_link **stack_a, t_link **stack_b)
{
	ft_rotate_down(stack_a);
	ft_rotate_down(stack_b);
}

int	ft_sorted_array(t_link *stack_a)
{
	t_link	*head;

	head = stack_a;
	while (stack_a->next)
	{
		if (stack_a->value < stack_a->next->value)
			stack_a = stack_a->next;
		else
			return (0);
	}
	ft_free_stack(&head);
	free(head);
	return (1);
}

void	ft_give_index(t_link *stack_a)
{
	t_link	*tmp;
	t_link	*head;

	tmp = stack_a;
	head = stack_a;
	while (stack_a)
	{
		stack_a->index = 0;
		while (tmp)
		{
			if (stack_a->value > tmp->value)
				stack_a->index++;
			tmp = tmp->next;
		}
		tmp = head;
		stack_a = stack_a->next;
	}
}

void	ft_push_a_keep_three(int argc, t_link **stack_a, t_link **stack_b)
{
	push_bottom_value(argc, stack_a, stack_b);
	push_rest_keep_three(stack_a, stack_b);
	ft_sort_three_args(get_list_length((*stack_a)), stack_a);
	ft_give_position((*stack_a));
	ft_give_position((*stack_b));
}
