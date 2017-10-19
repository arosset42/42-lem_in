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
** Structure graph
*/

typedef struct			s_tree
{
	char				*data;
	int					lvl;
	struct s_graph		*child;
}						t_tree;

typedef struct			s_graph // s_llist
{
	t_tree				*node;
	struct s_graph		*next;
}						t_graph;

/*
** Structure list parsing
*/

typedef	struct			s_road
{
	char				*src;
	char				*dest;
	int					use;
	struct s_road		*next;
}						t_road;

typedef struct			s_list
{
	char				*data;
	struct s_list		*next;
}						t_list;

/*
** Structure environement
*/

typedef struct 			s_env
{
	int					nb_ants;
	t_list				*room;
	t_road				*road;
	t_list				*init;
	t_graph				*graph;
	char				*start;
	char				*end;

	t_list				*file;
}						t_env;

/*
**	Fonction list
*/

int						ft_addend(char *str, t_list **add);
int						ft_addroad(char *src, char *dest, t_road **add);

/*
**	Fonction check
*/

int 					ft_check_and_add(t_env *env, char **line);
int						ft_check_name_road(t_env *env, char *src, char *dst);

/*
**	Parser
*/

int						ft_comment(char *line);
int						ft_check(char **line);
int						ft_count_char(char *str, char c);
int						ft_check_int(char *str);
t_env 					*ft_parse_file(void);

/*
**	Fonction search
*/

int		ft_search_in_list(char *str, t_list *list);
char					*ft_search_child(char *str, t_env *env);
char					*ft_search_brother(char *str, char *father, t_env *env);
int   					ft_search_room(t_env *env, char *s);
int						ft_search_road(t_env *env, t_road *road);
void 					ft_set_start_end(char *s, char *str, t_env *env);

/*
** Fonction create Graph
*/

t_tree					*ft_create_tree(char *str, t_env *env);
t_graph					*ft_create_graph(char *str, char *father, t_env *env);
void 					ft_start_graph(t_env *env);

/*
** Initialisation
*/

t_env					*init_env(void);
void 	ft_print_graph(t_graph *graph);
/*
** Fonction Free and Error
*/

void 					malloc_error();
void 					ft_error(t_env *env);

void 					ft_free_tab(char **tab);
void 					ft_free_list(t_list **list);
void 					ft_free_road(t_road **road);
void 					ft_free_env(t_env *env);

#endif
