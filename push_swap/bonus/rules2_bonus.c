/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:16:35 by majmani           #+#    #+#             */
/*   Updated: 2023/01/11 12:34:56 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sa(t_list **lst)
{
	int	s;

	if (ft_lstsize(*lst) > 1)
	{
		s = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = s;
	}
}

void	ft_ra(t_list **lst)
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
	}
}

void	ft_rra(t_list **lst)
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
	}
}

void	ft_pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;
	t_list	*pp;

	if ((*stack_b) == NULL)
		return ;
	tmp = (*stack_b)->next;
	pp = (*stack_a);
	(*stack_a) = (*stack_b);
	(*stack_a)->next = pp;
	(*stack_b) = tmp;
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
