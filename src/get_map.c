/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucivelek <ucivelek@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:00:28 by ucivelek          #+#    #+#             */
/*   Updated: 2022/07/29 14:00:30 by ucivelek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	get_x(t_var *var, char *map)
{
	int	i;

	i = 0;
	var->map.size.x = 0;
	while (map[i] != '\n')
	{
		i++;
		var->map.size.x++;
	}
	return (var->map.size.x);
}

int	get_y(t_var *var, char *map)
{
	int	i;

	i = 0;
	var->map.size.y = 0;
	while (map[i] != '\0')
	{
		i++;
		if (map[i] == '\n')
			var->map.size.y++;
	}
	var->map.size.y += 1;
	return (var->map.size.y);
}

void	create_matrix(t_var *var, char **mtx)
{
	var->map.mtx = mtx;
}

char	*get_map(int fd)
{
	static char	*left_str;
	char		*buff;
	int			rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

void	get_map_struct(t_var *var, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	get_x(var, get_map(fd));
	get_y(var, get_map(fd));
	create_matrix(var, ft_split(get_map(fd), '\n'));
}
