/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:47:53 by majmani           #+#    #+#             */
/*   Updated: 2023/01/11 13:18:24 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_list **lst)
{
	int	s;

	if (ft_lstsize(*lst) > 1)
	{
		s = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = s;
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	int	s;

	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		s = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = s;
		s = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = s;
		write(1, "ss\n", 3);
	}
}

void	ft_rb(t_list **lst)
{
	t_list	*tmp;
	t_list	*s;

	if (ft_lstsize(*lst) >= 2)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		s = ft_lstlast(*lst);
		s->next = tmp;
		tmp->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*s;

	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		s = ft_lstlast(*stack_a);
		s->next = tmp;
		tmp->next = NULL;
		tmp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		s = ft_lstlast(*stack_b);
		s->next = tmp;
		tmp->next = NULL;
		write(1, "rr\n", 3);
	}
}

void	ft_rrb(t_list **lst)
{
	t_list	*tmp;
	t_list	*s;
	t_list	*p;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = (*lst);
		p = (*lst);
		(*lst) = ft_lstlast(*lst);
		s = ft_lstlast(p);
		while (tmp != NULL)
		{
			if (tmp->next->next == NULL)
				break ;
			tmp = tmp->next;
		}
		s->next = p;
		tmp->next = NULL;
		write(1, "rrb\n", 4);
	}
}
