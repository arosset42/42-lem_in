/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:13:26 by arosset           #+#    #+#             */
/*   Updated: 2017/09/11 15:13:28 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	Parser Premiere ligne
**	Erreur : commentaire modifiant la prochaine ligne
**		     lecture GNL incorrect
**			 presence de signe autre que des chiffres
*/

int		ft_line_ant(t_list *list, char **line, int fd, int *nb_ants)
{
	int		val;

	while (get_next_line(fd, line) > 0)
	{
		ft_list_ins_next(list, list->tail, *line);
		if ((val = ft_comment(*line)) < 2)
			ft_error(NULL, list);
		else if (val == 3 && (*nb_ants = ft_check_int(*line)) > 0)
		{
			if (get_next_line(fd, line) < 1)
				ft_error(NULL, list);
			return (1);
		}
		else if (nb_ants <= 0)
			ft_error(NULL, list);
	}
	ft_error(NULL, list);
	return (-1);
}

/*
**	Verification de la ligne salle en cour
** 	Si plus de 2 ' ' et que ce n'est pas un commentaire rejet
*/

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

int		ft_parse_file(t_env *env)
{
	char	*line;
	int		nb_ants;
	int		val;

	val = 0;
	ft_list_init(env->init, free);
	ft_line_ant(env->init, &line, 0, &nb_ants);
	while (ft_line_rooms(&line))
	{
		val = ft_check(env->init, &line);
		ft_list_ins_next(env->init, env->init->tail, line);
		(get_next_line(0, &line) < 1) ? ft_error(NULL, env->init) : 0;
	}
	(val == 0) ? ft_error(NULL, env->init) : 0;
	while (ft_line_tunnels(&line))
	{
		ft_list_ins_next(env->init, env->init->tail, line);
		if (get_next_line(0, &line) < 1)
			break ;
	}
	return (nb_ants);
}
