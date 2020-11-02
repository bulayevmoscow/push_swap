#include "../includes/push_swap.h"

int			args_len(char **arg)
{
	int i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i] != NULL)
		i++;
	return (i);
}

void	args_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	**add_args(char *av, char **arg)
{
	char	**str;
	char	**tmp;
	int		i;
	int		k;

	str = ft_strsplit(av, ' ');
	if (!(i = args_len(arg)))
		return (str);
	k = args_len(str);
	if (!(tmp = (char **)malloc(sizeof(char *) * (i + k + 1))))
		exit(1);
	i = -1;
	while (arg[++i])
		tmp[i] = arg[i];
	k = -1;
	while (str[++k])
		tmp[i + k] = str[k];
	tmp[i + k] = NULL;
	free(arg);
	free(str);
	return (tmp);
}


char		**fill_args(char **av)
{
	char	**arg;
	int		i;

	i = -1;
	arg = NULL;
	while (av[++i])
		arg = add_args(av[i], arg);
	return (arg);
}
