/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:46:34 by arosset           #+#    #+#             */
/*   Updated: 2017/10/19 14:34:41 by arosset          ###   ########.fr       */
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

char	*ft_firstword(char *str, char c)
{
	char	*start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	j = i;
	while (str[i] != c && str[i] != '\0')
		i++;
	start = malloc(sizeof(char) * (i - j) + 1);
	i = 0;
	while (str[j] != c && str[i] != '\0')
	{
		start[i] = str[j];
		i++;
		j++;
	}
	start[j] = '\0';
	return (start);
}

char	*ft_lastword(char *str, char c)
{
	char	*last;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
		i++;
	j = i;
	while (str[i] != c && i > 0)
		i--;
	last = malloc(sizeof(char) * (j - i) + 1);
	i++;
	j = 0;
	while (str[i] != '\0')
	{
		last[j] = str[i];
		i++;
		j++;
	}
	last[j] = '\0';
	return (last);
}
