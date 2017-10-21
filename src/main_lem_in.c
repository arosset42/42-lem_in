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

int		main(void)
{
	t_env		*env;
	t_road		*road;
	t_parse		*ok;

	road = NULL;
	env = ft_parse_file();
	if (!ft_search_room(env, "##start") || !ft_search_room(env, "##end"))
		ft_error(env);
	env->graph = ft_createlist(env->start, NULL, env);
	ft_checklevel(env->graph, env->end, 0, &road);
	if ((ok = ft_searchlittleroad(env, road)))
	{
		ft_displaylist(*env);
		ft_displayant(ok, env->nb_ants, env->end);
		ft_free_list(&ok);
		ft_freeroad(&road);
		ft_free_env(env);
	}
	else
	{
		ft_freeroad(&road);
		ft_error(env);
	}
	// while (1);
	return (0);
}
