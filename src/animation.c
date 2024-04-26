/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:30:21 by bmartin           #+#    #+#             */
/*   Updated: 2023/02/01 18:12:00 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_choose(void)
{
	t_data	*var;

	var = get_data();
	if (var->direction == 0)
		animation_down();
	else if (var->direction == 1)
		animation_left();
	else if (var->direction == 2)
		animation_right();
	else if (var->direction == 3)
		animation_up();
}

void	animation_down(void)
{
	t_data		*var;
	static bool	frame;

	var = get_data();
	if (frame == 1)
	{
		var->penguin_idle_img = mlx_texture_to_image(var->mlx,
				var->penguin_walk_down2);
		frame = 0;
	}
	else
	{
		var->penguin_idle_img = mlx_texture_to_image (var->mlx,
				var->penguin_walk_down);
		frame = 1;
	}
}

void	animation_left(void)
{
	t_data		*var;
	static bool	frame;

	var = get_data();
	if (frame == 1)
	{
		var->penguin_idle_img = mlx_texture_to_image(var->mlx,
				var->penguin_walk_left);
		frame = 0;
	}
	else
	{
		var->penguin_idle_img = mlx_texture_to_image(var->mlx,
				var->penguin_walk_left2);
		frame = 1;
	}
}

void	animation_right(void)
{
	t_data		*var;
	static bool	frame;

	var = get_data();
	if (frame == 1)
	{
		var->penguin_idle_img = mlx_texture_to_image(var->mlx,
				var->penguin_walk_right);
		frame = 0;
	}
	else
	{
		var->penguin_idle_img = mlx_texture_to_image(var->mlx,
				var->penguin_walk_right2);
		frame = 1;
	}
}

void	animation_up(void)
{
	t_data		*var;
	static bool	frame;

	var = get_data();
	if (frame == 1)
	{
		var->penguin_idle_img = mlx_texture_to_image(var->mlx,
				var->penguin_walk_up2);
		frame = 0;
	}
	else
	{
		var->penguin_idle_img = mlx_texture_to_image(var->mlx,
				var->penguin_walk_up);
		frame = 1;
	}
}
