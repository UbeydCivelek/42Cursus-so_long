/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucivelek <ucivelek@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:58:37 by ucivelek          #+#    #+#             */
/*   Updated: 2022/07/29 13:58:40 by ucivelek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_control_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Girdiğiniz Dosyayı Bulamadım.");
		exit(0);
	}
	else
		close(fd);
}

int	ft_av_control(char *map, char *true_map)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(map);
	while (map[len - 1] != '.')
	{
		if (map[len - 1] == true_map[i])
			i++;
		else
		{
			ft_putendl("Harita uzantısı '.ber' değil");
			exit(0);
		}
		len--;
	}
	ft_control_file(map);
	return (1);
}

int	check_args(int ac, char **av)
{
	int	map_c;

	if (ac != 2)
	{
		ft_putendl("Haritayı Belirtin");
		exit(0);
	}
	map_c = ft_av_control(av[1], "reb");
	if (map_c == 0)
		exit(0);
	return (1);
}
