/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   souls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:05:30 by ebigotte          #+#    #+#             */
/*   Updated: 2025/10/01 10:41:11 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	init_souls(t_scene *scn)
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
			if (scn->map.map[i][j] == 5)
				c++;
			j++;
		}
		i++;
	}
	scn->nb_souls = c;
	scn->souls = ft_calloc(c + 1, sizeof(t_rect));
}

void	load_soul(t_obj *soul, int x, int y)
{
	soul->hb.x = x * 80;
	soul->hb.y = y * 80 + 30;
	soul->hb.width = 64;
	soul->hb.height = 64;
	soul->a = 0;
	soul->th = 0.025;
}

void	load_souls(t_data *data, t_scene *scn)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	init_souls(scn);
	set_img(data->mlx, "souls.xpm", &scn->soul);
	set_img_size(&scn->soul, 64, 64);
	scn->soul.offset = 5;
	while (scn->map.map[i])
	{
		j = 0;
		while (scn->map.map[i][j] != -1)
		{
			if (scn->map.map[i][j] == 5)
			{
				load_soul(&scn->souls[s], j, i);
				s++;
			}
			j++;
		}
		i++;
	}
}
