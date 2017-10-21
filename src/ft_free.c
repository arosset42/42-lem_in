/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:28:00 by arosset           #+#    #+#             */
/*   Updated: 2017/10/21 16:11:49 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_freeroad(t_road **pile)
{
	t_road *cppile;

	cppile = (*pile);
	while (cppile)
	{
		cppile = (*pile)->next;
		if ((*pile)->str)
			free((*pile)->str);
		free(*pile);
		*pile = cppile;
	}
}

void	ft_free_env(t_env *env)
{
	if (env)
	{
		if (env->room)
			ft_free_list(&env->room);
		if (env->road)
			ft_free_list(&env->road);
		if (env->file)
			ft_free_list(&env->file);
		if (env->init)
			ft_free_list(&env->init);
		if (env->start)
			ft_strdel(&env->start);
		if (env->end)
			ft_strdel(&env->end);
		if (env->graph)
			ft_free_graph(env->graph);
		free(env);
	}
}

void	ft_free_graph(t_llist *tree)
{
	t_llist	*tmp;
	t_llist *tmp2;
	t_tree	*father;

	tmp = tree;
	if (tree->node)
	{
		father = tree->node;
		free(father->str);
		if (father->child)
		{
			tmp2 = father->child;
			ft_free_graph(tmp2);
		}
		free(tree->node);
	}
	if (tree->next)
	{
		tmp = tree->next;
		ft_free_graph(tmp);
	}
	if (tree)
		free(tree);
}

void	ft_free_list(t_parse **list)
{
	t_parse *tmp;

	tmp = (*list);
	while (tmp)
	{
		tmp = (*list)->next;
		if ((*list)->str)
			free((*list)->str);
		free(*list);
		*list = tmp;
	}
}

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
