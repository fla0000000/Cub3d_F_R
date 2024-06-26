/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:33:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 15:24:46 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

// 1)FA IL FREE + CALLOC DI PIXELS
// 2)reset_pixels(game);
// 3)reset valori di default del ray
void	restore_rendering(t_game *game)
{
	int	i;

	i = 0;
	init_ray(game);
	if (game->pixels)
		free_matrix((void **)game->pixels);
	game->pixels = ft_calloc(game->win_height + 1,
			sizeof * game->pixels);
	if (!game->pixels)
		clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MALLOC, NULL));
	while (i < game->win_height)
	{
		game->pixels[i] = ft_calloc(game->win_width + 1,
				sizeof * game->pixels);
		if (!game->pixels[i])
			clean_exit(game, throw_exception(SYSTEM_EXCEPTION,
					ERR_MALLOC, NULL));
		i++;
	}
}

/**
 * @brief Renders the entire screen.
 *
 * This function renders the entire screen by iterating
 * through each pixel and determining its color based on
 * the raycasting results, producing a 3D perspective view
 * of the scene for the player.
 *
 * @param game Pointer to the game data structure containing
 * 			   rendering information.
 */
void	render_screen(t_game *game)
{
	restore_rendering(game);
	raycasting(game);
	print_screen(game);
}

// mlx_loop_hook's function
// will render a new image only if player has moved
int	render(t_game *game)
{
	if (has_moved(game))
		render_screen(game);
	return (0);
}
