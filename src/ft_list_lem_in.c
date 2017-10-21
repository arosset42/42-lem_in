/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lem_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:16:01 by arosset           #+#    #+#             */
/*   Updated: 2017/10/21 16:13:14 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_listlen(t_parse *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int		ft_add(char *str, t_parse **add)
{
	t_parse *new;

	if (!(new = malloc(sizeof(t_parse))))
		return (0);
	new->str = ft_strdup(str);
	new->next = *add;
	*add = new;
	return (0);
}

int		ft_addend(char *str, t_parse **add)
{
	t_parse *new;
	t_parse *tmp;

	if (!(new = malloc(sizeof(t_parse))))
		return (0);
	new->str = ft_strdup(str);
	new->next = NULL;
	tmp = *add;
	if (!tmp)
		*add = new;
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	return (0);
}

int		ft_addroad(char *str, int level, t_road **add)
{
	t_road *new;
	t_road *tmp;

	if (!(new = malloc(sizeof(t_road))))
		return (0);
	new->str = ft_strdup(str);
	new->level = level;
	new->next = NULL;
	tmp = *add;
	if (!tmp)
		*add = new;
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	return (0);
}
