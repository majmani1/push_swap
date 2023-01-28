/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:18:14 by majmani           #+#    #+#             */
/*   Updated: 2023/01/10 21:45:17 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_isnum(char *c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (c[i])
	{
		if ((c[i] >= '0' && c[i] <= '9') || c[i] == ' ' || ((c[i] == '-'
					|| c[i] == '+') && (c[i + 1] >= '0' && c[i + 1] <= '9')))
			count++;
		i++;
	}
	if (count != ft_strlen(c))
		return (0);
	else
		return (1);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_check_double(char **nums, char *num, int n)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (ft_atoi(num) == ft_atoi(nums[i]) && i != n)
			return (0);
		i++;
	}
	return (1);
}
