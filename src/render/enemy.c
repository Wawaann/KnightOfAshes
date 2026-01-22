/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:05:54 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/09 15:44:43 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	draw_enemy(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < data->scn.nb_enm)
	{
		animate(&data->scn.enm[i].img, 110);
		x = data->scn.enm[i].hitbox.x - data->scn.camera;
		y = data->scn.enm[i].hitbox.y;
		if (data->scn.enm[i].type == 1)
			draw_img(&data->frame, &data->scn.enm[i].img, x - 79, y - 80);
		if (data->scn.enm[i].type == 2)
			draw_img(&data->frame, &data->scn.enm[i].img, x - 75, y - 70);
		i++;
	}
}
