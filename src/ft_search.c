/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:25:22 by arosset           #+#    #+#             */
/*   Updated: 2017/10/19 14:33:43 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_searchlevel(t_road *road, char *str)
{
	while (road)
	{
		if (!ft_strcmp(str, road->str))
			return (road->level);
		road = road->next;
	}
	return (2147483647);
}

int		ft_search_room(t_env *env, char *s)
{
	t_parse	*tmp;
	char	*str;

	tmp = env->init;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->str) == 0)
		{
			while (tmp)
			{
				str = tmp->str;
				if (str[0] != '#')
				{
					str = ft_strsub(str, 0, ft_strchr(str, ' ') - str);
					ft_set_start_end(s, str, env);
					free(str);
					return (1);
				}
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
