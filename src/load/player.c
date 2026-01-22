/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:44:18 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/02 22:57:38 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	get_ply_pos(t_ply *ply, t_scene scn)
{
	int	i;
	int	j;

	i = 0;
	while (scn.map.map[i])
	{
		j = 0;
		while (scn.map.map[i][j] != -1)
		{
			if (scn.map.map[i][j] == 2)
			{
				scn.map.map[i][j] = 0;
				ply->hitbox.x = j * 80;
				ply->hitbox.y = i * 80 + i * 3;
				return ;
			}
			j++;
		}
		i++;
	}
}

// set_img(data->mlx, "ply.xpm", &data->ply.h);
// set_img_size(&data->ply.h, 50, 77);

void	load_player(t_data *data)
{
	get_ply_pos(&data->ply, data->scn);
	set_img(data->mlx, "knight.xpm", &data->ply.img);
	set_img_size(&data->ply.img, 240, 160);
	data->ply.sx = round(data->ply.hitbox.x) - data->scn.camera;
	data->ply.sy = round(data->ply.hitbox.y);
	data->ply.state = IDLE;
	data->ply.on_ground = false;
	data->ply.action = A_NONE;
	data->ply.vy = 0;
	data->ply.vx = 0;
	data->ply.g = GRAVITY;
	data->ply.hitbox.width = 50;
	data->ply.hitbox.height = 77;
	data->ply.dir_x = 1;
	data->ply.img.offset = 10;
	data->ply.img.flip = false;
	data->ply.prev_input = false;
	data->ply.input_count = 0;
}
