/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <arosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:32:43 by arosset           #+#    #+#             */
/*   Updated: 2017/05/23 15:26:21 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char		*ft_read(int const fd, char *str, char *buf)
{
	int		len;
	int		ret;
	char	*tmp;

	len = ft_strlen(buf) + ft_strlen(str);
	if (ft_strchr(buf, '\n') == NULL)
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (ret == -1)
				return (NULL);
			buf[ret] = '\0';
			tmp = ft_strjoin(str, buf);
			free(str);
			str = tmp;
			if (ft_strchr(str, '\n') != NULL)
				break ;
		}
	return (str);
}

static int		ft_return(char **line, char **str, int ret)
{
	if (ret == -1)
		*line = NULL;
	else if (ret == 0)
	{
		*line = NULL;
		free(*str);
	}
	else
		free(*str);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char		buf[BUFF_SIZE + 1] = {0};
	char			*str;

	if (line == NULL || fd < 0)
		return (-1);
	str = ft_strdup(buf);
	if (!(str = ft_read(fd, str, buf)))
		return (ft_return(line, &str, -1));
	if (ft_strlen(str) > 0 && ft_strchr(buf, '\n') == NULL)
	{
		*line = ft_strsub(str, 0, ft_strlen(str));
		ft_memset(buf, '\0', BUFF_SIZE + 1);
		return (ft_return(line, &str, 1));
	}
	else if (ft_strchr(buf, '\n') == NULL)
		return (ft_return(line, &str, 0));
	else
	{
		*line = ft_strsub(str, 0, ft_strchr(str, '\n') - str);
		ft_strcpy(buf, &buf[ft_strchr(buf, '\n') - buf + 1]);
	}
	return (ft_return(line, &str, 1));
}
