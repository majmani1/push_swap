/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:15:08 by majmani           #+#    #+#             */
/*   Updated: 2023/01/10 21:48:39 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_free2(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
}

int	ft_check2(t_list *lst, t_list *new)
{
	while (lst != NULL)
	{
		if (lst->content == new->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (ft_check2(*lst, new) == 0)
	{
		if (*lst != NULL)
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
		else
			*lst = new;
	}
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}
