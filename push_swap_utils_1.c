/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:58:26 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/18 12:38:10 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_args_to_stack(t_link **stack_a, int argc, char **argv)
{
	int		index;
	t_link	*tmp;

	index = 1;
	(*stack_a) = ft_lstnew(ft_atoi(argv[index]));
	tmp = *stack_a;
	while (++index < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[index]));
		tmp = ft_lstadd_back(stack_a, tmp);
		tmp = tmp->next;
	}
}

long int	ft_atoi(const char *nptr)
{
	long int	i;
	long int	n;
	long int	negative;

	i = 0;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	negative = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return (n * negative);
}

t_link	*ft_lstnew(int content)
{
	t_link	*head;

	head = malloc(sizeof(t_link));
	if (head == NULL)
		return (0);
	head->value = content;
	head->next = NULL;
	return (head);
}

t_link	*ft_lstadd_back(t_link **lst, t_link *new)
{
	t_link	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	return (*lst);
}

t_link	*ft_lstlast(t_link *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
