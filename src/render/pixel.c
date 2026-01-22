/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:02:40 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/28 16:37:40 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

uint32_t	get_pixel_color(t_img const *img, int x, int y)
{
	const char	*dst;

	dst = img->addr + ((y % img->width) * img->size_line
			+ (x % img->width) * (img->bpp / 8));
	return (*(uint32_t *)dst);
}

void	put_pixel(t_img *dest, int x, int y, uint32_t pixel)
{
	char	*dst;

	if (x < 0 || x >= dest->width || y < 0 || y >= dest->height)
		return ;
	dst = dest->addr + (y * dest->size_line + x * (dest->bpp / 8));
	*(unsigned int *)dst = pixel;
}

void	put_bg_pixel(t_img *dest, int x, int y, uint32_t pixel)
{
	char	*dst;

	while (x < 0)
		x += 1280;
	dst = dest->addr + (y * dest->size_line + (x % WIDTH) * (dest->bpp / 8));
	*(unsigned int *)dst = pixel;
}
