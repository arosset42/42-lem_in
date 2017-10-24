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

int		ft_freeanderror(t_parse **tmp)
{
	ft_freepile(tmp);
	ft_putendl("ERROR");
	return (0);
}

int		ft_freepile(t_parse **pile)
{
	t_parse *cppile;

	cppile = (*pile);
	while (cppile)
	{
		cppile = (*pile)->next;
		if ((*pile)->str)
			free((*pile)->str);
		free(*pile);
		*pile = cppile;
	}
	return (1);
}

int		ft_freeroad(t_road **pile)
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
	return (0);
}

void	ft_freetab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	ft_freetree(t_llist *tree)
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
			ft_freetree(tmp2);
		}
		free(tree->node);
	}
	if (tree->next)
	{
		tmp = tree->next;
		ft_freetree(tmp);
	}
	if (tree)
		free(tree);
}
