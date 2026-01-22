/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:08:35 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/28 16:37:05 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	draw_img(t_img *frame, t_img *img, int x_off, int y_off)
{
	int	x;
	int	y;
	int	color;

	x_off -= img->x_off * img->x;
	y_off -= img->y_off * img->y;
	y = img->y_off * img->y;
	while (y < (img->y_off + 1) * img->y)
	{
		x = img->x_off * img->x;
		while (x < (img->x_off + 1) * img->x)
		{
			color = get_pixel_color(img, x, y);
			if (color != 0)
			{
				if (img->x == WIDTH && img->y == HEIGHT)
					put_bg_pixel(frame, x + x_off, y + y_off, color);
				else if (x + x_off < WIDTH)
					put_pixel(frame, x + x_off, y + y_off, color);
				else
					break ;
			}
			x++;
		}
		y++;
	}
}

void	draw_flip_img(t_img *frame, t_img *img, int x_off, int y_off)
{
	int	x;
	int	y;
	int	color;
	int	start_x;

	y = img->y_off * img->y;
	while (y < (img->y_off + 1) * img->y)
	{
		start_x = (img->x_off + 1) * img->x - 1;
		x = start_x;
		while (x != img->x_off * img->x - 1)
		{
			color = get_pixel_color(img, x, y);
			if (color != 0)
			{
				if (x_off + (start_x - x) < WIDTH)
					put_pixel(frame, x_off + start_x - x, y_off
						+ (y - img->y_off * img->y), color);
				else
					break ;
			}
			x--;
		}
		y++;
	}
}
