/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:47:56 by ebigotte          #+#    #+#             */
/*   Updated: 2025/10/01 10:47:14 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	init_data(t_data *data)
{
	int		i;
	char	*title;

	i = 0;
	while (i < KEY_COUNT)
	{
		data->keys[i] = false;
		i++;
	}
	gettimeofday(&data->clock.tv, NULL);
	title = "Knight of Ashes";
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	data->bg = ft_calloc(4, sizeof(t_img));
	data->lvl = 0;
}

void	run_game(t_data *data)
{
	load_img(data);
	load_scene(data);
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 3, 1L << 1, key_released, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_loop_hook(data->mlx, update_game, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 1)
	{
		ft_putendl("Error\nUsage: no arguments are required");
		return (0);
	}
	init_data(&data);
	run_game(&data);
	return (0);
}
