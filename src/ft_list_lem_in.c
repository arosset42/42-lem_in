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
