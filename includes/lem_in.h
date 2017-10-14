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

typedef struct	s_listelem
{
	void				*data;
	struct s_listelem	*next;
}				t_listelem;

typedef struct	s_list
{
	int					size;
	void				(*ft_destroy)(void *data);
	struct s_listelem	*head;
	struct s_listelem	*tail;
}				t_list;

typedef struct 		s_env
{
	int				nb_ants;
	struct s_list	*init;
	struct s_list	**rooms;
	struct s_list	**tunnel;
}					t_env;

void		ft_list_init(t_list *list, void (*ft_destroy)(void *data));
void			ft_list_destroy(t_list *list);
int				ft_list_ins_next(t_list *list, t_listelem *elem, void *data);
int			ft_list_rem_next(t_list *list, t_listelem *elem, void **data);

/*
**
*/

int		ft_parse_file(t_env *env);

int				ft_comment(char *line);
int				ft_check(t_list *list, char **line);
int				ft_count_char(char *str, char c);
int		ft_check_int(char *str);

void 	malloc_error();
void	ft_error(void *graph, void *list);

#endif
