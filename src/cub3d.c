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

void	ft_init_cube(t_cub3d *cub3d)
{
	t_texture *tmp;
	cub3d = (t_cub3d *) malloc (sizeof(t_cub3d));
	tmp = (t_texture *) malloc (sizeof(t_texture));
	
	(*cub3d).texture = tmp;
	//cub3d->texture = tmp;
	cub3d->map_width = 0;
	//printf("termina o init0\n");
	cub3d->map_len = 0;
	//printf("termina o init1\n");
	cub3d->texture->north = NULL;
	cub3d->texture->south = NULL;
	cub3d->texture->west = NULL;
	cub3d->texture->east = NULL;
	//printf("termina o init\n");
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = NULL;
	if (ft_check_arg(argc, argv))
		return (EXIT_FAILURE);
	if (ft_read_scene(cub3d, argc, argv[1]))
		return (EXIT_FAILURE);
	ft_init_cube(cub3d);
	ft_read_textures(cub3d, argv[1]);

	return (0);
}
