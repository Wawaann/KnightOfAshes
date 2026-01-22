/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ply_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:18:30 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/02 11:26:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	jump(t_ply *ply)
{
	if (ply->on_ground)
	{
		ply->vy = -18;
		ply->on_ground = false;
		ply->prev_input = true;
		ply->action = A_JUMP;
	}
}

void	roll(t_ply *ply)
{
	ply->prev_input = true;
	ply->action = A_ROLL;
}

void	attak(t_ply *ply, t_action atk)
{
	ply->prev_input = true;
	ply->action = atk;
}
