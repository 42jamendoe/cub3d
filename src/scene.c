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

void	ft_identify_line(t_cub3d *cub3d, char *line)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	printf("number = %zu\n", line_len);
	printf("line[0] %c, line[1] %c\n", line[0], line[1]);
	if ((int)line_len > 2)
	{
		if (line[0] == 'N' && line[1] == 'O')
		{
			printf("entrou no fim\n");
			//cub3d->texture->north = line;
			printf("saiu no fim\n");
		}
		else if (line[0] == 'S' && line[1] == 'O')
			cub3d->texture->south = &(*line);
		else if (line[0] == 'W' && line[1] == 'E')
			cub3d->texture->west = line;
		else if (line[0] == 'E' && line[1] == 'A')
			cub3d->texture->east = line;
		else if (line[0] == 'F' || line[1] == 'C')
			;//ft_define_color(line);
		else if (line[0] == '0' || line[1] == '1' || line[0] == 'N' || line[1] == 'S' || line[0] == 'W' || line[1] == 'E' || line[0] == ' ' || line[1] == '\t')
		{
			cub3d->map_len++;
			if ((int)line_len > cub3d->map_width)
				cub3d->map_width = (int)line_len;
			free(line);
		}
	}
	printf("passou o identify line\n");
}

int	ft_read_textures(t_cub3d *cub3d, char *scene)
{
	char	*line;
	char	*trim_line;
	int		scene_fd;

	scene_fd = open(scene, O_RDWR);
	while (1)
	{
		line = get_next_line(scene_fd);
		// printf("1.2.\n");
		// write(STDOUT_FILENO, line, sizeof(line));
		// printf("\n\n");
		// printf("2.%s", line);
		if (!line)
			break ;
		//printf("passou o line\n");
		if (line[0] != '\n')
		{
			//printf("%c \n", line[0]);
			trim_line = ft_strtrim(line, "\n");
			free(line);
			if (!trim_line)
				break ;
			printf("tim_line: %s\n", trim_line);
			ft_identify_line(cub3d, trim_line);
		}
		else
			free(line);
		printf("passou o line trim\n");
	}
	printf("fechou\n");
	close(scene_fd);
	return (0);
}

int	ft_read_scene(t_cub3d *cub3d, int argc, char *argv)
{
	int	pos;

	(void) cub3d;
	pos = 0;
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	pos = ft_strlen(argv) - 4;
	if (ft_strncmp(&argv[pos], ".cub", 4))
	{
		printf("Error\nInvalid map extention\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
