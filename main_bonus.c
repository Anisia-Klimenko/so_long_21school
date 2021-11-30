/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:01 by anisiaklime       #+#    #+#             */
/*   Updated: 2021/11/30 21:14:29 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	check_args(argc);
	valid_file(argv[1]);
	get_map(argv[1]);
	g_game.mlx = mlx_init();
	g_game.win = mlx_new_window(g_game.mlx, g_game.w * 30 + 5,
			g_game.h * 30 + 5 + 30, "so_long_bonus");
	init_map();
	mlx_hook(g_game.win, 2, 1L << 0, key_hook, 0);
	mlx_hook(g_game.win, 17, 1L << 0, mouse_hook, 0);
	mlx_loop(g_game.mlx);
	return (0);
}
