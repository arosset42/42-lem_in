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


// void 	init_env(t_spec *s_env);
#endif
