/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:46:35 by majmani           #+#    #+#             */
/*   Updated: 2023/01/12 13:53:37 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_tableau(t_list *stack)
{
	int		j;
	int		i;
	int		*tab;
	t_list	*tmp;

	tmp = stack;
	j = ft_lstsize(stack);
	tab = malloc(j * sizeof(int));
	i = 0;
	while (tmp != NULL)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	sort_int_tab(tab, j);
	return (tab);
}

int	main(int argc, char **argv)
{
	t_list	*n;
	t_list	*n1 ;

	if (argc == 1)
		exit(1);
	n = NULL;
	n = ft_add_stack(argc, argv, n);
	if (ft_check_sorting(n) == 0)
		exit(1);
	if (ft_lstsize(n) > 7)
		ft_mya(&n, &n1);
	else if (ft_lstsize(n) == 2)
		ft_two(&n);
	else if (ft_lstsize(n) == 3)
		ft_three(&n);
	else if (ft_lstsize(n) >= 4 || ft_lstsize(n) < 8)
		ft_five(&n, &n1);
	return (0);
}
