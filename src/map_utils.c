/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:42:43 by bmartin           #+#    #+#             */
/*   Updated: 2023/02/03 14:31:34 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_valid_length(void)
{
	t_data	*var;

	var = get_data();
	if (var->width > 40)
	{
		printf("%s", E_MAP_TOO_WIDTH);
		exit(1);
	}
	if (var->height > 21)
	{
		printf("%s", E_MAP_TOO_HEIGTH);
		exit(1);
	}
}

void	map_valid_char(void)
{
	t_data	*var;
	char	*all_char_map;
	int		i;

	var = get_data();
	i = 0;
	all_char_map = var->all_char_map;
	while (all_char_map[i])
	{
		if (all_char_map[i] != '0' && all_char_map[i] != '1'
			&& all_char_map[i] != 'E' && all_char_map[i] != 'P'
			&& all_char_map[i] != 'C' && all_char_map[i] != '\n')
		{
			printf("%s", E_CHAR_INVALID);
			exit(1);
		}
		i++;
	}
}

void	map_valid_char_count(void)
{
	t_data	*var;

	var = get_data();
	var->i = 0;
	var->e = 0;
	var->p = 0;
	var->c = 0;
	while (var->all_char_map[var->i])
	{
		if (var->all_char_map[var->i] == 'E')
			var->e++;
		if (var->all_char_map[var->i] == 'P')
			var->p++;
		if (var->all_char_map[var->i] == 'C')
			var->c++;
		var->i++;
	}
	if (var->e != 1 || var->p != 1 || var->c < 1)
	{
		printf("%s", E_CHAR_MISSING);
		exit(1);
	}
}

void	map_valid_line_length(void)
{
	t_data	*var;
	int		i;
	int		line_count;

	i = 0;
	line_count = 0;
	var = get_data();
	while (var->all_char_map[i])
	{
		while (var->all_char_map[i++] != '\n')
		{
			line_count++;
		}
		if (line_count != var->width)
		{
			printf("%s", E_MAP_LINE_DIFF);
			exit(1);
		}
		else
		{
			line_count = 0;
			var->all_char_map[i] = var->all_char_map[i + 1];
		}
	}
}

void	map_valid_border(void)
{
	t_data	*var;
	int		x;
	int		y;

	y = 0;
	var = get_data();
	while (y < var->height)
	{
		x = 0;
		while (x < var->width)
		{
			if (x == 0 && var->map[y][x] != '1')
				print_error_exit();
			if (y == 0 && var->map[y][x] != '1')
				print_error_exit();
			if (x == var->width - 1 && var->map[y][x] != '1')
				print_error_exit();
			if (y == var->height - 1 && var->map[y][x] != '1')
				print_error_exit();
			x++;
		}
		y++;
	}
}
