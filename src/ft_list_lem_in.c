/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lem_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:16:01 by arosset           #+#    #+#             */
/*   Updated: 2017/09/07 15:16:03 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_addroadend(char *str, int level, t_end **add)
{
	t_end *new;
	t_end *tmp;

	if (!(new = malloc(sizeof(t_end))))
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

int		ft_addend(char *str, t_list **add)
{
	t_list *new;
	t_list *tmp;

	if (!(new = malloc(sizeof(t_list))))
		return (0);
	new->data = ft_strdup(str);
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

int		ft_addroad(char *src, char *dest, t_road **add)
{
	t_road *new;
	t_road *tmp;

	if (!(new = malloc(sizeof(t_road))))
		return (0);
	new->src = ft_strdup(src);
	new->dest = ft_strdup(dest);
	new->use = 0;
	new->line = ft_strjoin(src, "-");
	new->line = ft_strjoin(new->line, dest);
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
