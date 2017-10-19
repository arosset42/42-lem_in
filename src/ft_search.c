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

int		ft_search_in_list(char *str, t_list *list)
{
	while (list)
	{
		if (!ft_strcmp(str, list->data))
			return (0);
		list = list->next;
	}
	return (1);
}

int		ft_search_road(t_env *env, t_road *road)
{
	t_road	*tmp;

	tmp = env->road;
	while (tmp)
	{
		if (!ft_strcmp(road->src, tmp->src) &&
				!ft_strcmp(road->dest, tmp->dest))
		{
			free(tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		ft_search_room(t_env *env, char *s)
{
	t_list	*tmp;
	char	*str;

	tmp = env->init;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->data) == 0)
		{
			while (tmp)
			{
				str = tmp->data;
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
