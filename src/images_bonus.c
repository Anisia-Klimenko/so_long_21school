/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:37:57 by anisiaklime       #+#    #+#             */
/*   Updated: 2021/11/30 21:36:02 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_textures(void)
{
	g_game.img.floor.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/floor.XPM", &g_game.img.floor.h, &g_game.img.floor.w);
	g_game.img.wall.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/wall.XPM", &g_game.img.wall.h, &g_game.img.wall.w);
	g_game.img.exit_a.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/exit_a.XPM", &g_game.img.exit_a.h, &g_game.img.exit_a.w);
	g_game.img.exit_d.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/exit_d.XPM", &g_game.img.exit_d.h, &g_game.img.exit_d.w);
	g_game.img.player_left.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/player_left.XPM", &g_game.img.player_left.h,
			&g_game.img.player_left.w);
	g_game.img.player_right.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/player_right.XPM", &g_game.img.player_right.h,
			&g_game.img.player_right.w);
	g_game.img.obsticles.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/collect.XPM", &g_game.img.obsticles.h,
			&g_game.img.obsticles.w);
	g_game.img.black.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/black.XPM", &g_game.img.black.h, &g_game.img.black.w);
	g_game.img.boss.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/boss.XPM", &g_game.img.boss.h, &g_game.img.boss.w);
	g_game.img.cplay.img = g_game.img.player_right.img;
}

void	get_map(char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	g_game.map = malloc(sizeof(char *) * (g_game.h + 1));
	while (i < g_game.h)
	{
		g_game.map[i] = ft_strdup(line);
		if (!g_game.map[i])
		{
			free_map(i);
			return ;
		}
		i++;
		line = get_next_line(fd);
	}
	g_game.map[i] = NULL;
}

void	put_image(t_image texture, int x, int y)
{
	static int	n;
	char		*text;
	char		*ntext;

	mlx_put_image_to_window(g_game.mlx, g_game.win, texture.img,
		2 + x * 30, y * 30);
	if (texture.img == g_game.img.player_left.img
		|| texture.img == g_game.img.player_right.img)
	{
		g_game.x = x;
		g_game.y = y;
		g_game.img.cplay.img = texture.img;
		ntext = ft_itoa(n);
		text = ft_strjoin("Numbur of mooves: ", ntext);
		mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.img.black.img,
			20, g_game.h * 30 + 10);
		mlx_string_put(g_game.mlx, g_game.win, 20, g_game.h * 30 + 20,
			100000, text);
		free(text);
		free(ntext);
		printf("Numbur of mooves: %d\n", n);
		n++;
	}
}

void	draw(int i, int j)
{
	if (g_game.map[i][j] == '1')
		put_image(g_game.img.wall, j, i);
	else if (g_game.map[i][j] == 'E')
		put_image(g_game.img.exit_d, j, i);
	else if (g_game.map[i][j] == 'B')
		put_image(g_game.img.boss, j, i);
	else
		put_image(g_game.img.floor, j, i);
	if (g_game.map[i][j] == 'C')
	{
		put_image(g_game.img.obsticles, j, i);
		g_game.img.tocollect++;
	}
	if (g_game.map[i][j] == 'P')
		put_image(g_game.img.player_right, j, i);
}

void	init_map(void)
{
	int		i;
	int		j;

	i = -1;
	init_textures();
	while (++i < g_game.h)
	{
		j = -1;
		while (++j < g_game.w)
		{
			draw(i, j);
		}
	}
}
