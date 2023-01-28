/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:51:56 by majmani           #+#    #+#             */
/*   Updated: 2023/01/11 22:21:01 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*ft_add_stack(int argc, char **argv, t_list *n)
{
	int		c;
	char	**num;
	int		i;

	c = 1;
	while (c < argc)
	{
		num = ft_split(argv[c], ' ');
		if (num[0] == NULL)
			(write(1, "Error\n", 6), exit(0));
		i = 0;
		while (num[i])
		{
			if (ft_isnum(num[i]) == 0)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			ft_lstadd_back(&n, ft_lstnew(ft_atoi(num[i])));
			i++;
		}
		ft_free2(num);
		c++;
	}
	return (n);
}

int	ft_min(t_list **stack_a)
{
	int		min;
	t_list	*tmp;

	min = (*stack_a)->content;
	tmp = (*stack_a)->next;
	while (tmp != NULL)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_check(int c, int *tab, int j)
{
	while (j >= 0)
	{
		if (tab[j] == c)
			return (1);
		j--;
	}
	return (0);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				c;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			c = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = c;
			i = 0;
		}
		else
			i++;
	}
}
