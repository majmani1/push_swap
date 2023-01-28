/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:36:32 by majmani           #+#    #+#             */
/*   Updated: 2023/01/10 16:17:38 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*pp;

	if ((*stack_a) == NULL)
		return ;
	tmp = (*stack_a)->next;
	pp = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_b)->next = pp;
	(*stack_a) = tmp;
}
