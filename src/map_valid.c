/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:42:46 by bmartin           #+#    #+#             */
/*   Updated: 2023/02/06 14:21:40 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_valid(void)
{
	t_data	*var;

	var = get_data();
	map_valid_length();
	map_valid_char();
	map_valid_char_count();
	map_valid_line_length();
	map_valid_border();
	get_tmp_value();
	if (floodfill(var->tmp_player_position_x, var->tmp_player_position_y, var)
		!= 0)
		print_no_floodfill();
	if (var->flag_exit != 1)
		print_no_floodfill();
	release((void **)var->tmp_map);
}

void	get_tmp_value(void)
{
	t_data	*var;
	int		x;
	int		y;

	var = get_data();
	y = 0;
	while (y < var->height)
	{
		x = 0;
		while (x < var->width)
		{
			if (var->tmp_map[y][x] == 'P')
			{
				var->tmp_player_position_x = x;
				var->tmp_player_position_y = y;
			}
			if (var->tmp_map[y][x] == 'C')
				var->collectable_count++;
			x++;
		}
		y++;
	}
}

int	floodfill(int x, int y, t_data *var)
{
	static int	coll_nbr = -1;

	if (coll_nbr == -1)
		coll_nbr = var->collectable_count;
	if (x >= 0 && x <= var->width && y >= 0 && y <= var->height)
	{
		if (var->tmp_map[y][x] == 'X')
			return (coll_nbr);
		else
		{
			if (var->tmp_map[y][x] == 'C')
				coll_nbr--;
			else if (var->tmp_map[y][x] == '1')
				return (coll_nbr);
			else if (var->tmp_map[y][x] == 'E')
				var->flag_exit = 1;
			var->tmp_map[y][x] = 'X';
		}
		floodfill(x + 1, y, var);
		floodfill(x, y + 1, var);
		floodfill(x - 1, y, var);
		floodfill(x, y - 1, var);
	}
	return (coll_nbr);
}
