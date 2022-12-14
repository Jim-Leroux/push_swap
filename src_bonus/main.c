/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:15:31 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/26 16:10:33 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_link	*stack_a;
	t_link	*stack_b;

	fd = STDIN_FILENO;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !ft_check_args(argc, argv))
		return (0);
	ft_args_to_stack(&stack_a, argc, argv);
	if (!stack_a)
		return (0);
	ft_check(&stack_a, &stack_b, fd);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

void	ft_check(t_link **stack_a, t_link **stack_b, int fd)
{
	char	*line_read;

	while (fd)
		fd = STDIN_FILENO;
	line_read = get_next_line(fd, 0);
	while (line_read != NULL)
	{
		if (ft_strcmp(line_read, "pa\n") == 0)
			ft_pa(stack_a, stack_b);
		else if (ft_strcmp(line_read, "pb\n") == 0)
			ft_push(stack_a, stack_b);
		else if (ft_check_part_2(stack_a, stack_b, fd, line_read) == 0)
		{
			get_next_line(fd, 1);
			write(2, "Error\n", 7);
			return (free(line_read));
		}
		free(line_read);
		line_read = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	if (ft_is_sorted((*stack_a), (*stack_b)))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	ft_check_part_2(t_link **stack_a, t_link **stack_b, int fd, char *line_read)
{
	if (ft_strcmp(line_read, "sa\n") == 0)
		return (ft_swap(stack_a), 1);
	if (ft_strcmp(line_read, "sb\n") == 0)
		return (ft_swap(stack_b), 1);
	if (ft_strcmp(line_read, "ra\n") == 0)
		return (ft_rotate_up(stack_a), 1);
	if (ft_strcmp(line_read, "rb\n") == 0)
		return (ft_rotate_up(stack_b), 1);
	else if (ft_strcmp(line_read, "rra\n") == 0)
		return (ft_rotate_down(stack_a), 1);
	else if (ft_strcmp(line_read, "rrb\n") == 0)
		return (ft_rotate_down(stack_b), 1);
	else if (ft_strcmp(line_read, "rrr\n") == 0)
		return (ft_rrr(stack_a, stack_b), 1);
	else if (ft_strcmp(line_read, "rr\n") == 0)
		return (ft_rr(stack_a, stack_b), 1);
	else if (ft_strcmp(line_read, "ss\n") == 0)
		return (ft_ss(stack_a, stack_b), 1);
	return (0);
}

int	ft_is_sorted(t_link *stack_a, t_link *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a && stack_a->next)
	{
		if (stack_a->value < stack_a->next->value)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}
