/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:44:18 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/02 18:09:47 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	set_img(void *mlx, char *asset, t_img *img)
{
	char	*file;

	file = ft_strjoin("./assets/", asset);
	printf("asset: %s\n", file);
	img->img = mlx_xpm_file_to_image(mlx, file, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line,
			&img->endian);
	img->x_off = 0;
	img->y_off = 0;
	gettimeofday(&img->clock.tv, NULL);
	img->x = WIDTH;
	img->y = HEIGHT;
	img->flip = false;
	free(file);
}

void	set_img_size(t_img *img, int x, int y)
{
	img->x = x;
	img->y = y;
}

void	load_img(t_data *data)
{
	data->frame.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.size_line, &data->frame.endian);
	data->frame.width = WIDTH;
	data->frame.height = HEIGHT;
	set_img(data->mlx, "hitbox.xpm", &data->hitbox);
	set_img_size(&data->hitbox, 80, 80);
	set_img(data->mlx, "bg/sky.xpm", &data->bg[0]);
	set_img(data->mlx, "bg/tower.xpm", &data->bg[1]);
	set_img(data->mlx, "bg/town.xpm", &data->bg[2]);
	set_img(data->mlx, "bg/mountain.xpm", &data->bg[3]);
}
