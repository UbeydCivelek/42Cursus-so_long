/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucivelek <ucivelek@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:58:18 by ucivelek          #+#    #+#             */
/*   Updated: 2022/08/25 13:58:35 by ucivelek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_map(t_var var)

{
	check_wall(var);
	check_sprites(var);
	check_sprites_player(var);
	check_ret(var);
	check_char(var);
	return (1);
}
