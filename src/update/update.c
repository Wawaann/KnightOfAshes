/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:52:05 by ebigotte          #+#    #+#             */
/*   Updated: 2025/10/01 11:02:12 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	action_pressed(t_data *data, t_ply *ply, t_scene *scn)
{
	(void)data;
	(void)ply;
	(void)scn;
	// if (is_intersect())
}

int	update_game(t_data *data)
{
	long	elapsed_time;

	gettimeofday(&data->clock.tv2, NULL);
	elapsed_time = (data->clock.tv2.tv_sec - data->clock.tv.tv_sec) * 1000000
		+ (data->clock.tv2.tv_usec - data->clock.tv.tv_usec);
	if (elapsed_time >= FPS)
	{
		data->clock.tv = data->clock.tv2;
		update_enemys(data);
		update_player(data);
		render(data);
	}
	return (0);
}
