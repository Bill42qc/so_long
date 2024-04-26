/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:19:50 by bmartin           #+#    #+#             */
/*   Updated: 2023/06/01 12:09:42 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(void)
{
	png_to_texture();
	texture_to_image();
}

void	png_to_texture(void)
{
	t_data	*var;

	var = get_data();
	var->wall = mlx_load_png("./assets/wall.png");
	var->grass = mlx_load_png("./assets/grass.png");
	var->collectable = mlx_load_png("./assets/collectable.png");
	var->penguin_idle = mlx_load_png("./assets/penguin_idle.png");
	var->penguin_idle2 = mlx_load_png("./assets/penguin_idle2.png");
	var->penguin_walk_down = mlx_load_png("./assets/penguin_walk_down.png");
	var->penguin_walk_down2 = mlx_load_png("./assets/penguin_walk_down2.png");
	var->penguin_walk_up = mlx_load_png("./assets/penguin_walk_up.png");
	var->penguin_walk_up2 = mlx_load_png("./assets/penguin_walk_up2.png");
	var->penguin_walk_left = mlx_load_png("./assets/penguin_walk_left.png");
	var->penguin_walk_left2 = mlx_load_png("./assets/penguin_walk_left2.png");
	var->penguin_walk_right = mlx_load_png("./assets/penguin_walk_right.png");
	var->penguin_walk_right2 = mlx_load_png("./assets/penguin_walk_right2.png");
	var->exit = mlx_load_png("./assets/exit2.png");
}

void	texture_to_image(void)
{
	t_data	*var;

	var = get_data();
	var->wall_img = mlx_texture_to_image(var->mlx, var->wall);
	var->grass_img = mlx_texture_to_image(var->mlx, var->grass);
	var->collectable_img = mlx_texture_to_image(var->mlx, var->collectable);
	var->penguin_idle_img = mlx_texture_to_image(var->mlx, var->penguin_idle);
	var->exit_img = mlx_texture_to_image(var->mlx, var->exit);
}
