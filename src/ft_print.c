/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:42:06 by arosset           #+#    #+#             */
/*   Updated: 2017/10/19 14:42:07 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void 	ft_print_graph(t_graph *graph)
{
	ft_printf("Start Print\n");
	while (graph)
	{
		ft_printf("%s ", graph->node->data);
		graph = graph->next;
	}
}
