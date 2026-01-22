/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:13:15 by ebigotte          #+#    #+#             */
/*   Updated: 2025/10/01 10:42:19 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	set_state(t_ply *ply, t_state new_state)
{
	if (ply->state != new_state)
	{
		ply->state = new_state;
		ply->img.x_off = 0;
		ply->img.y_off = ply->state;
	}
}

void	update_state(t_data *data)
{
	if (data->ply.action == A_ATK1)
		return (set_state(&data->ply, ATK_1));
	if (data->ply.action == A_ATK2)
		return (set_state(&data->ply, ATK_2));
	if (data->ply.action == A_ROLL)
		return (set_state(&data->ply, ROLL));
	if (!data->ply.on_ground)
	{
		if (data->ply.vy < 0)
			return (set_state(&data->ply, JUMP));
		else if (data->ply.vy > 0)
			return (set_state(&data->ply, FALL));
	}
	if (data->keys[KEY_LEFT] || data->keys[KEY_RIGHT])
		return (set_state(&data->ply, RUN));
	set_state(&data->ply, IDLE);
}

void	move_ply_dir(t_data *data, int dir, float accel, int vmax)
{
	if (data->ply.action == A_ROLL)
		dir = data->ply.dir_x;
	if (dir != 0)
	{
		data->ply.vx += dir * accel;
		if (data->ply.vx > vmax)
			data->ply.vx = vmax;
		else if (data->ply.vx < -vmax)
			data->ply.vx = -vmax;
	}
	else
	{
		if (data->ply.vx > 0)
		{
			data->ply.vx -= FRICTION;
			if (data->ply.vx < 0)
				data->ply.vx = 0;
		}
		else if (data->ply.vx < 0)
		{
			data->ply.vx += FRICTION;
			if (data->ply.vx > 0)
				data->ply.vx = 0;
		}
	}
}

void	move_ply(t_data *data, float *new_posx)
{
	int	dir;

	dir = 0;
	if (data->keys[KEY_LEFT] && data->ply.action > 2)
	{
		data->ply.dir_x = -1;
		dir = -1;
	}
		if (data->keys[KEY_RIGHT] && data->ply.action > 2)
	{
		data->ply.dir_x = 1;
		dir = 1;
	}
	if (data->ply.action == A_ROLL)
		move_ply_dir(data, dir, ROLL_SPEED, ROLL_SPEED);
	else
		move_ply_dir(data, dir, ACCEL, VMAX);
	*new_posx += data->ply.vx;
	if ((data->ply.dir_x == -1 && data->ply.sx < 400) ||
		(data->ply.dir_x == 1 && data->ply.sx > 800))
		data->scn.camera += data->ply.vx;
}

bool	is_intersect(t_rect *rect, t_rect ent, int x, int y)
{
	if (x + ent.width <= rect->x)
		return (false);// printf("on_ground = %d\n", data->ply.on_ground);
	if (x >= rect->x + rect->width)
		return (false);
	if (y + ent.height <= rect->y)
		return (false);
	if (y >= rect->y + rect->height)
		return (false);
	return (true);
}

static void	can_move_x(t_data *data, float new_x, float y)
{
	int	i;

	i = 0;
	while (data->scn.hitbox[i])
	{
		if (is_intersect(data->scn.hitbox[i], data->ply.hitbox, new_x, y))
		{
			if (data->ply.hitbox.x > new_x)
				new_x = data->scn.hitbox[i]->x + data->scn.hitbox[i]->width;
			else
				new_x = data->scn.hitbox[i]->x - data->ply.hitbox.width;
			break ;
		}
		i++;
	}
	data->ply.hitbox.x = new_x;
}

static void	can_move_y(t_data *data, float x, float new_y)
{
	int		i;
	float	vy;

	i = 0;
	vy = data->ply.vy + data->ply.g;
	data->ply.on_ground = false;
	while (data->scn.hitbox[i])
	{
		if (is_intersect(data->scn.hitbox[i], data->ply.hitbox, x, new_y + vy))
		{
			data->ply.vy = 0;
			data->ply.g = GRAVITY;
			if (data->ply.hitbox.y > new_y)
				new_y = data->scn.hitbox[i]->y + data->scn.hitbox[i]->height;
			else
			{
				new_y = data->scn.hitbox[i]->y - data->ply.hitbox.height;
				data->ply.on_ground = true;
				if (data->ply.action == A_JUMP)
					data->ply.prev_input = false;
			}
			break ;
		}
		i++;
	}
	data->ply.hitbox.y = new_y;
}

void	update_player(t_data *data)
{
	float	new_posx;
	float	new_posy;

	new_posx = data->ply.hitbox.x;
	new_posy = data->ply.hitbox.y;
	if (!data->ply.on_ground)
	{
		data->ply.vy += data->ply.g;
		data->ply.g *= 1.07;
	}
	new_posy += data->ply.vy;
	move_ply(data, &new_posx);
	can_move_y(data, data->ply.hitbox.x, new_posy);
	can_move_x(data, new_posx, data->ply.hitbox.y);
	data->ply.sx = round(data->ply.hitbox.x) - data->scn.camera;
	data->ply.sy = round(data->ply.hitbox.y);
	process_input(data, get_time());
	update_state(data);
}
