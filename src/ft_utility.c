/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:46:34 by arosset           #+#    #+#             */
/*   Updated: 2017/09/11 15:46:36 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_nbr(char c, int total, int sign)
{
	int		tmp;

	tmp = total * 10;
	if (sign == 1 && c - '0' > INT_MAX - tmp)
		ft_error(NULL);
	if (sign == -1 && -(c - '0') < INT_MIN + tmp)
		ft_error(NULL);
	return (0);
}

int		ft_check_int(char *str)
{
	size_t		i;
	int			neg;
	int			total;

	total = 0;
	neg = 1;
	i = 0;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		check_nbr(str[i], total, neg);
		total = total * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != 0)
		ft_error(NULL);
	return (total * neg);
}

int				ft_comment(char *line)
{
	if (ft_strcmp(line, "##end") == 0)
		return (0);
	else if (ft_strcmp(line, "##start") == 0)
		return (1);
	else if (ft_strlen(line) > 2 && line[0] == '#' && line[1] != '#')
		return (2);
	else if (line[0] == '#')
		return (2);
	else
		return (3);
}

int				ft_count_char(char *str, char c)
{
	int		nbr;
	int		index;

	nbr = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			nbr++;
		if (str[0] == c)
			return (-1);
		index++;
	}
	return (nbr);
}

int				ft_check(char **line)
{
	static int		nbs = 0;
	static int		nbe = 0;
	static int		value = 0;

	if (ft_strcmp(*line, "##start") == 0)
	{
		(value == 1) ? ft_error(NULL) : 1;
		nbs++;
		value = 1;
	}
	else if (ft_strcmp(*line, "##end") == 0)
	{
		(value == 1) ? ft_error(NULL) : 1;
		nbe++;
		value = 1;
	}
	else if (ft_comment(*line) == 3
			&& ft_count_char(*line, ' ') == 2)
		value = 0;
	if (nbs > 1 || nbe > 1)
		ft_error(NULL);
	if (value == 1 || nbs == 0 || nbe == 0)
		return (0);
	return (1);
}
