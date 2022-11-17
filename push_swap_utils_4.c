/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:58:09 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/17 14:07:10 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_link *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void	push_bottom_value(int argc, t_link **stack_a, t_link **stack_b)
{
	int	index;
	int	limit3;

	index = 0;
	limit3 = 0;
	while (index < (argc - 1) && (argc - limit3 - 1) > 3)
	{
		if ((*stack_a)->index < (argc - 1) / 2)
		{
			limit3++;
			ft_push(stack_a, stack_b);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_rotate_up(stack_a);
			write(1, "ra\n", 3);
		}
		index++;
	}
}

void	push_rest_keep_three(t_link **stack_a, t_link **stack_b)
{
	int	list_length;
	int	count;

	list_length = 0;
	count = 0;
	list_length = get_list_length(*stack_a);
	while (count < list_length - 3)
	{
		ft_push(stack_a, stack_b);
		write(1, "pb\n", 3);
		count++;
	}
}

int	get_list_length(t_link *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

void	ft_give_position(t_link *stack)
{
	int	position;

	position = 0;
	while (stack)
	{
		stack->position = position;
		position++;
		stack = stack->next;
	}
}
