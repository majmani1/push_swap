/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:03:13 by majmani           #+#    #+#             */
/*   Updated: 2023/01/10 20:29:07 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_it_back(t_list **a, t_list **b)
{
	while ((*b))
		ft_pa(b, a);
}

void	ft_two(t_list **n)
{
	if ((*n)->content > (*n)->next->content)
		ft_sa(n);
}
