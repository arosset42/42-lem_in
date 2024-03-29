/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:09:11 by arosset           #+#    #+#             */
/*   Updated: 2017/10/24 15:50:09 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				ft_checklevel(t_llist *tree, char *str, int i, t_road **road)
{
	tree->node->level = i;
	ft_addroad(tree->node->str, i, road);
	if (tree->next)
		ft_checklevel(tree->next, str, i, road);
	if (tree->node->child)
		ft_checklevel(tree->node->child, str, i + 1, road);
	return (1);
}

static char		*thebestroom(t_parse *lst, t_road *road)
{
	char *tmp;

	if (!lst)
		return (NULL);
	if (!(lst->next))
		return (ft_strdup(lst->str));
	tmp = ft_strdup(lst->str);
	lst = lst->next;
	while (lst)
	{
		if (ft_searchlevel(road, tmp) > ft_searchlevel(road, lst->str))
		{
			free(tmp);
			tmp = ft_strdup(lst->str);
		}
		lst = lst->next;
	}
	return (tmp);
}

static	void	ft_cuproom(char *str, t_parse **lst, int i)
{
	char *t;

	if (i == 0)
	{
		t = ft_searchroominroad(str);
		ft_addend(t, lst);
		free(t);
	}
	if (i == 1)
	{
		t = ft_firstroominroad(str);
		ft_addend(t, lst);
		free(t);
	}
}

static t_parse	*therooms(t_stock *stok, char *str)
{
	t_parse	*tmp;
	t_parse	*lst;
	char	*one;

	one = NULL;
	tmp = stok->road;
	lst = NULL;
	while (tmp)
	{
		one = ft_firstroominroad(tmp->str);
		if (!ft_strcmp(one, str))
			ft_cuproom(tmp->str, &lst, 0);
		if (one)
			free(one);
		one = ft_searchroominroad(tmp->str);
		if (!ft_strcmp(one, str))
			ft_cuproom(tmp->str, &lst, 1);
		if (one)
			free(one);
		tmp = tmp->next;
	}
	return (lst);
}

t_parse			*ft_searchlittleroad(t_stock *stok, t_road *road)
{
	t_parse *tmp;
	t_parse *ret;
	char	*little;

	ret = NULL;
	stok->file = NULL;
	little = ft_strdup(stok->end);
	while (ft_strcmp(little, stok->start))
	{
		tmp = therooms(stok, little);
		free(little);
		if (!(little = thebestroom(tmp, road)))
			break ;
		ft_add(little, &ret);
		if (tmp)
			ft_freepile(&tmp);
	}
	if (little)
		free(little);
	if (ret)
		ft_addend(stok->end, &ret);
	else
		return (NULL);
	return (ret);
}
