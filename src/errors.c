/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"
#include "../includes/libft.h"

int ft_check_arg(int argc, char **argv)
{
	int	pos;

	pos = 0;
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	pos = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(&argv[1][pos], ".cub", 4))
	{
		printf("Error\nInvalid map extention\n");
		return (EXIT_FAILURE);
	}		
	return (EXIT_SUCCESS);
}
