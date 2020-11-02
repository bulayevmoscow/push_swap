#include "../includes/push_swap.h"

void				stack_free(t_stacks *stacks)
{
	t_node	*temp;
	int		i;

	i = 0;
	while (i < 2)
	{
		temp = stacks->stack[i]->first;
		while (temp)
		{
			stacks->stack[i]->first = stacks->stack[i]->first->next;
			free(temp);
			temp = stacks->stack[i]->first;
		}
		i++;
	}
	free(stacks->stack[A]);
	free(stacks->stack[B]);
}

void			stack_push(t_stack *stack, int data)
{
	t_node *tmp;

	if (!(tmp = (t_node*)malloc(sizeof(t_node))))
		exit(1);
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = stack->last;
	if (stack->last)
		stack->last->next = tmp;
	stack->last = tmp;
	if (!stack->first)
		stack->first = tmp;
	stack->size += 1;
}

t_stack		*stack_create(char tower)
{
	t_stack *tmp;

	if (!(tmp = (t_stack*)malloc(sizeof(t_stack))))
		exit(1);
	tmp->size = 0;
	tmp->tower = tower;
	tmp->first = NULL;
	tmp->last = NULL;
	return (tmp);
}

void		stacks_create(t_stacks *stacks, char **str)
{
	stacks->stack[0] = stack_create('a');
	stacks->stack[1] = stack_create('b');
	while (*str)
	{
		stack_push(stacks->stack[0], ft_atoi(*str));
		str += 1;
	}
	stacks->height_a = 0;
	stacks->height_b = 0;
	ft_bzero(stacks->block[A], ARG_MAX);
	ft_bzero(stacks->block[B], ARG_MAX);
	stacks->block[A][0] = stacks->stack[A]->size;
}

int			stacks_init(t_stacks *stacks, char **av)
{
	char	**str;
	int		err;

	str = fill_args(av);
	if (!fill_args(av)[0])
		return (1);
	if ((err = check_args_err(str)))
		return (err);
	stacks_create(stacks, str);
	args_free(str);
	return (err);
}
