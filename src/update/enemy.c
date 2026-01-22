/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:39:44 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/08 13:25:35 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	can_move_y(t_scene *scn, t_enmy *enm, float x, float new_y)
{
	int		i;
	float	vy;

	i = 0;
	vy = enm->vy + enm->g;
	enm->on_ground = false;
	while (scn->hitbox[i])
	{
		if (is_intersect(scn->hitbox[i], enm->hitbox, x, new_y + vy))
		{
			enm->vy = 0;
			enm->g = GRAVITY;
			if (enm->hitbox.y > new_y)
				new_y = scn->hitbox[i]->y + scn->hitbox[i]->height;
			else
			{
				new_y = scn->hitbox[i]->y - enm->hitbox.height;
				enm->on_ground = true;
			}
			break ;
		}
		i++;
	}
	enm->hitbox.y = new_y;
}

void	update_enemy(t_scene *scn, t_enmy *enm, t_ply *ply)
{
	float	new_posx;
	float	new_posy;
	(void)ply;

	new_posx = enm->hitbox.x;
	new_posy = enm->hitbox.y;
	if (!enm->on_ground)
	{
		enm->vy += enm->g;
		enm->g *= 1.07;
	}
	new_posy += enm->vy;
	can_move_y(scn, enm, enm->hitbox.x, new_posy);
}

void	update_enemys(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->scn.nb_enm)
	{
		update_enemy(&data->scn, &data->scn.enm[i], &data->ply);
		i++;
	}
}
