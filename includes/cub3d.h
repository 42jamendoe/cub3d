/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:00:55 by jamendoe          #+#    #+#             */
/*   Updated: 2023/04/14 21:01:00 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define SCREEN_HEIGHT 600
# define SCREEN_WIDTH 800

typedef struct s_coord{
	double	x;
	double	y;
}	t_coord;

typedef struct s_line{
	double	x;
	double	y;
	double	y_begin;
	double	y_end;
	double	x_texture;
	double	y_texture;
}	t_line;

typedef struct s_texture{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
}	t_texture;

typedef struct s_img{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_tiles{
	t_img	bg;
	t_img	floor;
	t_img	collectible;
	t_img	player;
	t_img	exit;
	t_img	wall;
}	t_tiles;

typedef struct s_collectible{
	t_coord					place_c;
	int						show;
	struct s_collectible	*next;
}	t_collectible;

typedef struct s_cub3d{

	t_coord			*player;
	t_coord			*vision;
	t_coord			*fieldov;
	t_texture		*texture;
	int				map_width;
	int				map_len;
	void			*mlx;
	void			*window;
	char			**map;
	char			**map_path;
	t_coord			size;
	//t_coord			player;
	int				collectibles_number;
	int				moves;
	int				path_map_ok;
	int				tile_size;
	int				win_end;
	t_collectible	*collectible_list;
	t_tiles			tile;
}	t_cub3d;

int		ft_check_arg(int argc, char **argv);
char	*get_next_line(int fd);
char	*ft_buffer(int fd, char *buffer);
char	*ft_next_line(char *buffer);
char	*ft_next_buffer(char *buffer);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_line_len(char *buffer);
int		ft_line_break(char *buffer);
char	*ft_new_buffer(char *buffer, char *nextbuffer, int i, int buffer_len);
int 	ft_read_scene(t_cub3d *cub3d, int argc, char *argv);
int		ft_read_textures(t_cub3d *cub3d, char *scene);
t_cub3d	*ft_init_cube(t_cub3d *cub3d);
int		ft_check_arg(int argc, char **argv);

#endif
