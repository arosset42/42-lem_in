/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:05:40 by arosset           #+#    #+#             */
/*   Updated: 2017/09/11 15:05:42 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_error(void *graph, void *list)
{
	ft_putstr_fd("ERROR\n", 2);
	// if (graph != NULL)
	// 	ft_graph_destroy(graph);
	// if (list != NULL)
	// 	ft_list_destroy(list);
	exit(1);
}

void 	malloc_error()
{
	exit(1);
}
