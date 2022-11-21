/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:16:18 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/20 16:26:25 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_down(t_link **stack)
{
	t_link	*tmp1;
	t_link	*tmp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp1 = *stack;
	while (tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp1->next = *stack;
	tmp2->next = NULL;
	(*stack) = tmp1;
}

int	ft_abs(int value)
{
	if (value < 0)
		value = value * -1;
	return (value);
}

void	ft_go_sort_part_one(t_link **stack_a, t_link **stack_b,
		t_link *stack_to_push)
{
	int	count;

	count = ft_abs(stack_to_push->cost_a) + ft_abs(stack_to_push->cost_b);
	while (count > 0)
	{
		if (stack_to_push->cost_b > 0 && stack_to_push->cost_a > 0)
		{
			ft_rr(stack_a, stack_b);
			write(1, "rr\n", 3);
			stack_to_push->cost_b--;
			stack_to_push->cost_a--;
		}
		else if (stack_to_push->cost_b < 0 && stack_to_push->cost_a < 0)
		{
			ft_rrr(stack_a, stack_b);
			write(1, "rrr\n", 4);
			stack_to_push->cost_a++;
			stack_to_push->cost_b++;
		}
		else
			ft_go_sort_part_two(stack_a, stack_b, stack_to_push);
		count--;
	}
}

void	ft_go_sort_part_two(t_link **stack_a, t_link **stack_b,
		t_link *stack_to_push)
{
	if (stack_to_push->cost_b < 0)
	{
		ft_rotate_down(stack_b);
		write(1, "rrb\n", 4);
		stack_to_push->cost_b++;
	}
	else if (stack_to_push->cost_b > 0)
	{
		ft_rotate_up(stack_b);
		write(1, "rb\n", 3);
		stack_to_push->cost_b--;
	}
	else if (stack_to_push->cost_a < 0)
	{
		ft_rotate_down(stack_a);
		write(1, "rra\n", 4);
		stack_to_push->cost_a++;
	}
	else if (stack_to_push->cost_a > 0)
	{
		ft_rotate_up(stack_a);
		write(1, "ra\n", 3);
		stack_to_push->cost_a--;
	}
}

void	ft_ordre(t_link **stack_a)
{
	t_link	*head;

	head = *stack_a;
	ft_give_position((*stack_a));
	while ((*stack_a)->index != 0)
		*stack_a = (*stack_a)->next;
	if ((*stack_a)->position > (get_list_length(head) / 2))
	{
		(*stack_a) = head;
		while ((*stack_a)->index != 0)
		{
			ft_rotate_down(stack_a);
			write(1, "rra\n", 4);
		}
	}
	if ((*stack_a)->position <= (get_list_length(head) / 2))
	{
		(*stack_a) = head;
		while ((*stack_a)->index != 0)
		{
			ft_rotate_up(stack_a);
			write(1, "ra\n", 3);
		}
	}
}
