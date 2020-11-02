#include "../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			err;

	stacks.print = 1;
	if (argc < 2)
	{
		(p_err(1));
		return (1);
	}

	if ((err = stacks_init(&stacks, argv + 1)))
	{
		p_err(err);
		return (err);
	}
	sort_manager(&stacks);
	stack_free(&stacks);
	return (err);
}
