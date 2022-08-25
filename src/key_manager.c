/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucivelek <ucivelek@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:00:48 by ucivelek          #+#    #+#             */
/*   Updated: 2022/07/29 14:00:50 by ucivelek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	mlx_close(t_var *var)
{
	free_exit(var, "\e[33m\e[1mOyun Kapandı! (X)\e[0m\n");
	return (0);
}

int	key_press(int key, t_var *var)
{
	int	init_steps;

	init_steps = var->game.count_steps;
	if (key == ESC)
	{
		free_exit(var, "\e[33m\e[1mOyun Kapandı! (ESC)\e[0m\n");
		exit(0);
	}
	else
	{
		movements(key, var);
	}
	if (init_steps != var->game.count_steps)
	{
		ft_putstr("Steps: ");
		ft_putnbr(var->game.count_steps);
		ft_putchar('\n');
	}
	write_map(*var);
	return (0);
}
