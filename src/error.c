/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:05:40 by arosset           #+#    #+#             */
/*   Updated: 2017/10/19 14:29:29 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_freestock(t_stock *stok)
{
	if (stok)
	{
		if (stok->room)
			ft_freepile(&stok->room);
		if (stok->room2)
			ft_freepile(&stok->room2);
		if (stok->road)
			ft_freepile(&stok->road);
		if (stok->file)
			ft_freepile(&stok->file);
		if (stok->com)
			ft_freepile(&stok->com);
		if (stok->end)
			free(stok->end);
		if (stok->start)
			free(stok->start);
		ft_displaylist(stok->room2);
		free(stok);
	}
	return (1);
}

int	ft_putendlreturn(char const *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}

int	ft_totalleaks(t_parse **lem, t_stock *stok, t_road **road,
		t_llist *tree)
{
	if (stok)
		ft_freestock(stok);
	if (lem)
		ft_freepile(lem);
	if (road)
		ft_freeroad(road);
	if (tree)
		ft_freetree(tree);
	return (1);
}
