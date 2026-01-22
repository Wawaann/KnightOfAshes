/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:04:02 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/02 15:57:10 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	reset_anime(t_ply *ply, int offset)
{
	if (ply->state < 4)
		return ;
	if (ply->img.x_off == offset - 1)
	{
		ply->prev_input = false;
		ply->img.x_off = 0;
		ply->action = A_NONE;
	}
}

void	animate(t_img *img, int time)
{
	float	elapsed_time;

	gettimeofday(&img->clock.tv2, NULL);
	elapsed_time = (img->clock.tv2.tv_sec - img->clock.tv.tv_sec) * 1000000
		+ (img->clock.tv2.tv_usec - img->clock.tv.tv_usec);
	if (elapsed_time >= time * 1000)
	{
		img->clock.tv = img->clock.tv2;
		img->x_off++;
		img->x_off = img->x_off % img->offset;
	}
}
