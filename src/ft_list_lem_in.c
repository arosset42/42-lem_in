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

// void		ft_list_init(t_list *list)
// {
// 	list->head = NULL;
// 	list->tail = NULL;
// 	list->size = 0;
// }
//
// int			ft_list_ins_next(t_list *list, t_listelem *elem, void *data)
// {
// 	t_listelem *new_element;
//
// 	new_element = (t_listelem*)malloc(sizeof(t_listelem));
// 	if (new_element == NULL)
// 		return (-1);
// 	new_element->data = (void *)data;
// 	if (elem == NULL)
// 	{
// 		if (list->size == 0)
// 			list->tail = new_element;
// 		new_element->next = list->head;
// 		list->head = new_element;
// 	}
// 	else
// 	{
// 		if (elem->next == NULL)
// 			list->tail = new_element;
// 		new_element->next = elem->next;
// 		elem->next = new_element;
// 	}
// 	list->size++;
// 	return (0);
// }
//
//
// int			ft_list_rem_next(t_list *list, t_listelem *elem, void **data)
// {
// 	t_listelem		*tmp;
//
// 	if (list->size == 0)
// 		return (-1);
// 	if (elem == NULL)
// 	{
// 		tmp = list->head;
// 		*data = tmp->data;
// 		list->head = tmp->next;
// 		if (list->size == 1)
// 			list->tail = NULL;
// 	}
// 	else
// 	{
// 		tmp = elem->next;
// 		*data = tmp->data;
// 		elem->next = tmp->next;
// 		if (elem->next == NULL)
// 			list->tail = elem;
// 	}
// 	free(tmp);
// 	(list->size)--;
// 	return (0);
// }

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
