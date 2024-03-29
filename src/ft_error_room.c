/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:20:03 by arosset           #+#    #+#             */
/*   Updated: 2017/10/24 15:20:05 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		ft_words(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if ((str[i] != ' ') && (str[i] != '\0'))
			j++;
		while ((str[i] != ' ') && (str[i] != '\0'))
			i++;
	}
	if (j == 3 || j == 0)
		return (1);
	else
		return (0);
}

static int		ft_searchintab(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int		ft_comptspace(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			c++;
		i++;
	}
	if (c == 2 || c == 0)
		return (1);
	else
		return (0);
}

int				ft_errorinroom(t_parse *room)
{
	while (room)
	{
		if (room->str[0] == 'L')
			return (0);
		if (room->str[0] != '#')
		{
			if (!ft_comptspace(room->str))
				return (0);
		}
		if (room->str[0] != '#')
		{
			if ((!ft_searchintab(room->str)) || (!ft_words(room->str)))
				return (0);
		}
		room = room->next;
	}
	return (1);
}
