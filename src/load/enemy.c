/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:46:14 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/09 15:45:03 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	init_enemy(t_scene *scn)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (scn->map.map[i])
	{
		j = 0;
		while (scn->map.map[i][j] != -1)
		{
			if (scn->map.map[i][j] == 3 || scn->map.map[i][j] == 4)
				c++;
			j++;
		}
		i++;
	}
	scn->nb_enm = c;
	scn->enm = ft_calloc(c + 1, sizeof(t_enmy));
}

void	load_axe(t_data *data, t_enmy *enm, int x, int y)
{
	enm->hitbox.x = x * 80 + 22;
	enm->hitbox.y = y * 80;
	enm->hitbox.width = 40;
	enm->hitbox.height = 75;
	enm->on_ground = false;
	enm->type = 2;
	enm->vx = 0;
	enm->vy = 0;
	enm->g = GRAVITY;
	set_img(data->mlx, "axe.xpm", &enm->img);
	set_img_size(&enm->img, 200, 160);
	enm->img.offset = 6;
	enm->img.x_off = x % 6;
}

void	load_imp(t_data *data, t_enmy *enm, int x, int y)
{
	enm->hitbox.x = x * 80 + 22;
	enm->hitbox.y = y * 80;
	enm->hitbox.width = 35;
	enm->hitbox.height = 60;
	enm->on_ground = false;
	enm->type = 1;
	enm->vx = 0;
	enm->vy = 0;
	enm->g = GRAVITY;
	set_img(data->mlx, "imp.xpm", &enm->img);
	set_img_size(&enm->img, 200, 160);
	enm->img.offset = 6;
	enm->img.x_off = x % 6;
}
// set_img(data->mlx, "ply.xpm", &enm->hb);
// set_img_size(&enm->hb, 40, 65);

void	load_enemy(t_data *data, t_scene *scn)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	init_enemy(scn);
	while (scn->map.map[i])
	{
		j = 0;
		while (scn->map.map[i][j] != -1)
		{
			if (scn->map.map[i][j] == 3)
			{
				load_imp(data, &scn->enm[e], j, i);
				e++;
			}
			if (scn->map.map[i][j] == 4)
			{
				load_axe(data, &scn->enm[e], j, i);
				e++;
			}
			j++;
		}
		i++;
	}
}
