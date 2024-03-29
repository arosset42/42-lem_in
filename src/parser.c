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

static void		ft_road(t_stock *stock, t_parse *tmp)
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

static t_stock	*ft_try(t_parse *lem)
{
	t_stock *stock;
	t_parse *tmp;
	char	*t;

	lem = lem->next;
	tmp = lem;
	stock = ft_initstock();
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

static int		ft_create(t_stock *stok, t_parse *lem, int ant)
{
	char	*str;
	t_road	*road;
	t_llist	*tree;
	t_parse	*ok;

	str = NULL;
	road = NULL;
	if ((!(ft_cmpinroom(stok->room)) || !(str = ft_startandend(stok->room, 0))
	|| (!(stok->end = ft_startandend(stok->room, 1)))) &&
	ft_totalleaks(&lem, stok, &road, NULL))
		return (ft_putendlreturn("ERROR"));
	tree = ft_createlist(str, NULL, stok);
	stok->start = str;
	if (ft_searchinlist(stok->end, stok->file) &&
	ft_totalleaks(&lem, stok, &road, tree))
		return (ft_putendlreturn("ERROR"));
	ft_freepile(&stok->file);
	ft_checklevel(tree, stok->end, 0, &road);
	if ((ok = ft_searchlittleroad(stok, road)) && ft_displaylist(lem) &&
	ft_displayant(ok, ant, stok->end) && ft_freepile(&ok))
		ft_totalleaks(&lem, stok, &road, tree);
	else if (ft_totalleaks(&lem, stok, &road, tree))
		return (ft_putendlreturn("ERROR"));
	return (1);
}

int				ft_parse(void)
{
	t_parse *lem;
	t_stock *stok;
	char	*str;
	int		ret;

	ret = 1;
	str = NULL;
	lem = NULL;
	while ((ret = get_next_line(0, &str)))
	{
		if (ret < 0 || str[0] == '\0')
			break ;
		ft_addend(str, &lem);
		ft_strdel(&str);
	}
	if (!lem || !lem->next || ret < 0)
		return (ft_putendlreturn("ERROR"));
	if (!ft_nbant(lem->str))
		return (ft_freeanderror(&lem));
	stok = ft_try(lem);
	if (!stok->road && ft_freepile(&lem) && ft_freestock(stok))
		return (ft_putendlreturn("ERROR"));
	if (!ft_errorinroom(stok->room2) && ft_freestock(stok))
		return (ft_freeanderror(&lem));
	return (ft_create(stok, lem, ft_atoi(lem->str)));
}
