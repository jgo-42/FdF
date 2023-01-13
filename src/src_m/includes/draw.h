/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:04:57 by jgo               #+#    #+#             */
/*   Updated: 2023/01/13 21:26:34 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

void	draw_process(t_meta *meta, t_bool init);

// draw_map.c

void draw(t_meta *meta, t_dot *projection, t_bool init);
void	draw_dot_between(t_meta *meta, t_dot start, t_dot end);

// edit_map.c

void	edit_map(t_meta *meta, t_dot *projection, int len);
void	draw_planet(t_map *map, t_dot *projection);
// void	draw_planet(t_meta *meta, t_dot *projection , float angle[3]);

// draw_status.c

void    draw_status(t_meta *meta);

#endif