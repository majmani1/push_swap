/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:03:04 by majmani           #+#    #+#             */
/*   Updated: 2023/01/10 12:03:05 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialisation(t_mya *m, t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	m->size = ft_lstsize(tmp);
	m->tab = ft_sort_tableau(tmp);
	m->milieu = m->size / 2;
	if (m->size <= 250)
		m->of = m->size / 8;
	if (m->size > 250)
		m->of = m->size / 18;
	m->start = m->milieu - m->of;
	m->end = m->milieu + m->of;
}

void	ft_re_start_end(t_mya *m)
{
	if (m->end > m->size - 1 || m->start < 0)
	{
		m->end = m->size - 1;
		m->start = 0;
	}
}

int	ft_out_range(t_list **stack_a, t_mya m, int c)
{
	if (!((*stack_a)->content >= m.tab[m.start]
			&& (*stack_a)->content <= m.tab[m.end]) && c == 1)
		return (1);
	if ((*stack_a)->content < m.tab[m.milieu]
		&& (*stack_a)->next != NULL && c == 2)
		return (1);
	return (0);
}

int	ft_maxx(t_list **stack_a)
{
	int		max;
	t_list	*tmp;
	int		p;
	int		count;

	count = 1;
	p = 0;
	max = (*stack_a)->content;
	tmp = (*stack_a)->next;
	while (tmp != NULL)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			p = count;
		}
		count++;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_check_sorting(t_list *stack_a)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (stack_a)
	{
		if (stack_a->next != NULL && stack_a->content < stack_a->next->content)
			count++;
		i++;
		stack_a = stack_a->next;
	}
	if (count == (i - 1))
		return (0);
	return (1);
}
