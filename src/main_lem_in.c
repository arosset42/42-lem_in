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

int		ft_line_ant(t_llem *list, cahr **line, int fd, int *nb_ants)
{
	int		val;

	while (get_next_line(fd, line) > 0)
	{
		ft_list_ins_next(list, LIST_TAIL(list), *line);
	}
}

int		ft_parse_file(t_llem *list)
{
	char	*line;
	int		nb_ants;

	ft_list_init(list);
	ft_line_ant(list, &line, 0, &nb_ants);
}

int main()
{
	t_llem		list;
	int			nb_ants;

	nb_ants = ft_parse_file(&list);
    return (0);
}
