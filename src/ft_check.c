/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:43:54 by arosset           #+#    #+#             */
/*   Updated: 2017/10/24 15:49:47 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_search(char *str, t_parse *room)
{
	t_parse *tmp;

	tmp = room;
	while (tmp)
	{
		if (!ft_strcmp(tmp->str, str))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_roominroad(char *str, t_parse *room)
{
	char	*one;
	char	*seconde;

	one = ft_firstword(str, '-');
	seconde = ft_lastword(str, '-');
	if (ft_search(one, room) && ft_search(seconde, room))
	{
		if (one)
			free(one);
		if (seconde)
			free(seconde);
		return (1);
	}
	return (0);
}

int			ft_formatroad(char *road)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (road[i] != '\0')
	{
		if (road[i] == '-')
			c++;
		if (road[i] == ' ')
			return (0);
		i++;
	}
	if (c == 1)
		return (1);
	else
		return (0);
}

int			ft_cmpinroom(t_parse *room)
{
	t_parse *tmp;
	char	*str;

	tmp = room;
	if (!room)
		return (0);
	while (tmp)
	{
		str = tmp->str;
		room = tmp->next;
		while (room)
		{
			if (!ft_strcmp(room->str, str))
				return (0);
			room = room->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
