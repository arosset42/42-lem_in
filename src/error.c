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

void 	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

void 	ft_error(void *list, void *env)
{
	ft_printf("Error\n");
	exit(1);
}

void 	malloc_error()
{
	exit(1);
}
