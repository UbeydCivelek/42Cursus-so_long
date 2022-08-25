/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucivelek <ucivelek@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:59:21 by ucivelek          #+#    #+#             */
/*   Updated: 2022/07/29 13:59:23 by ucivelek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_wall(t_var var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		if (row == 0 || row == (var.map.size.y - 1))
		{
			while (var.map.mtx[row][col])
			{
				if (var.map.mtx[row][col] != '1')
					free_exit(&var, "üstler ve altlar duvar ile çevrili değil");
				col++;
			}
		}
		if (var.map.mtx[row][0] != '1'
			|| var.map.mtx[row][var.map.size.x - 1] != '1')
			free_exit(&var, "yanlar duvar ile çevrili değil!");
		row++;
	}
	return (0);
}

int	check_sprites(t_var var)
{
	int		has[2];
	int		row;
	int		col;

	has[0] = 0;
	has[1] = 0;
	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		while (col <= var.map.size.x)
		{
			if (var.map.mtx[row][col] == 'C')
				has[0] += 1;
			if (var.map.mtx[row][col] == 'E')
				has[1] += 1;
			col++;
		}
		row++;
	}
	if (has[0] < 1 || has[1] < 1)
		free_exit(&var, "HATALI HARİTA: fazla veya eksik sprite");
	return (0);
}

int	check_sprites_player(t_var var)
{
	int		a;
	int		row;
	int		col;

	a = 0;
	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		while (col <= var.map.size.x)
		{
			if (var.map.mtx[row][col] == 'P')
				a += 1;
			col++;
		}
		row++;
	}
	if (a != 1)
		free_exit(&var, "HATALI HARİTA: fazla veya eksik sprite");
	return (0);
}

int	check_ret(t_var var)
{
	int		row;

	row = 0;
	while (row < var.map.size.y)
	{
		if (var.map.size.x != (int)ft_strlen(var.map.mtx[row]))
		{
			ft_putendl("HATALI HARİTA: harita boyutu eşit uyumsuz");
			exit(1);
		}
		row++;
	}
	return (0);
}

int	check_char(t_var var)
{
	int		row;
	int		col;	

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		while (var.map.mtx[row][col])
		{
			if (var.map.mtx[row][col] != '0' && var.map.mtx[row][col] != '1'
				&& var.map.mtx[row][col] != 'P' && var.map.mtx[row][col] != 'E'
				&& var.map.mtx[row][col] != 'C')
			{
				ft_putendl("HATALI HARİTA: tanimsiz karakter");
				exit(1);
			}
			col++;
		}
		row++;
	}
	return (0);
}
