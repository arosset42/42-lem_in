/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:05:46 by arosset           #+#    #+#             */
/*   Updated: 2017/09/11 15:05:48 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void 	ft_print_env(t_env env)
{
	ft_printf("=======TEST======\n nb_ant = %d\n",env.nb_ants);
	ft_printf("====LIST INIT====\n");
	while (env.init)
	{
		ft_printf("%s\n", env.init->data);
		env.init = env.init->next;
	}
	ft_printf("==== LIST ROOM ====\n");
	while (env.room)
	{
		ft_printf("%s\n", env.room->data);
		env.room = env.room->next;
	}
	ft_printf("==== LIST ROAD ====\n");
	while (env.road)
	{
		ft_printf("src = %s dest = %s\n", env.road->src, env.road->dest);
		env.road = env.road->next;
	}
	ft_printf("start = %s, end = %s\n", env.start, env.end);
}

int 	main()
{
	t_env		*env;


	env = ft_parse_file();
	if (!ft_search_room(env, "##start") || !ft_search_room(env, "##end"))
		ft_error(env);
	// ft_print_env(*env);
	ft_printf("\nPARSER OK\n");
	ft_free_env(env);
	// while (1);
    return (0);
}
