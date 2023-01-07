/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:51:24 by jgo               #+#    #+#             */
/*   Updated: 2023/01/04 19:19:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "matrix.h"

void	scale_map(t_dot *dot, int scale, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dot[i].axis[X] = dot[i].axis[X] * scale;
		dot[i].axis[Y] = dot[i].axis[Y] * scale;
		dot[i].axis[Z] = dot[i].axis[Z] * scale;
		i++;
	}
}

void	centering_map(t_dot *dot, t_dot src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dot[i].axis[X] = dot[i].axis[X] + src.axis[X];
		dot[i].axis[Y] = dot[i].axis[Y] + src.axis[Y];
		dot[i].axis[Z] = dot[i].axis[Z] + src.axis[Z];
		i++;
	}
}

void	rotate_map(t_dot *projection, float angle[3], size_t len)
{
	size_t	i;
	float	matrix3[3][3];
	float	rad3[3];

	matrix3_init(matrix3);
	radian_init(rad3, angle);
	matrix3[0][0] = cos(rad3[Z]) * cos(rad3[Y]);
	matrix3[0][1] = cos(rad3[Z]) * sin(rad3[Y]) * sin(rad3[X]) - sin(rad3[Z]) * cos(rad3[X]);
	matrix3[0][2] = cos(rad3[Z]) * sin(rad3[Y]) * cos(rad3[X]) - sin(rad3[Z]) * sin(rad3[X]);
	matrix3[1][0] = sin(rad3[Z]) * cos(rad3[Y]);
	matrix3[1][1] = sin(rad3[Z]) * sin(rad3[Y]) * sin(rad3[X]) + cos(rad3[Z]) * cos(rad3[X]);
	matrix3[1][2] = sin(rad3[Z]) * sin(rad3[Y]) * cos(rad3[X]) - cos(rad3[Z]) * sin(rad3[X]);
	matrix3[2][0] = -sin(rad3[Y]);
	matrix3[2][1] = cos(rad3[Y]) * sin(rad3[Z]);
	matrix3[2][2] = cos(rad3[Y]) * cos(rad3[Z]);
	i = 0;
	while (i < len)
	{
		projection[i] = mul3_mat(matrix3, projection[i]);
		i++;
	}	
}

// scale rotate translate

void	edit_map(t_meta *meta, t_dot *projection)
{
	scale_map(projection, meta->map.scale, meta->map.total_len);
	rotate_map(projection, meta->map.angle, meta->map.total_len);
	centering_map(projection, meta->map.src, meta->map.total_len);
	// move_map();
}