#include "../includes/push_swap.h"

void	p_err(int err)
{
	if (err)
		ft_printf("Error\n");
}

void	p_op(t_stacks *stack, const char *str, char tower)
{
	if (stack->print)
		ft_printf("%s%c\n", str, tower);
}

int		stack_median(t_stacks *stack, int tower, int num)
{
	int		max;
	int		min;
	t_node	*node;
	int		i;

	i = -1;
	node = stack->stack[tower]->first;
	max = node->data;
	min = node->data;
	while (++i < stack->block[tower][num])
	{
		(max < node->data) ? max = node->data : 0;
		(min > node->data) ? min = node->data : 0;
		node = node->next;
	}
	return ((max + min) / 2);
}

int		el_median(t_stacks *stack, int median, int s)
{
	t_node	*node;
	int		elements;
	int		i;

	elements = 0;
	i = -1;
	node = stack->stack[s]->first;
	if (s == A)
		while (++i < stack->block[s][stack->height_a])
		{
			if (node->data <= median)
				elements++;
			node = node->next;
		}
	else
		while (++i < stack->block[s][stack->height_b])
		{
			if (node->data >= median)
				elements++;
			node = node->next;
		}
	return (elements);
}

int		stack_is_sort(t_stack *stack)
{
	t_node	*node;

	node = stack->first;
	if (stack->tower == 'a')
	{
		while (node->next && node->data < node->next->data)
			node = node->next;
	}
	else
		while (node->next && node->data > node->next->data)
			node = node->next;
	return (!(stack->tower == 'a' ? node->next : node->prev));
}
