/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:25:22 by arosset           #+#    #+#             */
/*   Updated: 2017/10/24 15:51:01 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_searchlevel(t_road *road, char *str)
{
	while (road)
	{
		if (!ft_strcmp(str, road->str))
			return (road->level);
		road = road->next;
	}
	return (2147483647);
}

static int	ft_longnb(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] == '0' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	if (j > 10)
		return (0);
	return (1);
}

int			ft_nbant(char *str)
{
	int ant;
	int i;

	ant = 0;
	i = 0;
	if (!str || !ft_longnb(str))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			i = 0;
			break ;
		}
		i++;
	}
	if (i > 0)
	{
		ant = ft_atoi(str);
		if (ant > 2147483647 || ant <= 0)
			return (0);
		return (1);
	}
	else
		return (0);
}
