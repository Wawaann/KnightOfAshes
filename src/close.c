/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:21:57 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/28 10:33:13 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	close_win(t_data *data)
{
	int	i;

	mlx_destroy_image(data->mlx, data->bg[0].img);
	mlx_destroy_image(data->mlx, data->bg[1].img);
	mlx_destroy_image(data->mlx, data->bg[2].img);
	mlx_destroy_image(data->mlx, data->bg[3].img);
	mlx_destroy_image(data->mlx, data->scn.img.img);
	mlx_destroy_image(data->mlx, data->ply.img.img);
	mlx_destroy_image(data->mlx, data->hitbox.img);
	mlx_destroy_image(data->mlx, data->frame.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->bg);
	free(data->mlx);
	free(data->scn.map.asset);
	ft_freetab((char **)data->scn.map.map);
	i = 0;
	while (data->scn.hitbox[i])
	{
		free(data->scn.hitbox[i]);
		i++;
	}
	free(data->scn.hitbox);
	exit(0);
}
