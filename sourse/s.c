/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:37:50 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/02 19:37:51 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_small_three(t_stack *stack, t_stacks *stacks)
{
	while (!stack_is_sort(stack))
	{
		if (stack->first->data > stack->first->next->data)
			o_s(stack, stacks);
		else if (stack->first->next->data > stack->last->data)
			o_rr(stack, stacks);
		else
			o_r(stack, stacks);
	}
}

void		sort_min(t_stack *stack, t_stacks *stacks)
{
	t_stack	*to_stack;
	int		p;

	p = 0;
	to_stack = stacks->stack[B];
	while (!stack_is_sort(stack))
	{
		if (stack->first->data > stack->first->next->data)
		{
			if (to_stack->size > 1 && \
			to_stack->first->data < to_stack->first->next->data && !p)
				o_double(stacks, "ss", o_s);
			else
				o_s(stack, stacks);
		}
		else if (++p)
			o_p(stack, to_stack, stacks);
	}
	if (p)
	{
		while (p--)
			o_p(to_stack, stack, stacks);
		sort_min(stack, stacks);
	}
}

void		sort_quick(t_stacks *stacks)
{
	if (!stack_is_sort(stacks->stack[A]))
		stack_splt(stacks, stack_median(stacks, A, stacks->height_a));
	else if (stacks->stack[B]->size > 0)
		stack_mrg(stacks, stack_median(stacks, B, stacks->height_b));
	else
		return ;
	sort_quick(stacks);
}

void		sort_manager(t_stacks *stacks)
{
	if (stacks->stack[A]->size <= 3)
		sort_small_three(stacks->stack[A], stacks);
	else if (stacks->block[A][stacks->height_a] <= 3)
		sort_min(stacks->stack[A], stacks);
	else
		sort_quick(stacks);
}
