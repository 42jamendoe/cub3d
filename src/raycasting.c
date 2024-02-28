/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"
#include "../includes/libft.h"

void	ft_initial_lens(t_cub3d *cub3d)
{
	if (cub3d->vision->x < 0)
	{
		cub3d->side_x = (cub3d->player->x - (int)cub3d->player->x) * cub3d->delta_x;
	}
	if (cub3d->vision->x > 0)
	{
		cub3d->side_x = (1 - (cub3d->player->x - (int)cub3d->player->x)) * cub3d->delta_x;
	}
	if (cub3d->vision->y < 0)
	{
		cub3d->side_y = (cub3d->player->y - (int)cub3d->player->y) * cub3d->delta_y;
	}
	if (cub3d->vision->y > 0)
	{
		cub3d->side_y = (1 - (cub3d->player->y - (int)cub3d->player->y)) * cub3d->delta_y;
	}
}

void ft_get_deltas(t_cub3d *cub3d)
{
	double	handle_z;
	
	if (cub3d->vision->x == 0)
		handle_z = 1e30;
	else
		handle_z =  cub3d->vision->x; 
	cub3d->delta_x = fabs(1/handle_z);
	if (cub3d->vision->y == 0)
		handle_z = 1e30;
	else
		handle_z =  cub3d->vision->y; 
	cub3d->delta_y = fabs(1/handle_z);
}
