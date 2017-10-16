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

int		ft_line_ant(t_env *env, char **line, int fd)
{
	int		val;
	int		ret;

	while ((ret = get_next_line(fd, line)) > 0)
	{
		ft_addend(*line, &env->init);
		if ((val = ft_comment(*line)) < 2)
			ft_error(NULL, NULL);
		else if (val == 3 && (env->nb_ants = ft_check_int(*line)) > 0)
		{
			if (get_next_line(fd, line) < 1)
				ft_error(NULL, NULL);
			return (1);
		}
		else if (env->nb_ants <= 0)
			ft_error(NULL, NULL);
	}
	ft_error(NULL, NULL);
	return (-1);
}

int		ft_line_rooms(char **line)
{
	if (ft_count_char(*line, ' ') != 2 && ft_comment(*line) == 3)
		return (0);
	return (1);
}

int		ft_line_tunnels(char **line)
{
	int		val;

	if ((val = ft_comment(*line)) < 2)
		return (0);
	else if (val == 2)
		return (1);
	else
		return (1);
	return (0);
}

t_env 	*ft_parse(void)
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
		(get_next_line(0, &line) < 1) ? ft_error(NULL, NULL) : 0;
	}
	(val == 0) ? ft_error(NULL, NULL) : 0;
	while (ft_line_tunnels(&line))
	{
		ft_addend(line, &env->init);
		if (get_next_line(0, &line) < 1)
			break ;
	}
	return (env);
}

int 	main()
{
	t_env		*env;

	env = ft_parse();
	ft_printf("nb_ant = %d\n",env->nb_ants);
	while (env->init)
	{
		ft_printf("%s\n", env->init->data);
		env->init = env->init->next;
	}
	while (env->room)
	{
		ft_printf("%s\n", env->room->data);
		env->room = env->room->next;
	}
    return (0);
}

// int		ft_addend(char *str, t_parse **add)
