/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:46:06 by ebigotte          #+#    #+#             */
/*   Updated: 2025/10/01 10:51:56 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include "../.lib/include/libft.h"
# include "../../.mlx/mlx.h"
# include "key.h"

# include <sys/time.h>

# define FPS 16667
# define ACCEL 3.0
# define FRICTION 3.1
# define VMAX 14
# define ROLL_SPEED 20
# define GRAVITY 1.2
# define G_MAX 4.2
# define WIDTH 1280
# define HEIGHT 960
# define INPUT_BUFFER_SIZE 10
# define INPUT_BUFFER_TIME 0.7f
# define PI 3.1415926535

typedef struct s_clock
{
	struct timeval	tv;
	struct timeval	tv2;
}					t_clock;

typedef struct s_input
{
	int			action;
	float		time;
}				t_input;

typedef struct s_rect
{
	float		x;
	float		y;
	int			width;
	int			height;
}				t_rect;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	int			offset;
	int			x;
	int			y;
	int			x_off;
	int			y_off;
	bool		flip;
	t_clock		clock;
}				t_img;

typedef struct s_map
{
	char		*asset;
	int			hitbox;
	int			**map;
	int			width;
}				t_map;

typedef struct s_obj
{
	float		a;
	float		th;
	t_rect		hb;
}				t_obj;

typedef	struct s_enmy
{
	bool		on_ground;
	int			type;
	float		vx;
	float		vy;
	float		g;
	t_rect		hitbox;
	t_img		img;
	t_img		hb;
}				t_enmy;

typedef struct s_scene
{
	int			camera;
	int			nb_enm;
	int			nb_souls;
	t_rect		**hitbox;
	t_obj		*souls;
	t_enmy		*enm;
	t_map		map;
	t_img		img;
	t_img		soul;
}				t_scene;

typedef struct s_ply
{
	bool		on_ground;
	bool		prev_input;
	float		vy;
	float		vx;
	int			dir_x;
	float		g;
	int			sx;
	int			sy;
	int			input_count;
	t_action	action;
	t_state		state;
	t_rect		hitbox;
	t_img		h;
	t_img		img;
	t_input		input[INPUT_BUFFER_SIZE];
}				t_ply;

typedef struct s_data
{
	bool		keys[KEY_COUNT];
	t_clock		clock;
	void		*mlx;
	void		*win;
	int			lvl;
	t_scene		scn;
	t_ply		ply;
	t_img		frame;
	t_img		hitbox;
	t_img		*bg;
}				t_data;

//	Action ply
void		attak(t_ply *ply, t_action atk);
void		jump(t_ply *ply);
void		roll(t_ply *ply);

//	Close
int			close_win(t_data *data);

//	Render
uint32_t	get_pixel_color(t_img const *texture, int x, int y);
void		animate(t_img *img, int time);
void		put_bg_pixel(t_img *dest, int x, int y, uint32_t pixel);
void		draw_bg(t_data *data);
void		draw_enemy(t_data *data);
void		draw_img(t_img *frame, t_img *img, int x_off, int y_off);
void		draw_flip_img(t_img *frame, t_img *img, int x_off, int y_off);
void		draw_scene(t_data *data);
void		put_pixel(t_img *dest, int x, int y, uint32_t pixel);
void		render(t_data *data);
void		reset_anime(t_ply *ply, int offset);

//	Key Handler
int			key_pressed(int keycode, t_data *data);
int			key_released(int keycode, t_data *data);

//	Load
t_rect		*new_rect(int x, int y, int width, int height);
void		load_enemy(t_data *data, t_scene *snc);
void		load_hitbox(t_scene *scn);
void		load_img(t_data *data);
void		load_player(t_data *data);
void		load_scene(t_data *data);
void		load_souls(t_data *data, t_scene *scn);
void		set_img(void *mlx, char *asset, t_img *img);
void		set_img_size(t_img *img, int x, int y);

//	Update
bool		is_intersect(t_rect *rect, t_rect ent, int x, int y);
int			update_game(t_data *data);
float		get_time(void);
void		action_pressed(t_data *data, t_ply *ply, t_scene *scn);
void		add_input(t_ply *ply, t_action action, float time);
void		process_input(t_data *data, float time_now);
void		update_enemys(t_data *data);
void		update_input(t_data *data);
void		update_player(t_data *data);

#endif