/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:31:25 by majmani           #+#    #+#             */
/*   Updated: 2023/01/10 21:50:01 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list *a)
{
	int	max;

	max = a->content;
	while (a)
	{
		if (max > a->content)
			max = a->content;
		a = a->next;
	}
	return (max);
}

int	ft_min_position(t_list **stack_a)
{
	int		min;
	t_list	*tmp;
	int		p;
	int		count;

	count = 1;
	p = 0;
	min = (*stack_a)->content;
	tmp = (*stack_a)->next;
	while (tmp != NULL)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			p = count;
		}
		count++;
		tmp = tmp->next;
	}
	return (p);
}

int	ft_check_range(t_list *lst, int start, int end, int *index)
{
	t_list	*ls;

	ls = lst;
	while (ls != NULL)
	{
		if (ls->content >= start && ls->content <= end)
			return (1);
		ls = ls->next;
		(*index)++;
	}
	return (0);
}

int	ft_max_position(t_list **stack_a, int *tab, int end)
{
	int		max;
	t_list	*tmp;
	int		p;
	int		count;

	count = 0;
	p = -1;
	max = -1;
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		if (tmp->content == tab[end])
		{
			max = tmp->content;
			p = count;
			break ;
		}
		count++;
		tmp = tmp->next;
	}
	return (p);
}
