/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaqf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:00:55 by jmaqf             #+#    #+#             */
/*   Updated: 2023/04/14 21:01:00 by jmaqf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <mlx.h>
# include <stdio.h>

typedef struct s_coord{
	int	x;
	int	y;
}	t_coord;

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

typedef struct s_game{
	void			*mlx;
	void			*window;
	char			**map;
	char			**map_path;
	t_coord			size;
	t_coord			player;
	int				collectibles_number;
	int				moves;
	int				path_map_ok;
	int				tile_size;
	int				win_end;
	t_collectible	*collectible_list;
	t_tiles			tile;
}	t_game;

#endif
