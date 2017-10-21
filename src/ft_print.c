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

void	ft_disl(char *str, char *display)
{
	ft_putstr(str);
	ft_putendl(display);
	ft_putstr("\033[0m");
}

int		ft_displaylist(t_env env)
{
	while (env.init)
	{
		if (env.init->str[0] == '#' && env.init->str[1] == '#')
			ft_disl("\033[32m", env.init->str);
		else if (env.init->str[0] == '#' && env.init->str[1] != '#')
			ft_disl("\033[31m", env.init->str);
		else if (!ft_strchr(env.init->str, '-'))
			ft_disl("\033[33m", env.init->str);
		else
			ft_disl("\033[34m", env.init->str);
		env.init = env.init->next;
	}
	return (1);
}
