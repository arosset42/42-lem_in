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

void 	ft_list_init(t_llem *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

int		ft_list_ins_next(t_llem *list, t_listelem *elem, void *data)
{
	t_listelem	*new;

	if (!(new = (t_listelem*)malloc(sizeof(t_listelem))))
		return (-1);
	if (elem == NULL)
	{
		if (LIST_SIZE(list) == 0)
			list->tail = new;
		new->next = list->head;
		list->head = new;
	}
	else
	{
		if (elem->next == NULL)
			list->tail = new;
		new->next = elem->next
		elem->next = new;
	}
	list->size++;
	return (0);
}
