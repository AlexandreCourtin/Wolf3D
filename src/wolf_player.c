/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:23:12 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/14 16:27:37 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			wolf_player_loop(t_wolf *wolf_game)
{
	wolf_game->player.posx += wolf_game->player.movex * PLAYER_SPEED;
	wolf_game->player.posy += wolf_game->player.movey * PLAYER_SPEED;
	if (wolf_game->player.posx < 0)
		wolf_game->player.posx = 0;
	else if (wolf_game->player.posx > 29)
		wolf_game->player.posx = 29;
	if (wolf_game->player.posy < 0)
		wolf_game->player.posy = 0;
	else if (wolf_game->player.posy > 29)
		wolf_game->player.posy = 29;
}