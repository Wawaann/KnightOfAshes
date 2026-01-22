/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:12:50 by ebigotte          #+#    #+#             */
/*   Updated: 2025/10/01 10:50:52 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	key_handler(int keycode, t_data *data, bool is_pressed)
{
	if (keycode == K_ESC)
		close_win(data);
	if (keycode == K_Q && is_pressed)
		add_input(&data->ply, A_ATK2, get_time());
	if (keycode == K_W && is_pressed)
		add_input(&data->ply, A_ATK1, get_time());
	if (keycode == K_E && is_pressed)
		add_input(&data->ply, A_ROLL, get_time());
	if (keycode == K_SPACE && is_pressed)
		add_input(&data->ply, A_JUMP, get_time());
	if (keycode == K_A)
		action_pressed(data, &data->ply, &data->scn);
	if (keycode == K_UP)
		data->keys[KEY_UP] = is_pressed;
	if (keycode == K_LEFT)
		data->keys[KEY_LEFT] = is_pressed;
	if (keycode == K_RIGHT)
		data->keys[KEY_RIGHT] = is_pressed;
}

int	key_pressed(int keycode, t_data *data)
{
	key_handler(keycode, data, true);
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	key_handler(keycode, data, false);
	return (0);
}
