/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:13:26 by arosset           #+#    #+#             */
/*   Updated: 2017/10/19 14:35:29 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_road(t_env *stock, t_parse *tmp)
{
	while (tmp)
	{
		if (ft_strchr(tmp->str, '-') && !ft_strchr(tmp->str, ' ') &&
				tmp->str[0] != '#')
		{
			if (ft_roominroad(tmp->str, stock->room) &&
					ft_formatroad(tmp->str))
				ft_addend(tmp->str, &stock->road);
			else
				break ;
		}
		tmp = tmp->next;
	}
}

t_env	*ft_parse_file(t_parse *lem)
{
	t_env 	*stock;
	t_parse *tmp;
	char	*t;

	lem = lem->next;
	tmp = lem;
	stock = init_env();
	if (!lem)
		return (0);
	while (lem && !ft_strchr(lem->str, '-'))
	{
		if (lem->str[0] == '#' && lem->str[1] != '#')
			ft_addend(lem->str, &stock->com);
		else if ((ft_strchr(lem->str, ' ') || (lem->str[0] == '#' &&
		lem->str[1] == '#')) && !ft_strchr(lem->str, '-'))
		{
			t = ft_firstword(lem->str, ' ');
			ft_addend(t, &stock->room);
			ft_addend(lem->str, &stock->room2);
			free(t);
		}
		lem = lem->next;
	}
	ft_road(stock, lem);
	return (stock);
}
