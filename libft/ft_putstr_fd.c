/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:46:13 by acristin          #+#    #+#             */
/*   Updated: 2021/11/09 15:52:51 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd > 0)
	{
		if (s != NULL)
		{
			while (s[i] != '\0')
			{
				ft_putchar_fd(s[i], fd);
				i++;
			}
		}
		else
			ft_putstr_fd("(null)", 1);
	}
}
