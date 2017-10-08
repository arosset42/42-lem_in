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

typedef struct		s_parse
{
	char			*name;
	char			*param;
}					t_parse

void 	malloc_error();

#endif
