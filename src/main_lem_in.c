/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:05:46 by arosset           #+#    #+#             */
/*   Updated: 2017/10/21 16:14:55 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		ft_create(t_env *stok, t_parse *lem, int ant)
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

int		main(void)
{
	t_parse *lem;
	t_env 	*stok;
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
