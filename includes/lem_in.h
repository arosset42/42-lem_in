#ifndef LEM_IN_H
# define LEM_IN_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"

typedef	struct		s_spec
{
	int				ant;
	struct s_list	*room;
	struct s_list	*tunnel;
}					t_spec;


#endif
