/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:15:54 by majmani           #+#    #+#             */
/*   Updated: 2023/01/11 21:48:02 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_add_stack(int argc, char **argv, t_list *n)
{
	int		c;
	char	**num;
	int		i;

	c = 1;
	while (c < argc)
	{
		num = ft_split(argv[c], ' ');
		if (num[0] == NULL)
			(write(1, "Error\n", 6), exit(0));
		i = 0;
		while (num[i])
		{
			if (ft_isnum(num[i]) == 0)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			ft_lstadd_back(&n, ft_lstnew(ft_atoi(num[i])));
			i++;
		}
		ft_free2(num);
		c++;
	}
	return (n);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
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

void	ft_appliquer(char *l, t_list **stack_a, t_list **stack_b, int *c)
{
	if (ft_strcmp(l, "ra\n") == 0)
		ft_ra(stack_a);
	else if (ft_strcmp(l, "rb\n") == 0)
		ft_rb(stack_b);
	else if (ft_strcmp(l, "rr\n") == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(l, "sa\n") == 0)
		ft_sa(stack_a);
	else if (ft_strcmp(l, "sb\n") == 0)
		ft_sb(stack_b);
	else if (ft_strcmp(l, "ss\n") == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strcmp(l, "rra\n") == 0)
		ft_rra(stack_a);
	else if (ft_strcmp(l, "rrb\n") == 0)
		ft_rra(stack_b);
	else if (ft_strcmp(l, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b);
	else if (ft_strcmp(l, "pb\n") == 0)
		ft_pb(stack_a, stack_b);
	else if (ft_strcmp(l, "pa\n") == 0)
		ft_pa(stack_b, stack_a);
	else
		(*c)++;
}

int	main(int argc, char **argv)
{
	t_list	*n;
	t_list	*n1;
	char	*l;
	int		c;
	int		size;

	c = 0;
	n = NULL;
	if (argc == 1)
		exit(1);
	n = ft_add_stack(argc, argv, n);
	size = ft_lstsize(n);
	while (1)
	{
		l = get_next_line(0);
		if (l == NULL)
			break ;
		(ft_appliquer(l, &n, &n1, &c), free(l));
	}
	if (c > 0)
		(write(1, "Error\n", 6), exit(1));
	if (ft_check_sorting(n) == 0 && size == ft_lstsize(n))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
