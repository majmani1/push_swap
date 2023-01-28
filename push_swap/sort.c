/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:06:41 by majmani           #+#    #+#             */
/*   Updated: 2023/01/12 14:33:42 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_list **stack)
{
	int	x1;
	int	x2;
	int	x3;

	x1 = (*stack)->content;
	x2 = (*stack)->next->content;
	x3 = (*stack)->next->next->content;
	if ((x1 > x2) && (x2 < x3) && (x1 < x3))
		ft_sa(stack);
	else if ((x1 > x2) && (x2 > x3) && (x1 > x3))
		(ft_ra(stack), ft_sa(stack));
	else if ((x1 > x2) && (x2 < x3) && (x1 > x3))
		ft_ra(stack);
	else if ((x1 < x2) && (x2 > x3) && (x1 < x3))
		(ft_sa(stack), ft_ra(stack));
	else if ((x1 < x2) && (x2 > x3) && (x1 > x3))
		(ft_ra(stack), ft_ra(stack));
}

void	ft_five(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		index;
	t_list	*tmp;

	tmp = (*stack_a);
	if (ft_check_sorting(tmp) == 1)
	{
		while (ft_lstsize(*stack_a) > 3)
		{
			size = ft_lstsize(*stack_a);
			index = ft_min_position(stack_a);
			if (index == 0)
			{
				ft_pb(stack_a, stack_b);
				continue ;
			}
			if (index >= size / 2)
				ft_rra(stack_a);
			else
				ft_ra(stack_a);
		}
		ft_three(stack_a);
		get_it_back(stack_a, stack_b);
	}
}

void	ft_full(t_back_a *l, t_list **stack_a, t_list **stack_b, int *tab)
{
	l->size = ft_lstsize(*stack_b);
	l->index = ft_max_position(stack_b, tab, l->e);
	if (l->index == -1)
	{
		ft_rra(stack_a);
		l->d--;
		l->e--;
	}
	else if (l->index == 0)
	{
		ft_pa(stack_b, stack_a);
		l->e--;
	}
	else if ((*stack_b) && (l->d == 0
			|| (*stack_b)->content > ft_lstlast(*stack_a)->content))
	{
		(ft_pa(stack_b, stack_a), ft_ra(stack_a));
		l->d++;
	}
	else if (l->index >= (l->size - 1) / 2)
		ft_rrb(stack_b);
	else if (l->index < (l->size - 1) / 2)
		ft_rb(stack_b);
}

void	ft_back_a(t_list **stack_a, t_list **stack_b, int *tab, int end)
{
	t_back_a	l;

	l.d = 0;
	l.e = end;
	while ((*stack_b))
		ft_full(&l, stack_a, stack_b, tab);
	while (l.d-- != 0)
		ft_rra(stack_a);
}

void	ft_mya(t_list **stack_a, t_list **stack_b)
{
	t_mya	m;
	int		index;

	index = 0;
	ft_initialisation(&m, stack_a);
	while ((*stack_a))
	{
		while (ft_check_range((*stack_a), m.tab[m.start], m.tab[m.end], &index))
		{
			while (ft_out_range(stack_a, m, 1) == 1
				&& index > ft_lstsize(*stack_a) / 2)
				ft_rra(stack_a);
			while (ft_out_range(stack_a, m, 1) == 1
				&& index <= ft_lstsize(*stack_a) / 2)
				ft_ra(stack_a);
			ft_pb(stack_a, stack_b);
			if (ft_out_range(stack_b, m, 2))
				ft_rb(stack_b);
			index = 0;
		}
		m.start -= m.of;
		m.end += m.of;
		ft_re_start_end(&m);
	}
	(ft_back_a(stack_a, stack_b, m.tab, m.end), free(m.tab));
}
