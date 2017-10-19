/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 14:06:13 by arosset           #+#    #+#             */
/*   Updated: 2017/10/19 14:32:57 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*ft_search_brother(char *str, char *father, t_env *env)
{
	char	*s;
	t_road	*tmp;

	tmp = env->road;
	while (env->road)
	{
		if ((!ft_strcmp(env->road->src, father) &&
				!ft_strcmp(env->road->dest, str)) ||
				(!ft_strcmp(env->road->src, father) &&
				!ft_strcmp(env->road->dest, str)))
		{
			env->road = env->road->next;
			break ;
		}
		env->road = env->road->next;
	}
	s = ft_search_child(father, env);
	env->road = tmp;
	return (s);
}

char	*ft_return_child(t_road *road, t_env *env, int i)
{
	char	*seconde;
	char	*str;

	seconde = NULL;
	if (i == 0)
		seconde = road->dest;
	else
		seconde = road->src;
	str = ft_strjoin(road->src, "-");
	str = ft_strjoin(str, road->dest);
	if (ft_search_in_list(str, env->file) && ft_search_in_list(str, env->room))
	{
		ft_addend(str, &env->file);
		return (seconde);
	}
	free (seconde);
	return (NULL);
}

char	*ft_search_child(char *str, t_env *env)
{
	t_road	*tmp;
	char	*one;

	tmp = env->road;
	ft_printf("child3\n");
	while (tmp)
	{
		ft_printf("child6\n");
		one = tmp->src;
		if (!ft_strcmp(one, str))
		{
			if (ft_return_child(tmp, env, 0))
				return (one);
		}
		else
			free(one);
		one = tmp->dest;
		ft_printf("child5\n");
		if (!ft_strcmp(one, str))
		{
			if (ft_return_child(tmp, env, 1))
				return (one);
		}
		else
			free(one);
		tmp = tmp->next;
	}
	return (NULL);
}

t_tree	*ft_create_tree(char *str, t_env *env)
{
	t_tree		*tree;
	char		*name;
	char		*tmp;

	ft_printf("tree\n");
	if (!(tree = malloc(sizeof(t_tree))))
		ft_error(env);
	name = ft_strdup(str);
	tree->data = name;
	ft_addend(name, &env->file);
	tree->lvl = -1;
	ft_printf("child%s\n", name);
	tmp = ft_search_child(name, env);
	ft_printf("child 2\n");
	if (ft_strcmp(name, env->end) == 0)
		tree->child = NULL;
	else if (tmp)
	{
		tree->child = ft_create_graph(tmp, name, env);
		free(tmp);
	}
	else
		tree->child = NULL;
	return (tree);
}

t_graph		*ft_create_graph(char *str, char *father, t_env *env)
{
	t_graph		*graph;
	char		*tmp;

	// printf("str = %s, father = %s\n", str, father);
	if (!(graph = malloc(sizeof(t_graph))))
		ft_error(env);
	if (!father)
	{
		ft_printf("FIRST\n");
		graph->node = ft_create_tree(str, env);
		graph->next = NULL;
		return (graph);
	}
	graph->next = NULL;
	graph->node = ft_create_tree(str, env);
	while ((tmp = ft_search_brother(str, father, env)))
	{

		graph->next = ft_create_graph(tmp, father, env);
		free(tmp);
	}
	if (tmp)
		free(tmp);
	return (graph);
}

void	ft_start_graph(t_env *env)
{
	ft_printf("start graph\n");
	ft_create_graph(env->start, NULL, env);
	ft_printf("end graph\n");
	ft_print_graph(env->graph);
}
