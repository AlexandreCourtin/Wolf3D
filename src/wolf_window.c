/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:17:32 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/13 17:27:41 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int		exitwolf(void)
{
	ft_putendl("wolf3d shutting down");
	exit(0);
	return (0);
}

static int		keyevent(int keycode)
{
	ft_putstr("Button pressed : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == BUTTON_ESCAPE)
		exitwolf();
	return (0);
}

static void		window_init(t_mlx *smlx, t_img *i)
{
	smlx->mlx = mlx_init();
	smlx->win = mlx_new_window(smlx->mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3d");
	smlx->img = mlx_new_image(smlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	smlx->imgstr = (int*)mlx_get_data_addr(smlx->img, &i->bpp, &i->s_l, \
			&i->endian);
}

void			wolf_create_window(t_wolf *wolf_game)
{
	t_img		i;

	window_init(&wolf_game->smlx, &i);
	mlx_key_hook(wolf_game->smlx.win, keyevent, 0);
	mlx_hook(wolf_game->smlx.win, 17, 0, exitwolf, 0);
	mlx_loop(wolf_game->smlx.mlx);
}
