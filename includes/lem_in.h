/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:16:36 by arosset           #+#    #+#             */
/*   Updated: 2017/10/08 16:16:38 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# define INT_MAX		0x7FFFFFFF
# define INT_MIN		(int)0x80000000

/*
** Structure et define list parsing
*/

typedef struct			s_list
{
	char				*data;
	struct s_list		*next;
}						t_list;

typedef struct 			s_env
{
	int					nb_ants;
	t_list				*room;
	t_list				*road;
	t_list				*init;
}						t_env;

int		ft_addend(char *str, t_list **add);
int 	ft_check_and_add(t_env *env, char **line);

/*
**
*/

t_env	*init_env(void);
void 	ft_error(void *list, void *env);


int				ft_comment(char *line);
int				ft_check(char **line);
int				ft_count_char(char *str, char c);
int				ft_check_int(char *str);

void 			malloc_error();

#endif
