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

int		addend_lem(t_lem *list, char *name)
{
	t_lem 	*new;
	t_lem 	*tmp;

	if (!(new = (t_lem *)malloc(sizeof(t_lem))))
		malloc_error();
	new->name = ft_strdup(name);
	new->next = NULL;
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

t_lem 	*init_list()
{
	t_lem	*list;

	if (!(list = (t_lem *)malloc(sizeof(t_lem))))
		malloc_error();
	list->name = NULL;
	list->param = NULL;
	list->next = NULL;
	return (list);
}

t_env 	init_env()
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		malloc_error();
	env->ant = 0;
	env->room = init_list();
	env->tunnel = init_list();
	return (*env);
}

void 	test(t_env *env)
{
	env->ant = 10;
	env->room->name = "Test";
	addend_lem(env->room, "Test2");
}

int main()
{
	t_env	env;

	env = init_env();
	test(&env);
	ft_printf("ant = %d, name = %s\n", env.ant, env.room->name);
	ft_printf("ant = %d, name = %s\n", env.ant, env.room->next->name);
    return (0);
}
