/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:06:27 by ebigotte          #+#    #+#             */
/*   Updated: 2025/10/01 10:41:34 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

// printf("on_ground = %d\n", data->ply.on_ground);

void	render(t_data *data)
{
	draw_bg(data);
	draw_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.img, 0, 0);
}
