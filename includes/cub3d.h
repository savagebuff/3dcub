/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:20:39 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 20:12:47 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 250
# endif

# define HEIGHT 1080
# define WIDTH 1920

# define C_ID		1
# define F_ID		2
# define NO_ID		4
# define SO_ID		8
# define WE_ID		16
# define EA_ID		32
# define MP_ID		64
# define PL_ID		128

# define PL_SZ		2
# define G_BS		50
# define MOV_SPD	0.2
# define ROT_SPD	0.1
# define TEX_WID	64
# define TEX_HEI	64

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_path
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*sprite;
}					t_path;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct s_player
{
	t_vec			pos;
	t_vec			dir;
	t_vec			pln;
}					t_player;

typedef struct s_sprite
{
	t_vec			trans;
	t_vec			pos;
	t_point			d_s;
	t_point			d_e;
	t_point			txt;
	double			dis;
	int				dim;
	int				order;
	int				scr_x;
}					t_sprite;

typedef struct s_parse
{
	int				ids;
	int				spr_num;
	t_path			paths;
	t_rgb			floor;
	t_rgb			ceiling;
	t_player		ply;
	t_sprite		*sprites;
	char			**map;
}					t_parse;

typedef struct s_mapll
{
	char			*line;
	int				i;
	int				n;
	struct s_mapll	*next;
}					t_mapll;

typedef struct s_img
{
	int				bpp;
	int				size_line;
	int				endian;
	void			*img;
	char			*data;
}					t_img;

typedef struct s_text
{
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	void			*img;
	char			*data;
}					t_text;

typedef struct s_keys
{
	int				w_k;
	int				a_k;
	int				s_k;
	int				d_k;
	int				l_k;
	int				r_k;
	int				esc;
}					t_keys;

typedef struct s_cam
{
	t_vec			sidedist;
	t_vec			deltadist;
	t_vec			ray;
	t_point			step;
	t_point			map;
	t_point			texture;
	double			camera;
	double			pwd;
	double			wallx;
	double			texstep;
	double			texpos;
	double			*z_buff;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
}					t_cam;

typedef struct s_cub
{
	void			*mlx;
	void			*mlx_win;
	t_keys			keys;
	t_img			image;
	t_text			text[5];
	t_cam			cam;
	t_parse			parse;
}					t_cub;

// parsing
int			ft_extension(char *path, char *text);
int			get_next_line(int fd, char **line, int ret);
char		*ft_strndup(const char *src, int n);
void		ft_parsing(char *path, t_cub *cub);
void		ft_arrdel(char ***arr);
void		ft_str_free(char **s);
int			ft_array_len(char **arr);
int			ft_quit(char *msg, char *path, t_cub *cub);
int			ft_check_last_line(t_mapll *map);
int			ft_listlen(t_mapll *map);
void		ft_clear_game(t_cub *cub);
t_parse		ft_struct_init(void);
t_path		ft_init_path(void);
t_rgb		ft_init_color(void);
t_player	ft_init_player(void);
char		**ft_split_whitespaces(char *s, int i, int j, int in);
int			ft_is_id(char *c, int ids);
t_sprite	*ft_sprite_fill(t_parse *parse);
t_rgb		ft_color_fill(char *str, t_cub *cub);
char		*ft_path_fill(char *str, t_cub *cub);
void		ft_map_fill2(char *line, t_cub *cub, t_mapll *map);
t_mapll		*new_node(char *line, t_mapll *prv);
int			ft_check_end(t_mapll *tmp, int n);
char		**ft_map_convert(t_mapll *map);
void		ft_map_fill(int fd, t_cub *cub);
void		ft_check_store(char *line, t_cub *cub, t_mapll **map);
void		ft_check_space(t_mapll *tmp, char *line, int i, t_cub *cub);
void		ft_twod_check(t_mapll *tmp, char *line, int i, t_cub *cub);
int			ft_is_valid(char c);
t_player	ft_fill_player(t_parse *parse, t_mapll *tmp, char *line, int i);
t_vec		ft_fill_position(int a, int b);

// ray_casting
int			ft_ray_casting(t_cub *cub);
void		ft_texture_init(t_cub *cub);
void		ft_check_assign(t_cub *cub, int n, char *path);
void		delta(t_cub *cub, int i);
void		side_distance(t_cub *cub);
void		wall(t_cub *cub);
void		rendering(t_cub *cub, int n);
void		sprites(t_cub *cub);
void		sprite_render(t_cub *cub, int i);
int			key_press(int keycode, t_cub *cub);
int			key_release(int keycode, t_cub *cub);
int			key_close(t_cub *cub);
void		wall_rendering(t_cub *cub, int x, int y, int n);
void		pixel_fill(t_cub *cub, int x, int y, int color);
void		dda(t_cub *cub);
int			mv_manager(t_cub *cub);
void		move(t_cub *cub, t_vec pos, t_vec vec, double mov_spd);
void		rotate(t_cub *cub, double rot_spd);

#endif