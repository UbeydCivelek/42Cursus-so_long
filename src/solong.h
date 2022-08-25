/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucivelek <ucivelek@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:01:29 by ucivelek          #+#    #+#             */
/*   Updated: 2022/07/29 14:01:31 by ucivelek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include <stdio.h>

# define BUFFER_SIZE 5

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# if defined(__APPLE__)
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# endif

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void		*img_ptr;
	t_vector	size;
	t_vector	pos;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_map
{
	char		**mtx;
	t_vector	size;
}	t_map;

typedef struct s_game
{
	int			count_collec;
	int			count_steps;
}	t_game;

typedef struct s_var
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_img		img;
}	t_var;

void	ft_putchar(const char c);
void	ft_putstr(const char *str);
int		ft_strlen(const char *str);
void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
void	ft_putendl(const char *str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_substr(char const *s, unsigned int start, int len);
char	**ft_split(char const *s, char c);

int		check_args(int ac, char **av);
void	ft_control_file(char *map);
int		ft_av_control(char *map, char *true_map);
char	*get_map(int fd);
void	get_map_struct(t_var *var, char **av);
int		get_x(t_var *var, char *map);
int		get_y(t_var *var, char *map);
int		check_map(t_var var);
void	create_matrix(t_var *var, char **mtx);
int		get_init_position(t_var *var);
int		write_map(t_var var);
int		count_collec(t_var *var);
int		check_collect(t_var *var);
int		mlx_close(t_var *var);
int		key_press(int key, t_var *var);
int		move_left(t_var *var);
int		move_right(t_var *var);
int		move_down(t_var *var);
int		move_up(t_var *var);
int		movements(int key, t_var *var);
int		free_exit(t_var *var, char *msg);
int		free_map(t_var *var);
int		check_wall(t_var var);
int		check_sprites(t_var var);
int		check_sprites_player(t_var var);
int		check_ret(t_var var);
int		check_char(t_var var);

#endif
