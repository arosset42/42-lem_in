#ifndef LEM_IN_H
# define LEM_IN_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"


typedef	struct		s_lem
{
	char			*name;
	char			*param;
	int				use;
	struct s_lem	*next;
}					t_lem;

typedef	struct		s_spec
{
	int				ant;
	int				start;
	struct s_lem	*room;
	struct s_lem	*tunnel;
}					t_spec;

int					ft_count_tab(char **tab);
int					ft_isnumber(char *line);



void 				ft_parser(t_spec *lem_param);



t_spec 				*ft_init_struct_parser(void);

#endif
