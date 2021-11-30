/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:25 by anisiaklime       #+#    #+#             */
/*   Updated: 2021/11/30 21:42:07 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	quit(char *msg, int code)
{
	printf("%s", msg);
	exit(code);
	return (1 - code);
}

void	free_map(int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(g_game.map[i]);
		i++;
	}
	free(g_game.map);
}

void	destroy_game(void)
{
	free_map(g_game.h);
	mlx_destroy_image(g_game.mlx, g_game.img.floor.img);
	mlx_destroy_image(g_game.mlx, g_game.img.wall.img);
	mlx_destroy_image(g_game.mlx, g_game.img.exit_a.img);
	mlx_destroy_image(g_game.mlx, g_game.img.exit_d.img);
	mlx_destroy_image(g_game.mlx, g_game.img.player_left.img);
	mlx_destroy_image(g_game.mlx, g_game.img.player_right.img);
	mlx_destroy_image(g_game.mlx, g_game.img.obsticles.img);
	mlx_destroy_image(g_game.mlx, g_game.img.black.img);
	mlx_destroy_image(g_game.mlx, g_game.img.boss.img);
	mlx_destroy_window(g_game.mlx, g_game.win);
	quit("Game was closed!\n", 0);
}
