/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:52:57 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/02 11:28:22 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

float	get_time(void)
{
	static struct timeval	s;
	struct timeval			now;
	float					time;

	if (s.tv_sec == 0 && s.tv_usec == 0)
		gettimeofday(&s, NULL);
	gettimeofday(&now, NULL);
	time = (now.tv_sec - s.tv_sec) + (now.tv_usec - s.tv_usec) / 1000000.0f;
	return (time);
}

void	add_input(t_ply *ply, t_action action, float time)
{
	if (ply->input_count >= INPUT_BUFFER_SIZE)
		return ;
	// ft_printf("add input: %d, %d\n", action, (int)time);
	ply->input[ply->input_count].action = action;
	ply->input[ply->input_count].time = time;
	ply->input_count++;
}

void	update_input(t_data *data)
{
	if (data->keys[KEY_Q])
		add_input(&data->ply, A_ATK1, get_time());
	if (data->keys[KEY_W])
		add_input(&data->ply, A_ATK2, get_time());
	if (data->keys[KEY_E])
		add_input(&data->ply, A_ROLL, get_time());
	if (data->keys[KEY_SPACE])
		add_input(&data->ply, A_JUMP, get_time());
}

void process_input(t_data *data, float time_now)
{
	int i;

	if (data->ply.input_count == 0)
		return;
	t_input *input = &data->ply.input[0];
	if (time_now - input->time > INPUT_BUFFER_TIME)
	{
		for (i = 0; i < data->ply.input_count; i++)
			data->ply.input[i] = data->ply.input[i + 1];
		data->ply.input_count--;
		return;
	}
	if (data->ply.prev_input)
		return ;
	if (input->action == A_ATK1)
		attak(&data->ply, A_ATK1);
	if (input->action == A_ATK2)
		attak(&data->ply, A_ATK2);
	if (input->action == A_ROLL)
		roll(&data->ply);
	if (input->action == A_JUMP)
		jump(&data->ply);
	for (i = 0; i < data->ply.input_count; i++)
		data->ply.input[i] = data->ply.input[i + 1];
	data->ply.input_count--;
}
