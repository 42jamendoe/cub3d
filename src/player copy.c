/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"
#include "../includes/libft.h"

void    ft_set_orientation(t_cub3d *cub3d, char orientation)
{
    if (orientation == 'N' || orientation == 'S')
    {
        cub3d->fieldov_y = 0;
        cub3d->vision->x = 0;
        if (orientation == 'N')
        {
            cub3d->fieldov_x = 0.6;
            cub3d->vision->y = -1;
        }
        else
        {
            cub3d->fieldov_x = -0.6;
            cub3d->vision->y = 1;
        }
    }
    if (orientation == 'E' || orientation == 'W')
    {
        cub3d->fieldov->x = 0;
        cub3d->vision->y = 0;
        if (orientation == 'E')
        {
            cub3d->fieldov->y = -0.6;
            cub3d->vision->x = 1;
        }
        else
        {
            cub3d->fieldov->y = 0.6;
            cub3d->vision->x = -1;
        }
    }
}



void ft_load_player(t_cub3d *cub3d)
{
    int i;

    i = 0;
    while (cub3d->map[i] != '\0')
    {
        if (cub3d->map[i] == 'N' || cub3d->map[i] == 'S' || cub3d->map[i] == 'W' || cub3d->map[i] == 'E')
        {
            cub3d->player_x = (i % (cub3d->map_width - 1) + 0.5);
            cub3d->player_y = (i / (cub3d->map_width - 1) + 0.5);
            cub3d->orientation = cub3d->map[i];
            break ;
        }
        i++;
    }
}