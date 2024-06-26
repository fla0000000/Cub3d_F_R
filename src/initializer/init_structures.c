/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:41:09 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 15:34:41 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	init_image(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->path = NULL;
	image->bpp = 0;
	image->line_length = 0;
	image->endian = 0;
	image->width = 0;
	image->height = 0;
}

void	init_internal_structures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		init_image(&game->walls[i]);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		game->type[i].path = NULL;
		game->type[i].hex = 0;
		i++;
	}
}

void	init_ray(t_game *game)
{
	game->ray.direction.x = 0.0;
	game->ray.direction.y = 0.0;
	game->ray.player_pos.x = 0.0;
	game->ray.player_pos.y = 0.0;
	game->ray.step.x = 0.0;
	game->ray.step.y = 0.0;
	game->ray.side_distance.x = 0.0;
	game->ray.side_distance.y = 0.0;
	game->ray.delta_distance.x = 0.0;
	game->ray.delta_distance.y = 0.0;
	game->ray.ndc = 0.0;
	game->ray.cardinal = -1;
	game->ray.side = -1;
	game->ray.wall_dist = 0.0;
	game->ray.wall_x = 0;
	game->ray.line_height = 0;
	game->ray.draw_start = 0;
	game->ray.draw_end = 0;
	game->ray.s = 0.0;
	game->ray.pos = 0.0;
}

void	init_player(t_game *game)
{
	game->player.position.x = 0.0;
	game->player.position.y = 0.0;
	game->player.direction.x = 0.0;
	game->player.direction.y = 0.0;
	game->player.cam_plane.x = 0.0;
	game->player.cam_plane.y = 0.0;
	game->player.move.x = 0.0;
	game->player.move.y = 0.0;
	game->player.rotate = 0;
	game->pix_step = 0.0;
	game->pix_pos = 0.0;
}

// INIT STRUCTURES TO DEFAULT VALUES
void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->win_height = WIN_HEIGHT;
	game->win_width = WIN_WIDTH;
	game->map = NULL;
	game->map_len = 0;
	game->old_time = 0;
	game->fps = 0;
	game->path = NULL;
	game->raw_file = NULL;
	game->n_lines_file = 0;
	game->map_transferred = 0;
	game->pixels = NULL;
	game->textures = NULL;
	init_internal_structures(game);
	init_ray(game);
	init_player(game);
}
