/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:45:32 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/02 16:30:00 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

t_rect	*new_rect(int x, int y, int width, int height)
{
	t_rect	*rect;

	rect = ft_calloc(1, sizeof(t_rect));
	rect->x = x;
	rect->y = y;
	rect->width = width;
	rect->height = height;
	return (rect);
}

void	load_hitbox(t_scene *scn)
{
	int	i;
	int	j;
	int	h;

	i = 0;
	h = 0;
	scn->hitbox = ft_calloc(scn->map.hitbox + 1, sizeof(t_rect *));
	while (scn->map.map[i])
	{
		j = 0;
		while (scn->map.map[i][j] != -1)
		{
			if (scn->map.map[i][j] == 1)
			{
				scn->hitbox[h] = new_rect(j * 80, (i * 80) + 15, 80, 80);
				h++;
			}
			j++;
		}
		i++;
	}
}
