#include "../includes/push_swap.h"

void		stack_mrg(t_stacks *stack, int med)
{
	int el;
	int r;

	r = 0;
	el = el_median(stack, med, B);
	stack->block[A][stack->height_a] ? stack->height_a++ : 0;
	while (el)
	{
		if (stack->stack[B]->first->data >= med)
		{
			o_p(stack->stack[B], stack->stack[A], stack);
			stack->block[A][stack->height_a]++;
			stack->block[B][stack->height_b]--;
			if (stack->block[A][stack->height_a] <= 3)
				sort_min(stack->stack[A], stack);
			el--;
		}
		else if (++r)
			o_r(stack->stack[B], stack);
	}
	while (stack->height_b > 0 && r--)
		o_rr(stack->stack[B], stack);
	!stack->block[B][stack->height_b] ? stack->height_b-- : 0;
	sort_manager(stack);
}

void		stack_splt(t_stacks *stack, int median)
{
	int el;
	int r;

	r = 0;
	el = el_median(stack, median, A);
	stack->block[B][stack->height_b] ? stack->height_b++ : 0;
	while (el && !stack_is_sort(stack->stack[A]))
	{
		if (stack->stack[A]->first->data <= median)
		{
			o_p(stack->stack[A], stack->stack[B], stack);
			stack->block[A][stack->height_a]--;
			stack->block[B][stack->height_b]++;
			el--;
		}
		else if (++r)
			o_r(stack->stack[A], stack);
	}
	while (stack->height_a > 0 && r--)
		o_rr(stack->stack[A], stack);
	!stack->block[A][stack->height_a] ? stack->height_a-- : 0;
	sort_manager(stack);
}
