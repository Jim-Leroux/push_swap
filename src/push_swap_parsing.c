/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:13:08 by jileroux          #+#    #+#             */
/*   Updated: 2022/11/28 12:45:29 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_args(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (!ft_str_is_numeric(argv[index]))
			return (0);
		index++;
	}
	index = 1;
	if (!ft_number_is_unique(argc, argv))
		return (0);
	return (1);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	if (ft_strlen(str) > 11)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (ft_atoi(str) > 2147483647)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (ft_atoi(str) < -2147483648)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	if (!ft_str_is_numeric_2(str))
		return (0);
	return (1);
}

int	ft_str_is_numeric_2(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 7);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_number_is_unique(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 2;
	count = 0;
	while (i < argc - 1)
	{
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				count++;
			j++;
			if (count >= 1)
			{
				write(2, "Error\n", 7);
				return (0);
			}
		}
		count = 0;
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
