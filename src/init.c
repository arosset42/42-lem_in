/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:14:38 by arosset           #+#    #+#             */
/*   Updated: 2017/10/16 10:14:39 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int 	ft_check_and_add(t_env *env, char **line)
{
	char	**data;
	int		i;

	i = 0;
	if (ft_comment(*line) == 3)
	{
		data = ft_strsplit(*line, ' ');
		if (data[0][0] == 'L')
			ft_error(NULL, NULL);
		while (data[i] != NULL)
			i++;
		if (i != 3)
		{
			//insert fonction free tableau
			return (1);
		}
		ft_check_int(data[1]);
		ft_check_int(data[2]);
		ft_addend(data[0], &env->room);
		//insert free data
	}
	return (0);
}

t_env	*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		malloc_error();
	env->nb_ants = 0;
	env->room = NULL;
	env->road = NULL;
	env->init = NULL;
	return (env);
}
