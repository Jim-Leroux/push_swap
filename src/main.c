/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:27:49 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/21 13:59:09 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_link	*stack_a;
	t_link	*stack_b;
	char	*sorted_array;

	stack_a = NULL;
	stack_b = NULL;
	sorted_array = NULL;
	if (argc == 1 || !ft_check_args(argc, argv))
		return (0);
	ft_args_to_stack(&stack_a, argc, argv);
	if (!stack_a)
		return (0);
	if (ft_sorted_array(stack_a))
		return (0);
	else if (argc == 3)
	{
		ft_swap(&stack_a);
		return (write(1, "sa\n", 3));
	}
	ft_give_index(stack_a);
	ft_push_swap(argc, &stack_a, &stack_b);
	ft_ordre(&stack_a);
	ft_free_stack(&stack_a);
	free(stack_a);
	return (0);
}
