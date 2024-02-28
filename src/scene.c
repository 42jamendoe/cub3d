/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"
#include "../includes/libft.h"

void ft_build_map(t_cub3d *cub3d, char *line, int *nlin)
{
	int i;

	i = 0;
	if ((line[0] == 'N' && line[1] == 'O') || (line[0] == 'S' && line[1] == 'O') || (line[0] == 'W' && line[1] == 'E') \
	|| (line[0] == 'E' && line[1] == 'A') || (line[0] == 'F' || line[1] == 'C'))
		;//ft_define_color(line);
	else if (line[0] == '0' || line[0] == '1' || line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E' || line[0] == ' ' || line[0] == '\t')
	{
		while (line[i] && i < cub3d->map_width - 1)
		{
			cub3d->map[i + (*nlin) * (cub3d->map_width - 1)] = line[i];
			i++;
		}
		(*nlin)++;
	}
	free(line);
}



void	ft_identify_line(t_cub3d *cub3d, char *line)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	if (line[0] == 'N' && line[1] == 'O')
		cub3d->texture->north = ft_substr(line, 3, line_len - 4);
	else if (line[0] == 'S' && line[1] == 'O')
		cub3d->texture->south = ft_substr(line, 3, line_len - 4);
	else if (line[0] == 'W' && line[1] == 'E')
		cub3d->texture->west = ft_substr(line, 3, line_len - 4);
	else if (line[0] == 'E' && line[1] == 'A')
		cub3d->texture->east = ft_substr(line, 3, line_len - 4);
	else if (line[0] == 'F' || line[1] == 'C')
		;//ft_define_color(line);
	else if (line[0] == '0' || line[0] == '1' || line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E' || line[0] == ' ' || line[0] == '\t')
	{
		cub3d->map_len++;
		if ((int)line_len > cub3d->map_width)
			cub3d->map_width = (int)line_len;
	}
	free(line);
}

int	ft_read_textures(t_cub3d *cub3d, char *scene, int stage)
{
	char	*line;
	int		scene_fd;
	int		nlin;

	scene_fd = open(scene, O_RDWR);
	nlin = 0;
	while (1)
	{
		line = get_next_line(scene_fd);
		if (!line)
			break ;
		if (line[0] != '\n')
		{
			if (stage == 0)
				ft_identify_line(cub3d, line);
			else
				ft_build_map(cub3d, line, &nlin);
		}
		else
			free(line);
	}
	close(scene_fd);
	return (0);
}

int	ft_read_scene(t_cub3d *cub3d, int argc, char *argv)
{
	char *tmp;
	void *screenshoot;
	void *frame;
	
	(void) argc;
	ft_read_textures(cub3d, argv, 0);
	printf("witdh: %d, len: %d\n", cub3d->map_width, cub3d->map_len);
	tmp = (char *) ft_calloc ((cub3d->map_width) * cub3d->map_len + 1, sizeof(char));
	tmp[cub3d->map_width * cub3d->map_len + 1] = '\0';
	printf("%p\n", &tmp);
	cub3d->map = tmp;
	printf("%p\n", &cub3d->map);
	ft_read_textures(cub3d, argv, 1);
	ft_get_deltas(cub3d);
	ft_initial_lens(cub3d);
	printf("side x: %f side y: %f\n", cub3d->side_x, cub3d->side_y);
	printf("side x: %f side y: %f\n", cub3d->side_x, cub3d->side_y);
	cub3d->mlx = mlx_init();
	screenshoot = mlx_new_window(cub3d->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	frame = mlx_new_image(cub3d->mlx, 800, 600);
	mlx_put_image_to_window(cub3d->mlx, screenshoot, frame, 0, 0);
	mlx_loop(cub3d->mlx);
	//ft_load_player(cub3d);
	ft_print_debug(cub3d);
	return (EXIT_SUCCESS);
}
