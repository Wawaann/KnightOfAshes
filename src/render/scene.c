/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:06:49 by ebigotte          #+#    #+#             */
/*   Updated: 2025/08/29 16:33:08 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	draw_player(t_data *data)
{
	int			x;
	int			y;
	const int	offset[9] = {10, 10, 3, 3, 12, 6, 4, 5, 10};
	const int	time[9] = {100, 65, 80, 80, 36, 80, 70, 120, 90};

	x = data->ply.sx - 88;
	y = data->ply.sy - 83;
	if (data->ply.dir_x == 1)
		data->ply.img.flip = false;
	else
		data->ply.img.flip = true;
	data->ply.img.offset = offset[data->ply.state];
	if (data->ply.img.flip)
		draw_flip_img(&data->frame, &data->ply.img, x - 13, y);
	else
		draw_img(&data->frame, &data->ply.img, x, y);
	reset_anime(&data->ply, offset[data->ply.state]);
	animate(&data->ply.img, time[data->ply.state]);
}

int	get_y_off(t_obj *obj)
{
	float	y_off;

	if (obj->a >= 1)
		obj->th = -0.025;
	if (obj->a <= 0)
		obj->th = 0.025;
	obj->a += obj->th;
	y_off = sin((-fabs(obj->a) * PI)) * 20;
	return (floor(y_off));
}

void	draw_souls(t_data *data)
{
	int	i;
	int	y_off;

	i = 0;
	animate(&data->scn.soul, 80);
	while (i < data->scn.nb_souls)
	{
		y_off = get_y_off(&data->scn.souls[i]);
		draw_img(&data->frame, &data->scn.soul, floor(data->scn.souls[i].hb.x)
			- data->scn.camera, floor(data->scn.souls[i].hb.y + y_off));
		i++;
	}
}

void	draw_scene(t_data *data)
{
	draw_img(&data->frame, &data->scn.img, -data->scn.camera, 0);
	draw_souls(data);
	draw_enemy(data);
	draw_player(data);
}

// for (int i = 0; data->scn.hitbox[i]; i++)
// {
// 	draw_img(&data->frame, &data->hitbox, data->scn.hitbox[i]->x
//				 - data->scn.camera, data->scn.hitbox[i]->y);
// }
// draw_img(&data->frame, &data->ply.h, data->ply.sx, data->ply.sy);

// int	get_y_off(t_obj *obj)
// {
// 	float	y_off;

// 	if (obj->a >= 1)
// 		obj->th = -0.025;
// 	if (obj->a <= 0)
// 		obj->th = 0.025;
// 	obj->a += obj->th;
// 	y_off = sin((-fabs(obj->a) * PI)) * 20;
// 	return (floor(y_off));
// }

// void	draw_souls(t_data *data)
// {
// 	int	i;
// 	int	y_off;

// 	i = 0;
// 	animate(&data->scn.soul, 80);
// 	while (i < data->scn.nb_obj)
// 	{
// 		y_off = get_y_off(&data->scn.souls[i]);
// 		draw_img(&data->frame, &data->scn.soul, floor(data->scn.souls[i].hb->x)
// 			- data->scn.camera, floor(data->scn.souls[i].hb->y + y_off));
// 		i++;
// 	}
// }
