/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:46:05 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/02 19:47:09 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/includes/libftfull.h"

# define A				0
# define B				1

typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}					t_node;

typedef struct		s_stack
{
	t_node			*first;
	t_node			*last;
	int				size;
	char			tower;
}					t_stack;

typedef struct		s_stacks
{
	int				print;
	int				block[2][ARG_MAX];
	int				height_a;
	int				height_b;
	t_stack			*stack[2];
}					t_stacks;

void				o_r(t_stack *stack, t_stacks *stacks);
void				o_rr(t_stack *stack, t_stacks *stacks);
void				o_s(t_stack *stack, t_stacks *stacks);
void				o_p(t_stack *from_stack, t_stack *to_stack,\
						t_stacks *stacks);
void				o_double(t_stacks *stack, char *op, void (*f)(t_stack *,\
						t_stacks *));
int					stacks_init(t_stacks *stacks, char **av);
char				**fill_args(char **av);
t_stack				*stack_create(char tower);
int					check_args_err(char **str);
void				stack_free(t_stacks *stacks);
void				args_free(char **str);
void				sort_manager(t_stacks *stacks);
void				sort_min(t_stack *stack, t_stacks *stacks);
void				sort_quick(t_stacks *stacks);
void				stack_mrg(t_stacks *stack, int med);
void				stack_splt(t_stacks *stack, int median);
int					stack_median(t_stacks *stack, int tower, int num);
int					el_median(t_stacks *stack, int median, int s);
int					stack_is_sort(t_stack *stack);
void				p_err(int err);
void				p_op(t_stacks *stack, const char *str, char tower);

#endif
