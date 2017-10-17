/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:43:54 by arosset           #+#    #+#             */
/*   Updated: 2017/10/17 15:43:55 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_name_road(t_env *env, char *s)
{
	t_list *room;

	room = env->room;
	while (room)
	{
		if (ft_strcmp(s, room->data) == 0)
			return (1);
		room = room->next;
	}
	return (0);
}

int		ft_check_name_road(t_env *env, char *src, char *dst)
{
	if (ft_name_road(env, src) == 0 || ft_name_road(env, dst) == 0)
		return (0);
	if (!ft_addroad(src, dst, &env->road))
		return (0);
	return (1);
}

void 	ft_set_start_end(char *s, char *str, t_env *env)
{
	if (ft_strcmp(s, "##start") == 0)
		env->start = ft_strsub(str, 0, ft_strlen(str));
	if (ft_strcmp(s, "##end") == 0)
		env->end = ft_strsub(str, 0, ft_strlen(str));
}

int   ft_search_room(t_env *env, char *s)
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
					free (str);
					return (1);
				}
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

void 	ft_check_name(char *s, t_env *env)
{
	t_list	*room;

	if (env->room)
	{
		room = env->room;
		while (room)
		{
			if (ft_strcmp(s, room->data) == 0)
				ft_error(NULL, NULL);
			room = room->next;
		}
	}
}

int 	ft_check_and_add(t_env *env, char **line)
{
	char	**data;
	int		i;

	i = 0;
	if (ft_comment(*line) == 3)
	{
		data = ft_strsplit(*line, ' ');
		if (data[0][0] == 'L')
			ft_error(NULL, NULL);
		while (data[i] != NULL)
			i++;
		if (i != 3)
		{
			ft_free_tab(data);
			return (1);
		}
		ft_check_int(data[1]);
		ft_check_int(data[2]);
		ft_check_name(data[0], env);
		ft_addend(data[0], &env->room);
		ft_free_tab(data);
	}
	return (0);
}
