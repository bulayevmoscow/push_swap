/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:37:28 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/02 19:51:39 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			check_validation(char *str, int (*f)(const char *, const char *))
{
	if (!f(str, "pa") || !f(str, "pb") ||
		!f(str, "sa") || !f(str, "sb") ||
		!f(str, "ra") || !f(str, "rb") ||
		!f(str, "rra") || !f(str, "rrb") ||
		!f(str, "ss") || !f(str, "rr") ||
		!f(str, "rrr"))
		return (1);
	return (0);
}

void		check_do(t_stack *a, t_stack *b, t_stacks *stack, \
						char *operation)
{
	!ft_strcmp("pb", operation) ? o_p(a, b, stack) : 0;
	!ft_strcmp("pa", operation) ? o_p(b, a, stack) : 0;
	!ft_strcmp("sa", operation) ? o_s(a, stack) : 0;
	!ft_strcmp("sb", operation) ? o_s(b, stack) : 0;
	!ft_strcmp("ss", operation) ? o_double(stack, operation, o_s) : 0;
	!ft_strcmp("ra", operation) ? o_r(a, stack) : 0;
	!ft_strcmp("rb", operation) ? o_r(b, stack) : 0;
	!ft_strcmp("rr", operation) ? o_double(stack, operation, o_r) : 0;
	!ft_strcmp("rra", operation) ? o_rr(a, stack) : 0;
	!ft_strcmp("rrb", operation) ? o_rr(b, stack) : 0;
	!ft_strcmp("rrr", operation) ? o_double(stack, operation, o_rr) : 0;
}

int			check(t_stack *a, t_stack *b, t_stacks *stacks)
{
	char	*operation;

	while (get_next_line(0, &operation) > 0)
	{
		if (!check_validation(operation, ft_strcmp))
		{
			p_err(5);
			return (5);
		}
		check_do(a, b, stacks, operation);
		free(operation);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_stacks	stack;

	stack.print = 0;
	if (ac < 2)
		return (0);
	av += 1;
	if (stacks_init(&stack, av))
	{
		p_err(5);
		return (5);
	}
	if (check(stack.stack[A], stack.stack[B], &stack))
	{
		if (stack_is_sort(stack.stack[A]) && !stack.stack[1]->first)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	stack_free(&stack);
	return (0);
}
