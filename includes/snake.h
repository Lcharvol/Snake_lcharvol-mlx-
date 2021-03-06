/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 05:46:49 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/08 05:46:50 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

# include "mlx/mlx.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
#include <stdlib.h>
#include <time.h>
# include "../libft/libft.h"
# define WIDTH 1000
# define HEIGHT 1000
# define ECHAP	53
# define SIZE_X	40
# define SIZE_Y 40
# define  UP 126
# define  DOWN 125
# define  RIGHT 123
# define  LEFT 124

typedef struct		s_wall
{
	int				x;
	int				y;
	struct s_wall	*prev;
	struct s_wall	*next;
}					t_wall;

typedef struct		s_snake
{
	int				dir;
	int				id;
	int				pos_x;
	int 			pos_y;
	struct s_snake	*prev;
	struct s_snake	*next;
}					t_snake;

typedef struct		s_env
{
	int				level;
	int 			move;
	int				score;
	int 			game_over;
	int				bonus_x;
	int				bonus_y;
	struct s_snake	*snake;
	struct s_wall	*wall;
	int				pos_y;
	int				pos_x;
	int				r;
	int				v;
	int				b;
	char			*ret;
	void			*win;
	void			*mlx;
	void			*img;
}					t_env;

void		ft_start_env(t_env *p);
void		ft_choose_color(t_env *p);
void		ft_draw_score(t_env *p);
void		ft_game_over(t_env *p);
void		ft_verif_wall(t_env *p);
void		ft_verif_coli(t_env *p);
int			ft_verif_bonus(int x, int y, t_env *p);
void		ft_check_snake(int i, int i2, t_env *p);
int			ft_veri_bonus(int x, int y, t_env *p);
void		ft_verif(t_env *p);
t_snake		*ft_add_snake(t_env *p, int x, int y);
int			ft_get_alea();
void		ft_draw(t_env *p);
static int	ft_loop_key_hook(t_env *p);
int			ft_key_hook(int keycode, t_env *p);
int			ft_mouse_hook(int button, int x, int y, t_env *p);

#endif

