/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"
#include "../includes/libft.h"

char	*ft_join(int *file)
{
	char	*tmp;
	char	*line;
	char	*map;
	int		reset;

	map = ft_strdup("");
	reset = 0;
	while (reset == 0)
	{
		line = get_next_line(*file);
		if (!line)
			reset = 1;
		else
		{
			tmp = ft_strdup(map);
			free(map);
			map = ft_strjoin(tmp, line);
			free(tmp);
		}
		free(line);
	}
	return (map);
}

char	*ft_read_map_file(char *path)
{
	int		file;
	char	*read_map;

	file = open(path, O_RDONLY);
	if (file < 1)
		exit(EXIT_FAILURE);
	read_map = ft_join(&file);
	return (read_map);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*cub3d_fv;
	t_game	game;
	double x_screen;
	int x;
	x = 0;
	void	*frame;
	char *frame_c;
	char *map;
	int bpp;
	int size_line;
	int endian;

	mlx_t

	(void) game;
	(void) argc;
	(void) argv;

	if(argc < 2)
		perror("You didn't especify any map");
	else
	{
	mlx = mlx_init();
	cub3d_fv = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	frame = mlx_new_image(mlx, 800, 600);
	frame_c = mlx_get_data_addr(frame, &bpp, &size_line, &endian);
	map = ft_read_map_file()
	while (x < SCREEN_WIDTH)
	{
		x_screen = x * 2 / SCREEN_WIDTH - 1;
		x++;
	}
	mlx_put_image_to_window(mlx, cub3d_fv, frame, 0, 0);
	mlx_pixel_put(mlx, cub3d_fv, 5, 5, 0xFFFFFF);
	mlx_loop(mlx);
	(void)cub3d_fv;
	(void)x_screen;
	(void)frame_c;
	//printf("Hello World\n");
	}
	return (0);
}
