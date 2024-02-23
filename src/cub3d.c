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

t_cub3d	*ft_init_cube(t_cub3d *cub3d)
{
	t_texture *tmp;

	cub3d = (t_cub3d *) malloc (sizeof(t_cub3d));
	if (!cub3d)
		return (NULL);
	tmp = (t_texture *) malloc (sizeof(t_texture));
	if (!tmp)
	{
		free(cub3d);
		return (NULL);
	}
	cub3d->texture = tmp;
	cub3d->map_width = 0;
	cub3d->map_len = 0;
	cub3d->texture->north = NULL;
	cub3d->texture->south = NULL;
	cub3d->texture->west = NULL;
	cub3d->texture->east = NULL;
	return (cub3d);
}

void ft_print_debug( t_cub3d *cub3d)
{
	printf("map width: %d\n", cub3d->map_width);
	printf("map lenght: %d\n", cub3d->map_len);
	printf("north: %s\n", cub3d->texture->north);
	printf("south: %s\n", cub3d->texture->south);
	printf("west: %s\n", cub3d->texture->west);
	printf("east: %s\n", cub3d->texture->east);
}


int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = NULL;
	if (ft_check_arg(argc, argv))
		return (EXIT_FAILURE);
	cub3d = ft_init_cube(cub3d);
	if (!cub3d)
		return (EXIT_FAILURE);
	if (ft_read_scene(cub3d, argc, argv[1]))
		return (EXIT_FAILURE);
	return (0);
}
