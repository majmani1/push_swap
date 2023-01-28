/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:58:05 by majmani           #+#    #+#             */
/*   Updated: 2023/01/10 21:45:32 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free2(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
}

size_t	ft_strlen( char *str)
{
	size_t	c;

	c = 0;
	if (str == NULL)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

int	ft_isnum(char *c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (c[i])
	{
		if ((c[i] >= '0' && c[i] <= '9') || c[i] == ' '
			|| ((c[i] == '-' || c[i] == '+') && (c[i + 1] >= '0'
					&& c[i + 1] <= '9')))
			count++;
		i++;
	}
	if (count != ft_strlen(c))
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		m;
	size_t	nb;

	i = 0;
	m = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		if ((nb > 2147483647 && m == 1) || (nb > 2147483648 && m == -1))
			(write(1, "Error\n", 6), exit(0));
		i++;
	}
	return (nb * m);
}

int	ft_sort(char **num)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (num[i])
	{
		if (num[i + 1] != '\0' && ft_atoi(num[i]) < ft_atoi(num[i + 1]))
			count++;
		i++;
	}
	if (count == (i - 1))
		return (0);
	return (1);
}
