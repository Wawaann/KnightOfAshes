/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:08:47 by ebigotte          #+#    #+#             */
/*   Updated: 2025/08/29 16:30:00 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	convert_map(t_map *map, char *line, int fd)
{
	int	a;
	int	i;
	int	j;

	map->map = ft_calloc(17, sizeof(int *));
	map->width = ft_strlen(line + 1) - 1;
	j = 0;
	while (line)
	{
		a = 1;
		i = 0;
		map->map[j] = ft_calloc(map->width, sizeof(int));
		map->map[j][map->width - 1] = -1;
		while (line[a] != '2')
		{
			if (line[a] == 'P')
				map->map[j][i] = 2;
			else if (line[a] == 'I')
				map->map[j][i] = 3;
			else if (line[a] == 'A')
				map->map[j][i] = 4;
			else if (line[a] == 'S')
				map->map[j][i] = 5;
			else
				map->map[j][i] = line[a] - '0';
			if (line[a] == '1')
				map->hitbox++;
			i++;
			a++;
		}
		free(line);
		line = get_next_line(fd);
		j++;
	}
}

void	get_map(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: file '%s' doesn't exist\n", file);
		exit(0);
	}
	line = get_next_line(fd);
	map->asset = ft_strtrim(line, "\n");
	map->hitbox = 0;
	free(line);
	line = get_next_line(fd);
	convert_map(map, line, fd);
}

void	load_scene(t_data *data)
{
	char	*nb;
	char	*level;

	data->scn.camera = 0;
	nb = ft_itoa(data->lvl);
	level = ft_calloc(12, sizeof(char));
	ft_strlcpy(level, "./map/", 12);
	ft_strlcat(level, nb, 12);
	ft_strlcat(level, ".ber", 12);
	get_map(&data->scn.map, level);
	free(nb);
	free(level);
	set_img(data->mlx, data->scn.map.asset, &data->scn.img);
	set_img_size(&data->scn.img, data->scn.map.width * 80, 960);
	load_souls(data, &data->scn);
	load_player(data);
	load_enemy(data, &data->scn);
	load_hitbox(&data->scn);
}

// for (int a = 0; a < 2; a++)
// {
// 	printf("asset: %s\n", data->scn[a].map.asset);
// 	printf("width: %d\n", data->scn[a].map.width);
// 	for (int i = 0; data->scn[a].map.map[i]; i++)
// 	{
// 		for (int j = 0; data->scn[a].map.map[i][j] != -1; j++)
// 		{
// 			printf("%d ", data->scn[a].map.map[i][j]);
// 		}
// 		printf("\n");
// 	}
// }