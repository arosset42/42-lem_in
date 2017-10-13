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

typedef struct 			s_listelem
{
	void 				*data;
	struct s_listelem	*next;
}						t_listelem;

typedef	struct			s_llem
{
	int					size;
	struct	s_listelem	*head;
	struct	s_listelem	*tail;
}						t_llem;

# define LIST_SIZE(list)				((list)->size)
# define LIST_HEAD(list)				((list)->head)
# define LIST_TAIL(list)				((list)->tail)
# define LIST_DATA(elem)				((elem)->data)
# define LIST_NEXT(elem)				((elem)->next)

typedef	struct		s_lem
{
	char			*name;
	char			*param;

	struct s_lem	*next;
}					t_lem;

typedef	struct		s_env
{
	int				ant;

	struct s_lem	*room;
	struct s_lem	*tunnel;
}					t_env;

void 	ft_list_init(t_llem *list);
int		ft_list_ins_next(t_llem *list, t_listelem *elem, void *data);

int		ft_parse_file(t_llem *list);

int				ft_comment(char *line);
int				ft_check(t_llem *list, char **line);
int				ft_count_char(char *str, char c);
int		ft_check_int(char *str);

void 	malloc_error();
void	ft_error(void *graph, void *list);

#endif
