/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:37:58 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/02 19:44:41 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_duplicate(char **s)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[j])
		{
			if (j != i)
				if (!ft_strcmp(s[i], s[j]))
					return (3);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_int(char **s)
{
	int i;


	i = 0;

	while (s[i])
	{
		if ((ft_atoi(s[i]) == 0 || ft_atoi(s[i]) > INT_MAX || ft_atoi(s[i]) < INT_MIN) && (ft_strlen(s[i]) > 1))
			return (2);
		i++;
	}
	return (0);
}
int		check_valid_int(char **s)
{
	int i;
	int j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == '-' || s[i][j] == '+')
				if (ft_isdigit(s[i][j + 1]))
					continue;
			if (!ft_isdigit(s[i][j]))
				return (4);
		}
	}
	return (0);
}

int		check_args_err(char **str)
{
	int err;

	err = check_valid_int(str) + check_int(str) + check_duplicate(str);
	return (err);
}
