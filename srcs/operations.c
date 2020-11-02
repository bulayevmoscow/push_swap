#include "../includes/push_swap.h"

void	o_double(t_stacks *stack, char *op, void (*f)(t_stack *, t_stacks *))
{
	int i;

	i = stack->print;
	stack->print = 0;
	f(stack->stack[A], stack);
	f(stack->stack[B], stack);
	stack->print = i;
	p_op(stack, op, 0);
}

void	o_rr(t_stack *stack, t_stacks *stacks)
{
	t_node *temp;

	if (stack->first && stack->last)
	{
		temp = stack->last;
		temp->next = stack->first;
		stack->first->prev = temp;
		stack->first = temp;
		stack->last = stack->last->prev;
		stack->last->next = NULL;
		stack->first->prev = NULL;
		p_op(stacks, "rr", stack->tower);
	}
}

void	o_r(t_stack *stack, t_stacks *stacks)
{
	if (stack->first && stack->last)
	{
		stack->last->next = stack->first;
		stack->first->prev = stack->last;
		stack->last = stack->first;
		stack->first = stack->first->next;
		stack->first->prev = NULL;
		stack->last->next = NULL;
		p_op(stacks, "r", stack->tower);
	}
}

void	o_s(t_stack *stack, t_stacks *stacks)
{
	int temp;

	if (stack->first && stack->first->next)
	{
		temp = stack->first->data;
		stack->first->data = stack->first->next->data;
		stack->first->next->data = temp;
		p_op(stacks, "s", stack->tower);
	}
}

void	o_p(t_stack *from_stack, t_stack *to_stack, t_stacks *stacks)
{
	t_node *temp;

	if (!from_stack->first)
		return ;
	temp = from_stack->first;
	if (from_stack->first->next)
	{
		from_stack->first = from_stack->first->next;
		from_stack->first->prev = NULL;
	}
	else
		from_stack->first = NULL;
	temp->next = to_stack->first;
	temp->prev = NULL;
	if (to_stack->first)
		to_stack->first->prev = temp;
	to_stack->first = temp;
	if (!to_stack->last)
		to_stack->last = temp;
	from_stack->size -= 1;
	to_stack->size += 1;
	p_op(stacks, "p", to_stack->tower);
}
