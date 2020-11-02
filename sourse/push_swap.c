/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:37:39 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/02 19:38:29 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
