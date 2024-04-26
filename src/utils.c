/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:31:45 by bmartin           #+#    #+#             */
/*   Updated: 2023/02/06 15:18:09 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(int x, int y)
{
	t_data	*var;

	var = get_data();
	var->player_position_x = x;
	var->player_position_y = y;
}

void	collectable_left(t_data *var)
{
	int			c;
	static bool	done;

	c = 0;
	var->y = 0;
	while (var->y < var->width)
	{
		var->x = 0;
		while (var->x < var->height)
		{
			if (var->map[var->x][var->y] == 'C')
				c++;
			var->x++;
		}
		var->y++;
	}
	if (!done)
	{
		var->collectable_count = c;
		var->collectable_left = c;
		done = 1;
	}
	else
		var->collectable_left = c;
}

char	**strdup_2d(char **str, int height)
{
	char	**copy;
	int		i;
	t_data	*var;

	var = get_data();
	copy = (char **)ft_calloc((height * var->width) + 1, sizeof(char *));
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(str[i]);
		i++;
	}
	return (copy);
}
