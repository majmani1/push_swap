/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:20:20 by majmani           #+#    #+#             */
/*   Updated: 2023/01/10 14:12:52 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

# define BUFFER_SIZE 100

char	**ft_split(char const *s, char c);
size_t	ft_strlen( char *str);
t_list	*ft_add_stack(int argc, char **argv, t_list *n);
int		ft_check_double(char **nums, char *num, int n);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
void	ft_sa(t_list **lst);
void	ft_sb(t_list **lst);
void	ft_sa(t_list **lst);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **lst);
void	ft_rb(t_list **lst);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **lst);
void	ft_rrb(t_list **lst);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_b, t_list **stack_a);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_free2(char **str);
int		ft_check2(t_list *lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *str);
int		ft_isnum(char *c);
t_list	*ft_lstnew(int content);
t_list	*ft_add_stack(int argc, char **argv, t_list *n);
int		ft_strcmp(char *s1, char *s2);
void	ft_appliquer(char *l, t_list **stack_a, t_list **stack_b, int *c);
int		ft_check_sorting(t_list *stack_a);
#endif