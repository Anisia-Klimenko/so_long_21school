/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:37:46 by anisiaklime       #+#    #+#             */
/*   Updated: 2021/11/30 22:25:39 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	mouse_hook(void)
{
	destroy_game();
	return (0);
}

int	key_hook(int key, void *param)
{
	(void)param;
	if (key == ESC)
		destroy_game();
	if (key == W || key == A || key == S || key == D)
		play_game(key);
	return (0);
}

void	open_exit(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_game.h)
	{
		j = 0;
		while (j < g_game.w)
		{
			if (g_game.map[i][j] == 'E')
			{
				put_image(g_game.img.floor, j, i);
				put_image(g_game.img.exit_a, j, i);
			}
			j++;
		}
		i++;
	}
}

int	check_path(int dx, int dy)
{
	if (g_game.map[g_game.y + dy][g_game.x + dx] == 'C')
	{
		g_game.img.tocollect--;
		g_game.map[g_game.y + dy][g_game.x + dx] = '0';
	}
	if (!g_game.img.tocollect)
		open_exit();
	if (g_game.map[g_game.y + dy][g_game.x + dx] == '1')
		return (0);
	if (g_game.map[g_game.y + dy][g_game.x + dx] == 'E'
		&& g_game.img.tocollect)
		return (0);
	if (g_game.map[g_game.y + dy][g_game.x + dx] == 'E'
		&& !g_game.img.tocollect)
	{
		put_image(g_game.img.cplay, g_game.y + dy, g_game.x + dx);
		destroy_game();
	}
	if (g_game.map[g_game.y + dy][g_game.x + dx] == 'B')
	{
		put_image(g_game.img.cplay, g_game.y + dy, g_game.x + dx);
		quit("Lose!\n", 0);
	}
	return (1);
}

void	play_game(int key)
{
	if (key == W && check_path(0, -1))
	{
		put_image(g_game.img.floor, g_game.x, g_game.y);
		put_image(g_game.img.cplay, g_game.x, g_game.y - 1);
	}
	if (key == A && check_path(-1, 0))
	{
		put_image(g_game.img.floor, g_game.x, g_game.y);
		put_image(g_game.img.player_left, g_game.x - 1, g_game.y);
	}
	if (key == S && check_path(0, 1))
	{
		put_image(g_game.img.floor, g_game.x, g_game.y);
		put_image(g_game.img.cplay, g_game.x, g_game.y + 1);
	}
	if (key == D && check_path(1, 0))
	{
		put_image(g_game.img.floor, g_game.x, g_game.y);
		put_image(g_game.img.player_right, g_game.x + 1, g_game.y);
	}	
}
