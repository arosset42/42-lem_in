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

void 	malloc_error(void)
{
	exit(1);
}

t_lem	*init_list_lem(void)
{
	t_lem	*new;

	if (!(new = (t_lem *)malloc(sizeof(t_lem))))
		malloc_error();
	new->name = NULL;
	new->param = NULL;
	new->next = NULL;
	return (new);
}

void 	init_env(t_env *s_env)
{
	s_env->ant = 0;
	s_env->room = init_list_lem();
	s_env->tunnel = init_list_lem();
}

int main()
{
	t_env	*s_env;

	if (!(s_env = (t_env *)malloc(sizeof(t_env))))
		malloc_error();
	init_env(&s_env);
	ft_printf("%d\n", s_env->ant);


    return (0);
}
