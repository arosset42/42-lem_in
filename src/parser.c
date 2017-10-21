/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:13:26 by arosset           #+#    #+#             */
/*   Updated: 2017/10/19 14:35:29 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_line_ant(t_env *env, char **line, int fd)
{
	int		val;
	int		ret;

	while ((ret = get_next_line(fd, line)) > 0)
	{
		ft_addend(*line, &env->init);
		if ((val = ft_comment(*line)) < 2)
			ft_error(env);
		else if (val == 3 && (env->nb_ants = ft_check_int(*line)) > 0)
		{
			if (get_next_line(fd, line) < 1)
				ft_error(env);
			return (1);
		}
		else if (env->nb_ants <= 0)
			ft_error(env);
		ft_strdel(line);
	}
	ft_error(env);
	return (-1);
}

int		ft_line_rooms(char **line)
{
	if (ft_count_char(*line, ' ') != 2 && ft_comment(*line) == 3)
		return (0);
	return (1);
}

void	ft_road(char **line, t_env *env, t_parse *tmp)
{
	int		len;
	char	*src;
	char	*dst;

	while (tmp)
	{
		len = ft_strlen(tmp->str);
		if (ft_strncmp(*line, tmp->str, len) == 0)
		{
			if (line[0][len] == '-')
			{
				src = ft_strsub(*line, 0, len);
				dst = ft_strsub(*line, len + 1, ft_strlen(*line) - (len + 1));
			}
			if (ft_check_name_road(env, src, dst, *line))
			{
				ft_strdel(&src);
				ft_strdel(&dst);
				break ;
			}
		}
		tmp = tmp->next;
	}
}

int		ft_line_road(char **line, t_env *env)
{
	int		val;
	t_parse	*tmp;

	tmp = env->room;
	if ((val = ft_comment(*line)) < 2)
		return (0);
	else if (val == 2)
		return (1);
	ft_road(line, env, tmp);
	return (1);
}

t_env	*ft_parse_file(void)
{
	t_env	*env;
	int		val;
	char	*line;

	env = init_env();
	val = 0;
	ft_line_ant(env, &line, 0);
	while (ft_line_rooms(&line))
	{
		val = ft_check(&line);
		if (ft_check_and_add(env, &line) == 1)
			break ;
		ft_addend(line, &env->init);
		ft_strdel(&line);
		(get_next_line(0, &line) < 1) ? ft_error(env) : 0;
	}
	(val == 0) ? ft_error(env) : 0;
	while (ft_line_road(&line, env))
	{
		ft_addend(line, &env->init);
		ft_strdel(&line);
		if (get_next_line(0, &line) < 1)
			break ;
	}
	return (env);
}
