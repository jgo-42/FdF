/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:22:56 by jgo               #+#    #+#             */
/*   Updated: 2023/01/12 21:32:46 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  -> 이미지가 실시간으로 window에 표시되는데 동일한 이미지를 변경 중이면 이미지가 깨질 수도 있음
//  -> 그러므로 이미지를 2개 이상 만드는 것이 안정적임 
// img copy가 필요하겠군. 

#include "declaration.h"
#include "utils.h"
#include "draw.h"
#include "error.h"
#include "color.h"

void	draw_background(t_meta *meta, int back_color, int menu_color)
{
	int	axis[2];
	int	draw_color;

	menu_color = get_color(meta, menu_color);
	back_color = get_color(meta, back_color);
	axis[Y] = 0;
	while (axis[Y] < WIN_HEIGHT)
	{
		axis[X] = 0;
		while (axis[X] < WIN_WIDTH)
		{
			if (axis[X] < MENU_WIDTH)
				draw_color = menu_color;
			else
				draw_color = back_color;
			my_dot_put(meta, axis[X], axis[Y], draw_color);
			axis[X]++;
		}
		axis[Y]++;
	}	
}

void	draw_process(t_meta *meta, t_bool init)
{
	t_dot	*projection;

	projection = malloc(meta->map.total_len * sizeof(t_dot));
	allocate_error_handler(projection);
	draw_background(meta, meta->map.color.back_color, meta->map.color.menu_color);
	copy_dot(meta->map.dot, projection, meta->map.total_len);
	edit_map(meta, projection, meta->map.total_len);
	draw(meta, projection, init);
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->img.img, 0, 0);
	draw_status(meta);
	// draw_keymap(meta); 추가예정.
	free(projection);
}