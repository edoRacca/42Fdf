/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 08:05:54 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 11:42:50 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/includes/ft_printf.h"
# include "keys.h"
# include "colors.h"
# include <math.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*---STRUCTS---*/

typedef struct s_point 
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

typedef struct s_map
{
	t_point	**cordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}				t_map;

/*
** Current line being printed
*/
typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	transform_z;
}				t_line;

/*
** Color struct (valid for t_line)
*/
typedef struct s_color
{
	int	start_color;
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_color;
	int	end_r;
	int	end_g;
	int	end_b;
	int	delta_r;
	int	delta_g;
	int	delta_b;
}				t_color;

/*
** Image data struct (same of t_data example)
*/

typedef struct s_image {
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_line	*line;
}				t_image;

/*
** Camera data struct: holds information about displayed image, 
** such as type of projection, scale, translation delta and 
** angle values for rotation on 3 axis
*/

typedef struct s_cam
{
	int		projection;
	int		color_pallet;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}				t_cam;

/*
** fdfd data struct: holds all necessary information for the fdf
** program to run, so it's made easier to pass reference by sub-function
*/

typedef struct s_fdf
{
	t_map	*map;
	void	*mlx;
	int		win_x;
	int		win_y;
	void	*win;
	t_image	*image;
	t_cam	*cam;
}				t_fdf;

/*---MACROS---*/

/*
** Window config
*/

# define WIN_NAME	"fdf - eraccane"
# define WIN_WIDTH	1920
# define WIN_HEIGHT	900
# define MAX_PIXEL	1080000

/*
** Colors
*/

# define LINE_DEFAULT		C_PINK
# define BACKGROUND_DEFAULT	C_BLUE_B
# define C_TEXT				C_WHITE

/*
** Conversion bases & useful angles in rad
*/

# define HEXADECIMAL_L_BASE	"0123456789abcdef"
# define ANG_1				0.01745329
# define ANG_30				0.52359877
# define ANG_45				0.78539816

/*
** Enumerator for projection names and boolean
*/

enum e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	TOP
};

enum e_bool
{
	FALSE,
	TRUE
};

/*---FUNCTIONS---*/

//main.c
int		expose_handle(t_fdf *fdf);

//ft_close.c
void	ft_close_window(t_fdf *fdf);
void	ft_close_cordinates(t_point **cordinates, int width);
void	ft_close_all(t_fdf *fdf, int code);
void	ft_close_map(t_fdf *fdf, int code);

//ft_colors.c
int		ft_gradient(t_color *color, float progress);
int		ft_get_color(t_color *color, int i_line, int line_size);
t_color	*ft_color_init(t_point start, t_point end);
t_color	*ft_color_pallet_init(int min_color, int max_color);
void	ft_put_color(t_fdf *fdf, t_point *point);

//ft_draw_map.c
void	ft_pixel_to_image(t_image *image, float x, float y, int color);
void	ft_bresenham(t_fdf *fdf, t_point start, t_point end);
void	ft_clear_image(t_image *image, int image_size);

//ft_error.c
void	error(int code);

//ft_get_points.c
void	ft_fill_points(char *point, t_map *map, int coord_x, int coord_y);
void	ft_get_points(char *filename, t_map *map);

//ft_hook.c
void	ft_key_project(int keycode, t_fdf *fdf);
void	ft_key_rotate(int keycode, t_fdf *fdf);
void	ft_key_scale(int keycode, t_fdf *fdf);
void	ft_key_translate(int keycode, t_fdf *fdf);
int		ft_press_button(int keycode, t_fdf *fdf);

//ft_init_cordinates.c
t_point	**ft_init_cordinates(int width, int height);
float	scale_to_fit(t_map *map);
void	ft_reset(t_fdf *fdf);

//ft_init_fdf.c
t_image	*ft_init_image(void *mlx);
t_cam	*ft_init_cam(t_map *map);
t_fdf	*ft_init_fdf(char *filename);
t_map	*ft_init_map(void);
t_line	*ft_init_line(t_fdf *fdf, t_point start, t_point end);

//ft_menu.c
char	*ft_get_projection_name(t_fdf *fdf);
void	ft_print_menu(t_fdf *fdf);

//ft_projection.c
void	ft_perspective(t_line *line);
void	ft_isometric(t_line *line);
void	ft_projection(t_cam *cam, t_line *line);

//ft_read_map.c
int		ft_get_height(char *filename);
int		ft_get_width(char *filename);
void	ft_center_origin(t_map *map);
int		ft_check_fdf_file(char *av);
t_map	*ft_read_map(char *filename, t_fdf *fdf);

//ft_render.c
void	ft_put_color(t_fdf *fdf, t_point *point);
void	ft_render_line(t_fdf *fdf, t_point start, t_point end);
void	ft_render(t_fdf *fdf);

//ft_rotate.c
void	ft_rotate_z(t_line *line, double angle);
void	ft_rotate_y(t_line *line, double angle);
void	ft_rotate_x(t_line *line, double angle);
void	ft_rotate(t_cam *cam, t_line *line);

//ft_transform.c
void	ft_translate(t_line *line, int move_x, int move_y);
void	ft_scale(t_line *line, int scale_factor);
void	ft_transform(t_cam *cam, t_line *line);

//ft_utils_math.c
float	absolute(float nbr);
float	max(float a, float b);
float	min(float a, float b);

//ft_utils.c
int		ft_convert_from_base(char *str, char *base);
int		ft_check_base_error(char *str);
int		ft_atoi_base(char *str, char *base);
size_t	ft_split_count(const char *s, char c);

#endif