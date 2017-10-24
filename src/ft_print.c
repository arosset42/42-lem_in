/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:42:06 by arosset           #+#    #+#             */
/*   Updated: 2017/10/21 16:13:35 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	ft_disl(char *str, char *display)
{
	ft_putstr(str);
	ft_putendl(display);
	ft_putstr("\033[0m");
}

int			ft_displaylist(t_parse *list)
{
	t_parse *display;

	display = list;
	while (display)
	{
		if (display->str[0] == '#' && display->str[1] == '#')
			ft_disl("\033[32m", display->str);
		else if (display->str[0] == '#' && display->str[1] != '#')
			ft_disl("\033[31m", display->str);
		else if (!ft_strchr(display->str, '-'))
			ft_disl("\033[33m", display->str);
		else
			ft_disl("\033[34m", display->str);
		display = display->next;
	}
	return (1);
}
