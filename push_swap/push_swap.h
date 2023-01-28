/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:07:23 by majmani           #+#    #+#             */
/*   Updated: 2023/01/10 21:15:02 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
typedef struct s_back_a {
	int	size;
	int	index;
	int	d;
	int	e;	
}				t_back_a;
typedef struct s_mya{
	int	start;
	int	end;
	int	milieu;
	int	of;
	int	size;
	int	*tab;
}				t_mya;

char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_sa(t_list **lst);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **lst);
void	ft_rra(t_list **lst);
void	ft_rrb(t_list **lst);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rb(t_list **lst);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_b, t_list **stack_a);
void	ft_three(t_list **stack);
int		ft_min_position(t_list **stack_a);
void	ft_five(t_list **stack_a, t_list **stack_b);
int		ft_lstsize(t_list *lst);
int		ft_check_sorting(t_list *stack_a);
t_list	*ft_add_stack(int argc, char **argv, t_list *n);
void	ft_mya(t_list **stack_a, t_list **stack_b);
int		*ft_sort_tableau(t_list *stack);
void	sort_int_tab(int *tab, unsigned int size);
int		ft_check_range(t_list *lst, int start, int end, int *index);
int		ft_max_position(t_list **stack_a, int *tab, int end);
int		ft_maxx(t_list **stack_a);
void	ft_back_a(t_list **stack_a, t_list **stack_b, int *tab, int end);
void	get_it_back(t_list **a, t_list **b);
int		ft_min(t_list **stack_a);
int		ft_check_double(char **nums, char *num, int n);
int		ft_atoi(const char *str);
int		ft_isnum(char *c);
size_t	ft_strlen( char *str);
void	ft_free2(char **str);
void	ft_re_start_end(t_mya *m);
int		ft_out_range(t_list **stack_a, t_mya m, int c);
void	ft_initialisation(t_mya *m, t_list **stack_a);
void	ft_two(t_list **n);
#endif
