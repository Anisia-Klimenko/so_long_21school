/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:03 by anisiaklime       #+#    #+#             */
/*   Updated: 2021/11/30 21:08:41 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "src/gnl/get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

// structure for checking map validation
typedef struct s_valid
{
	int	coll;
	int	wall;
	int	exit;
	int	start;
	int	valid;
}	t_valid;

// structure for one image on map
typedef struct s_image
{
	void	*img;
	int		h;
	int		w;
}	t_image;

// structure for all types of textures
typedef struct s_textures
{
	t_image	floor;
	t_image	wall;
	t_image	exit_a;
	t_image	exit_d;
	t_image	player_left;
	t_image	player_right;
	t_image	obsticles;
	t_image	cplay;
	t_image	black;
	t_image	boss;
	int		tocollect;
}	t_textures;

// structure for info about game
typedef struct s_info
{
	void		*mlx;
	void		*win;
	char		**map;
	int			x;
	int			y;
	int			h;
	int			w;
	t_textures	img;
}	t_info;

t_valid	g_valid;
t_info	g_game;

int		check_args(int argc);
int		valid_file(char *path);

void	get_map(char *path);
void	init_map(void);

int		mouse_hook(void);
int		key_hook(int key, void *param);
void	put_image(t_image texture, int x, int y);
void	play_game(int key);

int		quit(char *msg, int code);
void	free_map(int line);
void	destroy_game(void);

#endif