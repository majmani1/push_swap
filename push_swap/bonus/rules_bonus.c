/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:39:03 by majmani           #+#    #+#             */
/*   Updated: 2023/01/11 12:37:19 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sb(t_list **lst)
{
	int	s;

	if (ft_lstsize(*lst) > 1)
	{
		s = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = s;
	}
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
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
	}
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
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
	}
}
