/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:21 by anisiaklime       #+#    #+#             */
/*   Updated: 2021/11/30 22:14:05 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_args(int argc)
{
	if (argc == 1)
		quit("No map as an argument\nTry ./so_long <name of map>\n", 1);
	if (argc > 2)
		quit("Too many arguments\nTry ./so_long <name of map>\n", 1);
	return (1);
}

static char	*ft_trim_map(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (g_valid.valid != 1 && s[i] != '\0')
	{
		if (s[i] == 'E')
			g_valid.exit = 1;
		if (s[i] == 'C')
			g_valid.coll = 1;
		if (s[i] == 'P')
			g_valid.start = 1;
		if (s[i] == '1')
			g_valid.wall = 1;
		if (g_valid.exit == 1 && g_valid.coll == 1 && g_valid.start == 1
			&& g_valid.wall == 1)
			g_valid.valid = 1;
		i++;
	}
	return (ft_strtrim(s, set));
}

static int	manage_lines(char *s0, char *s1)
{
	char	*tmp;
	int		flag;

	if (s0 == NULL)
		tmp = ft_trim_map(s1, "1");
	else if (s1 == NULL)
		tmp = ft_trim_map(s0, "1");
	else if (ft_strlen(s0) == ft_strlen(s1) && s1[0] == '1'
		&& s1[ft_strlen(s1) - 2] == '1')
		tmp = ft_trim_map(s1, "EBCP01");
	else
		return (0);
	if (!ft_memcmp(tmp, "\n", 1) || !ft_memcmp(tmp, "\0", 1))
		flag = 1;
	else
		flag = 0;
	free(tmp);
	return (flag);
}

static int	check_valid_map(char *fline, int fd)
{
	char			*line;
	int				flag;

	flag = manage_lines(NULL, fline);
	line = get_next_line(fd);
	g_game.w = ft_strlen(fline) - 1;
	g_game.h += 1;
	while (line && flag)
	{
		flag = manage_lines(fline, line);
		free(fline);
		fline = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		g_game.h += 1;
	}
	if (!line && flag)
		flag = manage_lines(fline, NULL);
	free(line);
	free(fline);
	return (flag * g_valid.valid);
}

int	valid_file(char *path)
{
	char	*line;
	int		fd;

	if (ft_strlen(path) < 4)
		return (quit("Non valid map name\nShould be <name>.ber\n", 1));
	if (ft_memcmp(path + ft_strlen(path) - 4, ".ber", 4))
		return (quit("Non valid map extension\nShould be <name>.ber\n", 1));
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (quit("Empty map\n", 1));
	if (!check_valid_map(line, fd))
		return (quit("Non valid map\n", 1));
	return (1);
}
