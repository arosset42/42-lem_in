/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:16:36 by arosset           #+#    #+#             */
/*   Updated: 2017/10/24 15:49:22 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

typedef struct		s_parse
{
	char			*str;
	struct s_parse	*next;
}					t_parse;

typedef struct		s_tree
{
	char			*str;
	int				level;
	struct s_llist	*child;
}					t_tree;

typedef struct		s_road
{
	char			*str;
	int				level;
	struct s_road	*next;
}					t_road;

typedef struct		s_llist
{
	t_tree			*node;
	struct s_llist	*next;
}					t_llist;

typedef struct		s_stock
{
	t_parse			*room;
	t_parse			*room2;
	t_parse			*road;
	t_parse			*com;
	t_parse			*file;
	char			*end;
	char			*start;
}					t_stock;

t_stock				*ft_initstock(void);
int					ft_cmpinroom(t_parse *room);
int					ft_add(char *str, t_parse **add);
int					ft_displayant(t_parse *ok, int nb, char *end);
int					ft_freeanderror(t_parse **tmp);
int					ft_nbant(char *str);
int					ft_addend(char *str, t_parse **add);
int					ft_parse(void);
int					ft_displaylist(t_parse *list);
char				*ft_startandend(t_parse *room, int i);
int					ft_searchbestroad(t_parse *room, t_parse *road);
char				*ft_firstword(char *str, char c);
char				*ft_lastword(char *str, char cc);
t_parse				*ft_cpypile(t_parse *pilea);
int					ft_listlen(t_parse *list);
char				*ft_listend(t_parse *list);
t_tree				*ft_firsttree(t_parse *room, t_parse *road);
t_llist				*ft_createlist(char *str, char *father, t_stock *stok);
int					ft_roominroad(char *str, t_parse *room);
char				*ft_searchroominroad(char *str);
char				*ft_firstroominroad(char *str);
t_llist				*ft_build(t_tree *tree, t_llist *lst);
t_tree				*ft_createtree(char *str, t_stock *stok);
char				*ft_searchchild(char *str, t_stock *stok);
char				*ft_searchbrother(char *str, char *father, t_stock *stok);
int					ft_searchinlist(char *str, t_parse *file);
int					ft_searchinroom(t_parse *room, char *str);
int					ft_errorinroom(t_parse *room);
int					ft_checklevel(t_llist *tree, char *str, int i,
					t_road **road);
int					ft_addroad(char *str, int level, t_road **add);
void				ft_displayroad(t_road *road);
t_parse				*ft_searchlittleroad(t_stock *stok, t_road *road);
int					ft_searchlevel(t_road *road, char *str);
int					ft_freepile(t_parse **pile);
int					ft_freeroad(t_road **pile);
int					ft_formatroad(char *road);
void				ft_freetree(t_llist *tree);
int					ft_freestock(t_stock *stok);
int					ft_totalleaks(t_parse **lem, t_stock *stok,
					t_road **road, t_llist *tree);
void				ft_freetab(char **tab);
int					ft_putendlreturn(char const *s);
#endif
