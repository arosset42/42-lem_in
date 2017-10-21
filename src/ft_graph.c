/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 14:06:13 by arosset           #+#    #+#             */
/*   Updated: 2017/10/21 16:12:38 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*ft_searchbrother(char *str, char *father, t_env *stok)
{
	char	*one;
	char	*seconde;
	t_parse *tmp;

	seconde = NULL;
	tmp = stok->road;
	while (stok->road)
	{
		one = ft_firstroominroad(stok->road->str);
		seconde = ft_searchroominroad(stok->road->str);
		if ((!ft_strcmp(one, father) && !ft_strcmp(seconde, str)) ||
				(!ft_strcmp(one, str) && !ft_strcmp(seconde, father)))
		{
			free(one);
			free(seconde);
			stok->road = stok->road->next;
			break ;
		}
		free(one);
		free(seconde);
		stok->road = stok->road->next;
	}
	seconde = ft_searchchild(father, stok);
	stok->road = tmp;
	return (seconde);
}

char	*ft_returnchild(char *one, char *str, t_env *stok, int i)
{
	char *seconde;

	seconde = NULL;
	free(one);
	if (i == 0)
		seconde = ft_searchroominroad(str);
	else
		seconde = ft_firstroominroad(str);
	if (ft_searchinlist(str, stok->file) &&
			ft_searchinroom(stok->room, seconde))
	{
		ft_addend(str, &stok->file);
		return (seconde);
	}
	free(seconde);
	return (NULL);
}

char	*ft_searchchild(char *str, t_env *stok)
{
	char	*one;
	t_parse	*tmp;

	tmp = stok->road;
	while (tmp)
	{
		one = ft_firstroominroad(tmp->str);
		if (!ft_strcmp(one, str))
		{
			if ((one = ft_returnchild(one, tmp->str, stok, 0)))
				return (one);
		}
		else
			free(one);
		one = ft_searchroominroad(tmp->str);
		if (!ft_strcmp(one, str))
		{
			if ((one = ft_returnchild(one, tmp->str, stok, 1)))
				return (one);
		}
		else
			free(one);
		tmp = tmp->next;
	}
	return (NULL);
}

t_tree	*ft_createtree(char *str, t_env *stok)
{
	t_tree	*tree;
	char	*name;
	char	*tmp;

	if (!(tree = malloc(sizeof(t_tree))))
		return (NULL);
	name = ft_strdup(str);
	tree->str = name;
	ft_addend(name, &stok->file);
	tree->level = 2147483647;
	tmp = ft_searchchild(name, stok);
	if (!ft_strcmp(name, stok->end))
		tree->child = NULL;
	else if (tmp)
	{
		tree->child = ft_createlist(tmp, name, stok);
		free(tmp);
	}
	else
		tree->child = NULL;
	return (tree);
}

t_llist	*ft_createlist(char *str, char *father, t_env *stok)
{
	t_llist		*tree;
	char		*tmp;

	if (!(tree = malloc(sizeof(t_llist))))
		return (NULL);
	if (!father)
	{
		tree->node = ft_createtree(str, stok);
		tree->next = NULL;
		return (tree);
	}
	tree->next = NULL;
	tree->node = ft_createtree(str, stok);
	while ((tmp = ft_searchbrother(str, father, stok)))
	{
		tree->next = ft_createlist(tmp, father, stok);
		free(tmp);
	}
	if (tmp)
		free(tmp);
	return (tree);
}
