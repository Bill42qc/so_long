/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:31:30 by bmartin           #+#    #+#             */
/*   Updated: 2023/05/24 13:26:37 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	release(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_data	*get_data(void)

{
	static t_data	*var = NULL;

	if (!var)
	{
		var = ft_calloc(1, sizeof(t_data));
		var->width = 0;
		var->height = 0;
		var->width_pixel = 0;
		var->height_pixel = 0;
		var->player_position_x = 0;
		var->player_position_y = 0;
		var->tmp_player_position_x = 0;
		var->tmp_player_position_y = 0;
		var->collectable_left = 1;
		var->move_counter = 0;
		var->direction = 0;
		var->flag_exit = 0;
		var->exit_x = 0;
		var->exit_y = 0;
		var->map_y = -1;
		var->stash = "p";
		var->all_char_map = NULL;
		return (var);
	}
	return (var);
}

void	str_move(void)
{
	t_data	*var;
	char	*str_move_counter;

	var = get_data();
	mlx_image_to_window(var->mlx, var->wall_img, 0 * 64, 0 * 64);
	mlx_image_to_window(var->mlx, var->wall_img, 1 * 64, 0 * 64);
	mlx_image_to_window(var->mlx, var->wall_img, 2 * 64, 0 * 64);
	mlx_image_to_window(var->mlx, var->wall_img, 3 * 64, 0 * 64);
	mlx_put_string(var->mlx, "Number of moves: ", 0, 0);
	str_move_counter = ft_itoa(var->move_counter);
	mlx_put_string(var->mlx, str_move_counter, 165, 0);
	free(str_move_counter);
}

int32_t	main(int argc, char *argv[])
{
	t_data	*var;

	var = get_data();
	map_load(argc, argv);
	map_valid();
	var->mlx = mlx_init(var->width_pixel, var->height_pixel, "so_long", false);
	if (!var->mlx)
		exit(EXIT_FAILURE);
	img_init();
	render();
	collectable_left(var);
	var->move_counter = 0;
	mlx_key_hook(var->mlx, &my_key_hook, NULL);
	mlx_loop(var->mlx);
	mlx_terminate(var->mlx);
	release((void **)var->map);
	free(var);
	return (EXIT_SUCCESS);
}
