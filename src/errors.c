/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:42:49 by bmartin           #+#    #+#             */
/*   Updated: 2023/02/06 18:28:33 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_exit(void)
{
	printf("%s", E_MAP_BORDER);
	exit(0);
}

void	print_map_name_error(void)
{
	printf("%s", E_FILE_NAME);
	exit(0);
}

void	print_no_floodfill(void)
{
	printf("%s", E_FLOODFILL);
	exit(0);
}

void	print_argc_error(void)
{
	printf("%s", E_ARGS_NUM);
	exit(0);
}

void	check_map_extension(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.' && argv[i + 1] == 'b' && argv[i + 2] == 'e' && argv[i
				+ 3] == 'r' && argv[i + 4] == '\0')
		{
			return ;
		}
		else
			i++;
	}
	print_map_name_error();
}
