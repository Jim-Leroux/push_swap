/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:27:49 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/17 14:45:29 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_link	*stack_a;
	t_link	*stack_b;
	char	*sorted_array;
	int tmp1;
	int tmp2;

	stack_a = NULL;
	stack_b = NULL;
	sorted_array = NULL;
	tmp2 = ft_atoi(argv[2]);
	tmp1 = ft_atoi(argv[1]);
	if (!ft_check_args(argc, argv))
	{
		tmp2 = ft_atoi(argv[2]);
		tmp1 = ft_atoi(argv[1]);
		return (0);
	}
	ft_args_to_stack(&stack_a, argc, argv);
	// print_list(stack_a);
	if (!stack_a)
		return (0);
	if (ft_sorted_array(stack_a))
		return (0);
	else if (argc == 3)
	{
		ft_swap(&stack_a);
		write(1, "sa\n", 3);
		return (0);
	}
	ft_give_index(stack_a);
	ft_push_swap(argc, &stack_a, &stack_b);
	ft_ordre(&stack_a);
	// print_list(stack_a);
	return (0);
}
