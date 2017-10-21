/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:51:14 by arosset           #+#    #+#             */
/*   Updated: 2017/10/20 10:51:15 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*ft_firstroominroad(char *str)
{
	char	*firstroom;
	int		i;

	i = 0;
	firstroom = NULL;
	while (str[i] != '-' && str[i] != '\0')
		i++;
	if (i > 0)
	{
		if (!(firstroom = malloc(sizeof(char) * i + 1)))
			return (NULL);
		i = 0;
		while (str[i] != '-' && str[i] != '\0')
		{
			firstroom[i] = str[i];
			i++;
		}
		firstroom[i] = '\0';
	}
	return (firstroom);
}

char	*ft_searchroominroad(char *str)
{
	char	*seconderoom;
	int		i;
	int		j;

	seconderoom = NULL;
	i = 0;
	j = 0;
	while (str[i] != '-' && str[i] != '\0')
		i++;
	if (!(seconderoom = malloc(sizeof(char) * ((ft_strlen(str) - i) + 1))))
		return (NULL);
	i++;
	while (str[i] != '\0')
	{
		seconderoom[j] = str[i];
		i++;
		j++;
	}
	seconderoom[j] = '\0';
	return (seconderoom);
}

int		ft_searchinlist(char *str, t_parse *file)
{
	while (file)
	{
		if (!ft_strcmp(str, file->str))
			return (0);
		file = file->next;
	}
	return (1);
}

int		ft_searchinroom(t_parse *room, char *str)
{
	while (room)
	{
		if (!ft_strcmp(room->str, str))
			return (1);
		room = room->next;
	}
	return (0);
}
