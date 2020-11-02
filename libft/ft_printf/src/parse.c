/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:47:20 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:47:21 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		parse_main(const char *str, va_list arg_list)
{
	int		ft_printf;

	g_model = push_mopdel(str, NULL, 1, 0);
	parse_sec(str, arg_list);
	ft_printf = print_result();
	remove_struct();
	return (ft_printf);
}

int		print_result(void)
{
	int			len;
	int			i;
	t_model		*model1;

	model1 = g_model;
	model1 = model1->next;
	len = 0;
	while (model1)
	{
		i = 0;
		while (model1->len-- > 0 || model1->str[i])
		{
			if (model1->str[i] == 1)
				ft_putchar('\x01');
			else
				ft_putchar(model1->str[i]);
			i++;
		}
		len += i;
		if (model1->next == NULL)
			break ;
		model1 = model1->next;
	}
	return (len);
}

int		parse_sec(const char *str, va_list arg_list)
{
	int len[2];

	len[0] = 0;
	len[1] = 0;
	while (str[(len[1] + len[0])])
	{
		if (str[len[1] + len[0]] == '%')
		{
			if (len[1] != 0)
				push_mopdel(ft_strsub(str, len[0], len[1]), g_model, 02, 0);
			len[1] += parse_pros((char *)str + (len[0] + len[1]), arg_list);
			len[0] += len[1];
			len[1] = 0;
		}
		else
			len[1]++;
	}
	push_mopdel(ft_strsub(str, len[0], len[1]), g_model, 22, 0);
	return (0);
}

int		parse_pros(char *str, va_list arg_list)
{
	int			len;
	t_info		test;

	test = info_init();
	len = check_manager(str, &test);
	pusher_manager(&test, arg_list);
	return (len);
}

t_model	*push_mopdel(const char *str, t_model *g_model, int isnew, int len)
{
	t_model		*model1;

	model1 = (t_model *)malloc(sizeof(t_model));
	model1->value = isnew;
	model1->str = (char *)str;
	model1->len = len;
	model1->next = NULL;
	if (isnew == 1)
		return (model1);
	while (g_model->next != NULL)
		g_model = (t_model *)g_model->next;
	g_model->next = (t_model *)model1;
	return (NULL);
}
