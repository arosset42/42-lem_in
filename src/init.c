/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:14:38 by arosset           #+#    #+#             */
/*   Updated: 2017/10/24 15:52:00 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_stock		*ft_initstock(void)
{
	t_stock *stock;

	if (!(stock = malloc(sizeof(t_stock))))
		return (NULL);
	(stock)->room = NULL;
	(stock)->room2 = NULL;
	(stock)->road = NULL;
	(stock)->com = NULL;
	(stock)->file = NULL;
	stock->end = NULL;
	stock->start = NULL;
	return (stock);
}

static char	*ft_returnroom(char *start, char *end, int i)
{
	if (!start || !end)
		return (NULL);
	if (i == 1 && end)
	{
		if (start)
			free(start);
		return (end);
	}
	if (i == 0 && start)
	{
		if (end)
			free(end);
		return (start);
	}
	return (NULL);
}

char		*ft_startandend(t_parse *room, int i)
{
	t_parse *tmp;
	char	*start;
	char	*end;

	tmp = room;
	end = NULL;
	start = NULL;
	while (tmp->next)
	{
		if ((!ft_strcmp("##start", tmp->str) &&
					!ft_strcmp("##end", tmp->next->str))
			|| (!ft_strcmp("##start", tmp->str) &&
				!ft_strcmp("##end", tmp->next->str)))
			return (0);
		else if (!ft_strcmp("##start", tmp->str))
			start = ft_strdup(tmp->next->str);
		else if (!ft_strcmp("##end", tmp->str))
			end = ft_strdup(tmp->next->str);
		tmp = tmp->next;
	}
	return (ft_returnroom(start, end, i));
}
