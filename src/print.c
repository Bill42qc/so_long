/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:15:07 by bmartin           #+#    #+#             */
/*   Updated: 2023/02/07 15:01:10 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(void)
{
	t_data	*var;

	var = get_data();
	var->move_counter++;
	printf("\n YOU WON in %d moves", var->move_counter);
	mlx_terminate(var->mlx);
	exit(0);
}

void print_fd_wrong (void)
{
	t_data *var;

	var = get_data();
	printf("%s", E_FD_WRONG);
	exit(0);
}
