/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:28:25 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/17 13:17:13 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_link **stack)
{
	t_link	*tmp1;
	t_link	*tmp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*stack = tmp2;
}

void	ft_ss(t_link **stack_a, t_link **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_push(t_link **stack_a, t_link **stack_b)
{
	t_link	*tmp;

	if ((*stack_a) == NULL)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_b)->next = tmp;
}

void	ft_pa(t_link **stack_a, t_link **stack_b)
{
	t_link	*tmp;

	if ((*stack_b) == NULL)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_a)->next = tmp;
}

void	ft_rotate_up(t_link **stack)
{
	t_link	*tmp1;
	t_link	*tmp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp1 = *stack;
	tmp2 = *stack;
	(*stack) = (tmp1)->next;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	tmp2->next = NULL;
}
