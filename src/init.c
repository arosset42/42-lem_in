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

t_env	*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		malloc_error();
	env->nb_ants = 0;
	env->room = NULL;
	env->road = NULL;
	env->init = NULL;
	env->start = NULL;
	env->end = NULL;
	return (env);
}
