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

// void 	ft_list_parser_add(t_spec *lem_in, char *name, char *param)
// {
// 	t_lem	*new;
//
// 	if (lem_in != NULL)
// 	{
// 		if (!(new = (t_lem *)malloc(sizeof(t_lem))))
// 			ft_malloc_error();
// 		new->name = malloc(ft_strlen(name));
// 		new->param = malloc(ft_strlen(param));
// 		ft_memcpy(new->name, name, ft_strlen(name));
// 		ft_memcpy(new->param, param, ft_strlen(param));
// 		new->use = 0;
// 		new->next = NULL;
// 		if (lem_in->room == NULL)
// 			lem_in->room = new;
// 		else
// 			lem_in->room->next = new;
// 	}
// 	return (lem_in);
// }

t_spec 		*ft_init_struct_parser(void)
{
	t_spec		*new;

	if (!(new = (t_spec *)malloc(sizeof(t_spec))))
		return (NULL);
	new->ant = 0;
	new->start = 1;
	new->room = NULL;
	new->tunnel = NULL;
	return (new);
}
