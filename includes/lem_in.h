/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:16:36 by arosset           #+#    #+#             */
/*   Updated: 2017/10/21 16:16:48 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# define INT_MAX	0x7FFFFFFF
# define INT_MIN	(int)0x80000000

/*
** Structure graph
*/

typedef struct		s_tree
{
	char			*str;
	int				level;
	struct s_llist	*child;
}					t_tree;

typedef struct		s_llist
{
	t_tree			*node;
	struct s_llist	*next;
}					t_llist;

/*
** Structure list parsing
*/

typedef struct		s_road
{
	char			*str;
	int				level;
	struct s_road	*next;
}					t_road;

typedef struct		s_parse
{
	char			*str;
	struct s_parse	*next;
}					t_parse;

/*
** Structure environement
*/

typedef struct		s_env
{
	int				nb_ants;
	t_parse			*room;
	t_parse			*road;
	t_parse			*file;
	t_parse			*init;
	t_llist			*graph;
	char			*start;
	char			*end;
}					t_env;

/*
**					Initialisation and Print
*/

int					ft_displayant(t_parse *ok, int nb, char *end);
int					ft_displaylist(t_env env);
t_env				*init_env(void);

/*
**					Fonction list
*/

int					ft_listlen(t_parse *list);
int					ft_add(char *str, t_parse **add);
int					ft_addend(char *str, t_parse **add);
int					ft_addroad(char *str, int level, t_road **add);

/*
**					Fonction check
*/

int					ft_checklevel(t_llist *tree, char *str, int i,
						t_road **road);
int					ft_check_and_add(t_env *env, char **line);
int					ft_check_name_road(t_env *env, char *src, char *dst,
						char *line);

/*
**					Parser
*/

int					ft_comment(char *line);
int					ft_check(char **line);
int					ft_count_char(char *str, char c);
int					ft_check_int(char *str);
t_env				*ft_parse_file(void);

/*
**					Fonction search
*/

char				*ft_searchroominroad(char *str);
char				*ft_firstroominroad(char *str);
int					ft_searchlevel(t_road *road, char *str);
int					ft_searchinroom(t_parse *room, char *str);
int					ft_searchinlist(char *str, t_parse *file);
int					ft_search_room(t_env *env, char *s);
void				ft_set_start_end(char *s, char *str, t_env *env);

/*
**					Fonction create Graph
*/

char				*ft_returnchild(char *one, char *str, t_env *stok, int i);
char				*ft_searchbrother(char *str, char *father, t_env *stok);
char				*ft_searchchild(char *str, t_env *stok);
t_tree				*ft_createtree(char *str, t_env *stok);
t_llist				*ft_createlist(char *str, char *father, t_env *stok);
void				ft_start_graph(t_env *env);

/*
**					Algo
*/

t_parse				*ft_searchlittleroad(t_env *stok, t_road *road);
t_parse				*therooms(t_env *stok, char *str);
void				ft_cuproom(char *str, t_parse **lst, int i);
char				*thebestroom(t_parse *lst, t_road *road);
/*
**					Fonction Free and Error
*/

void				malloc_error(void);
void				ft_error(t_env *env);
void				ft_freeroad(t_road **pile);
void				ft_free_graph(t_llist *tree);
void				ft_free_tab(char **tab);
void				ft_free_list(t_parse **list);
void				ft_free_env(t_env *env);

#endif
