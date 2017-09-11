/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:13:26 by arosset           #+#    #+#             */
/*   Updated: 2017/09/11 15:13:28 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void 	tri(char *line, t_spec *lem_param)
{
	char 	**tab;
	int 	ret;
	int		i;

	i = 0;
	ft_printf("=== Phase %d ===\n", lem_param->start);
	if (lem_param->start == 1)
	{
		if (ft_isnumber(line))
			lem_param->ant = ft_atoi(line);
		else
			ft_printf("Inserer error (parser)\n");
		lem_param->start = 2;
		ft_printf("verif ant ->%d<-\n", lem_param->ant);
		return;
	}
	tab = ft_strsplit(line, '\n');
	if (lem_param->start == 2)
	{
		ret = ft_count_tab(tab);
		if (ret == 3)
		{
			ft_printf("Ok phase 2 name : %s", tab[0]);
		}

	}
}

void	ft_parser(t_spec *lem_param)
{
	char 	*line;
	int		ret;

	ret = 1;
	while (ret == get_next_line(0, &line) > 0)
	{
		tri(line, lem_param);
	}

}
